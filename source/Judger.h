#pragma once
#include "Status.h"
#include "Mode.h"
#include "Date.h"

class Judger
{
public:
	static Judger* getInstance();
	static Judger* judger;
	//モード判定
	CalculateMode judge(struct date);
	//日付の大小判定
	bool judge(struct tm);
	//入力値判定
	bool judge(std::string, std::string);
private:
	Judger();
	~Judger();
};
