#pragma once
#include "Date.h"
class CostCalculator
{
public:
	int CostCalculate();
protected:
	int minitus = 0;
	int calculateCost = 0;
	int perMinitus = 1;
	int perCost = 1;
	int maxCost = 0;

};

class CostCalculator_Noon :
	public CostCalculator
{
public:
	CostCalculator_Noon();
	CostCalculator_Noon(int);
	~CostCalculator_Noon();

private:

};

class CostCalculator_Night :
	public CostCalculator
{
public:
	CostCalculator_Night();
	CostCalculator_Night(int);
	~CostCalculator_Night();
private:

};

class CostCalculator_SpecialDay :
	public CostCalculator
{
public:
	CostCalculator_SpecialDay();
	CostCalculator_SpecialDay(int);
	~CostCalculator_SpecialDay();
private:
};
