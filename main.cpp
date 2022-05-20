
#include <vector>
#include "./header.hpp"
#include "./iterator.hpp"
// #include <iterator>
using namespace std;


int main ()
{
    vector<int> ar ;
    for (int i = 0; i < 10; i++)
      ar.push_back(i);
    ar.push_back(90);
      
    // Declaring iterator to a vector
    vector<int>::iterator ptr;
      
    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
    ft::vector<int> p;
    for (int i = 0; i < 10; i++)
      p.push_back(i);
    ft::vector<int>::iterator pt = p.begin();
    ft::vector<int>::iterator tp(p.end());
    tp = tp - 5;
  cout <<  "\n" << *tp << endl;
    for (pt = p.begin(); pt < p.end(); pt++)
        cout << *pt << " ";
  return 0;
}