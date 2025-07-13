# 最小バージョン要件の設定
cmake_minimum_required(VERSION 3.15)

# プロジェクト名設定
project(Coinperking 
	VERSION 1.0.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDART 11)
set(CMAKE_CXX_STANDART_REQUIRED ON)

# ソースファイルの一括設定
set(SOURCES
    source/CostCalculator.cpp  
    source/Judger.cpp 
    source/ModeCounter.cpp  
    source/Proxy.cpp  
    source/main.cpp
)
# ヘッダーファイルの一括設定
set(HEADERS
    source/CostCalculator.h  
    source/Date.h  
    source/Judger.h  
    source/Mode.h  
    source/ModeCounter.h  
    source/Proxy.h
)

# 実行ファイルの作成
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
