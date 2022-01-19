#include "pch.h"
#include "../Perking/Judger.h"
#include "../Perking/Mode.h"
#include "../Perking/Date.h"
#include "../Perking/Proxy.h"

TEST(ProxyTest, ConstracterTest) {
	std::string Indate = "2022/01/22-11:00";
	std::string Outdate = "2022/01/22-11:00";
	EXPECT_NO_THROW(Proxy ProxyTest = Proxy::Proxy(Indate, Outdate));
}
TEST(ProxyTest, ShowCostTest) {
	std::string Indate = "2022/01/22-11:00";
	std::string Outdate = "2022/01/22-11:00";
	Proxy ProxyTest = Proxy::Proxy(Indate, Outdate);
	EXPECT_NO_THROW(ProxyTest.showCost());
}
