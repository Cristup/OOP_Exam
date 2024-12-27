#include "util.h"

string clean(const string& word)
{
	string cleanWord;
	for (char c : word) {
		if (!ispunct(c)) {
			cleanWord += c;
		}
	}
	return cleanWord;
}
