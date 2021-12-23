#include  <gtest/gtest.h>
#include "../source/Proxy.h"

TEST(AddTest, onePlusTwoGivesThree){
    Judger* judger = Judger::getInstance();
    EXPECT_EQ(true, judger->judge("2021/12/23.12:00","2021/12/23.13:00"));
}