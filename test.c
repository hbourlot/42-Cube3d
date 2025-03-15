

// C program for DDA line generation 
  
#include <.gitignore>/
#include "./lib/minilibx-linux/mlx.h" 
#include <math.h> 
#include <stdio.h> 
// Function for finding absolute value 

  
// Driver program 
int main() 
{ 
    int gd = DETECT, gm; 
  
    // Initialize graphics function 
    initgraph(&gd, &gm, ""); 
  
    int X0 = 2, Y0 = 2, X1 = 14, Y1 = 16; 
  
    // Function call 
    DDA(2, 2, 14, 16); 
    return 0; 
}
