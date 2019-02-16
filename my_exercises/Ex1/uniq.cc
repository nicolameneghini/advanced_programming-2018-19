/*
7/10/2018       Nicola Meneghini

Aim: writing a code that counts the words n the same way
as the function "uniq -c"

I am doing so using two variables: "my_string" which stores the input sting and
"prev_string" which stores the old string.

The text file I used is uniq.txt


*/


#include <iostream>
#include <string>

int main(){

std::string prev_string, my_string; //my_string is the input strings;
                                    //prev_string insted stores the previous input string

unsigned int counter = 0;

std::getline(std::cin, my_string);  //first input

prev_string = my_string;

while(std::getline(std::cin, my_string)){

  counter++;                        //counter

  if (my_string != prev_string){  //I here check the inequality

    std::cout << counter <<  " -> " << prev_string << '\n' ;

    counter = 0;
  }

  prev_string = my_string; //reassigning the value of prev_string

  continue;

}

std::cout << counter + 1 << " -> " << prev_string << '\n';

}
