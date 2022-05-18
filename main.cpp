
#include <vector>
#include "./header.hpp"
using namespace std;


int main ()
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';




  ft::vector<int> fooo (3,100);   // three ints with a value of 100
  ft::vector<int> baar (5,200);   // five ints with a value of 200

  fooo.swap(baar);

  std::cout << "fooo contains:";
  for (unsigned i=0; i<fooo.size(); i++)
    std::cout << ' ' << fooo[i];
  std::cout << '\n';

  std::cout << "baar contains:";
  for (unsigned i=0; i<baar.size(); i++)
    std::cout << ' ' << baar[i];
  std::cout << '\n';
  return 0;
}