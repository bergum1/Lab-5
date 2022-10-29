/*
 Austin Bergum
 C++ Fall 2022
 Due: 28 October 2022
 Lab 5 Number Guessing Game
 Description: Write a number-guessing game in which the computer selects a random
 number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
 the end of each game, users should be told whether they won or lost, and then be asked
 whether they want to play again. When the user quits, the program should output the
 total number of wins and losses. To make the game more interesting, the program
 should vary the wording of the messages that it outputs for winning, for losing, and for
 asking for another game. Create 10 different messages for each of these cases, and use
 random numbers to choose among them. This application should use at least one Do-
 While loop and at least one Switch statement. Write your C++ code using good style and
 documenting comments. You should use functions in your code as well. Your source
 code file should be called Lab5.cpp.
 */

#include <iostream> //preconstition: needed for everything to output to screen. postcondition: everything is outputted to the screen

void random_num( int &num, int &random, int &guesses, bool &againExit ); //void function call w/ pass by reference values to be used in other functions
void wrong_answer(); //void function call
void right_answer(); //void function call
void output( int &num, int &random, int &guesses, bool &againExit ); //void function call w/ pass by reference values to be used in other functions
void number_generator( int &num); //void function call w/ pass by reference values to be used in other functions

using namespace std;

int main() //main function to output everything
{
    int num; //int num declared for user input number
    int guesses; //int guesses declared to limit user to 20 guesses later on in the code
    bool againExit; //bool value declared to run program in loop with condition that it's true
    srand(time(NULL)); //sets time, still unsure exatly how this statement works, i just know it need to be used to generate a random number
    
    do //do while loop used
    {
        int random = rand() % 100 + 1; //random number generated between 1 and 100
        random_num(num, random, guesses, againExit); //sets outsput statements if user guess is invalid and then output called inside this function to set cout statements under certain conditions
    }while(againExit == true); //sets condition to run the do while loop
    
    return 0;
}

void random_num( int &num, int &random, int &guesses, bool &againExit ) //function created to declare the random number generated and then set the conition statements for the user answer. this is called in a do while loop in the main function so
{
    number_generator(num); //generates random number
    output(num, random, guesses, againExit); //outputs to screen under certain conditions due to the user guess
}

void wrong_answer() //function created for when user guess does not match the random number generated
{
    int incorrect = rand() % 10 + 1; //random number generated between 1 and 10 to randomly choose a case in switch statement
    switch (incorrect) //switch statement used with 10 different cases
    {
        case 1:
            cout << "Versuchen Sie es erneut, Verlierer." << endl;
            break;
        case 2:
            cout << "Du bist scheiße, versuch es weiter." << endl;
            break;
        case 3:
            cout << "Du bist schrecklich darin, rate noch einmal, wenn du dich traust." << endl;
            break;
        case 4:
            cout << "Falsch, wie kann man bei einem Spiel so schlecht sein? Weiter versuchen." << endl;
            break;
        case 5:
            cout << "Verliererrrrrrr, spiel weiter." << endl;
            break;
        case 6:
            cout << "Verdammt, du bist so schlecht in diesem Spiel. Du musst wieder raten." << endl;
            break;
        case 7:
            cout << "Oh verdammt, du hast verloren. Versuchen Sie es noch einmal, ich glaube an Sie." << endl;
            break;
        case 8:
            cout << "Probieren Sie es noch einmal aus, ich weiß, dass Sie dies tun können." << endl;
            break;
        case 9:
            cout << "Wenn Sie dies lesen, haben Sie das Spiel verloren, Sie Penner." << endl;
            break;
        case 10:
            cout << " Das Spiel wird Sie schlagen, bevor Sie es schlagen. Versuchen Sie es erneut, wenn Sie erneut verlieren möchten.." << endl;
            break;
    }
}

void right_answer() //function created for when user guess matches the random number generated
{
    int correct = rand() % 10 + 1; //random number generated between 1 and 10 to randomly choose a case in switch statement
    switch (correct) //switch statement used with 10 different cases
    {
        case 1:
            cout << "Congrats, you won the game! ";
            break;
        case 2:
            cout << "Du hast endlich gewonnen. ";
            break;
        case 3:
            cout << "OH. MY. GOSH. I can't belive you won. ";
            break;
        case 4:
            cout << "Ich dachte, du würdest nie gewinnen. Herzlichen Glückwunsch! ";
            break;
        case 5:
            cout << "Gewinner Gewinner, Chicken Dinner. ";
            break;
        case 6:
            cout << "Ihre harte Arbeit hat sich gelohnt, herzlichen Glückwunsch! ";
            break;
        case 7:
            cout << "Buen trabajo mi amigo! Ganaste! ";
            break;
        case 8:
            cout << "Bravo, you won! ";
            break;
        case 9:
            cout << "You might have won, but I still think you're a loser. ";
            break;
        case 10:
            cout << "Winner winner chicken dinner. ";
            break;
    }
}

void output( int &num, int &random, int &guesses, bool &againExit ) //function created to set output only under certain conditions
{
    int choice;
    
    guesses = 1;
    
    do //do while loop used to run the conditions of the guesses. adds a guess every time the user gets it wrong, and then gives them the option to play again or exit after 20 tries
    {
        if (num != random) //if statement used to for when user answeres incorrectly
        {
            guesses++; //add a guess everytime user answers incorrectly
            wrong_answer(); //wrong answer function called
            number_generator(num); //number_generator called to generate new number after user gets choses to play again after 20th try
        }
        if (num == random) //if statement used for when user guesses number correctly
        {
            right_answer();
                
            cout << "If you would like to play again, press 1. If you would like to exit the game, press 2." << endl;
            cout << "Please enter 1 or 2: ";
            cin >> choice;
                
            if (choice == 1) //if and else statements used to give user option to play again or exit after they guess the number correctly
            {
                againExit = true;
            }
            else if (choice == 2)
            {
                againExit = false;
                cout << "Game has been ended" << endl;
            }
            guesses = 20;
        }
            
        if (num != random && guesses == 20) //if statement used for when user guesses incorrectly on the 20th try
        {
            cout << "Sorry, you lost. This was your last attempt so if you would like to play again, press 1. If you would like to exit the game, press 2." << endl;
            cout << "Please enter 1 or 2: ";
            cin >> choice;
                
                if (choice == 1) //if and else statements used to give user option to play again or exit after they guess the number correctly
                {
                    againExit = true;
                }
                else if (choice == 2)
                {
                    againExit = false;
                    cout << "Game has been ended" << endl;
                }
        }
    }while(guesses < 20); //sets condition to run the do while loop
    
}

void number_generator( int &num) //function created to set conditions to the user guess
{
    bool bFail; //bool used to make user guess true or false
    cout << "Guess an integer number between 1 and 100: ";
    do //do while loop declared here to run throughout the entire game if a user answeres with an invalid input
    {
        cin >> num;
        
        bFail = cin.fail(); //tells whether anser is invalid or not
        cin.clear(); //clears invalid answer
        cin.ignore(10, '\n'); //not really sure what this one does not gonna lie
        
    if (num >= 1 && num <= 100) //if statement used to set condition for else statement
    {}
    else //else statement used output if user input is invalid
    {
        cout << "Your input is ivalid... please try again: ";
    }
        
    }while(bFail == true); //sets condition to run the do while loop
}
