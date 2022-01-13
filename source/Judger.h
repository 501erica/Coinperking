#pragma once
#include "Mode.h"
#include "Date.h"

class Judger
{
public:
	//static Judger* getInstance();
	//static Judger* judger;
	Judger();
	~Judger();
	//モード判定
	CalculateMode judge(struct date);
	//日付の大小判定
	bool judge(struct tm,struct tm);
	//入力値判定
	bool judge(std::string, std::string);

};
