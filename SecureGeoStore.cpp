#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

using namespace std;

string encryptDecrypt(const string& data, char key = 'K') {
    string output = data;
    for (char& c : output) {
        c ^= key;
    }
    return output;
}

void storeFile() {
    string country, state, district, description;
    
    cout << "Enter Country: ";
    getline(cin, country);
    cout << "Enter State: ";
    getline(cin, state);
    cout << "Enter District: ";
    getline(cin, district);
    cout << "Enter Description: ";
    getline(cin, description);

    // Folder path
    fs::path dir = "./data/" + country + "/" + state + "/" + district;
    fs::create_directories(dir);  // Create directories if not exist

    string filePath = dir.string() + "/info.txt";

    ofstream outFile(filePath);
    if (outFile.is_open()) {
        string content = "Country: " + country + "\nState: " + state + "\nDistrict: " + district + "\nDescription: " + description + "\n";
        outFile << encryptDecrypt(content);
        outFile.close();
        cout << "✅ File saved successfully in encrypted form!\n\n";
    } else {
        cerr << "❌ Error creating file.\n";
    }
}

void retrieveFile() {
    string country, state, district;
    
    cout << "Enter Country: ";
    getline(cin, country);
    cout << "Enter State: ";
    getline(cin, state);
    cout << "Enter District: ";
    getline(cin, district);

    string filePath = "./data/" + country + "/" + state + "/" + district + "/info.txt";
    
    ifstream inFile(filePath);
    if (inFile.is_open()) {
        string encryptedContent((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
        string decrypted = encryptDecrypt(encryptedContent);
        cout << "\n📄 Decrypted Content:\n" << decrypted << "\n\n";
        inFile.close();
    } else {
        cerr << "❌ File not found.\n";
    }
}

int main() {
    while (true) {
        cout << "==== Secure GeoStore ====\n";
        cout << "1. Store New File\n";
        cout << "2. Retrieve File\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore();  // Flush newline from buffer

        switch (choice) {
            case 1:
                storeFile();
                break;
            case 2:
                retrieveFile();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
