#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

#pragma region 1 завдання
//
//struct Abonent {
//    string surname;
//    string phone;
//};
//
//void readFromFile(const string& name, vector<Abonent>& abonents) {
//    ifstream file(name);
//    if (!file.is_open()) {
//        cerr << "Cannot open the file: " << name << endl;
//        return;
//    }
//
//    string line;
//    while (getline(file, line)) {
//        istringstream iss(line);
//        Abonent abonent;
//        iss >> abonent.surname >> abonent.phone;
//        abonents.push_back(abonent);
//    }
//
//    file.close();
//}
//
//void printAllAbonents(const vector<Abonent>& abonents) {
//    for (const auto& abonent : abonents) {
//        cout << abonent.surname << " " << abonent.phone << endl;
//    }
//}
//
//void printAbonent(const vector<Abonent>& abonents, const string& surname) {
//    for (const auto& abonent : abonents) {
//        if (abonent.surname == surname) {
//            cout << abonent.surname << " " << abonent.phone << endl;
//            return;
//        }
//    }
//    cout << "Abonent with surname " << surname << " not found." << endl;
//}
//
//int main() {
//    vector<Abonent> abonents;
//    readFromFile("abonents.txt", abonents);
//
//    int choice;
//    cout << "Enter 1 to print all abonents or 2 to search for a specific abonent: ";
//    cin >> choice;
//
//    if (choice == 1) {
//        printAllAbonents(abonents);
//    }
//    else if (choice == 2) {
//        string surname;
//        cout << "Enter the surname of the abonent: ";
//        cin >> surname;
//        printAbonent(abonents, surname);
//    }
//    else {
//        cout << "Invalid choice." << endl;
//    }
//
//    return 0;
//}
#pragma endregion 


#pragma region 2 завдання
//
//void copyFileLines(const string& sourceFile, const string& targetFile) {
//    ifstream inFile(sourceFile);
//    ofstream outFile(targetFile);
//
//    if (!inFile.is_open()) {
//        cerr << "Cannot open the source file: " << sourceFile << endl;
//        return;
//    }
//
//    if (!outFile.is_open()) {
//        cerr << "Cannot open the target file: " << targetFile << endl;
//        return;
//    }
//
//    string line;
//    while (getline(inFile, line)) {
//        outFile << line << endl;
//    }
//
//    inFile.close();
//    outFile.close();
//}
//
//int main() {
//    string sourceFile = "file.txt";
//    string targetFile = "result.txt";
//
//    copyFileLines(sourceFile, targetFile);
//
//    cout << "Lines copied from " << sourceFile << " to " << targetFile << " successfully." << endl;
//
//    return 0;
//}
//

#pragma endregion

#pragma region 3 завдання
//
//void reverseLinesInFile(const string& inputFilename, const string& outputFilename) {
//    ifstream inputFile(inputFilename);
//    if (!inputFile.is_open()) {
//        cerr << "Cannot open the input file: " << inputFilename << endl;
//        return;
//    }
//
//    vector<string> lines;
//    string line;
//    while (getline(inputFile, line)) {
//        lines.push_back(line);
//    }
//
//    inputFile.close();
//
//    ofstream outputFile(outputFilename);
//    if (!outputFile.is_open()) {
//        cerr << "Cannot open the output file: " << outputFilename << endl;
//        return;
//    }
//
//    for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
//        outputFile << *it << endl;
//    }
//
//    outputFile.close();
//}
//
//int main() {
//    string inputFilename = "file.txt";
//    string outputFilename = "output.txt";
//
//    reverseLinesInFile(inputFilename, outputFilename);
//
//    cout << "The lines from " << inputFilename << " have been reversed and written to " << outputFilename << "." << endl;
//
//    return 0;
//}

#pragma endregion

#pragma region 4завдання

bool containsSpace(const string& str) {
    return str.find(' ') != string::npos;
}

void addDashesAfterLastNonSpaceLine(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Cannot open the input file: " << filename << endl;
        return;
    }

    vector<string> lines;
    string line;
    int lastNonSpaceLineIndex = -1;

    while (getline(inputFile, line)) {
        lines.push_back(line);
        if (!containsSpace(line)) {
            lastNonSpaceLineIndex = lines.size() - 1;
        }
    }

    inputFile.close();

    if (lastNonSpaceLineIndex == -1) {
        lines.push_back("------------");
    }
    else {
        lines.insert(lines.begin() + lastNonSpaceLineIndex + 1, "------------");
    }

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cerr << "Cannot open the output file: " << filename << endl;
        return;
    }

    for (const auto& line : lines) {
        outputFile << line << endl;
    }

    outputFile.close();
}

int main() {
    string filename = "input.txt";
    addDashesAfterLastNonSpaceLine(filename);
    cout << "Dashes have been added to " << filename << "." << endl;
    cout<<"End";
    return 0;
}

#pragma endregion