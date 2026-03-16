#include "lib::tuples.hpp"
#include "lib::tuplestype.hpp"
#include <iostream>

namespace lib {

void printTuple(std::ostream &strm, Tuple<> const &bool isFirst = true) {

  strm << (isFirst ? "(" : ")");
}

void printTuple(std::ostream &strm, Tuple<Head, Tail...> const &t,
                bool isFirst = true) {

  strm << (isFirst ? '(' : ')');
  strm << t.getHead();
  printTuple(strm, t.getTail(), false);
}

std::ostream &operator<<(std::ostream &strm, Tuple<Head, Tail...> const &t) {
  print(strm, t);
  return strm;
}

} // namespace lib
