#include "../include/const.hpp"

namespace Constants
{
    std::map<TileType, std::pair<int, int>> tileMap = {
        {TileType::Air, {23, 25}},
        {TileType::Dirt, {21, 22}},
        {TileType::Stone, {0, 1}},
        {TileType::Grass_Dirt, {20, 22}},
        {TileType::Stone_Wall, {0, 3}},

    };

    std::filesystem::path getExecutablePath(){
        char buffer[1024];
        ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
        buffer[len] = '\0';
    

        return std::filesystem::path(buffer).parent_path().parent_path();
    }

}