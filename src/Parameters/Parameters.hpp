#pragma once

#include <Grid/Grid.h>


struct BKeeperParameters : Grid::Serializable
{
    GRID_SERIALIZABLE_CLASS_MEMBERS(
        BKeeperParameters,
        int,                      iterations,
        double,                   mass,
        std::vector<std::string>, benchmarks
    )
};

BKeeperParameters readParameterFile(std::string& filepath);
