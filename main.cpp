
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
  std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  myvector.erase (myvector.begin(),myvector.begin()+3);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';





  ft::vector<int> myvect;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvect.push_back(i);

  // erase the 6th element
  myvect.erase (myvect.begin()+5);

  // erase the first 3 elements:
  myvect.erase (myvect.begin(),myvect.begin()+3);

  std::cout << "myvect contains:";
  for (unsigned i=0; i<myvect.size(); ++i)
    std::cout << ' ' << myvect[i];
  std::cout << '\n';
  return 0;

}