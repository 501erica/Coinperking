#include "pch.h"
#include "../Perking/CostCalculator.h"
#include "../Perking/Mode.h"
#include "../Perking/Date.h"

TEST(CostCalculate, Noon) {
	CostCalculator_Noon testclass = CostCalculator_Noon(200);
	EXPECT_EQ(testclass.CostCalculate(), 900);

	CostCalculator_Noon testclass2 = CostCalculator_Noon(100);
	EXPECT_EQ(testclass2.CostCalculate(), 500);
}

TEST(CostCalculate, Night) {
	CostCalculator_Night testclass = CostCalculator_Night(181);
	EXPECT_EQ(testclass.CostCalculate(), 300);

	CostCalculator_Night testclass2 = CostCalculator_Night(120);
	EXPECT_EQ(testclass2.CostCalculate(), 200);

	CostCalculator_Night testclass3 = CostCalculator_Night(180);
	EXPECT_EQ(testclass.CostCalculate(), 300);
}

TEST(CostCalculate, SpecialDay) {
	CostCalculator_SpecialDay testclass = CostCalculator_SpecialDay(200);
	EXPECT_EQ(testclass.CostCalculate(), 2000);

	CostCalculator_SpecialDay testclass2 = CostCalculator_SpecialDay(201);
	EXPECT_EQ(testclass2.CostCalculate(), 2000);

	CostCalculator_SpecialDay testclass3 = CostCalculator_SpecialDay(19);
	EXPECT_EQ(testclass3.CostCalculate(), 200);

	CostCalculator_SpecialDay testclass4 = CostCalculator_SpecialDay(20);
	EXPECT_EQ(testclass4.CostCalculate(), 200);

	CostCalculator_SpecialDay testclass5 = CostCalculator_SpecialDay(21);
	EXPECT_EQ(testclass5.CostCalculate(), 400);
}