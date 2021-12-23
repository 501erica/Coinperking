#pragma once
#include <iostream>
//tm\‘¢‘Ì‚É‚µ‚Ä‚©‚çFX‚ÆC³‚ª•K—v
struct date {
	struct tm information = {0};
	enum month {
		January,
		Febrary,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		Octorber,
		November,
		December
	};
	int day_of_week() {
		if (this->information.tm_mon < month::March) {
			this->information.tm_year--;
			this->information.tm_mon += 12;
		}
		int dayofweek = (this->information.tm_year + this->information.tm_year / 4 - this->information.tm_year / 100 + this->information.tm_year / 400 + (13 * this->information.tm_mon + 8) / 5 + this->information.tm_mday) % 7;
		return dayofweek;
	}
	bool is_leap_year(int y)
	{
		y += 1900;
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) { //[4‚ÅŠ„‚èØ‚ê‚é]‚©‚Â[100‚ÅŠ„‚èØ‚ê‚È‚¢A‚Ü‚½‚Í400‚ÅŠ„‚èØ‚ê‚é]
			return true;
		}
		else {
			return false;
		}
	}
	//y”NmŒŽ‚ÉŠÜ‚Ü‚ê‚é“ú”‚ðŒvŽZ‚·‚éŠÖ”
	int num_days_in_month(int y, int m)
	{
		int days = 0;
		if (is_leap_year(y) == true && m == month::Febrary) { //‚¤‚é‚¤”N‚Å2ŒŽ‚Ì‚Æ‚«
			days = 28;
		}
		else if (is_leap_year(y) == false && m == month::Febrary) { //‚¤‚é‚¤”N‚Å‚Í‚È‚¢2ŒŽ
			days = 29;
		}
		else if (m == month::April || m == month::June || m == month::September || m == month::November) { //‚SŒŽA‚UŒŽA‚XŒŽA‚P‚PŒŽ‚Ì‚Æ‚«
			days = 30;
		}
		else { //ã‹LˆÈŠO
			days = 31;
		}
		return days;
	}
	struct date advance(int Day)
	{
		struct date nextDate = *this;
		nextDate.information.tm_mday += Day;
		while (nextDate.information.tm_mday > num_days_in_month(nextDate.information.tm_year, nextDate.information.tm_mon)) { //‚»‚ÌŒŽ‚Ì“ú”‚æ‚èday‚ª¬‚³‚­‚È‚é‚Ü‚ÅŒJ‚è•Ô‚·(day‚ÍŒ¸‚Á‚Ä‚¢‚­)
			nextDate.information.tm_mday -= num_days_in_month(nextDate.information.tm_year, nextDate.information.tm_mon);
			if ((nextDate.information.tm_mon++) > 11 ){ //12ŒŽ‚Ü‚Å‚¢‚Á‚½‚ç1ŒŽ‚É–ß‚é
				nextDate.information.tm_year++;
				nextDate.information.tm_mon = 0;
			}
		}
		return nextDate;
	}

};