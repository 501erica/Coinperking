add_library(coinperking_core
    CostCalculator.cpp
    Judger.cpp
    ModeCounter.cpp
    Proxy.cpp
)

target_include_directories(coinperking_core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# 実行ファイル：main.cpp + 上記ライブラリ
add_executable(Coinperking
    main.cpp
)

target_link_libraries(Coinperking
    coinperking_core
)

# ライブラリのインストール
install(TARGETS coinperking_core
    EXPORT coinperkingTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

# 実行ファイルのインストール
install(TARGETS Coinperking
    RUNTIME DESTINATION bin
)

# ヘッダー
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)