#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = " abc";// English letter for reference(for now)
    string morseRef[4] = {"/", ".-","-...","-.-."};// Morse code reference(for now)

    string userInput = "abc eeee ab cb cd ec eeee ab c eeee ab ";// user input for testing(for now)
    string userMorseInput = ".- -... -...";// user input for testing(for now)
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
  //  for (int i = 0; i < userMorseInput.length(); i++) {
        int leftPosit = 0;// begin position of the substring function call
        int rightPosit = userMorseInput.find(" ");

        cout << rightPosit << endl;

        for ( int j = 0; j < 4; j++) {
            if (userMorseInput.substr(leftPosit, rightPosit) == morseRef[j])
                cout << englishRef.at(j);
        }

        leftPosit = rightPosit;
        rightPosit = userMorseInput.substr(leftPosit, userMorseInput.length()-1).find(" ");

        cout << rightPosit;

//    }// end for loop

}//end main
