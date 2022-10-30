#pragma once
#include <iostream>

class Decimal {
 public:
  Decimal(std::string value);

  const bool is_positive_;
  bool IsZero() const { return value_ == "0," || value_ == "-0,"; }

  std::string GetValue() const { return value_; }
  std::string GetIntegerPart() const;
  std::string GetFractionalPart() const;

  bool operator<(const Decimal& other_decimal) const;
  bool operator>(const Decimal& other_decimal) const;
  bool operator==(const Decimal& other_decimal) const;

 private:
  std::string value_;
  size_t point_position_;
};
