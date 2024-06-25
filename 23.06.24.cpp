#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

void copyFileLines(const string& sourceFile, const string& targetFile) {
    ifstream inFile(sourceFile);
    ofstream outFile(targetFile);

    if (!inFile.is_open()) {
        cerr << "Cannot open the source file: " << sourceFile << endl;
        return;
    }

    if (!outFile.is_open()) {
        cerr << "Cannot open the target file: " << targetFile << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        outFile << line << endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    string sourceFile = "file.txt";
    string targetFile = "result.txt";

    copyFileLines(sourceFile, targetFile);

    cout << "Lines copied from " << sourceFile << " to " << targetFile << " successfully." << endl;

    return 0;
}


#pragma endregion



