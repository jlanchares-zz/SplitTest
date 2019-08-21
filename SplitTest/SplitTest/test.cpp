#include "pch.h"
#include "SplitTest.h"

TEST(SplitTestCase, OneSpaceDelimiterTest) {
	std::vector<std::string> result = SplitTest::split("a b", ' ');
	EXPECT_EQ(result.size(), 2);
	EXPECT_EQ(result[0], "a");
	EXPECT_EQ(result[1], "b");
}