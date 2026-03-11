#include "../include/blockPickerMenu.hpp"
#include "../include/worldGridController.hpp"

BlockPickerMenu::BlockPickerMenu(WorldController *controller, Texture2D *tex, const Rectangle &rect) : worldController(controller), texture(tex), menuRect(rect)
{

    for (std::map<TileType, std::pair<int, int>>::const_iterator it = Constants::tileMap.begin(); it != Constants::tileMap.end(); ++it)
    {
        TileType type = it->first;
        menuTiles.push_back(MenuTile(type, Vec2(menuTiles.size() * Constants::menuTileSize * 1.1 + 10, Constants::menuTilePadding), texture));
    }

    std::sort(menuTiles.begin(), menuTiles.end(), [](const MenuTile &a, const MenuTile &b)
              { return a.getTileType() < b.getTileType(); });
}

void BlockPickerMenu::drawMenu() const
{
    DrawRectangleRec(menuRect, (Color){50, 64, 99, 255});

    for (const auto &menuTile : menuTiles)
    {

        menuTile.drawTile();

        if (worldController && menuTile.getTileType() == worldController->getSelectedTileType())
        {
            DrawRectangleLinesEx(menuTile.getBoundingBox(), 2, (Color){255, 255, 255, 255});
        }
    }
}

bool BlockPickerMenu::isMouseOverMenu() const
{
    Vector2 mouse = GetMousePosition();
    return CheckCollisionPointRec(mouse, menuRect);
}

void BlockPickerMenu::handleInput(const Vec2 &mousePos)
{

    for (const auto &menuTile : menuTiles)
    {
        if (CheckCollisionPointRec(mousePos, menuTile.getBoundingBox()))
        {

            DrawRectangleLinesEx(menuTile.getBoundingBox(), 2, (Color){255, 255, 255, 255});

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (worldController)
                {
                    worldController->setSelectedTileType(menuTile.getTileType());
                    std::cout << "Selected tile type: " << menuTile.getTileType() << "\n";
                }
            }
        }
    }
}
