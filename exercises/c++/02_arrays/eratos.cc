/*
14/10/2018           Nicola Meneghini

Aim: calculating the first N primes using the sieve of Erathostenes.

I have to allocate a vector of dimension N. I assign 0 the all the elements which, according to the sieve, are false.
In this way the only elements different from zero will be the primes number.

Note also that I kind of start counting the elements from i = 2 (basically I waste the 0th and 1st element of the array)
in order to have a correspondance between the index of the array and the numbers.


*/



#include <iostream>
#include <cmath>



int main(){

  unsigned int dimension, p = 2, i, j ;

  std::cout << "insert number: ";

  std::cin >> dimension;

  unsigned int primes[dimension];

  primes[2] = 2;

  for (i = 3; i < dimension; i++)

    primes[i] = i ; //primes[3] = 3, primes[4] = 4 and so on


    for (p = 2; p < std::sqrt(dimension); p++){

      if (primes[p] != 0){

        for (j = 2; j * p < dimension; j++ ){

          primes[j*p] = 0; //assigning zero to all the multiples.

        }

      }


    }



    for (unsigned int i = 2; i < dimension; i++)

      if (primes[i] != 0) std::cout << primes[i] << '\n';


return 0;

}
