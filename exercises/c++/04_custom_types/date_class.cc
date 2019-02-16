/*
28/10/2018      Nicola Meneghini

Aim: implement a class "Date"

The class was implemented following the instructions: the functions return day, month, year are public; also the
function used to add day is public. I added another private function which verify what is the number of days of the
current month. In fact the function add_days() works adding one day at a time and verifies if the month is
"finished". If this is the case, the variable _month is increased. SOmething similar was also done for the years.
*/


#include <iostream>
#include <string>

enum class Month {jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};


class Date{

  int _day;
  int _year;
  enum Month _month;

  int current_max_day( enum Month _month ) {

    switch (_month) {

      case Month::apr: case Month::jun:
      case Month::sep: case Month::nov: return 30; break;

  //here I also check wether a year is a leap one.
      case Month::feb:

      if (_year%4 == 0 && _year%400 != 0) return 29;

      else return 28; break;

      default:  return 31;  break;
    }

  }

  public:

    //constructur
    Date(int d , enum Month m, int y ) :
    _day{d}, _month{m}, _year{y} {}

    // definition of the functions
    int day() const {return _day;}
    int year() const {return _year;}
    Month month() const {return _month;}

    //this one will be written outside the class declaration
    void add_days(const unsigned int n);


};

void Date::add_days(const unsigned int n){

  //taking max_day as given in the main
  int max_day = current_max_day(_month);


  for ( unsigned int i = 1; i <= n; i++){

    _day += 1;

 //checking on wheather I have to change month. I also verify that I am not in december
    if (_day > max_day && static_cast<int>(_month) != 12) {

     _day = 1;
     _month = Month(static_cast<int>(_month) + 1);
     max_day = current_max_day(_month);


     continue;

//If I am in december I have to add one year
   } else if (_day > max_day && static_cast<int>(_month) == 12){

     _day = 1;
     _month = Month::jan;
     max_day = current_max_day(_month);
     _year += 1;

     continue;}

    }

}
//-------------------------------------------------------
//operator << overloading
std::ostream& operator<<(std::ostream& os, Month month) {
      return os << static_cast<int>(month) ;
}

std::ostream& operator<<(std::ostream& os, Date d0) {
    os <<  d0.day() << "/" << d0.month() << "/" << d0.year();
    return os;
}

//-------------------------------------------------------
//operator == overloading

bool operator==(const Date& lhs, const Date& rhs){

    if (lhs.day() == rhs.day() && lhs.month() == rhs.month() && lhs.year() == rhs.year() )

    return 1;

    else return 0;

  }

//-------------------------------------------------------
//operator != overloading

  bool operator!=(const Date& lhs, const Date& rhs){

      if (lhs.day() != rhs.day() || lhs.month() != rhs.month() || lhs.year() != rhs.year() )

      return 1;

      else return 0;

    }

//-------------------------------------------------------

int  main(int argc, char const *argv[]) {


  int day=25;

  Month month = Month::oct;

  int year = 2018;

  unsigned int n = 100;

  Date d0(day,month,year);

  std::cout << "If today is:   ";
  std::cout << d0 << std::endl ;
  std::cout << "In " << n << " days will be:   " ;
  d0.add_days(n);
  std::cout << d0  << std::endl ;



}
