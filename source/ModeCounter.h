#pragma once
#include "CostCalculator.h"
#include "Date.h"
#include "Judger.h"
#include "Mode.h"
#include <vector>

class ModeCounter
{
  public:
    ModeCounter();
    ~ModeCounter();
    ModeCounter(struct date, struct date);
    void ModeCount(std::vector<CostCalculator *> &);
    CostCalculator *CreateCostCalculator(CalculateMode mode, int minitus);
    bool evalDate(struct date, struct date);
    bool ExtraCalc(date &startdate, date &enddate, bool &FirstFlag);
    struct date evalBorderDate(enum CalculateMode);

  private:
    struct date startDate;
    struct date endDate;
    class Judger *modejudger;
};