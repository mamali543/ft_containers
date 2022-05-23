
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
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;  
  it = myvector.begin() + 2;
  std::cout << "\n";
  std::cout << *it << std::endl;
  it = myvector.insert ( it , 200 );
  std::cout << std::endl;
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  std::cout << std::endl;
  std::cout << *it << std::endl;

std::cout << "--------------------------------------" << std::endl;
  ft::vector<int> myvect (3,100);
  ft::vector<int>::iterator itt;
  for (int i = 0; i < myvect.size(); i++)
    std::cout << myvect[i] << std::endl;  
  itt = myvect.begin() + 2;
  std::cout << "\n";
  std::cout << *itt << std::endl;
  itt = myvect.insert ( itt , 200 );
  std::cout << std::endl;
  for (int i = 0; i < myvect.size(); i++)
    std::cout << myvect[i] << std::endl;
  std::cout << std::endl;
  std::cout << *itt << std::endl;
  return 0;

}