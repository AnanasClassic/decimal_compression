#pragma once
#include "Decimal.h"

Decimal::Decimal(std::string value) :
  point_position_(value.find(',')), is_positive_(value[0] != '-') {
  int last_significat_digit = value.size();
  for (size_t i = value.size() - 1; i != 0; --i) {
    if (value[i] != '0') {
      last_significat_digit = i;
      break;
    }
  }
  value_ = value.substr(0, last_significat_digit + 1);
  if (value_.back() == ',') {
    value_.push_back('0');
  }
}

std::string Decimal::GetIntegerPart() const { return value_.substr(0, point_position_); }
std::string Decimal::GetFractionalPart() const { return value_.substr(point_position_ + 1, value_.size()); }

bool Decimal::operator<(const Decimal& other_decimal) const {
  if (IsZero() && other_decimal.IsZero()) {
    return false;
  }
  if (is_positive_ != other_decimal.is_positive_) {
    return other_decimal.is_positive_;
  }
  std::string int_1 = GetIntegerPart();
  std::string int_2 = other_decimal.GetIntegerPart();
  if (int_1.size() < int_2.size()) {
    return other_decimal.is_positive_;
  }
  if (int_1.size() > int_2.size()) {
    return !other_decimal.is_positive_;
  }
  return GetFractionalPart() < other_decimal.GetFractionalPart() ?
      other_decimal.is_positive_ : !other_decimal.is_positive_;
}
bool Decimal::operator>(const Decimal& other_decimal) const { return other_decimal < *this; }
bool Decimal::operator==(const Decimal& other_decimal) const {
  if (other_decimal.is_positive_ != is_positive_) {
    return false;
  }
  if (other_decimal.value_.size() != GetValue().size()) {
    return false;
  }
  return value_ == other_decimal.GetValue();
}
