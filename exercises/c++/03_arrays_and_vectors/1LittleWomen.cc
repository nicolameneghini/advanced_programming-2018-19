/*
21/10/2018        Nicola Meneghini

Aim: read words from a file, erase the repeated ones and count the repetitions.

I store all the words in a vector and then I sort it so that
I only have to check a repetition between two consecutiv words. In this way I avoid using
two nested for loops

Time to be completed: 0.31 seconds (usr)

*/


#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

int main(){

std::vector<std::string> words;

std::string s;

unsigned int counter{1};


std::ifstream infile;
std::ofstream outfile;
infile.open("LittleWomen.txt");

int i;

//here I read the file
while(infile.good()){

  infile >> s;

  words.push_back(s);

}


//Now I sort the array so I only have to check a repetition between two consecutiv words.

  std::sort(words.begin(), words.end());

  outfile.open("counter.txt");

  for ( i = 1; i < words.size(); i++){

    if(words[i] == words[i-1]) counter++;

    else{

      outfile << words[i-1] << " ->" << counter   << '\n';

      counter = 1;

    }

  }

  return 0;

}
