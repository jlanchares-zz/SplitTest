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
	for (int nextCharPos = 0; nextCharPos < len; ++nextCharPos) {
		std::string possibleDelimiter{ text.substr(nextCharPos, delimiter.length()) };
		char nextChar = text.at(nextCharPos);
		if (possibleDelimiter != delimiter) {
			word.push_back(nextChar);
		}
		else {
			if (!word.empty()) {
				result.push_back(word);
				word.clear();
			}
			nextCharPos += delimiter.length() - 1;
		}
	}
	if (!word.empty()) {
		result.push_back(word); // Last word
	}
	return result;
}
