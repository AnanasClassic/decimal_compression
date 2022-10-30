#pragma once
#include "Decimal.h"

class Solution {
 public:
  static void Solve(){
    std::string value_1;
    std::string value_2;
    std::cin >> value_1 >> value_2;
    Decimal fraction_1(value_1);
    Decimal fraction_2(value_2);
    std::cout << (fraction_1 == fraction_2 ? '=' : fraction_1 <fraction_2 ? '<' : '>');
  }
};
