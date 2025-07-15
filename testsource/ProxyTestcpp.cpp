#include "pch.h"
#include "Judger.h"
#include "Mode.h"
#include "Date.h"
#include "Proxy.h"

TEST(ProxyTest, ConstracterTest) {
	std::string Indate = "2022/01/22-11:00";
	std::string Outdate = "2022/01/22-11:00";
	EXPECT_NO_THROW(Proxy ProxyTest = Proxy(Indate, Outdate));
}
TEST(ProxyTest, ShowCostTest) {
	std::string Indate = "2022/01/22-11:00";
	std::string Outdate = "2022/01/22-11:00";
	Proxy ProxyTest = Proxy(Indate, Outdate);
	EXPECT_NO_THROW(ProxyTest.showCost());
}
