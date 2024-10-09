#include "BKeeperLog.hpp"


BKeeperLogger BKeeperLogError(1,"Error");
BKeeperLogger BKeeperLogWarning(1,"Warning");
BKeeperLogger BKeeperLogMessage(1,"Message");
BKeeperLogger BKeeperLogResult(1,"Result");
BKeeperLogger BKeeperLogIterative(1,"Iterative");
BKeeperLogger BKeeperLogDebug(1,"Debug");
BKeeperLogger BKeeperLogIRL(1,"IRL");

namespace BKeeper
{
    void initLogger(void)
    {
        using namespace Grid;

        auto w  = std::string("BKeeper").length();
        int  cw = 8;

        GridLogError    .setTopWidth(w);
        GridLogWarning  .setTopWidth(w);
        GridLogMessage  .setTopWidth(w);
        GridLogIterative.setTopWidth(w);
        GridLogDebug    .setTopWidth(w);
        GridLogIRL      .setTopWidth(w);
        GridLogError    .setChanWidth(cw);
        GridLogWarning  .setChanWidth(cw);
        GridLogMessage  .setChanWidth(cw);
        GridLogIterative.setChanWidth(cw);
        GridLogDebug    .setChanWidth(cw);
        GridLogIRL      .setChanWidth(cw);

        BKeeperLogError    .Active(true);
        BKeeperLogWarning  .Active(true);
        BKeeperLogMessage  .Active(GridLogMessage.isActive());
        BKeeperLogResult   .Active(GridLogMessage.isActive());
        BKeeperLogIterative.Active(GridLogIterative.isActive());
        BKeeperLogDebug    .Active(GridLogDebug.isActive());
        BKeeperLogIRL      .Active(GridLogIRL.isActive());
        BKeeperLogError    .setTopWidth(w);
        BKeeperLogWarning  .setTopWidth(w);
        BKeeperLogMessage  .setTopWidth(w);
        BKeeperLogResult  .setTopWidth(w);
        BKeeperLogIterative.setTopWidth(w);
        BKeeperLogDebug    .setTopWidth(w);
        BKeeperLogIRL      .setTopWidth(w);
        BKeeperLogError    .setChanWidth(cw);
        BKeeperLogWarning  .setChanWidth(cw);
        BKeeperLogMessage  .setChanWidth(cw);
        BKeeperLogResult  .setChanWidth(cw);
        BKeeperLogIterative.setChanWidth(cw);
        BKeeperLogDebug    .setChanWidth(cw);
        BKeeperLogIRL      .setChanWidth(cw);
    }
}
