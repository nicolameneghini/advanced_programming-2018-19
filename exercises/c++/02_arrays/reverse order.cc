/*
14/10/2018          Nicola Meneghini

Aim: writing the elements of an array in the reverse order

I use two templates functions: one to dinamically allocate the dimension of the array, the other to print
the elements in the revers order.

*/




#include <iostream>

template <typename T>
 T* heap_alloc(const int dimension){

  T*tmp {new T[dimension]};

  return tmp;
}

template <typename T1>
void reverse(T1* array, const int dimension){

  for (int i{dimension - 1} ; i >= 0; i--)

  std::cout << array[i] << '\n';
}


int main(){


  int i, dimension;

  std::cout << "What's the array dimension?" << '\n';

  std::cin >> dimension;

  double* array;

  array = heap_alloc<double>(dimension);


  std::cout << "Type the array entries" << '\n';

  for (i = 0; i < dimension; i++){

  std::cin >> array[i];

  }

  std::cout << "Array in reverse order:" << '\n';

  reverse(array, dimension);


  delete[] array; //I here free the memory
  return 0;

}
