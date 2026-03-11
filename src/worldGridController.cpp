#include "../include/worldGridController.hpp"
#include "../include/blockPickerMenu.hpp"

WorldController::WorldController(WorldGrid *grid) : worldGrid(grid), selectedTileType(TileType::Stone_Wall) {}

Vec2 WorldController::getClickedTile(const Camera2D &camera) const
{

    Vector2 mousePos = GetMousePosition();

    Vec2 worldPos = GetScreenToWorld2D(mousePos, camera);

    int tileX = static_cast<int>(worldPos.x / Constants::tileSize);
    int tileY = static_cast<int>(worldPos.y / Constants::tileSize);

    return Vec2(tileX, tileY);
}

void WorldController::update(const Camera2D &camera, BlockPickerMenu &menu)
{

    Vec2 tilePos = getClickedTile(camera);

    if (tilePos.x < 0 || tilePos.y < 0 ||
        tilePos.x >= Constants::worldCols || tilePos.y >= Constants::worldRows)
    {
        return; 
    }

    
    if (!menu.isMouseOverMenu())
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            std::cout << "Clicked tile at: (" << tilePos.x << ", " << tilePos.y << ")\n";
            placeTileAt(tilePos);
        }
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
        {
            std::cout << "Erased tile at: (" << tilePos.x << ", " << tilePos.y << ")\n";
            eraseTileAt(tilePos);
        }

        DrawRectangleLinesEx((Rectangle){tilePos.x * Constants::tileSize, tilePos.y * Constants::tileSize, Constants::tileSize, Constants::tileSize}, 0.75f, (Color){255, 255, 255, 100});
    }
    else
    {
        // menu.handleInput(GetMousePosition());
    }
}

void WorldController::placeTileAt(const Vec2 &worldPos)
{
    if (worldGrid)
    {
        worldGrid->setTileAt(worldPos, selectedTileType);
    }
}

void WorldController::eraseTileAt(const Vec2 &worldPos)
{
    if (worldGrid)
    {
        worldGrid->setTileAt(worldPos, TileType::Air);
    }
}

void WorldController::setSelectedTileType(TileType type)
{
    std::cout << "WorldController: Setting selected tile type to " << type << "\n";
    selectedTileType = type;
}

TileType WorldController::getSelectedTileType() const
{
    return selectedTileType;
}

const WorldGrid *WorldController::getWorldGrid() const
{
    return worldGrid;
}
