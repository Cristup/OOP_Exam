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
            system(command.c_str());
            cout << "\033[" << 33 << "m" << "Filename << " << "\033[" << 97 << "m";
            cin >> filename;

            std::ifstream file("data\\" + filename);
            if (!file.is_open()) {
                std::cerr << "File not found!\n";
                file.close();
                continue;
            }
        }
    }
}
