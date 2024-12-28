#include "dataUtils.h"

void read(const string& filename, map<string, int>& word_count, map<string, set<int>>& word_location, set<string>& urls){
	int lineNumber = 0;
	string word;
	string line_input;
	stringstream buf;
	regex urlPattern(R"((https?://[^\s]+|www\.[^\s]+|[a-zA-Z0-9-]+\.[a-zA-Z]{2,})(/[^\s]*)?)");

	ifstream file("data\\" + filename);
	buf << file.rdbuf();
	file.close();

	while (getline(buf, line_input)) {
		stringstream line(line_input);
		lineNumber++;
		string url;

		smatch match;
		string::const_iterator searchStart(line_input.cbegin());
		while (regex_search(searchStart, line_input.cend(), match, urlPattern)) {
			url = match.str();
			if (url.back() == ',') { url.pop_back(); }
			urls.insert(url);
			searchStart = match.suffix().first;
		}

		while (line >> word) {

			smatch match;
			if (!regex_match(word, match, urlPattern)) {
				word = clean(word);

				if (!word.empty()) {
					word_count[word]++;
					word_location[word].insert(lineNumber);
				}
			}

		}
	}

}

void printData(const string& filename, const map<string, int>& word_count, const map<string, set<int>>& word_location){
	string name = filename.substr(0, filename.length() - 4);
	name += "_result.txt";
	ofstream file_output("results\\" + name);

	file_output << "      word      |count|          locations\n";
	file_output << "----------------+-----+----------------------------------\n";
	for (const auto& rec : word_count) {
		if (rec.second > 1) {
			file_output << setw(16) << left << rec.first << "| " << setw(5) << left << rec.second << "|   ";
			for (const auto& a : word_location.at(rec.first)) {
				file_output << a << " ";
			}
			file_output << endl;
		}
	}
	file_output.close();

}

void printUrls(const set<string>& urls) {
	int id = 0;
	cout << " ID |                URL\n";
	cout << "----+-------------------------------------\n";
	for (const string& url : urls) {
		id++;
		cout << setw(3) << left << id <<
			" | " << url << endl;
	}
}


