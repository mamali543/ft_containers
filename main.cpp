
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  std::cout << "\n sallaam" << *(it) << std::endl;

  myvector.insert (it,2,300);
  std::cout << "\n sallaam" << *(it) << std::endl;
  std::cout << "\n" << std::endl;
  for (int  i = 0; i < myvector.size(); i++ )
    std::cout << myvector[i] << std::endl;
  // "it" no longer valid, get a new one:
std::cout << "------------------------\n" << std::endl;
{
    ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );
  std::cout << "\n sallaam" << *(it) << std::endl;

  myvector.insert (it,2,300);
  std::cout << "\n sallaam" << *it << std::endl;
  std::cout << "\n" << std::endl;
  for (int  i = 0; i < myvector.size(); i++ )
    std::cout << myvector[i] << std::endl;
}
  return 0;
}