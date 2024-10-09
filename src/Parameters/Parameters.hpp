#pragma once

#include <Grid/Grid.h>


struct BKeeperParameters : Grid::Serializable
{
    GRID_SERIALIZABLE_CLASS_MEMBERS(
        BKeeperParameters,
        std::vector<std::string>, benchmarks
    )
};

BKeeperParameters readParameterFile(std::string& filepath);
