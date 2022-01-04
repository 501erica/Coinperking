#include "CostCalculator.h"
#include <cmath>

//============================================================
//CostCalculator
//CostCalculator::CostCalculate()
//INPUT : 
//OUTPUT : 
//MEMO : コスト計算
//============================================================
int CostCalculator::CostCalculate()
{
	this->calculateCost = static_cast<int>(std::ceil(static_cast<double>(this->minitus) / this->perMinitus) * this->perCost);
	if (this->calculateCost > this->maxCost) {
		return this->maxCost;
	}
	return this ->calculateCost;
}
//============================================================
//CostCalculator
//CostCalculator_Noon::CostCalculator_Noon()
//INPUT : 
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_Noon::CostCalculator_Noon()
{
}
//============================================================
//CostCalculator
//CostCalculator_Noon::CostCalculator_Noon()
//INPUT : int minitus
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_Noon::CostCalculator_Noon(int minitus)
{
	this->perCost = 100;
	this->perMinitus = 20;
	this->maxCost = 900;
	this->minitus = minitus;
}
//============================================================
//CostCalculator
//CostCalculator_Noon::~CostCalculator_Noon()
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ 
//============================================================
CostCalculator_Noon::~CostCalculator_Noon()
{
}
//============================================================
//CostCalculator
//CostCalculator_Night::CostCalculator_Night()
//INPUT : 
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_Night::CostCalculator_Night()
{
}
//============================================================
//CostCalculator
//CostCalculator_Night::CostCalculator_Night()
//INPUT : int minitus
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_Night::CostCalculator_Night(int minitus)
{
	this->perCost = 100;
	this->perMinitus = 60;
	this->maxCost = 300;
	this->minitus = minitus;
}
//============================================================
//CostCalculator
//CostCalculator_Night::~CostCalculator_Night()
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ
//============================================================
CostCalculator_Night::~CostCalculator_Night()
{
}
//============================================================
//CostCalculator
//CostCalculator_SpecialDay::CostCalculator_SpecialDay()
//INPUT : 
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_SpecialDay::CostCalculator_SpecialDay()
{

}
//============================================================
//CostCalculator
//CostCalculator_SpecialDay::CostCalculator_SpecialDay()
//INPUT : int minitus
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
CostCalculator_SpecialDay::CostCalculator_SpecialDay(int minitus)
{
	this->perCost = 200;
	this->perMinitus = 20;
	this->maxCost = 2000;
	this->minitus = minitus;
}
//============================================================
//CostCalculator
//CostCalculator_SpecialDay::~CostCalculator_SpecialDay()
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ
//============================================================
CostCalculator_SpecialDay::~CostCalculator_SpecialDay()
{
}