#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 39;
int userChoice = 5, innerUserChoice;

string englishRef = " abcdefghijklmnopqrstuvwxyz0123456789,.";// English letter for reference(for now)
string morseRef[SIZE] = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                         "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "--..--",
                         ".-.-.-"};// Morse code reference
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
         << "\n\n\n\n\n\n\n\t\t\tPress any key to see menu...";
         cin.get();
         system("cls");
}

// function to translate English to Morse
void EnglishToMorse() {
    int linePosit = 1;
    string userInput = "";
    cout << "\n\t\t\tWhat you like to translate: \n\t\t\t    (English to Morse)\n" << endl;
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
        }// end if loop

    }//end for loop
  //  cout << "\n------------------------\n\n";
}

// function to translate Morse to English
void MorseToEnglish() {
    int linePosit = 1;
    string userInput = "";
    cout << "\n\t\t\tWhat you like to translate: \n\t\t\t    (Morse to English)\n" << endl;
    getline(cin,userInput);

    string currentMorse = "";
    istringstream morseToEngl(userInput);

    while (morseToEngl >> currentMorse) {
        int i = 0;// counter for looping the morseRef array
        int flag = 1;// flag for checking if the morse code exists in reference

        for (int m = 0; m < currentMorse.length(); m++) {
            // find the same morse code to convert it to English letter
            while (i < SIZE) {

                if (currentMorse == morseRef[i]) {
                    cout << englishRef.at(i);
                    flag = 0;
                    //print a new line if too many characters printed
                    if (linePosit > 12) {
                        cout << "\n";
                        linePosit = 0;// reset linePosit to 0
                    }
                linePosit++;
                }
            i++;
            }// end inner while
            // if not found, translate it to X
            if (flag) {
                cout << "X";
                //print a new line if too many characters printed
                if (linePosit > 12) {
                    cout << "\n";
                    linePosit = 0;// reset linePosit to 0
                }
                linePosit++;
            }
        }// end for loop
    }// end while
}

// function to translate Morse file to English file
void FileMorseToEngl() {
    int linePosit = 1;
    string tempReading;
    ifstream readFile("translated.txt");
    ofstream creatFile("translate.txt");

    string currentMorse = "";

    // while loop to get line from the target file
    while (getline(readFile, tempReading)) {

        istringstream morseToEngl(tempReading);

        while (morseToEngl >> currentMorse) {
            int i = 0;// counter for looping the morseRef array
            int flag = 1;// flag for checking if the morse code exists in reference

            for (int m = 0; m < currentMorse.length(); m++) {
                // find the same morse code to convert it to English letter
                while (i < SIZE) {

                    if (currentMorse == morseRef[i]) {
                        creatFile << englishRef.at(i);
                        flag = 0;
                        //print a new line if too many characters printed
                        if (linePosit > 12) {
                            creatFile << "\n";
                            linePosit = 0;// reset linePosit to 0
                        }
                    linePosit++;
                    }
                i++;
                }// end while
                // if not found, translate it to X
                if (flag) {
                    creatFile << "X";
                    //print a new line if too many characters printed
                    if (linePosit > 12) {
                        creatFile << "\n";
                        linePosit = 0;// reset linePosit to 0
                    }
                    linePosit++;
                }
            }// end for loop
        }// end inner while
    }// end outer while
    cout << "\n\n\t\t      ---------------------------------\n"
              << "\t\t     |     Your Text is Translated     |\n"
              << "\t\t      ---------------------------------\n\n"
              << "\t\t     Please check your current directory\n\n\n\n\n\n" << endl;

}

// function to translate English file to Morse file
void FileEnglToMorse() {
    int linePosit = 1;
    string tempReading;
    ifstream readFile("translate.txt");
    ofstream creatFile("translated.txt");

    while (getline(readFile, tempReading)) {

        for (int i = 0; i < tempReading.length(); i++, linePosit++) {

            // Fining position by comparing englishRef and userInput
            int findPosit = englishRef.find(tempReading.at(i));

            //output Morse code translation
            if (findPosit+1)
                creatFile << morseRef[findPosit] << " ";
            else
                creatFile << "X ";

            if (linePosit > 15) {
                creatFile << "\n";
                linePosit = 0;//(linePosit+1) % 12;// reset linePosit to 0
            }// end i
        }
    }// end while

    cout << "\n\n\t\t      ---------------------------------\n"
              << "\t\t     |     Your Text is Translated     |\n"
              << "\t\t      ---------------------------------\n\n"
              << "\t\t     Please check your current directory" << endl;
}

// function to check continue translation
void continueTranslate() {
    cout << "\n\n  Do you want to continue translate: 1 yes, 0 no: ";
    cin >> userChoice;
    system("cls");
}

// function to display menu for user choices
void userMenu() {

    while (userChoice) {
       cout << "\n\n\n"
            << "       _____           _              _     _______                   \n"
            << "      |_   _|         | |            | |   |__   __|                  \n"
            << "        | |  _ __  ___| |_ __ _ _ __ | |_     | |_ __ __ _ _ __  ___  \n"
            << "  (1)   | | | '_ \\/ __| __/ _` | '_ \\| __|    | | '__/ _` | '_ \\/ __| \n"
            << "       _| |_| | | \\__ \\ || (_| | | | | |_     | | | | (_| | | | \\__ \\_\n"
            << "      |_____|_| |_|___/\\__\\__,_|_| |_|\\__|    |_|_|  \\__,_|_| |_|___(_)\n\n\n\n"
            << "        ______ _ _        _          ______ _ _      \n"
            << "       |  ____(_) |      | |        |  ____(_) |     \n"
            << "       | |__   _| | ___  | |_ ___   | |__   _| | ___ \n"
            << "  (2)  |  __| | | |/ _ \\ | __/ _ \\  |  __| | | |/ _ \\\n"
            << "       | |    | | |  __/ | || (_) | | |    | | |  __/\n"
            << "       |_|    |_|_|\\___|  \\__\\___/  |_|    |_|_|\\___|\n"
            << "\n\n\  Tell me about your choice: ";

        cin >> userChoice;

        switch(userChoice) {

            case 1:// instant translation menu
                cin.get();
                system("cls");

                cout << "\n\n  Instant Translation:\n"
                     << "----------------------------\n\n"
                     << "  1. English to Morse\n"
                     << "  2. Morse to English\n"
                     << "----------------------------\n"
                     << "\n  Tell me about your choice: " << endl;

                cin >> innerUserChoice;

                if (innerUserChoice == 1) {
                    cin.get();
                    system("cls");
                    EnglishToMorse();
                }
                else if (innerUserChoice == 2) {
                    cin.get();
                    system("cls");
                    MorseToEnglish();
                }

                break;

            case 2:// file to file menu
                cin.get();
                system("cls");

                cout << "\t\t\tFile to File translation:\n\n"
                     << "\t1. English File to Morse File   2. Morse File to English File" << endl;

                cin >> innerUserChoice;

                if (innerUserChoice == 1) {
                    cin.get();
                    system("cls");
                    FileEnglToMorse();
                }
                else if (innerUserChoice == 2) {
                    cin.get();
                    system("cls");
                    FileMorseToEngl();
                }

                break;
            default:
                cout << "  You entered a *INVALID* choice. Please press a valid choice to enter menu!";
                break;
        }// end witch statement

        continueTranslate();
    }


    cin.get();
    system("cls");
}
