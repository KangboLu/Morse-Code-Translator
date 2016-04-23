#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void greeting() {
    cout << "\n\n  __  __                             ____            _        \n"
         << " |  \\/  |  ___   _ __  ___   ___    / ___| ___    __| |  ___  \n"
         << " | |\\/| | / _ \\ | '__|/ __| / _ \\  | |    / _ \\  / _` | / _ \\ \n"
         << " | |  | || (_) || |   \\__ \\|  __/  | |___| (_) || (_| ||  __/ \n"
         << " |_|__|_| \\___/ |_|   |___/ \\___|   \\____|\\___/  \\__,_| \\___| \n"
         << " |_   _|__ _  _ __   ___ | |  __ _ | |_  ___   _ __           \n"
         << "   | | / _` || '_ \\ / __|| | / _` || __|/ _ \\ | '__|          \n"
         << "   | || (_| || | | |\\__ \\| || (_| || |_| (_) || |             \n"
         << "   |_| \\__,_||_| |_||___/|_| \\__,_| \\__|\\___/ |_|             \n"
         << "                                                              \n";
}

int main ()
{
    const int SIZE = 27;
    string englishRef = " abcdefghijklmnopqrstuvwxyz";// English letter for reference(for now)
    string morseRef[SIZE] = {"/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                         "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};// Morse code reference(for now)

    string userInput = "abcdefghijklmnopqrstuvwxyz";// user input for testing(for now)
    string userMorseInput = ".- -... -.-. -.. . / ..-. ..- -.-. -.-";// user input for testing(for now)
    int linePosit = 0;

    greeting();
    // for loop for testing purpose only
    cout << "Testing: \n";
    for (int i = 0; i < userInput.length(); i++) {

        cout << userInput.at(i) << " is ";// output each letter with its morse reference

        int findPosit = englishRef.find(userInput.at(i));
        if (findPosit+1)
            cout << morseRef[findPosit] << endl;
        else
            cout << "Not in the reference" << endl;
    }
    cout << "------------------------\n\n";

    // for loop for basic translating purpose only
    cout << "Translating(English to Morse): \n\n";
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

    cout << "Translating(Morse to English): \n\n";

    string engOutput = "";
    string currentMorse = "";
    istringstream morseToEngl(userMorseInput);
    cout << userMorseInput << endl;

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
        }
        // if not exist in reference, output capital "X"
        if (flag)
            cout << "X";
        flag = 1;
    }

}//end main
