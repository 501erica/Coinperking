#include<iostream>
#include <string>
#include <regex>
#include "Proxy.h"
#include "Status.h"
#include "Judger.h"

int main(int argc, char** argv) {//Statusで色々頑張る

	//諸々初期化
	std::string InDate;
	std::string OutDate;
	enum answer {
		CONTINUE,
		END
	};
	auto rx = std::regex{ R"((\d{4})(\.|-|/)(\d{2})(\.|-|/)(\d{2})(\.|-|/)(\d{2})(:|-|/)(\d{2}))" };
	bool LoopFlag = false;

	do {

		//入力処理
		std::cout << "入庫時刻を入力してください（2021年01月15日の場合：2021/01/15.11:05）";
		std::cin >> InDate;
		std::cout << std::endl;
		std::cout << "出庫時刻を入力してください（2021年01月15日の場合：2021/01/15.11:05）";
		std::cin >> OutDate;
		std::cout << std::endl;
		Judger* judger = Judger::getInstance();
		//入力値に問題ない？
		if (std::regex_match(InDate.c_str(), rx) && std::regex_match(OutDate.c_str(), rx)) { 

			//計算～料金表示実施
			Proxy * p_Proxy = new Proxy(InDate,OutDate);
			delete p_Proxy;
		}
		else {
			std::cout << "入力値に問題があります。" << std::endl;
		}

		//継続確認(数値以外をいれるとダメなので直す)
		std::cout << "処理を継続しますか？" << std::endl;
		std::cout << "継続：0　終了：0以外" << std::endl;
		int answer;
		std::cin >> answer;
		switch (answer) {
		case CONTINUE:
			LoopFlag = true;
			break;
		case END:
			LoopFlag = false;
			break;
		default:
			std::cout << "＝＝＝＝＝処理を終了します＝＝＝＝＝" << std::endl;
			LoopFlag = false;
			break;
		}

	} while (LoopFlag);

	return 0;
}