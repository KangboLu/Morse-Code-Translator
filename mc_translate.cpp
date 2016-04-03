#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = " abc";// English letter for reference
    string morseRef[4] = {"/", ".-","-...","-.-."};// Morse code reference

    string userInput = "abc eeee ab cb cd ec eeee ab c eeee ab ";// User inputs
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
    cout << "Translating(English to Morse): \n\n";
    for (int i = 0; i < userInput.length(); i++, linePosit++) {

        // finded position by comparing englishRef and userInput
        int findPosit = englishRef.find(userInput.at(i));

        //output morse code translation
        if (findPosit+1)
            cout << morseRef[findPosit] << " ";
        else
            cout << "X ";

        // if loop for adding new line after 10th character Morse Code translation
        if ((linePosit + 1) / 10) {
            cout << "\n";
            linePosit = (linePosit+1) % 10;// reset linePosit to 0
            cout << "Line Position is: " << linePosit << "\n\n";
        }

    }//end for loop
    cout << "\nEnd position is " << linePosit <<endl;// for testing purpose

}//end main
