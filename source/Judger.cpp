#include "Judger.h"
#include "Mode.h"
#include "Date.h"
#include <vector>
#include <regex>

//============================================================
//Judger
//Judgeri()
//INPUT :
//OUTPUT :
//MEMO : コンストラクタ
//============================================================
Judger::Judger()
{
}
//============================================================
//Judger
//~Judger
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ
//============================================================
Judger::~Judger()
{
}
//============================================================
//Judger
//judge(struct date)
//INPUT : struct date
//OUTPUT : CalculateMode
//MEMO : 引数の日付のモード判定
//============================================================
CalculateMode Judger::judge(date date)
{
    std::vector<std::pair<int,int>> specialdaylist;
    specialdaylist.push_back(std::make_pair(8,13));
    specialdaylist.push_back(std::make_pair(8,14));
    specialdaylist.push_back(std::make_pair(8,15));
    specialdaylist.push_back(std::make_pair(12,31));
    specialdaylist.push_back(std::make_pair(1,1));
    specialdaylist.push_back(std::make_pair(1,2));
    specialdaylist.push_back(std::make_pair(1,3));

    if(date.day_of_week() == 0 || date.day_of_week() == 6){
        return CalculateMode::SPECIAL_DAY;
    }
    for(int i = 0; i < specialdaylist.size();i++){
        if((date.information.tm_mon + 1 == specialdaylist.at(i).first) && (date.information.tm_mday == specialdaylist.at(i).second)){
            return CalculateMode::SPECIAL_DAY;
        }
    }

    if(date.information.tm_hour < 7){
        return CalculateMode::NIGHT;
    }
    if(22 <= date.information.tm_hour){
        return CalculateMode::NIGHT;
    }
    return CalculateMode::NOON;
}
//============================================================
//Judger
//judge(std::string, std::string)
//INPUT : string,string
//OUTPUT : bool
//MEMO : 入力値判定
//============================================================
bool Judger::judge(std::string InDate, std::string OutDate)
{
	auto rx = std::regex{ R"((\d{4})(\.|-|/)(\d{2})(\.|-|/)(\d{2})(\.|-|/| )(\d{2})(:|-|/)(\d{2}))" };
	if (!(std::regex_match(InDate.c_str(), rx) && std::regex_match(OutDate.c_str(), rx))) { 
	    std::cout << "入力形式が不正です。以下の形式で日時を半角で入力してください" << "yyyy/mm/dd-hh:mm" << std::endl;
        return false;
    }

    auto rx2 = std::regex{ R"(([1-2][0-9][0-9][0-9])(\.|-|/)(0[1-9]|1[0-2])(\.|-|/)(0[1-9]|[12][0-9]|3[01])(\.|-|/| )([01][0-9]|2[0-3])(:|-|/)([0-5][0-9]))" };
    if (!(std::regex_match(InDate.c_str(), rx2) && std::regex_match(OutDate.c_str(), rx2))) {
        std::cout << "入力形式が不正です。入力年は1000~2999,入力月は01~12,入力日は01~31で入力してください。" << std::endl;
        return false;
    }


    struct date Indate,Outdate;
    Indate.information.tm_year = stoi(std::regex_replace(InDate.c_str(), rx, "$1")) - 1900;
    Indate.information.tm_mon = stoi(std::regex_replace(InDate.c_str(), rx, "$3")) - 1;
    Indate.information.tm_mday = stoi(std::regex_replace(InDate.c_str(), rx, "$5"));
    Indate.information.tm_hour = stoi(std::regex_replace(InDate.c_str(), rx, "$7"));
    Indate.information.tm_min = stoi(std::regex_replace(InDate.c_str(), rx, "$9"));
    Indate.information.tm_isdst = -1;

    Outdate.information.tm_year = stoi(std::regex_replace(OutDate.c_str(), rx, "$1")) - 1900;
    Outdate.information.tm_mon = stoi(std::regex_replace(OutDate.c_str(), rx, "$3")) - 1;
    Outdate.information.tm_mday = stoi(std::regex_replace(OutDate.c_str(), rx, "$5"));
    Outdate.information.tm_hour = stoi(std::regex_replace(OutDate.c_str(), rx, "$7"));
    Outdate.information.tm_min = stoi(std::regex_replace(OutDate.c_str(), rx, "$9"));
    Outdate.information.tm_isdst = -1;

    time_t Intime = mktime(&Indate.information);
    time_t Outtime = mktime(&Outdate.information);
    time_t now = time(nullptr);

    if((Outtime - Intime) > 72*3600){
        std::cout << "最大駐車時間（72時間）を超える日時が指定されています。" << std::endl;
        return false;
    }

    if(Intime > Outtime){
        std::cout << "日時指定が不正です。出庫日時に入庫時刻より過去の時間が指定されています。" << std::endl;
        return false;
    }

    if(Intime == Outtime){
        std::cout << "日時指定が不正です。入庫・出庫日時が同じです。" << std::endl;
        return false;
    }
    
    if(now > Intime){
        std::cout << "日時指定が不正です。本日より過去の日時が指定されています。" << std::endl;
        return false;
    }

    return true;
}


