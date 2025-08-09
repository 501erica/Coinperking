#include "Judger.h"
#include "Date.h"
#include "Mode.h"
#include "pch.h"

TEST(JudgerTest, spcialday_case1)
{
    // 2021�N12��31��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2021 - 1900;
    testdate.information.tm_mon = 12 - 1;
    testdate.information.tm_mday = 31;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case2)
{
    // 2022�N1��1��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 1;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case3)
{
    // 2022�N1��2��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 2;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case4)
{
    // 2022�N1��3��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 3;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case5)
{
    // 2022�N8��13��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 8 - 1;
    testdate.information.tm_mday = 13;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case6)
{
    // 2022�N8��14��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 8 - 1;
    testdate.information.tm_mday = 14;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case7)
{
    // 2022�N8��15��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 8 - 1;
    testdate.information.tm_mday = 15;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case8_saturday)
{
    // 2022�N1��8��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 8;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, spcialday_case9_Sun)
{
    // 2022�N1��9��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 9;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, night_case10_Mon)
{
    // 2022�N1��10��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 10;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 6;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 7;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 21;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 22;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}
TEST(JudgerTest, night_case10_Tsu)
{
    // 2022�N1��11��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 11;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 6;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 7;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 21;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 22;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}
TEST(JudgerTest, night_case10_Wed)
{
    // 2022�N1��12��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 12;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 6;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 7;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 21;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 22;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}
TEST(JudgerTest, night_case10_Thr)
{
    // 2022�N1��13��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 13;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 6;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 7;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 21;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 22;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}
TEST(JudgerTest, night_case10_Fri)
{
    // 2022�N1��14��
    struct date testdate;
    Judger testJudger;
    testdate.information.tm_year = 2022 - 1900;
    testdate.information.tm_mon = 1 - 1;
    testdate.information.tm_mday = 14;
    testdate.information.tm_hour = 0;
    testdate.information.tm_min = 0;
    testdate.information.tm_isdst = -1;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 6;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 7;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 21;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
    testdate.information.tm_hour = 22;
    testdate.information.tm_min = 00;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
    testdate.information.tm_hour = 23;
    testdate.information.tm_min = 59;
    EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}

TEST(JudgerTest, over72h)
{
    // over 72h
    Judger testJudger;
    std::string testdate1 = "2022/01/20-12:00";
    std::string testdate2 = "2022/01/23-12:01";
    EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, BiggerIntime)
{
    // Intime > Outtime
    Judger testJudger;
    std::string testdate1 = "2022/01/20-15:00";
    std::string testdate2 = "2022/01/20-12:00";
    EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, sametime)
{
    // same time error
    Judger testJudger;
    std::string testdate1 = "2022/01/20-12:00";
    std::string testdate2 = "2022/01/20-12:00";
    EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, pasttime)
{
    // past time
    Judger testJudger;
    std::string testdate1 = "2022/01/01-12:00";
    std::string testdate2 = "2022/01/01-13:00";
    EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
