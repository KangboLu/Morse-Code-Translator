#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = " abc";// English letter for reference
    string morseRef[4] = {"/", ".-","-...","-.-."};// Morse code reference

    string userInput = "abc a b c ab ac bc cba cd addd ed ed";// User inputs
    int linePosit = 0;

    // for loop for testing purpose only
    cout << "Testing: \n";
    for (int i = 0; i < userInput.length(); i++) {

        cout << userInput.at(i) << " is ";

        int findPosit = englishRef.find(userInput.at(i));
        if (findPosit+1)
            cout << morseRef[findPosit] << endl;
        else
            cout << "Not in the reference" << endl;
    }
    cout << "------------------------\n\n";

    // for loop for basic translating purpose only
    cout << "Translating(English to ): \n";
    for (int i = 0; i < userInput.length(); i++, linePosit++) {

        int findPosit = englishRef.find(userInput.at(i));// finded position
        if (findPosit+1)
            cout << morseRef[findPosit] << " ";
        else
            cout << "X" << endl;

        // if loop for adding new line after 10th character Morse Code translation
        if ((linePosit + 1) / 10) {
            cout << "\n";
            linePosit = (linePosit+1) % 10;
            cout << "Line Position is: " << linePosit << endl;
        }

    }//end for loop


}//end main
