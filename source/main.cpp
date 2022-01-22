#include<iostream>
#include <string>
#include <regex>
#include "Proxy.h"
#include "Judger.h"

int main(int argc, char** argv) {

	//諸々初期化
	std::string InDate;
	std::string OutDate;
	enum answer {
		CONTINUE,
		END
	};

	bool LoopFlag = false;
	do {
		//入力処理
		std::cout << "入庫日時を入力してください（2021年01月15日の場合：2021/01/15-11:05）";
		std::cin >> InDate;
		std::cout << std::endl;
		std::cout << "出庫日時を入力してください（2021年01月15日の場合：2021/01/15-11:05）";
		std::cin >> OutDate;
		std::cout << std::endl;
		Judger* inputJudger = new Judger();;

		//入力値に問題ない？
		if((inputJudger->judge(InDate,OutDate))){
			//計算～料金表示実施
			Proxy * p_Proxy = new Proxy(InDate,OutDate);
			delete p_Proxy;
		}

		delete inputJudger;

		//継続確認
		std::cout << "処理を継続しますか？" << std::endl;
		std::cout << "継続：y　終了：n" << std::endl;
		std::string answer;
		std::cin >> answer;
		auto rx = std::regex{ R"(([yY]))" };
		if (std::regex_match(answer.c_str(), rx)) {
			LoopFlag = true;
		}
		else {
			LoopFlag = false;
		}
	} while (LoopFlag);

	return 0;
}