/*
14/10/2018          Nicola Meneghini

Aim: write all the primes (smaller than 100) in an array.

I write all the primes in an array which is constantely resized. In this way, I do not waste memeory.
To check if a number is prime, I calculate the rest of the division with all its previous numbers and see if
it is always different from zero.

*/


#include <iostream>

template <typename T>
 T* heap_alloc(const unsigned int dimension){

  T*tmp {new T[dimension]}; //allocation in the heap

  return tmp;
}

template <typename T1>
 T1* realloc(T1* a, const unsigned int dimension){

   T1* tmp = heap_alloc<T1>(dimension + 1); //allocation of a greater space

   int i;

   for ( i = 0; i < dimension; i++)

   tmp[i] = a[i]; //coping all the elements of the smaller array

   delete[] a;

   return tmp;

}


int main(){

  unsigned int dimension = 1;

  unsigned int *primes, *tmp;

  int i = 3,j;

  primes = heap_alloc<unsigned int>(dimension);

  primes[0] = 2;

  while ( i < 100){

    for ( j = 2; j<i; j++){

      if ( (i % j) == 0) break;


      if (j == i-1){

        dimension++; 

        primes = realloc<unsigned int>(primes, dimension);

        primes[dimension - 1] = i;


                  }

                }

i++;

  }

  for (i = 0; i < dimension; i ++)

  std::cout << primes[i] << std::endl;

return 0;

}
