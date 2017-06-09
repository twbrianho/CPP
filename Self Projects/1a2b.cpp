#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    cout << "WELCOME TO << 1A2B GAME >> !" << endl << endl;
    cout << "Guess the 4-digit code in as few steps as possible!" << endl << endl;
    cout << "A correct number in the CORRECT place will return A," << endl;
    cout << "and a correct number in the INCORRECT place will return B." << endl << endl;
    cout << "You win if you get '4A0B'!" << endl << endl;
    cout << "(EX: code'1234', guess'1357', get'1A1B')" << endl << endl;
    cout << "--------------------------------------" << endl;
    newgame:
    cout << "Start guessing below!" << endl;
    while(true){
        int num1, num2, num3, num4, g1, g2, g3, g4, guesses=0;
        srand(static_cast<unsigned int>(time(NULL)));
        num1 = rand() % 9;
        do{
            num2 = rand() % 9;
        }while(num1 == num2);
        do{
            num3 = rand() % 9;
        }while(num1 == num3 || num2 == num3);
        do{
            num4 = rand() % 9;
        }while(num1 == num4 || num2 == num4 || num3 == num4);

        while(true){
            int A = 0;
            int B = 0;
            string input;
            cin >> input;
            g1 = input[0] - '0';
            g2 = input[1] - '0';
            g3 = input[2] - '0';
            g4 = input[3] - '0';
            if(g1 == num1)A++;
            else if(g1 == num2 || g1 == num3 || g1 == num4)B++;
            if(g2 == num2)A++;
            else if(g2 == num1 || g2 == num3 || g2 == num4)B++;
            if(g3 == num3)A++;
            else if(g3 == num1 || g3 == num2 || g3 == num4)B++;
            if(g4 == num4)A++;
            else if(g4 == num1 || g4 == num2 || g4 == num3)B++;
            if(A == 4)break;
            guesses++;
            cout << A << "A" << B << "B" << endl;
            cout << "----" << endl;
        }
        cout << "...." << endl;
        cout << "....CORRECT!" << endl;
        cout << "You found the answer in " << guesses << " guesses!" << endl;
        cout << "-----------------------------------" << endl;
        cout << "NEW GAME START!" << endl;
        cout << "-----------------------------------" << endl;
        goto newgame;
    }
    
    return 0;
}
