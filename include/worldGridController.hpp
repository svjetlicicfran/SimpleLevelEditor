#pragma once
#include <raylib.h>
#include "const.hpp"
#include "vec2.hpp"
class BlockPickerMenu;

#include "tile.hpp"
#include "worldGrid.hpp"
#include <iostream>

class WorldController
{

private:
    TileType selectedTileType;
    WorldGrid *worldGrid;

    Vec2 getClickedTile(const Camera2D &camera) const;

public:
    WorldController(WorldGrid *grid);

    const WorldGrid *getWorldGrid() const;

    void update(const Camera2D &camera, BlockPickerMenu &menu);

    void setSelectedTileType(TileType type);

    TileType getSelectedTileType() const;

    void placeTileAt(const Vec2 &worldPos);
    void eraseTileAt(const Vec2 &worldPos);
};
