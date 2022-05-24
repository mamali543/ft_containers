
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
  std::vector<int> myvector (3,100); //cap =3
  std::vector<int>::iterator it;

  it = myvector.begin() + 2;
      //  myvector.insert ( it , 250 );
      //  myvector.insert ( it , 250 );
      //  myvector.insert ( it , 250 );


  myvector.insert (it,2,300);
  std::cout << "\n sallaam" << *(it) << std::endl;
  // std::cout << "\n sallaam" << *(it) << std::endl;
  //myvector.insert (it,1,400);
  //std::cout << "\n sallaam" << *(it) << std::endl;
  std::cout << "\n" << std::endl;
  std::cout << myvector.capacity() << std::endl;
  for (std::vector<int>::iterator itt=myvector.begin();  itt !=  myvector.end(); itt++ )
  {
      std::cout << *itt<< std::endl;
  }

  // "it" no longer valid, get a new one:
std::cout << "------------------------\n" << std::endl;
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin() + 2;
      // myvector.insert ( it , 250 );
      // myvector.insert ( it , 250 );
      // myvector.insert ( it , 250 );
  // std::cout << "\n sallaam" << *it << std::endl;

  myvector.insert (it,2,300);
  std::cout << "\n sallaam" << *it << std::endl;
  std::cout << "\n" << std::endl;
  std::cout << myvector.capacity() << std::endl;
  for (ft::vector<int>::iterator itt=myvector.begin();  itt !=  myvector.end(); itt++ )
  {
      std::cout << *itt<< std::endl;
  }
}
  return 0;
}

//100 100 100
//        100 100 100
