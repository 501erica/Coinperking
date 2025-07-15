#include "pch.h"
#include "Judger.h"
#include "Mode.h"
#include "Date.h"

TEST(JudgerTest, spcialday_case1) {
	//2021年12月31日
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
TEST(JudgerTest, spcialday_case2) {
	//2022年1月1日
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
TEST(JudgerTest, spcialday_case3) {
	//2022年1月2日
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
TEST(JudgerTest, spcialday_case4) {
	//2022年1月3日
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
TEST(JudgerTest, spcialday_case5) {
	//2022年8月13日
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
TEST(JudgerTest, spcialday_case6) {
	//2022年8月14日
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
TEST(JudgerTest, spcialday_case7) {
	//2022年8月15日
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
TEST(JudgerTest, spcialday_case8_saturday) {
	//2022年1月8日
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
TEST(JudgerTest, spcialday_case9_Sun) {
	//2022年1月9日
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
	testdate.information.tm_min =59;
	EXPECT_EQ(testJudger.judge(testdate), CalculateMode::SPECIAL_DAY);
}
TEST(JudgerTest, night_case10_Mon) {
	//2022年1月10日
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
	testdate.information.tm_hour =21;
	testdate.information.tm_min = 59;
	EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NOON);
	testdate.information.tm_hour = 22;
	testdate.information.tm_min = 00;
	EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
	testdate.information.tm_hour = 23;
	testdate.information.tm_min = 59;
	EXPECT_EQ(testJudger.judge(testdate), CalculateMode::NIGHT);
}
TEST(JudgerTest, night_case10_Tsu) {
	//2022年1月11日
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
TEST(JudgerTest, night_case10_Wed) {
	//2022年1月12日
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
TEST(JudgerTest, night_case10_Thr) {
	//2022年1月13日
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
TEST(JudgerTest, night_case10_Fri) {
	//2022年1月14日
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

TEST(JudgerTest, over72h) {
	//over 72h
	Judger testJudger;
	std::string testdate1 = "2022/01/20-12:00";
	std::string testdate2 = "2022/01/23-12:01";
	EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, BiggerIntime) {
	// Intime > Outtime
	Judger testJudger;
	std::string testdate1 = "2022/01/20-15:00";
	std::string testdate2 = "2022/01/20-12:00";
	EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, sametime) {
	// same time error
	Judger testJudger;
	std::string testdate1 = "2022/01/20-12:00";
	std::string testdate2 = "2022/01/20-12:00";
	EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}
TEST(JudgerTest, pasttime) {
	//past time
	Judger testJudger;
	std::string testdate1 = "2022/01/01-12:00";
	std::string testdate2 = "2022/01/01-13:00";
	EXPECT_FALSE(testJudger.judge(testdate1, testdate2));
}

