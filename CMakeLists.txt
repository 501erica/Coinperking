# 最小バージョン要件の設定
cmake_minimum_required(VERSION 3.15)

# プロジェクト名設定
project(Coinperking 
	VERSION 1.0.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(FetchContent)

# GoogleTestの取得と有効化（testsource で使うため）
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(source)
add_subdirectory(testsource)
