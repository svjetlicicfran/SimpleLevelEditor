#include <raylib.h>
#include "../include/const.hpp"
#include "../include/vec2.hpp"
#include "../include/cameraController.hpp"
#include "../include/tile.hpp"
#include "../include/worldGrid.hpp"
#include "../include/blockPickerMenu.hpp"
#include "../include/worldGridController.hpp"
#include <iostream>

int main(){
    InitWindow(Constants::screenWidth, Constants::screenHeight, Constants::windowTitle);
    SetTargetFPS(Constants::targetFPS);

    Texture2D texture = LoadTexture(Constants::tileMapPath.c_str());

    CameraController cameraController;

    WorldGrid worldGrid(Constants::worldRows, Constants::worldCols, &texture);

    WorldController worldController(&worldGrid);

    BlockPickerMenu blockPickerMenu(&worldController, &texture);

    while (!WindowShouldClose()) {
        cameraController.updateCamera();

        BeginDrawing();
        ClearBackground(BLACK);

        BeginMode2D(cameraController.getCamera());
        
        worldGrid.drawGrid();
        worldController.update(cameraController.getCamera(), blockPickerMenu);

        EndMode2D();

        blockPickerMenu.drawMenu(); // <-- This is outside BeginMode2D/EndMode2D
        blockPickerMenu.handleInput(GetMousePosition());

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}
