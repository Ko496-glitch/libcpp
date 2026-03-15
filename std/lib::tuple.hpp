
#include <new>
#include <utility>

namespace lib {
template <typename... types> class Tuple;

template <typename Head, typename... Tail> class Tuple<head, tail> {

private:
  Head head;
  Tuple<Tail...> tail;

public:
  Tuple(const Head &head, const Tuple<Tail...> &tail)
      : head(head), tail(tail) {}

  Head &getHead() { return head; }
  Head const &getHead() { return head; }
  Tuple<Tail...> &getTail() { return tail; }
  Tuple<Tail...> const &getTail() { return tail; }
};
} // namespace lib
