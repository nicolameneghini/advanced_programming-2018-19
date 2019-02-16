#include <string>
#include <algorithm>
#include <iostream>

std::string to_upper(const std::string& os){
  extern int n;
  n=0;
  ++n;
  const auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::toupper);
  std::cout << "function " << __func__ << " has been called " << n << " times\n";
  return s;
}

std::string to_lower(const std::string& os){
  static auto s = os;
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
