#include "pch.h"
#include "Judger.h"
#include "Mode.h"
#include "ModeCounter.h"

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
TEST(ExtraCalcUnitTest, FirstFlagFalse) {
	//2022年1月26日 21:55-2022年1月26日 23:00
	bool FirstFlag = false;
	struct date testdate_input;
	testdate_input.information.tm_year = 2022 - 1900;
	testdate_input.information.tm_mon = 1 - 1;
	testdate_input.information.tm_mday = 26;
	testdate_input.information.tm_hour = 21;
	testdate_input.information.tm_min = 55;
	testdate_input.information.tm_isdst = -1;

	struct date testdate_output;
	testdate_output.information.tm_year = 2022 - 1900;
	testdate_output.information.tm_mon = 1 - 1;
	testdate_output.information.tm_mday = 26;
	testdate_output.information.tm_hour = 23;
	testdate_output.information.tm_min = 00;
	testdate_output.information.tm_isdst = -1;

	ModeCounter ModeCountTest = ModeCounter(testdate_input, testdate_output);

	EXPECT_FALSE(ModeCountTest.ExtraCalc(testdate_input,testdate_output, FirstFlag));
	
}


TEST(ExtraCalcUnitTest, FirstFlagTrue_NOON) {
	//2022年1月26日 21:55-2022年1月26日 23:00
	bool FirstFlag2 = true;
	struct date testdate_input2;
	testdate_input2.information.tm_year = 2022 - 1900;
	testdate_input2.information.tm_mon = 1 - 1;
	testdate_input2.information.tm_mday = 26;
	testdate_input2.information.tm_hour = 21;
	testdate_input2.information.tm_min = 55;
	testdate_input2.information.tm_isdst = -1;

	struct date testdate_output2;
	testdate_output2.information.tm_year = 2022 - 1900;
	testdate_output2.information.tm_mon = 1 - 1;
	testdate_output2.information.tm_mday = 26;
	testdate_output2.information.tm_hour = 22;
	testdate_output2.information.tm_min = 00;
	testdate_output2.information.tm_isdst = -1;

	ModeCounter ModeCountTest = ModeCounter(testdate_input2, testdate_output2);
	EXPECT_TRUE(ModeCountTest.ExtraCalc(testdate_input2, testdate_output2, FirstFlag2));
	EXPECT_EQ(testdate_output2.information.tm_hour,22);
	EXPECT_EQ(testdate_output2.information.tm_min,15);

}
TEST(ExtraCalcUnitTest, FirstFlagTrue_NIGHT) {
	//2022年1月26日 06:55-2022年1月26日 7:00
	bool FirstFlag2 = true;
	struct date testdate_input2;
	testdate_input2.information.tm_year = 2022 - 1900;
	testdate_input2.information.tm_mon = 1 - 1;
	testdate_input2.information.tm_mday = 26;
	testdate_input2.information.tm_hour = 06;
	testdate_input2.information.tm_min = 55;
	testdate_input2.information.tm_isdst = -1;

	struct date testdate_output2;
	testdate_output2.information.tm_year = 2022 - 1900;
	testdate_output2.information.tm_mon = 1 - 1;
	testdate_output2.information.tm_mday = 26;
	testdate_output2.information.tm_hour = 07;
	testdate_output2.information.tm_min = 00;
	testdate_output2.information.tm_isdst = -1;

	ModeCounter ModeCountTest = ModeCounter(testdate_input2, testdate_output2);
	EXPECT_TRUE(ModeCountTest.ExtraCalc(testdate_input2, testdate_output2, FirstFlag2));
	EXPECT_EQ(testdate_output2.information.tm_hour, 7);
	EXPECT_EQ(testdate_output2.information.tm_min, 55);

}
TEST(ExtraCalcUnitTest, FirstFlagTrue_SPECIAL) {
	//2022年1月23日 23:55-2022年1月24日 0:00
	bool FirstFlag2 = true;
	struct date testdate_input2;
	testdate_input2.information.tm_year = 2022 - 1900;
	testdate_input2.information.tm_mon = 1 - 1;
	testdate_input2.information.tm_mday = 23;
	testdate_input2.information.tm_hour = 23;
	testdate_input2.information.tm_min = 55;
	testdate_input2.information.tm_isdst = -1;

	struct date testdate_output2;
	testdate_output2.information.tm_year = 2022 - 1900;
	testdate_output2.information.tm_mon = 1 - 1;
	testdate_output2.information.tm_mday = 24;
	testdate_output2.information.tm_hour = 00;
	testdate_output2.information.tm_min = 00;
	testdate_output2.information.tm_isdst = -1;

	ModeCounter ModeCountTest = ModeCounter(testdate_input2, testdate_output2);
	EXPECT_TRUE(ModeCountTest.ExtraCalc(testdate_input2, testdate_output2, FirstFlag2));
	EXPECT_EQ(testdate_output2.information.tm_hour, 0);
	EXPECT_EQ(testdate_output2.information.tm_min, 15);

}

