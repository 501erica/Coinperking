#pragma once
#include <vector>
#include <string>
#include "CostCalculator.h"
#include <iostream>
#include <regex>
#include "ModeCounter.h"
#include "Date.h"

class Proxy
{
public:
	Proxy();
	~Proxy();
	Proxy(std::string, std::string);
	void showCost();
	std::vector<CostCalculator*> ModeContainer;

private:
	int Cost = 0;
	struct date InDate;
	struct date OutDate;
	Judger* p_judger = nullptr;
	ModeCounter* p_ModeCounter = nullptr;

	void Initialize(std::string, std::string);
};
