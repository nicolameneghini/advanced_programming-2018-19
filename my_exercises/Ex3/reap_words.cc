/*
21/10/2018        Nicola Meneghini

Aim: read words from a file and erase the repeated ones.

I store all the words in a vector and then I use two nested for loops to check if a word has ever
appeared before. If this is the case, I delete the "current" element of the array.

*/


#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

int main(){

std::vector<std::string> words;

std::string s;

std::ifstream file;
file.open("text.txt");

int i;

//here I read the file
while(file.good()){


  file >> s;

  words.push_back(s);



}

//and here I check the repetitions
  for ( i = 0; i < words.size(); i++){

    for (unsigned int j = 0; j < i; j++)

    if (words[i] == words[j])

    words.erase(words.begin() + i);

  }

  for ( i = 0; i < words.size(); i++)

  std::cout << words[i] << '\n';


  return 0;

}
