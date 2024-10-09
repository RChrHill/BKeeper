#pragma once

#include <Grid/Grid.h>


class BKeeperLogger: public Grid::Logger
{
public:
    BKeeperLogger(int on, std::string nm): Logger("BKeeper", on, nm, Grid::GridLogColours, "BLACK") {};
};

extern BKeeperLogger BKeeperLogError;
extern BKeeperLogger BKeeperLogWarning;
extern BKeeperLogger BKeeperLogMessage;
extern BKeeperLogger BKeeperLogResult;
extern BKeeperLogger BKeeperLogIterative;
extern BKeeperLogger BKeeperLogDebug;
extern BKeeperLogger BKeeperLogIRL;

namespace BKeeper
{
    void initLogger(void);
}
