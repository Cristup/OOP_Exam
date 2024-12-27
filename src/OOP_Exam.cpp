#include "libs.h"
#include "dataUtils.h"

int main()
{
    //===VARIABLES AND CONTAINERS===
    string file_name;
    string user_selection;

    map<string, int> word_count;
    map<string, set<int>> word_locations;
    set<string> urls;

    //===FOR USER===
    cout << "\033[" << 33 << "m" <<
        "Enter:\n 'file' - to select text file.\n 'end' - to close the program.\n\n" <<
        "\033[" << 97 << "m";

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
        if (user_selection.substr(0, 3) == "file") {
            
        }
    }
}
