#pragma once
#include <iostream>
#include <ctime>
struct date {
	struct tm information = {0};
	//============================================================
	//Date
	//day_of_week()
	//INPUT : 
	//OUTPUT : int
	//MEMO : —j“ú”»’è [0`6](“ú:0 ŒŽ:1 ‰Î:2 …:3 –Ø:4 ‹à:5 “y:6)
	//============================================================
	int day_of_week()
	{
		auto information = this->information;
		auto time = mktime(&information);
		information = *localtime(&time);
		return information.tm_wday;
	}
	//============================================================
	//Date
	//advance(int Day)
	//INPUT : int
	//OUTPUT : date
	//MEMO : ˆø”‚ÅŽw’è‚³‚ê‚½”‚¾‚¯“ú•t‚ði‚ß‚é
	//============================================================
	date advance(int Day)
	{
		date nextdate;
		const time_t ONE_DAY = 24 * 60 * 60 ;
		auto time = mktime(&(this->information)) + (Day * ONE_DAY);
		nextdate.information = *localtime(&time);
		return nextdate;
	}

};