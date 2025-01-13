#include "raylib.h"


int main(void)
{
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Particle Simulation v.0.1");

    SetTargetFPS(60);
    
    const int proton_amt = 10;
    const int neutron_amt = 10;
    const int electron_amt = 10;
    
    
    int proton_size = 10;
    int p_pos_x[proton_amt][1];
    
    
    int neutron_size = 8;
    int n_pos_x[neutron_amt][1];
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        
        BeginDrawing();



            ClearBackground(BLACK);
            
            int i;
            for (i = 0; i < 10; i++)
            {
                DrawCircle(GetScreenWidth()/2, GetScreenHeight()/2, proton_size, MAROON);
            }
            

           // DrawText("text", 190, 200, 20, LIGHTGRAY);
        DrawFPS(10, 10);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();        // Close window and OpenGL context

    return 0;
}