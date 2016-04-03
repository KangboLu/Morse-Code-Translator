#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = "abc";// English letter for reference
    string morseRef[3] = {".-","-...","-.-."};// Morse code reference

    string userInput = "abc";// User inputs

    for (int i = 0; i < userInput.length(); i++) {

        cout << userInput.at(i) << " is ";

        int findPosit = englishRef.find(userInput.at(i));
        if (findPosit+1)
            cout << morseRef[findPosit] << endl;
        else
            cout << "Not in the reference" << endl;
    }
}
