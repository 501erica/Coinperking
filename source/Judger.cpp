#include "Judger.h"
#include "Mode.h"
#include <vector>

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
CalculateMode Judger::judge(date date)
{
    std::vector<std::pair<int,int>> specialdaylist;
    specialdaylist.push_back(std::make_pair(8,13));
    specialdaylist.push_back(std::make_pair(8,14));
    specialdaylist.push_back(std::make_pair(8,15));
    specialdaylist.push_back(std::make_pair(12,31));
    specialdaylist.push_back(std::make_pair(1,1));
    specialdaylist.push_back(std::make_pair(1,2));
    specialdaylist.push_back(std::make_pair(1,3));

    if(date.day_of_week() == 0 || date.day_of_week() == 6){
        return CalculateMode::SPECIAL_DAY;
    }
    for(int i = 0; i < specialdaylist.size();i++){
        if((date.information.tm_mon + 1 == specialdaylist.at(i).first) && (date.information.tm_mday == specialdaylist.at(i).second)){
            return CalculateMode::SPECIAL_DAY;
        }
    }

    if(date.information.tm_hour < 7){
        return CalculateMode::NIGHT;
    }
    if(22 <= date.information.tm_hour){
        return CalculateMode::NIGHT;
    }
    return CalculateMode::NOON;
}
bool Judger::judge(tm)
{
    return false;
}

bool Judger::judge(std::string, std::string)
{
    return false;
}


