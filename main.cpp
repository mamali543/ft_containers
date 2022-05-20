
#include <vector>
#include "./vector.hpp"
#include "./iterator.hpp"
#include "./revers_iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef std::vector<int>::iterator iter_type;
                                                         // ? 0 1 2 3 4 5 6 7 8 9 ?
  iter_type from (myvector.begin());                     //   ^
                                                         //         ------>
  iter_type until (myvector.end());                      //                       ^
                                                         //
  std::reverse_iterator<iter_type> rev_until (from);     // ^
                                                         //         <------
  std::reverse_iterator<iter_type> rev_from (until);     //                     ^

  std::cout << "myvector:";
  while (rev_from != rev_until)
    std::cout << ' ' << *rev_from++;
  std::cout << '\n';



  ft::vector<int> vect;
  for (int i=0; i<10; i++) vect.push_back(i);

  typedef ft::vector<int>::iterator iterr_type;
                                                         // ? 0 1 2 3 4 5 6 7 8 9 ?
  iterr_type froom(vect.begin());                     //   ^
                                                         //         ------>
  iterr_type untiil(vect.end());                      //                       ^
                                                         //
  ft::reverse_iterator<iterr_type> rev_untiil(froom);     // ^
                                                         //         <------
  ft::reverse_iterator<iterr_type> rev_froom(untiil);     //                     ^

  std::cout << "vect:";
  while (rev_froom != rev_untiil)
    std::cout << ' ' << *rev_froom++;
  std::cout << '\n';
  return 0;
}