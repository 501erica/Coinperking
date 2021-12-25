#include  <gtest/gtest.h>
// gtest.lib ‚ðƒŠƒ“ƒN
//#include "../source/Proxy.h"


 int Factorial(int n)
{
    if( n <= 1 ) return 1;
    return n * Factorial(n-1);
}

// test “à—e
TEST(Foo, Factorial)
{
    ASSERT_EQ(1, Factorial(1));
    ASSERT_EQ(2, Factorial(2));
    ASSERT_EQ(6, Factorial(3));
    ASSERT_EQ(40320, Factorial(8));
}

//TEST(AddTest, Judger){
//    Judger* judger = Judger::getInstance();
//    EXPECT_EQ(true, judger->judge("2021/12/23.12:00","2021/12/23.13:00"));
//}