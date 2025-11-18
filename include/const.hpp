#pragma once
#include <map>
#include <filesystem>
#include <unistd.h>
#include <limits.h>
#include <unistd.h>
#include <limits.h>


enum EditorMode
{
    PlaceTile,
    EraseTile,
    SelectTile
};

enum TileType
{
    Dirt,
    Stone,
    Grass_Dirt,
    Stone_Wall,
    Air,
};

namespace Constants
{

    std::filesystem::path getExecutablePath();

    constexpr const char *windowTitle = "2D Level Editor";
    constexpr const int targetFPS = 60;

    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    constexpr int tilesPerRow = 24;    // Number of tiles horizontally
    constexpr int tilesPerColumn = 26; // Number of tiles vertically

    constexpr float tileSize = 384.0f / static_cast<float>(tilesPerRow); // Size of each tile in pixels

    constexpr int worldRows = 20;
    constexpr int worldCols = 40;

    extern std::map<TileType, std::pair<int, int>> tileMap;

    const std::filesystem::path tileMapPath = getExecutablePath() / "assets" / "textures_02_08_25.png";

    constexpr int menuHeight = 75;
    constexpr int menuTilePadding = 10;
    constexpr int menuTileSize = 55;
}
