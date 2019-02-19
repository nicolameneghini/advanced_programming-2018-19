#include "utility.h"
#include <iostream>

#ifndef __FOO_H
#define __FOO_H

struct Foo{
  static double f;
  std::string bar;
  Foo() = default;
  Foo(const std::string& s) : bar{to_upper(s)} {};
};

double Foo::f;

#endif
