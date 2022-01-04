#include "Proxy.h"

//============================================================
//Proxy
//:Proxy()
//INPUT : 
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
Proxy::Proxy()
{
}
//============================================================
//Proxy
//~Proxy()
//INPUT : 
//OUTPUT : 
//MEMO : デストラクタ
//============================================================
Proxy::~Proxy()
{
	delete p_ModeCounter;
}
//============================================================
//Proxy
//Proxy(std::string InDate, std::string OutDate)
//INPUT : string , string
//OUTPUT : 
//MEMO : コンストラクタ
//============================================================
Proxy::Proxy(std::string InDate, std::string OutDate)
{
	//メンバ変数の初期化
	this->Initialize(InDate, OutDate);
	//入力値判定(main関数でやらないために)
	Judger* p_judger = Judger::getInstance();
	//===========分割してもいいんじゃないか============
	//Mode数をカウント
	p_ModeCounter->ModeCount(ModeContainer);
	//料金を計算して表示
	this->showCost();
}
//============================================================
//Proxy
//howCost()
//INPUT : 
//OUTPUT : 
//MEMO : 料金表示
//============================================================
void Proxy::showCost()
{
	//vectorの要素の料金計算を指示
	for (int i = 0; i < this -> ModeContainer.size(); i++) {
		this->Cost += this -> ModeContainer.at(i)->CostCalculate();
	}
	std::cout << "料金は　" << this->Cost << "　円です。" << std::endl;
}

//============================================================
//Proxy
//Initialize(std::string InDate, std::string OutDate)
//INPUT : string , string
//OUTPUT : 
//MEMO : メンバ変数の初期化
//============================================================
void Proxy::Initialize(std::string InDate, std::string OutDate)
{
	const auto rx = std::regex{ R"((\d{4})(\.|-|/)(\d{2})(\.|-|/)(\d{2})(\.|-|/| )(\d{2})(:|-|/)(\d{2}))" };

	this->InDate.information.tm_year = stoi(std::regex_replace(InDate.c_str(), rx, "$1")) - 1900;
	this->InDate.information.tm_mon = stoi(std::regex_replace(InDate.c_str(), rx, "$3")) - 1;
	this->InDate.information.tm_mday = stoi(std::regex_replace(InDate.c_str(), rx, "$5"));
	this->InDate.information.tm_hour = stoi(std::regex_replace(InDate.c_str(), rx, "$7"));
	this->InDate.information.tm_min = stoi(std::regex_replace(InDate.c_str(), rx, "$9"));
	this->InDate.information.tm_isdst = -1;

	this->OutDate.information.tm_year = stoi(std::regex_replace(OutDate.c_str(), rx, "$1")) - 1900;
	this->OutDate.information.tm_mon = stoi(std::regex_replace(OutDate.c_str(), rx, "$3")) - 1;
	this->OutDate.information.tm_mday = stoi(std::regex_replace(OutDate.c_str(), rx, "$5"));
	this->OutDate.information.tm_hour = stoi(std::regex_replace(OutDate.c_str(), rx, "$7"));
	this->OutDate.information.tm_min = stoi(std::regex_replace(OutDate.c_str(), rx, "$9"));
	this->OutDate.information.tm_isdst = -1;

	this -> p_ModeCounter = new ModeCounter(this->InDate, this->OutDate);

}