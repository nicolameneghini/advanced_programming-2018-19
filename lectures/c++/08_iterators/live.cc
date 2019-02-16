//live coding sessionw

#include <iostream>
#include <memory>
#include <stdexcept>

enum class method {push_back, push_front};

template <class T>
class List<T>::Iterator{

  using Node = List<T>::Node;
  Node* current;

public:
    Iterator(Node* n): current {n}{}
    T& operator*() const {return current -> val;}
    Iterator& operator++(){
      current = current->next.get();
      return *this;
    }
  /*  Iterator operator++(int){
      Iterator it{*this};
      ++(*this);
      return it;
    }*/
    bool operator==(const Iterato& other){
      return current==other.current;
    }
    bool operator!=(const Iterato& other){
      return !(*this==other);
    }

};



//class list

template <class T>
class List{
//a list is made of many blocks -> Do we need a class block? Yes
//what is our list?
//I need a first node that we call "head"
//The class block should be private or public? Should the user care about the blocks? No, so it's private
//The user should care only about the values

  struct Node{ //it is no more templated
    T val;
    //I can use unique pointer because the position pointed shoul be univoquely determined
    std::unique_ptr<Node> next;
    Node(const T& v, Node* n): val{v}, next{n} {} //pointer and value are the elelment of each block
    ~Node() = default;
  };

  std::unique_ptr<Node> head; //I need anothe unique_ptr for the head -> it is a non-building type
  void push_front(const T& t){
  /*  auto old = head.release();  //reset is part of unique_ptr (read documentation) -> points to the old node and release its ownership
    auto tmp = new Node{t,old};
    head.reset(tmp);*/
    //previous three line with :

    head.reset(new Node{t,head.release()});

  };
  void push_back(const T& t);


public:
  friend std::ostream& operator<<(std::ostream&, const List&);
  List() = default;
  void push(const T& t, method m = method::push_front/*default method*/){
     //I created a scoped class for the purpose of the push
    if(head == nullptr){
      Node * tmp = new Node{t, nullptr};
      head.reset(tmp);
      return;
    }
    switch (m){
      case method::push_back:
        push_back(t);
        break;
      case method::push_front:
        push_front(t);
        break;
      default:
        throw std::runtime_error{"Unknown method \n"};
      };
  }

    class Iterator;
    class Constiterator;
    Iterator begin() {return Iterator{head.get()};}
    iterator end(); {return Iterator{nullptr};}

    Constiterator begin() const;
    Constiterator end() const;

};

template <typename T>
void List<T>::push_back(const T& t){
  auto tmp = head.get();
  while(tmp->next != nullptr){
    tmp = tmp->next.get();
  }
  tmp->next.reset(new Node{t,nullptr});
}

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& head){
  auto tmp = head.get();
  while (tmp != nullptr){
    os << tmp->vale << " ";
    tmp->next.get();
  } //in this way I know all the details I wanteed to keep private

  /*os << std::endl;
  return os;

  auto it = l.begin();
  auto stop = l.end();
  for(; it!=stop; ++it)
    os << *it << " ";

  return os;*/ //here I don't say anything about my class
}

int main()
{
  List<int> list; //I need a push front and a push back
  list.push(3); //calls push front by default
  list.push(5, method::push_back);
  list.push(42, method::push_front);

  for (auto& x:list){
    ++x
  }



  return 0;
}
