#include "CostCalculator.h"
#include <cmath>

int CostCalculator::CostCalculate()
{
	this->calculateCost = static_cast<int>(std::ceil(static_cast<double>(this->minitus) / this->perMinitus) * this->perCost);
	if (this->calculateCost > this->maxCost) {
		return this->maxCost;
	}
	return this ->calculateCost;
}

CostCalculator_Night::CostCalculator_Night()
{
}

CostCalculator_Night::CostCalculator_Night(int minitus)
{
	this->perCost = 100;
	this->perMinitus = 60;
	this->maxCost = 300;
	this->minitus = minitus;
}

CostCalculator_Night::~CostCalculator_Night()
{
}


CostCalculator_Noon::CostCalculator_Noon()
{
}

CostCalculator_Noon::CostCalculator_Noon(int minitus)
{
	this->perCost = 100;
	this->perMinitus = 20;
	this->maxCost = 900;
	this->minitus = minitus;
}

CostCalculator_Noon::~CostCalculator_Noon()
{
}


CostCalculator_SpecialDay::CostCalculator_SpecialDay()
{

}

CostCalculator_SpecialDay::CostCalculator_SpecialDay(int minitus)
{
	this->perCost = 200;
	this->perMinitus = 20;
	this->maxCost = 2000;
	this->minitus = minitus;
}

CostCalculator_SpecialDay::~CostCalculator_SpecialDay()
{
}

