#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 27;
int linePosit = 0;
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

void userMenu() {
    cout << "\t\t\tHere is your user menu:\n\n"
         << "1. Translate English to Morse Code\n"
         << "2. Translate Morse code to English\n"
         << "3. Translate from File to File\n"
         << "4. Leave the dark console screen\n\n"
         << "Tell me about what's your choice: ";

    int userChoice = 0;
    cin >> userChoice;

    while (!userChoice) {

        switch(userChoice) {
            case 1:
                cout << "You chose to translate English to Morse" << endl;
            case 2:
                cout << "You chose to translate Morse to English" << endl;
            case 3:
                cout << "You chose to translate File to File" << endl;
            case 4:
                cout << "You chose to leave" << endl;

        }

    }


    cin.get();
    system("cls");
}

// function to translate English to Morse
void EnglishToMorse(string userInput) {
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
        if ((linePosit + 1) / 10) {
            cout << "\n";
            linePosit = (linePosit+1) % 10;// reset linePosit to 0
            cout << "Line Position is: " << linePosit << "\n\n";
        }// end if loop

    }//end for loop
    cout << "\nEnd position is " << linePosit <<endl;// for testing purpose
    cout << "------------------------\n\n";
    cin.get();
    system("cls");
}

// function to translate Morse to English
void MorseToEnglish(string userInput) {
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
        }// end inner while
        // if not exist in reference, output capital "X"
        if (flag)
            cout << "X";
        flag = 1;
    }// end while
}

