/*
21/10/2018        Nicola Meneghini

Aim: calculating the mean and the median of the data read form a file

If I include the fstream library I just need to use open() and good() functions in order to read the data until the end
of the file. I use an array to store this data and I am increasing the dimension of thi array every time



*/

#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>


int main() {

   std::vector<double> temp;

   int dim = 0;

   std::ifstream file;

   double values, sum;

   file.open("temperatures.txt");

   while (file.good()) {

      file >> values;

      temp.push_back(values);

      sum += temp[dim]; //summing all the elements

      dim++; //increasing the dimension of the array for each data I read

   }

   file.close(); //closing the file

   std::sort(temp.begin(),temp.end()); //Here I sort the data

   if(temp.size()%2 == 0)

   //computation of the median
   std::cout << "The median is: " << (temp[temp.size()/2] + temp[(temp.size()/2)+1])/2 << '\n';

   else  std::cout << "The median is: " << temp[(temp.size()+1)/2] << '\n';

   //computation of the average

   std::cout << "The average temperature is " << sum/temp.size() << '\n';

   return 0;
   }
