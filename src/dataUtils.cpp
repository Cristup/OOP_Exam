#include "dataUtils.h"

void read(const string& filename, map<string, int>& word_count, map<string, set<int>>& word_location, set<string>& urls)
{
	int lineNumber = 0;
	string word;
	string line_input;
	stringstream buf;
	regex urlPattern("(https?://|www\\.|[a-zA-Z0-9-]+\\.[a-zA-Z]{2,})(/[^\\s]*)?");

	ifstream file("data\\" + filename);
	buf << file.rdbuf();
	file.close();

	while (getline(buf, line_input)) {
		stringstream line(line_input);
		lineNumber++;
		while (line >> word) {

			smatch match;
			if (regex_match(word, match, urlPattern)) {
				urls.insert(word);
			}
			else {
				word = clean(word);

				if (!word.empty()) {
					word_count[word]++;
					word_location[word].insert(lineNumber);
				}
			}

		}

	}
}

void printData(const string& filename, const map<string, int>& word_count, const map<string, set<int>>& word_location)
{
	for (const auto& rec : word_count) {
		if (rec.second > 1) {
			cout << rec.first << ": " << rec.second << endl;
		}
	}
}
