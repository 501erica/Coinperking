#pragma once
#include <vector>
#include"CostCalculator.h"
#include "Date.h"
#include "Mode.h"
#include "Judger.h"

class ModeCounter 
{
public:
	ModeCounter();
	~ModeCounter();
	ModeCounter(struct date, struct date);
	void ModeCount(std::vector<CostCalculator*>&);
	CostCalculator* CreateCostCalculator(CalculateMode mode ,int minitus);
	bool evalDate(struct date, struct date);
	void updateStartDate(date&,CalculateMode);
	struct date evalBorderDate(enum CalculateMode);
private:
	struct date startDate;
	struct date endDate;
	class Judger* modejudger;

};