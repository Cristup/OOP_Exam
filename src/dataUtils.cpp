#include "dataUtils.h"

void read(const string& filename, map<string, int>& word_count, map<string, set<int>>& word_location, set<string>& urls)
{
	int lineNumber = 0;
	string word;
	string line_input;
	stringstream buf;
	regex urlPattern(R"((https?://[^\s]+|www\.[^\s]+|[a-zA-Z0-9-]+\.[a-zA-Z]{2,}(/[^\s]*)?))");

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
	string name = filename.substr(0, filename.length() - 4);
	name += "_result.txt";
	ofstream file_output("results\\" + name);

	for (const auto& rec : word_count) {
		if (rec.second > 1) {
			file_output << setw(15) << rec.first << setw(5) << rec.second << setw(30);
			for (const auto& a : word_location.at(rec.first)) {
				file_output << a << ", ";
			}
			file_output << endl;
		}
	}
	file_output.close();

}
