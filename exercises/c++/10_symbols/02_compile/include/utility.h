#include <string>
#include <algorithm>
#include <iostream>


#ifndef __UTILITY_H
#define __UTILITY_H

void print_upper(const std::string& s);
void print_lower(const std::string& s);

std::string to_upper(const std::string& os){
  static int n;
  ++n;
  auto s = os;
  std::transform(os.begin(), os.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}


std::string to_lower(const std::string& os){
  auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
#endif
