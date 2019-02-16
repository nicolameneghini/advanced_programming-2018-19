/*
28/10/2018        Nicla Meneghini

Aim: implement the for-range loop in the Vector class

To do so, I simply have to create the functions "begin()" and "end()", which will
be used as boundary check in

      for (auto i : vector)

*/


#include <iostream>
#include <string>
#include <vector>


template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  ~Vector() { delete[] elem; }

  std::size_t size() const { return _size; }

  num& operator[](const std::size_t i) {  return elem[i]; }

  const num& operator[](const std::size_t i) const {return elem[i]; }

  num* begin()  {return &elem[0];}      //these functions need to be pointers!
  num* end()    {return &elem[_size];}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};


  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

    for (auto i : v)
  std::cout << i << std::endl;


  return 0;
}
