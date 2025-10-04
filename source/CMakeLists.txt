# 可搬な標準ディレクトリ（bin/lib/include 等）
include(GNUInstallDirs)

# コアライブラリ
add_library(coinperking_core STATIC
    CostCalculator.cpp
    Judger.cpp
    ModeCounter.cpp
    Proxy.cpp
)

# “ビルド時”と“インストール後”の見え方を分けて宣言
target_include_directories(coinperking_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}> 
)

# 実行ファイル：main.cpp + 上記ライブラリ
add_executable(Coinperking main.cpp)
target_link_libraries(Coinperking coinperking_core)

# ヘッダー
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include)
#ライブラリのインストール
install(TARGETS coinperking_core
    EXPORT coinperkingTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

 # 実行ファイルのインストール
install(TARGETS Coinperking
    RUNTIME DESTINATION bin
)
