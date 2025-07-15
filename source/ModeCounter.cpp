#include "ModeCounter.h"
#include "Mode.h"
#include <iostream>
#include <time.h>

//============================================================
//ModeCounter
//ModeCounter()
//INPUT : 
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
ModeCounter::ModeCounter()
{
	modejudger = new Judger();
	this->startDate = {};
	this->endDate = {};

}
//============================================================
//ModeCounter
//ModeCounter(struct date InDate, struct date OutDate)
//INPUT : struct date ,struct date
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
ModeCounter::ModeCounter(struct date InDate, struct date OutDate)
{
	modejudger = new Judger();
	this->startDate = InDate;
	this->endDate = OutDate;
}
//============================================================
//ModeCounter
//~ModeCounter()
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ
//============================================================
ModeCounter::~ModeCounter()
{
	delete modejudger;
}
//============================================================
//ModeCounter
//ModeCount(std::vector<CostCalculator*>& cost)
//INPUT : vector<CostCaluculator*>
//OUTPUT : 
//MEMO : 入場時刻と退場時刻からモード(昼・夜・特別日)の個数を計算
//============================================================
void ModeCounter::ModeCount(std::vector<CostCalculator*>& cost)
{
	bool FirstFlag = true;
	while (ModeCounter::evalDate(this ->startDate,this -> endDate)) {
		//startDateが何モードか判定
		CalculateMode mode = modejudger->judge(this -> startDate);
	
		//startDateから一番近い料金切り替え時刻を計算
		date nextDate = this->evalBorderDate(mode);

		//講座中に追加されたルール対応
		if (FirstFlag) {
			ExtraCalc(startDate, nextDate, FirstFlag);
		}

		//nextDateの方が大きい場合
		if (ModeCounter::evalDate(this->endDate , nextDate)) {
			nextDate = this->endDate;
		}

		//モードの時刻算出
		time_t startTime = mktime(&(this->startDate.information));
		time_t nextTime = mktime(&(nextDate.information));
		int minitus = difftime(nextTime, startTime) / 60;

		//vectorに突っ込む
		cost.push_back(CreateCostCalculator(mode,minitus));
		//startDateを更新
		this->startDate.information = nextDate.information;
	}
}
//============================================================
//ModeCounter
//CreateCostCalculator(CalculateMode mode,int minitus)
//INPUT : CalculateMode mode,int minitus
//OUTPUT : CreateCostCalculator*
//MEMO : モード、分に応じてCreateCostCalculator*を作成
//============================================================
CostCalculator* ModeCounter::CreateCostCalculator(CalculateMode mode,int minitus)
{
	switch (mode) {
	case CalculateMode::NOON:
		return new CostCalculator_Noon(minitus);
		break;
	case CalculateMode::NIGHT:
		return  new CostCalculator_Night(minitus);
		break;
	case CalculateMode::SPECIAL_DAY:
		return  new CostCalculator_SpecialDay(minitus);
		break;
	default:
		return nullptr;
		std::cout << "ModeError" << std::endl;
	}
}
//============================================================
//ModeCounter
//evalDate(date startDate, date endDate)
//INPUT : struct date,struct date
//OUTPUT : bool
//MEMO : startDate < endDate の場合ture
//============================================================
bool ModeCounter::evalDate(date startDate, date endDate)
{
	time_t startTime = mktime(&startDate.information);
	time_t endTime = mktime(&(endDate.information));
	if (difftime(startTime, endTime) < 0) {
		return true;
	}
	return false;
}
//============================================================
//ModeCounter
//evalBorderDate(enum CalculateMode mode)
//INPUT : enum CalculateMode
//OUTPUT : struct date
//MEMO : startDateから最短のモード変更時刻を算出
//============================================================
struct date ModeCounter::evalBorderDate(enum CalculateMode mode) {
	struct date nextDate = this->startDate;
	switch (mode) {
	case CalculateMode::NOON:
		//22:00にセット
		nextDate.information.tm_hour = 22;
		nextDate.information.tm_min = 0;
		break;
	case CalculateMode::NIGHT:
		//22:00以降？
		if (this->startDate.information.tm_hour >= 22) {
			//翌日が特別日？
			if (modejudger->judge(this->startDate.advance(1)) == SPECIAL_DAY) {
				//翌日の00:00にセット
				nextDate = this->startDate.advance(1);
				nextDate.information.tm_hour = 0;
				nextDate.information.tm_min = 0;
				break;
			}
			//翌日の07:00にセット
			nextDate = this->startDate.advance(1);
			nextDate.information.tm_hour =7;
			nextDate.information.tm_min = 0;
			break;
		}
		//当日の07:00にセット
		nextDate.information.tm_hour =7;
		nextDate.information.tm_min = 0;
		break;
	case CalculateMode::SPECIAL_DAY:
		//翌日の00:00にセット
		nextDate = this->startDate.advance(1);
		nextDate.information.tm_hour = 0;
		nextDate.information.tm_min = 0;
		break;
	default:
	break;
	}
	return nextDate;
}

//============================================================
//ModeCounter
//ExtraCalc()
//INPUT : struct date , struct date , bool FirstFlag
//OUTPUT : ture false
//MEMO : 最初だけモードを跨ぐ＆時間が
//       昼と特別日：20分、夜：60分以下ならnextdateを変更
//============================================================
bool ModeCounter::ExtraCalc(struct date& startdate, struct date& bordardate, bool& FirstFlag) {
	//初めて？
	if (!FirstFlag) {
		return false;
	}
	//FirstFlagをfalseに変更
	FirstFlag = false;
	//モードの時刻算出
	time_t startTime = mktime(&startdate.information);
	time_t nextTime = mktime(&bordardate.information);
	int minitus = difftime(nextTime, startTime) / 60;
	CalculateMode mode = modejudger->judge(this->startDate);
	switch (mode) {
	case CalculateMode::NOON:
		if (minitus < 20) {
			///20分追加する
			nextTime =(startTime += 60 * 20);
			localtime_r(&nextTime,&bordardate.information);
			return true;
		}
		return false;
		break;
	case CalculateMode::NIGHT:
		if (minitus < 60) {
			//60分追加する
			nextTime = (startTime += 60 * 60);
			localtime_r(&nextTime,&bordardate.information);
			return true;
		}
		return false;
		break;
	case CalculateMode::SPECIAL_DAY:
		if (minitus < 20) {
			//20分追加する
			nextTime = (startTime += 60 * 20);
			localtime_r(&nextTime,&bordardate.information);
			return true;
		}
		return false;
		break;
	default:
		return false;
		break;
	}
}
