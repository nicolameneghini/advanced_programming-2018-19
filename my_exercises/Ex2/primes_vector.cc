/*

14/10/2018         Nicola Meneghini

Aim: write all the primes (smaller than 100) in a vector.

I simply have to use the resize() function.
*/
#include <iostream>
#include <vector>


int main(){

  unsigned int dimension = 0;

  std::vector<unsigned int> primes;

  int i = 3, j;

  primes.resize(1);


  primes[0] = 2;


  while ( i < 100){

    for ( j = 2; j<i; j++){

      if ( (i % j) == 0) break;


      if (j == i-1){

        dimension++;

        primes.resize(dimension + 1);

        primes[dimension] = i;



                  }

                }

i++;

  }

for (i = 0; i < primes.size(); i ++)
  std::cout << primes[i] << std::endl;

return 0;

}
