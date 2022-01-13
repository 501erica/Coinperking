#include "pch.h"
#include "../Perking/Judger.h"
#include "../Perking/Mode.h"
#include "../Perking/ModeCounter.h"

TEST(evalDateTest, inputsmall) {
	ModeCounter ModeCountTest;
	//2021年12月31日
	struct date testdate1;
	testdate1.information.tm_year = 2021 - 1900;
	testdate1.information.tm_mon = 12 - 1;
	testdate1.information.tm_mday = 31;
	testdate1.information.tm_hour = 0;
	testdate1.information.tm_min = 0;
	testdate1.information.tm_isdst = -1;
	//2022年1月1日
	struct date testdate2;
	testdate2.information.tm_year = 2022 - 1900;
	testdate2.information.tm_mon = 1 - 1;
	testdate2.information.tm_mday = 1;
	testdate2.information.tm_hour = 0;
	testdate2.information.tm_min = 0;
	testdate2.information.tm_isdst = -1;
	EXPECT_TRUE(ModeCountTest.evalDate(testdate1, testdate2));
}
TEST(evalDateTest, inputbig) {
	ModeCounter ModeCountTest;
	//2022年1月1日
	struct date testdate1;
	testdate1.information.tm_year = 2022 - 1900;
	testdate1.information.tm_mon = 1 - 1;
	testdate1.information.tm_mday = 1;
	testdate1.information.tm_hour = 0;
	testdate1.information.tm_min = 0;
	testdate1.information.tm_isdst = -1;
	//2021年12月31日
	struct date testdate2;
	testdate2.information.tm_year = 2021 - 1900;
	testdate2.information.tm_mon = 12 - 1;
	testdate2.information.tm_mday = 31;
	testdate2.information.tm_hour = 0;
	testdate2.information.tm_min = 0;
	testdate2.information.tm_isdst = -1;
	EXPECT_FALSE(ModeCountTest.evalDate(testdate1, testdate2));
}
TEST(evalBorderDateTest, nextNoon) {
	//2021年12月30日 0:00
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 0;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::NIGHT).information.tm_hour, 7);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::NIGHT).information.tm_min, 00);

	//2021年12月30日 6:59
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 6;
	testdate.information.tm_min = 59;
	testdate.information.tm_isdst = -1;
	ModeCounter ModeCountTest2 = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest2.evalBorderDate(CalculateMode::NIGHT).information.tm_hour, 7);
	EXPECT_EQ(ModeCountTest2.evalBorderDate(CalculateMode::NIGHT).information.tm_min, 00);
}
TEST(evalBorderDateTest, nextNight) {
	//2021年12月30日 7:00
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 7;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::NOON).information.tm_hour, 22);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::NOON).information.tm_min, 00);

	//2021年12月30日 21:59
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 21;
	testdate.information.tm_min = 59;
	testdate.information.tm_isdst = -1;
	ModeCounter ModeCountTest2 = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest2.evalBorderDate(CalculateMode::NOON).information.tm_hour, 22);
	EXPECT_EQ(ModeCountTest2.evalBorderDate(CalculateMode::NOON).information.tm_min, 00);
}
TEST(evalBorderDateTest, nextSpecialDay_not_sunday_saturday) {
	//2021年12月30日 22:00
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 22;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mday, 31);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_hour, 0);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_min, 00);

	//2021年12月30日 23:59
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 23;
	testdate.information.tm_min = 59;
	testdate.information.tm_isdst = -1;
	ModeCounter ModeCountTest2 = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mday, 31);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_hour,  0);
	EXPECT_EQ(ModeCountTest2.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_min, 00);
}
TEST(evalBorderDateTest, nextSpecialDay_Friday_to_saturday) {
	//2022年1月7日 22:00
	struct date testdate;
	testdate.information.tm_year = 2022 - 1900;
	testdate.information.tm_mon = 1 - 1;
	testdate.information.tm_mday = 7;
	testdate.information.tm_hour = 22;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mday, 8);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_hour, 0);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_min, 00);
}
TEST(evalBorderDateTest, nextSpecialday_20220101) {
	//2021年12月31日 7:00
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 31;
	testdate.information.tm_hour = 7;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_year, 2022 - 1900);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mon, 1-1);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mday, 1);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_hour, 0);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_min, 00);
}
TEST(evalBorderDateTest, nextNight_20220104) {
	//2022年1月3日 7:00
	struct date testdate;
	testdate.information.tm_year = 2022 - 1900;
	testdate.information.tm_mon = 1 - 1;
	testdate.information.tm_mday = 3;
	testdate.information.tm_hour = 7;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日にしてるけど意味ない（コンストラクタの引数で必要）
	struct date dummydate;
	dummydate.information.tm_year = 2021 - 1900;
	dummydate.information.tm_mon = 12 - 1;
	dummydate.information.tm_mday = 31;
	dummydate.information.tm_hour = 0;
	dummydate.information.tm_min = 0;
	dummydate.information.tm_isdst = -1;
	ModeCounter ModeCountTest = ModeCounter(testdate, dummydate);

	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_year, 2022 - 1900);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mon, 1 - 1);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_mday, 4);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_hour, 0);
	EXPECT_EQ(ModeCountTest.evalBorderDate(CalculateMode::SPECIAL_DAY).information.tm_min, 00);
}
TEST(ModeCount, case1) {
	//2021年12月30日 7:00
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 30;
	testdate.information.tm_hour = 7;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;

	//2021年12月31日 23:00
	struct date enddate;
	enddate.information.tm_year = 2021 - 1900;
	enddate.information.tm_mon = 12 - 1;
	enddate.information.tm_mday = 31;
	enddate.information.tm_hour = 23;
	enddate.information.tm_min = 0;
	enddate.information.tm_isdst = -1;

	ModeCounter ModeCountTest = ModeCounter(testdate, enddate);
	std::vector<CostCalculator*> testvector;

	ModeCountTest.ModeCount(testvector);

	EXPECT_EQ(testvector.size(), 3);

}