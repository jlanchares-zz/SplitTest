#include "pch.h"
#include "SplitTest.h"

std::vector<std::string> SplitTest::split(std::string text, char delimiter)
{
	std::vector<std::string> result;
	int len = text.length();
	std::string word;
	for (int i = 0; i < len; i++) {
		char next = text.at(i);
		if (next != delimiter) {
			word.push_back(next);
		}
		else {
			if (!word.empty()) {
				result.push_back(word);
				word.clear();
			}
		}
	}
	if (!word.empty()) {
		result.push_back(word); // Last word
	}
	return result;
}
