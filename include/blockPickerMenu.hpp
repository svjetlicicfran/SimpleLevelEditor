#pragma once
#include <raylib.h>
#include "const.hpp"
#include "vec2.hpp"
#include "tile.hpp"
#include "worldGrid.hpp"
#include "menuTile.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class WorldController; // Forward declaration

class BlockPickerMenu
{
private:
    Rectangle menuRect;               // Rectangle defining the menu area
    WorldController *worldController; // Pointer to the WorldController to set selected tile type
    Texture2D *texture;               // Tileset texture
    std::vector<MenuTile> menuTiles;  // Vector to hold MenuTile objects

public:
    BlockPickerMenu(WorldController *controller, Texture2D *texture, const Rectangle &rect = (Rectangle){0, 0, Constants::screenWidth, Constants::menuHeight});

    bool isMouseOverMenu() const;

    void drawMenu() const;

    void handleInput(const Vec2 &mousePos);
};