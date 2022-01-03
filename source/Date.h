#pragma once
#include <iostream>
#include <ctime>
//tm\‘¢‘Ì‚É‚µ‚Ä‚©‚çFX‚ÆC³‚ª•K—v
struct date {
	struct tm information = {0};
	//y”NmŒŽ‚ÉŠÜ‚Ü‚ê‚é“ú”‚ðŒvŽZ‚·‚éŠÖ”
	int day_of_week()
	{
		auto information = this->information;
		auto time = mktime(&information);
		information = *localtime(&time);
		//—j“ú[0`6](“ú:0 ŒŽ:1 ‰Î:2 …:3 –Ø:4 ‹à:5 “y:6)
		return information.tm_wday;
	}
	date advance(int Day)
	{
		date nextdate;
		const time_t ONE_DAY = 24 * 60 * 60 ;
		auto time = mktime(&(this->information)) + (Day * ONE_DAY);
		nextdate.information = *localtime(&time);
		return nextdate;
	}

};