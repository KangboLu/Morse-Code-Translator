#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string englishRef = "abc";
    string morseRef[3] = {".-","-...","-.-."};

    string userInput = "abc";

    for (int i = 0; i < userInput.length(); i++) {
        cout << userInput.at(i) << " ";
    }
}
