/*
Simple Rock Paper Scissors Game :)
by Keith Tan, 06/28/2023
*/

#include <iostream>
#include <iomanip> // setw() and setfill()
#include <ctime> // to seed
#include <conio.h> // getch();

using namespace std;

//Function prototypes
void displayChoices(int& input); //Welcome user, intake and output choice
bool checkError(int input); //Check if user input is valid
void getComputerChoice(int& a); //Uses RNG to get computer choice
void checkWhoWins(int a, int b, int& wins); //Compares the user and computer input
bool playAgain(); //Asks if user wants to play again
 

int main() { //start of main

    int userInput = 0;
    int computerChoice = 0;
    int wins = 0;

    do {
        displayChoices(userInput);
        getComputerChoice(computerChoice);
        checkWhoWins(userInput,computerChoice, wins);
    } while(playAgain() == true);

    return 0;
} //End of main


//Set Functions here
void displayChoices(int& input) {

    cout << endl;
    cout << left << setw(5) << setfill('-') << "";
    cout << "Rock Paper Scissors Game!";
    cout << left << setw(5) << setfill('-') << "" << endl;

    do {
        cout << "Choose between 1.Rock, 2.Paper, 3.Scissors: ";
        cin >> input;
    } while (checkError(input) == false);

    switch (input) {
        case 1:
        cout << "You have chosen Rock!" << endl;
        break;
        case 2:
        cout << "You have chosen Paper!" << endl;
        break;
        case 3:
        cout << "You have chosen Scissors!" << endl;
        break;
    }
}

bool checkError(int input) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error: Invalid input!" << endl;
        return false;
    }
    if(input < 1 || input > 3) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Error: Invalid input!" << endl;
        return false;
    }
    return true;
}

void getComputerChoice(int& a) {
    srand(time(nullptr));
    a = (rand() % 3 + 1); 
        switch (a) {
        case 1:
        cout << "The Computer has chosen Rock!" << endl;
        break;
        case 2:
        cout << "The Computer has chosen Paper!" << endl;
        break;
        case 3:
        cout << "The Computer has chosen Scissors!" << endl;
        break;
    }
}

void checkWhoWins(int a, int b, int& wins) {
    if (a == b) {
        cout << "Its a draw!" << endl;
    }
    if (a == 1) {
        if(b == 2) {
            cout << "You lose!" << endl;
        }
        if(b == 3) {
            wins++;
            cout << "You win, you have won " << wins << " times!" << endl;
        }
    }
    if (a == 2) {
        if(b == 1) {
            wins++;
            cout << "You win, you have won " << wins << " times!" << endl;
        }
        if(b == 3) {
            cout << "You lose!" << endl;
        }
    }
    if (a == 3) {
        if(b == 1) {
            cout << "You lose!" << endl;
        }
        if(b == 2) {
            wins++;
            cout << "You win, you have won " << wins << " times!" << endl;
        }
    }
}

bool playAgain() {
    char input = ' ';
    cout << "Would you like to play again? (Y / N): ";
    cin >> input;
    if (input == 'y' || input == 'Y')
    {
        return true;
    } else if (input == 'n' || input == 'N')
    {
        cout << endl << "Thanks for playing!" << endl;
        cout << "Press any key to continue..." << endl;
        getch();
        return false;
    } else {
        cout << "Error: Invalid input! Closing program..." << endl;
        exit(0);
    }
}