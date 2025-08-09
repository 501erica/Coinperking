include(GoogleTest)

add_executable(CoinperkingTests
    CostCalculator.cpp  
    DateTest.cpp  
    JudgerTest.cpp  
    ModeCounterTest.cpp  
    ProxyTestcpp.cpp
)

target_link_libraries(CoinperkingTests
    gtest
    gtest_main
    coinperking_core
)

target_include_directories(CoinperkingTests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/source/include
)

gtest_discover_tests(CoinperkingTests)
