#include "pch.h"
#include "SplitTest.h"

std::vector<std::string> SplitTest::split(std::string text, char delimiter)
{
	std::string textFromChar{ delimiter };
	return split(text, textFromChar);
}

std::vector<std::string> SplitTest::split(std::string text, std::string delimiter)
{
	std::vector<std::string> result;
	int len = text.length();
	std::string word;
	for (int i = 0; i < len; i++) {
		std::string possibleDelimiter{ text.substr(i, delimiter.length())};
		char next = text.at(i);
		if (possibleDelimiter != delimiter) {
			word.push_back(next);
		}
		else {
			if (!word.empty()) {
				result.push_back(word);
				word.clear();
			}
			i += delimiter.length() - 1;
		}
	}
	if (!word.empty()) {
		result.push_back(word); // Last word
	}
	return result;
}
