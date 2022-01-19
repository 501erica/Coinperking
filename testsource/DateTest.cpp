#include "pch.h"
#include "../Perking/Date.h"

TEST(DateTest, day_of_week) {
//2021/12/31
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 31;
	testdate.information.tm_hour = 0;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;
	EXPECT_EQ(testdate.day_of_week(), 5);
	EXPECT_EQ(testdate.advance(1).day_of_week(), 6);
	EXPECT_EQ(testdate.advance(2).day_of_week(), 0);
	EXPECT_EQ(testdate.advance(3).day_of_week(), 1);
	EXPECT_EQ(testdate.advance(4).day_of_week(), 2);
	EXPECT_EQ(testdate.advance(5).day_of_week(), 3);
	EXPECT_EQ(testdate.advance(6).day_of_week(), 4);
}

TEST(DateTest, advance) {
	//2021/12/31
	struct date testdate;
	testdate.information.tm_year = 2021 - 1900;
	testdate.information.tm_mon = 12 - 1;
	testdate.information.tm_mday = 31;
	testdate.information.tm_hour = 0;
	testdate.information.tm_min = 0;
	testdate.information.tm_isdst = -1;
	date advanceTestDate = testdate.advance(1);
	EXPECT_EQ(advanceTestDate.information.tm_year, 2022 - 1900);
	EXPECT_EQ(advanceTestDate.information.tm_mon, 1 - 1);
	EXPECT_EQ(advanceTestDate.information.tm_mday, 1);
	EXPECT_EQ(advanceTestDate.information.tm_min, 0);
	EXPECT_EQ(advanceTestDate.information.tm_isdst, -1);




}
