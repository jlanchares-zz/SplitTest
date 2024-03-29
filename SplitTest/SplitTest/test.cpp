#include "pch.h"
#include "SplitTest.h"

TEST(SplitTestCase, OneSpaceDelimiterTest) {
	std::vector<std::string> result = SplitTest::split("a b", ' ');
	EXPECT_EQ(result.size(), 2);
	EXPECT_EQ(result[0], "a");
	EXPECT_EQ(result[1], "b");
}

TEST(SplitTestCase, TwoSpaceDelimiterTest) {
	std::vector<std::string> result = SplitTest::split("a b c", ' ');
	EXPECT_EQ(result.size(), 3);
	EXPECT_EQ(result[0], "a");
	EXPECT_EQ(result[1], "b");
	EXPECT_EQ(result[2], "c");
}

TEST(SplitTestCase, TwoCommaDelimiterTest) {
	std::vector<std::string> result = SplitTest::split("a,b,c", ',');
	EXPECT_EQ(result.size(), 3);
	EXPECT_EQ(result[0], "a");
	EXPECT_EQ(result[1], "b");
	EXPECT_EQ(result[2], "c");
}

TEST(SplitTestCase, TwoCommaDelimiterNotExpectedTest) {
	std::vector<std::string> result = SplitTest::split("a b c", ',');
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a b c");
}

TEST(SplitTestCase, EmptyStringTest) {
	std::vector<std::string> result = SplitTest::split("", ',');
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, OneDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",", ',');
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, MultipleDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",,,,,", ',');
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, CornerCaseLeftDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split("a,", ',');
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a");
}

TEST(SplitTestCase, CornerCaseRighttDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",a", ',');
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a");
}

TEST(SplitTestCase, StringtDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split("abcbd", "bc");
	EXPECT_EQ(result.size(), 2);
	EXPECT_EQ(result[0], "a");
	EXPECT_EQ(result[1], "bd");
}

TEST(SplitTestCase, StringtDelimiterEmptyStringTest) {
	std::vector<std::string> result = SplitTest::split("", ",");
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, StringtDelimiterOneDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",", ",");
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, StringtDelimiterMultipleDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",,,,,", ",");
	EXPECT_EQ(result.size(), 0);
}

TEST(SplitTestCase, StringtDelimiterCornerCaseLeftDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split("a,", ",");
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a");
}

TEST(SplitTestCase, StringtDelimiterCornerCaseRighttDelimiterAloneTest) {
	std::vector<std::string> result = SplitTest::split(",a", ",");
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a");
}

TEST(SplitTestCase, StringtDelimiterCornerCaseRighttDelimiterSeparationTest) {
	std::vector<std::string> result = SplitTest::split("b,a,,c,,", ",,");
	EXPECT_EQ(result.size(), 2);
	EXPECT_EQ(result[0], "b,a");
	EXPECT_EQ(result[1], "c");
}

TEST(SplitTestCase, StringtDelimiterCornerCaseRighttDelimiterAsFullTextTest) {
	std::vector<std::string> result = SplitTest::split(",,,,a", ",,,,");
	EXPECT_EQ(result.size(), 1);
	EXPECT_EQ(result[0], "a");
}