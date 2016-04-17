#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
    const int SIZE = 4;
    string englishRef = " abc";// English letter for reference(for now)
    string morseRef[SIZE] = {"/", ".-","-...","-.-."};// Morse code reference(for now)

    string userInput = "abc eeee ab cb cd ec eeee ab c eeee ab ";// user input for testing(for now)
    string userMorseInput = ".- -... -...";// user input for testing(for now)
    int linePosit = 0;

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

    int i = 0;
    while (morseToEngl >> currentMorse) {
        cout << currentMorse << endl;
        while (i < SIZE) {
            if (currentMorse == morseRef[i])
                cout << englishRef.at(i);
            else
                cout << "X";
            i++;
        }
    }

}//end main
