#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int SIZE = 37;
int userChoice = 5;

string englishRef = " abcdefghijklmnopqrstuvwxyz0123456789";// English letter for reference(for now)
string morseRef[SIZE] = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                         "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};// Morse code reference
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
        //    cout << "Line Position is: " << linePosit << "\n\n";
        }// end if loop

    }//end for loop
 //   cout << "\nEnd position is " << linePosit-1 <<endl;// for testing purpose
    cout << "------------------------\n\n";
}

// function to translate Morse to English
void MorseToEnglish() {
    int linePosit = 1;
    string userInput = "";
    cout << "\t\t\tWhat you like to translate: \n\t\t\t    (Morse to English)\n" << endl;
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
            }// end while
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
    ifstream readFile("translate.txt");
    ofstream creatFile("translated.txt");

    creatFile << " ------------------------------------\n"
              << "|   Your Translated Text is Here     |\n"
              << " ------------------------------------\n";
    string currentMorse = "";

    while (getline(readFile, tempReading)) {

        istringstream morseToEngl(tempReading);
        while (morseToEngl >> currentMorse) {
            int i = 0;// counter for looping the morseRef array
            int flag = 1;// flag for checking if the morse code exists in reference

            while (i < SIZE) {
                if (currentMorse == morseRef[i]) {
                    creatFile << englishRef.at(i);
                    flag = 0;
                    break;
                }
                i++;
                linePosit++;
            }// end inner while
            // if not exist in reference, output capital "X"
            if (flag)
                creatFile << "X";

            if ((linePosit/2) / 25) {
                creatFile << "\n";
                linePosit = 1;// reset linePosit to 0
            }//

            flag = 1;
        }// end inner while
    }// end while

    cout << "Translation is completed" << endl;
}

// function to translate English file to Morse file
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

            if (linePosit / 15) {
                creatFile << "\n";
                linePosit = 0;//(linePosit+1) % 12;// reset linePosit to 0
            }// end i
        }
    }// end while

    cout << "Translation is completed" << endl;
}

// function to check continue translation
void continueTrans() {
    cout << "Do you want to continue translate: 1 yes, 0 no: ";
    cin >> userChoice;
    system("cls");
}

// function to display menu for user choices
void userMenu() {

    while (userChoice) {
        cout << "\t\t\tHere is your user menu:\n\n\n"
         << "1. Translate English to Morse Code\n"
         << "2. Translate Morse code to English\n"
         << "3. English File to Morse Code File\n"
         << "4. Morse Code File to English File\n\n"
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
                cout << "Translate English File -> Morse Code File\n" << endl;
                FileEnglToMorse();
                break;
            case 4:
                cout << "Translate Morse Code File -> English File\n" << endl;
                FileMorseToEngl();
                break;
        }

        continueTrans();
    }


    cin.get();
    system("cls");
}
