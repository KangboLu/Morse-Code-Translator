#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 27;
int userChoice = 5;

string englishRef = " abcdefghijklmnopqrstuvwxyz";// English letter for reference(for now)
string morseRef[SIZE] = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};// Morse code reference(for now)
// function for greeting
void greeting() {
    cout << "\n\n\n\n\n           __  __                             ____            _        \n"
         << "          |  \\/  |  ___   _ __  ___   ___    / ___| ___    __| |  ___  \n"
         << "          | |\\/| | / _ \\ | '__|/ __| / _ \\  | |    / _ \\  / _` | / _ \\ \n"
         << "          | |  | || (_) || |   \\__ \\|  __/  | |___| (_) || (_| ||  __/ \n"
         << "          |_|__|_| \\___/ |_|   |___/ \\___|   \\____|\\___/  \\__,_| \\___| \n"
         << "          |_   _|__ _  _ __   ___ | |  __ _ | |_  ___   _ __           \n"
         << "            | | / _` || '_ \\ / __|| | / _` || __|/ _ \\ | '__|          \n"
         << "            | || (_| || | | |\\__ \\| || (_| || |_| (_) || |             \n"
         << "            |_| \\__,_||_| |_||___/|_| \\__,_| \\__|\\___/ |_|             \n"
         << "                                                              \n"
         << "\n\n\n\n\n\n\n\t\t\tPress any key to continue...";
         cin.get();
         system("cls");
}

// function to translate English to Morse
void EnglishToMorse() {
    int linePosit = 1;
    string userInput = "";
    cout << "\t\t\tWhat you like to translate: \n\t\t\t    (English to Morse)\n" << endl;
    getline(cin,userInput);

    cout << "\nTranslating(English to Morse): \n\n";
    for (int i = 0; i < userInput.length(); i++, linePosit++) {

        // Fining position by comparing englishRef and userInput
        int findPosit = englishRef.find(userInput.at(i));

        //output Morse code translation
        if (findPosit+1)
            cout << morseRef[findPosit] << " ";
        else
            cout << "X ";

        // if loop for adding new line after 10th character Morse Code translation
        if (linePosit / 12) {
            cout << "\n";
            linePosit = 0;// reset linePosit to 0
            cout << "Line Position is: " << linePosit << "\n\n";
        }// end if loop

    }//end for loop
    cout << "\nEnd position is " << linePosit-1 <<endl;// for testing purpose
    cout << "------------------------\n\n";
}

// function to translate Morse to English
void MorseToEnglish() {
    int linePosit = 1;
    string userInput = "";
    cout << "\t\t\tWhat you like to translate: \n\t\t\t    (Morse to English)\n" << endl;
    getline(cin,userInput);

    cout << "\nTranslating(Morse to English): \n\n";

    string engOutput = "";
    string currentMorse = "";

    istringstream morseToEngl(userInput);
    cout << userInput << endl;

    while (morseToEngl >> currentMorse) {
        int i = 0;// counter for looping the morseRef array
        int flag = 1;// flag for checking if the morse code exists in reference
        while (i < SIZE) {
            if (currentMorse == morseRef[i]) {
                cout << englishRef.at(i);
                flag = 0;
                break;
            }
            i++;
            linePosit++;
        }// end inner while
        // if not exist in reference, output capital "X"
        if (flag)
            cout << "X";

        if (linePosit / 12) {
            cout << "\n";
            linePosit = 0;// reset linePosit to 0
        }//

        flag = 1;
    }// end while
}

void FileEnglToMorse() {
    int linePosit = 1;
    string tempReading;
    ifstream readFile("translate.txt");
    ofstream creatFile("translated.txt");

    creatFile << " ------------------------------------\n"
              << "|   Your Translated Text is Here     |\n"
              << " ------------------------------------\n";

    while (getline(readFile, tempReading)) {

        for (int i = 0; i < tempReading.length(); i++, linePosit++) {

            // Fining position by comparing englishRef and userInput
            int findPosit = englishRef.find(tempReading.at(i));

            //output Morse code translation
            if (findPosit+1)
                creatFile << morseRef[findPosit] << " ";
            else
                creatFile << "X ";

            if (linePosit / 12) {
                creatFile << "\n";
                linePosit = 0;//(linePosit+1) % 12;// reset linePosit to 0
            }// end i
        }
    }// end while

    cout << "Translation is completed" << endl;
}

void continueTrans() {
    cout << "Do you want to continue translate: 1 yes, 0 no: ";
    cin >> userChoice;
    system("cls");
}

void userMenu() {

    while (userChoice) {
        cout << "\t\t\tHere is your user menu:\n\n\n"
         << "1. Translate English to Morse Code\n"
         << "2. Translate Morse code to English\n"
         << "3. Translate from File to File\n"
         << "4. Leave the dark console screen\n\n"
         << "Tell me about what's your choice: ";

        cin >> userChoice;

        switch(userChoice) {
            case 1:
                cout << "You chose to translate English to Morse\n";
                cin.get();
                system("cls");
                EnglishToMorse();
                break;
            case 2:
                cout << "You chose to translate Morse to English\n";
                cin.get();
                system("cls");
                MorseToEnglish();
                break;

            case 3:
                cout << "You chose to translate File to File" << endl;
            case 4:
                cout << "You chose to leave" << endl;
                userChoice = 0;
        }

        continueTrans();
    }


    cin.get();
    system("cls");
}
