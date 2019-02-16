/*
21/10/2018        Nicola Meneghini

Aim: read words from a file, and count the repetitions using a map.

I simply have to use the words in the file as the key of the map

Time to be completed: 0.17 seconds (usr)

*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>


int main(){

std::unordered_map<std::string, unsigned int> words;

std::string s;

unsigned int counter{1};

std::ifstream infile;
std::ofstream outfile;
infile.open("LittleWomen.txt");


while (infile.good()) {

  infile >> s;

  ++words[s];

}


outfile.open("counter3.txt");

for ( const auto& output : words){

      //if (output.second > 2)

      outfile << output.first << " ->" << output.second   << '\n';


}



  return 0;
}
