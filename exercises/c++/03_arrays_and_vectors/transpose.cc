/*
21/10/2018         Nicola Meneghini

Aim: computing the traspose of a matrix using a std::array.

I compute the transpose in a function in the most simple way, i.e. simply inverting columns and rows. I do not
do that in place.
In order to pass an array to a function I must pass the array of the given size and, in this case, also
the number of rows and the number of columns.

*/



#include <iostream>
#include <cmath>
#include <array>

template<std::size_t SIZE>
std::array<double,SIZE> transp (std::array<double, SIZE> matrix, unsigned int col, unsigned int rw){

  std::array<double, SIZE>  transpose;

  for (auto i = 0; i < rw; i++){

    for (auto j = 0; j < col; j++)

  transpose[j * rw + i] =  matrix[i * col +  j];

  }

  return transpose;
}


int main(int argc, char const *argv[]) {

  unsigned int columns{4}, rows{2};

  const int dimension{8};


  std::array<double, dimension> matrix, transpose;

  for ( auto i = 0; i < dimension; i++)

  matrix[i] = i;


  std::cout << "The matrix is" << '\n';

  for (auto i = 0; i < rows; i++){

    for (auto j = 0; j < columns; j++)

      std::cout << matrix[i * columns +  j] << " " ;

      std::cout << '\n';
  }



  transpose = transp(matrix, columns, rows);


  std::cout << "The transpose is " << '\n';

  for (auto i = 0; i < columns; i++){

    for (auto j = 0; j < rows; j++)

      std::cout << transpose[i * rows +  j] << " " ;

      std::cout << '\n';
  }



  return 0;
}
