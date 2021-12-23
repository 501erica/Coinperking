#include "Judger.h"
#include "Mode.h"
Judger* Judger::judger = nullptr;

Judger::Judger()
{
}
Judger::~Judger()
{
}
Judger* Judger::getInstance()
{
    if (!Judger::judger) {
        Judger::judger = new Judger();
    }
    return nullptr;
}
CalculateMode Judger::judge(date)
{
    CalculateMode mode = CalculateMode::NOON;

    //—j“ú”»’è
    //“ú•t”»’è

    return mode;
}
bool Judger::judge(tm)
{
    return false;
}

bool Judger::judge(std::string, std::string)
{
    return false;
}


