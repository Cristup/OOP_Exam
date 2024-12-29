#include "libs.h"
#include "dataUtils.h"

int main()
{
    //===VARIABLES AND CONTAINERS===
    string filename;
    string user_selection;

    map<string, int> word_count;
    map<string, set<int>> word_locations;
    set<string> urls;

    //CREATING DIRECTORIES
    _mkdir("data");
    string command = "dir data\\*.txt /B";
    _mkdir("results");

    //===FOR USER===
    cout << "\033[" << 33 << "m" <<
        "Enter:\n 'file' - to select text file.\n 'end' - to close the program.\n" <<
        "\033[" << 97 << "m";
    cout << "Upload text files to 'OOP_Exam\\data.'\n\n";

    while (true) {
        cout << "\033[" << 33 << "m" << "Enter << " << "\033[" << 97 << "m";
        cin >> user_selection;
        transform(user_selection.begin(), user_selection.end(), user_selection.begin(), ::tolower);

        //===END===
        if (user_selection.substr(0, 3) == "end") {
            system("pause");
            return 1;
        }

        //===FILE===
        if (user_selection.substr(0, 3) == "fil") {
            cout << "\nAvailable '.txt' files:\n=======================\n";
            system(command.c_str());
            cout << "=======================\n\n";

            while (true) {
                cout << "\033[" << 33 << "m" << "Filename << " << "\033[" << 97 << "m";
                cin >> filename;

                if (filename.length() <= 4 || filename.substr(filename.length() - 4, 4) != ".txt") {
                    filename += ".txt";
                }

                std::ifstream file("data\\" + filename);
                if (!file.is_open()) {
                    std::cerr << "File with name: '" << filename << "' not found!\n";
                    file.close();
                    continue;
                }
                break;
            }

            string fn = filename.substr(0, filename.length() - 4) + "_result.txt";
            cout << "\nResults of '" << filename << "' are in results folder.\nResult file name is: '" << fn << "'.\n\n";

            read(filename, word_count, word_locations, urls);
            printData(filename, word_count, word_locations);
            printUrls(urls);

            word_count.clear();
            word_locations.clear();
            urls.clear();

        }
    }
}
