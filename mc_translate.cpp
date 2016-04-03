#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = " abc";// English letter for reference
    string morseRef[4] = {"/", ".-","-...","-.-."};// Morse code reference

    string userInput = "abc a b c ab ac bc cba";// User inputs
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
    cout << "Translating: \n";
    for (int i = 0; i < userInput.length(); i++, linePosit++) {

        int findPosit = englishRef.find(userInput.at(i));
        if (findPosit+1)
            cout << morseRef[findPosit] << " ";
        else
            cout << "X" << endl;

        if ((linePosit + 1) / 10) {
            cout << "\n";
            linePosit = (linePosit+1) % 10;
            cout << "Line Position is: " << linePosit << endl;
        }

    }//end for loop


}//end main
