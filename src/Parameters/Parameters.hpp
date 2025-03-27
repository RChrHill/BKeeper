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

bool readParameterFile(BKeeperParameters& out, std::string& filepath);
