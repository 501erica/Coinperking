#include<iostream>
#include <string>
#include <regex>
#include "Proxy.h"
#include "Status.h"
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
		std::cout << "入庫時刻を入力してください（2021年01月15日の場合：2021/01/15-11:05）";
		//std::getline(std::cin, InDate);
		std::cin >> InDate;
		std::cout << std::endl;
		std::cout << "出庫時刻を入力してください（2021年01月15日の場合：2021/01/15-11:05）";
		//std::getline(std::cin , OutDate);
		std::cin >> OutDate;
		std::cout << std::endl;
		Judger* inputJudger = Judger::getInstance();

		//入力値に問題ない？
		if((inputJudger->judge(InDate,OutDate))){
			//計算～料金表示実施
			Proxy * p_Proxy = new Proxy(InDate,OutDate);
			delete p_Proxy;
		}

		//継続確認
		std::cout << "処理を継続しますか？" << std::endl;
		std::cout << "継続：0　終了：0以外" << std::endl;
		int answer;
		std::cin >> answer;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore( 256, '\n' );
			std::cout << "answer is not Integer" << std::endl;
			answer = 1;
		}
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