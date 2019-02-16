
/*
7/10/2018       Nicola Meneghini

Aim: writing a function that reads from stdin until a valid number is fed


*/

#include <iostream>
using namespace std;


int main(){


int input;

cout << "Type a number" << '\n';


while(!(cin >> input)){ //I just have to keep reading the input until it is not equal to the correct type

cin.clear(); //clears the flag error

cin.ignore(); //ignores the wrong inputs

}

cout << input << endl; //I print the correct input
return 0;

}
