# Coinperking

Coinperking は、CMake で構築された C++ プロジェクトです。  
コアライブラリ (`coinperking_core`) と実行ファイル (`Coinperking`) を含みます。

## 必要環境

- CMake 3.15 以上
- Ninja（推奨。なければ make でも可）
- C++11 対応コンパイラ (g++, clang++, MSVC など)
- (テスト実行する場合) GoogleTest

## ビルド・テスト・パッケージ化手順


```bash
cmake -S . -B build -G Ninja -DCMAKE_INSTALL_PREFIX=./install
cmake --build build
ctest --test-dir build
cmake --install build
cpack --config build/CPackConfig.cmake
