
#include <vector>
#include "./header.hpp"
using namespace std;

int main ()
{
  std::vector<int>::size_type sz;

  std::vector<int> foo;
  sz = foo.capacity();
  std::cout << "making foo grow:\n";
  for (int i=0; i<100; ++i) {
    foo.push_back(i);
    if (sz!=foo.capacity()) {
        sz = foo.capacity();
        std::cout << "foo capacity: " << foo.capacity() << '\n';
        std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::vector<int> bar;
  sz = bar.capacity();
  bar.reserve(100);   // this is the only difference with foo above
  std::cout << "making bar grow:\n";
  for (int i=0; i<100; ++i) {
    bar.push_back(i);
    if (sz!=bar.capacity()) {
      sz = bar.capacity();
      std::cout << "capacity changed: " << sz << '\n';
    }
  }

  std::cout << "-----      -------       --------" << std::endl;

  ft::vector<int>::size_type k;

  ft::vector<int> fooo;
  k = fooo.capacity();
  std::cout << "making fooo grow:\n";
  for (int i=0; i<100; ++i) {
    fooo.push_back(i);
    if (k!=fooo.capacity()) {
        k = fooo.capacity();
        std::cout << "fooo capacity: " << fooo.capacity() << '\n';
        std::cout << "capacity changed: " << k << '\n';
    }
  }

  ft::vector<int> barr;
  k = barr.capacity();
  barr.reserve(100);   // this is the only difference with fooo above
  std::cout << "making barr grow:\n";
  for (int i=0; i<100; ++i) {
    barr.push_back(i);
    if (k!=barr.capacity()) {
      k = barr.capacity();
      std::cout << "capacity changed: " << k << '\n';
    }
  }
  return 0;
}