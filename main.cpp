
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
{  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  it = myvector.begin();

  std::vector<int> anothervector (4,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  std::cout << "\n";
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;}
  std::cout << '\n';
  std::cout << '\n';
  std::cout << '\n';

{
    ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  it = myvector.begin();

  ft::vector<int> anothervector (4,400);
  myvector.insert (it+2,anothervector.begin(),anothervector.end());
  std::cout << "\n";
  for (int i = 0; i < myvector.size(); i++)
    std::cout << myvector[i] << std::endl;
  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
}
}
