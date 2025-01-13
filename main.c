#include "raylib.h"
#include <stdlib.h>

int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Particle Simulation v.0.1");

    SetTargetFPS(60);
    
    const int proton_amt = 10;
    const int neutron_amt = 10;
    const int electron_amt = 10;
    const float damping = 0.99;
    
    
    int proton_size = 10;
    Vector2 p_position[proton_amt];
    Vector2 p_velocity[proton_amt];
    
    
    
    int i;
    for (i = 0; i < proton_amt + 1; i++)
    {
        p_position[i].x = rand() % screenWidth;
        p_position[i].y = rand() % screenHeight;
        p_velocity[i].x = rand() % 5;
        p_velocity[i].y = rand() % 5;
    }
    
    
    int neutron_size = 8;
    int n_pos[neutron_amt][1];
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        
        BeginDrawing();



            ClearBackground(BLACK);
            
            int i;
            for (i = 0; i < proton_amt +1; i++)
            {
                
                
                
                if (p_position[i].x >= screenWidth || p_position[i].x <= 0)
                {
                    p_velocity[i].x *= -1;
                }
                if (p_position[i].y >= screenHeight || p_position[i].y <= 0)
                {
                    p_velocity[i].y *= -1;
                }
                
                
                p_velocity[i].x *= damping;
                p_velocity[i].y *= damping;
                
                p_position[i].x += p_velocity[i].x;
                p_position[i].y += p_velocity[i].y;
                
                DrawCircle(p_position[i].x, p_position[i].y, proton_size, MAROON);
                // DrawText(, 190, 200, 20, LIGHTGRAY);
            }
            

           // DrawText("text", 190, 200, 20, LIGHTGRAY);
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}