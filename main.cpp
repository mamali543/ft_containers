
#include <vector>
#include "./header.hpp"
using namespace std;

int main ()
{
  std::vector<int> vect;


  for (int i=0; i<100; i++) vect.push_back(i);

  std::cout << "size: " << (int) vect.size() << '\n';
  std::cout << "capacity: " << (int) vect.capacity() << '\n';
  std::cout << "max_size: " << (int) vect.max_size() << '\n';

  /*-------------         ------------ ------------- ------------      -------------*/

  ft::vector<int> myvector;
  for (int i=0; i<100; i++) myvector.push_back(i);

std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';

  return 0;
}