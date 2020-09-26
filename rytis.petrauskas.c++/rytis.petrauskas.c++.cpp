

#include <iostream>
#include <experimental/filesystem>
    
namespace fs = std::experimental::filesystem;
using namespace std;


void listAlldirectories();
void setPath(string path, vector<fs::path>& parentPath);
vector<string> splitString(string line);
void returnDirectory(fs::path parentPath);
int main()
{

    vector<fs::path> parentPath;
    while (true) {

        string choice;
        cout << fs::current_path() << "\\";
        cin >> choice;
        cout << endl << choice << endl;
        int choicee;
        if (choice == "list") {
            choicee = 1;
        }
        if (choice.find("enter") != string::npos) {
            choicee = 2;
        }
        if (choice == "leave") {
            choicee = 3;
        }
        if (choice == "stop") {
            exit(1);
        }
        switch (choicee) {
        case 1: {
            listAlldirectories();
            break;
        }
        case 2: {
            string path;
            cin >> path;
            setPath(path, parentPath);
            break;
        }
        case 3: {
            returnDirectory(parentPath[parentPath.size() - 1]);
            parentPath.erase(parentPath.begin() + parentPath.size() - 1);
            break;
        }
        }
        
    }
    
}   

vector<string> splitString(string line) {
    string word = "";
    vector<string> splitLine;
    for (auto x : line)
    {
        if (x == ' ')
        {
            splitLine.push_back(word);
            word = "";
        }
        else
        {
            word = word + x;
        }
    }
    splitLine.push_back(word);
    return splitLine;
}


void listAlldirectories() {
 
    for (auto& p : fs::directory_iterator(fs::current_path())) {
        if (p.path().filename().string().find(".") != string::npos) {
            std::cout << p.path().filename() << "...................." << fs::file_size(p.path().filename()) << "\n";
            
        }
        else {
            std::cout << p.path().filename() << "...................." << "directory\n";
        }
    }
}

void setPath(string path, vector<fs::path>& parentPath) {
    for (auto& p : fs::directory_iterator(fs::current_path())) {
        if (p.path().filename().string() == path) {
            fs::current_path(p);
            parentPath.push_back(p.path().parent_path());
        }

    }
}

void returnDirectory(fs::path parentPath) {
     fs::current_path(parentPath);
}