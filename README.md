## Description
This program scans and analyzes text files. It finds all the unique words, counts how 
many times each word appears, and notes where they are located in the text. It also identifies
 any URL addresses present in the files.

## Instruction

1. To begin, run the program and type `file` to access the file selection feature.
2. You will see a list of available .txt files. From this list, enter the exact name
 of the file you wish to scan for data analysis (IN case you forget, **.txt** will be added by the program).   
<img src="images/list.png" alt="URL's" style="height: 180px;"/>

3. If you would like to scan another file, simply enter its name again. If you wish to exit the
 program, type `end` to terminate the process.

Make sure to place all your data files in the designated **data** folder to ensure the program can
 locate them. Once the scanning is complete, the results will be saved in the **results** folder. 
 If you're using the program for the first time, you might need to create these folders yourself.
  Alternatively, you can just launch the program, and it will automatically create both folders for you.

The program will show the results in a simple table format:

| word | count | location |
|--|--|--|
about         | 2    |  47 55 
active          | 2    |  46 48 
advertisers      | 2    |  87 89 
became       | 3    |  20 23 87 
been         | 2    |  62 70 

<img src="images/url.png" alt="URL's" style="height: 200px;"/>

## About the code

The program stores the results from each scan in specific containers.
 After printing the results, it clears these containers to prepare for the next scan.

 ```c++
map<string, int> word_count;
map<string, set<int>> word_locations;
set<string> urls;
 ```

The text is analyzed line-by-line. Before scanning each word in the line,
 we first check whether the line contains any URLs. If URLs are detected,
  they are processed using a regular expression. 

```c++
regex urlPattern(R"((https?://[^\s]+|www\.[^\s]+|[a-zA-Z0-9-]+\.[a-zA-Z]{2,})(/[^\s]*)?)");
smatch match;
string::const_iterator searchStart(line_input.cbegin());
while (regex_search(searchStart, line_input.cend(), match, urlPattern)) {
	url = match.str();
	if (url.back() == ',') { url.pop_back(); }
	urls.insert(url);
	searchStart = match.suffix().first;
}
 ```

After identifying any URLs, we examine each word in the line. If a word
 (defined as symbols between whitespace) is not a URL, it is then cleaned
  by removing numbers and punctuation. Finally, all letters are converted
   to lowercase for uniformity.

 ```c++
string clean(const string& word)
{
	string cleanWord;
	for (char c : word) {
		if (!ispunct(c) && !isdigit(c)) {
			cleanWord += tolower(c);
		}
	}
	return cleanWord;
}
 ```