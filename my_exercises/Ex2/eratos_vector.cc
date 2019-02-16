/*
14/10/2018           Nicola Meneghini

Aim: calculating the first N primes using the sieve of Erathostenes and an array of boolean.

The implementation is identical to the other one.

*/

#include <iostream>
#include <cmath>
#include <vector>



int main(){

  unsigned int dimension = 100, p = 2, i, j ;

  std::cout << "insert number: ";

  std::cin >> dimension;

  std::vector<bool> primes;

  primes.resize(dimension);

  primes[2] = true;

  for (i = 3; i < dimension; i++)

    primes[i] = true ;


    for (p = 2; p < std::sqrt(dimension); p++){

      if ((primes[p])){

        for (j = 2; j * p < dimension; j++ ){

          primes[j*p] =  false;

        }

      }


    }



    for (unsigned int i = 2; i < dimension; i++)


      if ((primes[i])) std::cout << i << '\n';


return 0;

}
