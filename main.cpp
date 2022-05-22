
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
  std::vector<int> first;


  first.assign (7,100);             // 7 ints with a value of 100

// assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';

    
  ft::vector<int> fiirst;
  fiirst.assign (7,100);             // 7 ints with a value of 100

// assigning from array.

  std::cout << "Size of fiirst: " << int (fiirst.size()) << '\n';
  return 0;
}