

// C program for DDA line generation 
  
#include "./lib/minilibx-linux/mlx.h" 
/*
** Raycaster using MiniLibX (C conversion)
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
# include <X11/X.h>      // Button press
# include <X11/keysym.h> // Key device

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

int worldMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct {
    void *mlx;
    void *win;
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
    double  planeX;
    double  planeY;
    double  time;
    double  oldTime;
    double  cameraX;
    int     mapX;
    int     mapY;
    double  sideDistX;
    double  sideDistY;
    double  rayDirX;
    double  rayDirY;
    double  deltaDistX;
    double  deltaDistY;
    int     stepX;
    int     stepY;
    int     hit;
    int     side;
    int     lineHeight;
    int     drawStart;
    int     drawEnd;
    int     color;
    double  perpWallDist;
} t_data;

int render_frame(t_data *data)
{
    int x;

    for (x = 0; x < SCREEN_WIDTH; x++) {
        data->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        data->rayDirX = data->dirX + data->planeY * data->cameraX;
        data->rayDirY = 0 + 0.66 * data->cameraX;
        data->mapX = 22;
        data->mapY = 12;
        data->deltaDistX = fabs(1 / data->rayDirX);
        data->deltaDistY = fabs(1 / data->rayDirY);
        
        data->hit = 0;
        data->side = 0;

        if (data->rayDirX < 0) {
            data->stepX = -1;
            data->sideDistX = (22 - data->mapX) * data->deltaDistX;
        } else {
            data->stepX = 1;
            data->sideDistX = (data->mapX + 1.0 - 22) * data->deltaDistX;
        }
        if (data->rayDirY < 0) {
            data->stepY = -1;
            data->sideDistY = (12 - data->mapY) * data->deltaDistY;
        } else {
            data->stepY = 1;
            data->sideDistY = (data->mapY + 1.0 - 12) * data->deltaDistY;
        }

      //perform DDA
        while (data->hit == 0)
        {
            //jump to next map square, either in x-direction, or in y-direction
            if (data->sideDistX < data->sideDistY)
            {
                data->sideDistX += data->cameraX;
                data->mapX += data->stepX;
                data->side = 0;
            } 
            else
            {
                data->sideDistY += data->deltaDistY;
                data->mapY += data->stepY;
                data->side = 1;
            }
            if (worldMap[data->mapX][data->mapY] > 0)
                data->hit = 1;
        }
        // if (data->side == 0)
        //     data->perpWallDist = (data->sideDistX - data->deltaDistX);
        // else
        //     data->perpWallDist = (data->sideDistY - data->deltaDistY);
        //Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
        //hit to the camera plane. Euclidean to center camera point would give fisheye effect!
        //This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
        //for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
        //because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
        //steps, but we subtract deltaDist once because one step more into the wall was taken above.        
        data->lineHeight = (int)(SCREEN_HEIGHT / ((data->side == 0) ? (data->sideDistX - data->cameraX) : (data->sideDistY - data->deltaDistY)));
        data->drawStart = -data->lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (data->drawStart < 0) 
            data->drawStart = 0;
        data->drawEnd = data->lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (data->drawEnd >= SCREEN_HEIGHT)
            data->drawEnd = SCREEN_HEIGHT - 1;
        data->color = (data->side == 1) ? 0xAAAAAA : 0xFFFFFF;
        for (int y = data->drawStart; y < data->drawEnd; y++)
            mlx_pixel_put(data->mlx, data->win, x, y, data->color);
    }
    return (0);
}

// int keys(int keycode, t_data *data)
// {
//     if (keycode == XK_Up)
//     {

//     }
// }

int main()
{
    t_data data;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Raycaster");
    data.posX = 22;
    data.posY = 12;  //x and y start position
    data.dirX = -1;
    data.dirY = 0; //initial direction vector
    data.planeX = 0;
    data.planeY = 0.66; //the 2d raycaster version of camera plane
    data.time = 0; //time of current frame
    data.oldTime = 0; //time of previous frame
    mlx_loop_hook(data.mlx, render_frame, &data);
    mlx_loop(data.mlx);
    return 0;
}
