#include <iostream>
#include <memory>      //uniq_ptr

template <class T> //two different "class": in this line is equal to typename
class Vector{

  std::unique_ptr<T[]> elem; //the real data: they will e stored in the heap
  std::size_t _size;
  std::size_t _free_slots = 0;

  void check_and_alloc();
public:
  Vector(const std::size_t length) :
  //in this region the members of the class are constructed
  elem { new T[length]},
  _size {length}
  {}

  auto size() const noexcept {return _size;} //auto is b/c I will use c++14

  T&operator[](const std::size_t i) noexcept {return elem[i];} //T& is to make that operator a reference
  const T&operator[](const std::size_t i) const noexcept {return elem[i];}
//commenting the previous line there's a failure in the << overloading as it calls "const Vector"


  void push_back(const T& e);
  void push_back(T&& e); // push_back with move. I have two signatures

  template <class... Args>
  void emplace_back(Args&&...args){
    push_back(T{std::forward<Args>(args)... });
  }

}; //class is a declaration: it needs the semicolon

template <class T>
void Vector<T>::push_back(const T& e){

    check_and_alloc();

    (*this)[size()] = e; //copy semantics
    _size ++;
    _free_slots--;
}

template <class T>
void Vector<T>::push_back(T&& e){

    check_and_alloc();

    (*this)[size()] = e; //copy semantics
    _size ++;
    _free_slots--;
}


template <class T>
void Vector<T>::check_and_alloc(){

  if(_free_slots == 0)
  { auto tmp = new T[size()*2]; //I am supposing _size > 0
    _free_slots = size();

    for (auto i = 0llu; i < size(); i++)
    //  tmp[i] = (*this)[i]; //do I need to copy? No, I can move
    tmp[i] = std::move( (*this)[i] );

    elem.reset(tmp);

    }

}


template <class T>
auto& operator <<(std::ostream &os, const Vector<T>& v) //1)auto insted of ostream b/c I will use c++14
                                                //2) I need the last & b/c it needs to be a reference
{
  for (auto i = 0llu; i < v.size(); ++i) //forcing i to be equal to size
    os << v[i] << " ";
  os << std::endl;
  return os;
}


class Date{
  int d,m,y;
public:
  Date(const int day, const int month, const int year):
  d{day}, m{month}, y{year} {}
  Date() = default;
  auto day() const noexcept {return d;}
  auto month() const noexcept {return m;}
  auto year() const noexcept {return y;}


};






int main(){

  Vector<int> v{4};

  {
    auto i = v.size();
    while(--i)
      v[i] = i; //here I use the non const version of [] operator
  }

 std::cout << v;

 v.push_back(5);

 std::cout << v;

 Vector<Date> vd{2};

 vd.push_back(Date{1,2,3}); //I need to specify again the type Date --> in c++11 I can do:
 vd.emplace_back(1,2,3); //but how can I write a function that knows the type at runtime?
 

 return 0;
}
