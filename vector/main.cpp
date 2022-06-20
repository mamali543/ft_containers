
#include <vector>
#include "./vector.hpp"
#include "../stack/stack.hpp"
// #include "./stack.hpp"
// #include "./iterator.hpp"
// #include "./revers_iterator.hpp"
// #include <iterator>
// using namespace std;

// #include "../system/system_methods.ipp"
// #include "__service.ipp"

// class B {
// public:
//     char *l;
//     int i;
//     B():l(nullptr), i(1) {};
//     B(const int &ex) {
//         this->i = ex;
//         this->l = new char('a');
//     };
//     virtual ~B() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// class A : public B {
// public:
//     A():B(){};
//     A(const B* ex){
//         this->l = new char(*(ex->l));
//         this->i = ex->i;
//         if (ex->i == -1) throw "n";
//     }
//     ~A() {
//         delete this->l;
//         this->l = nullptr;
//     };
// };

// template <typename T>
// std::vector<int> insert_test_3(std::vector<T> vector) {
//     std::vector<int> v;
//     std::vector<int> tmp;
//     tmp.assign(2600 * 1, 1);
//     vector.assign(4200 * 1, 1);
//     vector.insert(vector.end() - 1000 * 1, tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     std::vector<A> vv;
//     std::vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }

//     return v;
// }

// template <typename T>
// std::vector<int> insert_test_3(ft::vector<T> vector) {
//     std::vector<int> v;
//     ft::vector<int> tmp;
//     tmp.assign(2600 * 1, 1);
//     vector.assign(4200 * 1, 1);
//     vector.insert(vector.end() - 1000 * 1, tmp.begin(), tmp.end());
//     v.push_back(vector[3]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     std::unique_ptr<B> k2(new B(3));
//     std::unique_ptr<B> k3(new B(4));
//     std::unique_ptr<B> k4(new B(-1));
//     ft::vector<A> vv;
//     ft::vector<B*> v1;

//     v1.push_back(&(*k2));
//     v1.push_back(&(*k3));
//     v1.push_back(&(*k4));
//     try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
//     catch (...) {
//         v.push_back(vv.size());
//         v.push_back(vv.capacity());
//     }

//     return v;
// }

// int main ()

// {  // const``ructors used in the same order as described above:
//   std::vector<int> v1;
//   ft::vector<int> v2;
//   std::vector<int> v;
//   std::vector<int> vv;

//   v = insert_test_3(vv);
//   v1 = insert_test_3(v2);
//   for (int i = 0;  i < v.size(); i++)
//     std::cout << v[i] << std::endl;
//   std::cout << "----------------------------------" << std::endl;
//   std::cout << "----------------------------------" << std::endl;
//   for (int i = 0;  i < v1.size(); i++)
//     std::cout << v1[i] << std::endl;
//   system("leaks a.out");
//   return 0;
// }

// template <typename T>
// std::vector<int> constructor_test(std::vector<T> vector) {
//     std::vector<int> v;
//     std::vector<int> tmp0(vector);
//     std::vector<int> tmp(1000, 4), tmp2(1000, 5);
//     tmp = tmp2;
//     std::vector<int> tmp3(tmp);
//     std::vector<int> tmp4(tmp.begin(), tmp.end());
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try { std::vector<int> tmp5(-1, -1); }
//     catch (std::exception &e) { v.push_back(1); }
//     return v;
// }

// template <typename T>
// std::vector<int> constructor_test(ft::vector<T> vect) {

//     std::vector<int> v;
// 	ft::vector<int> tmp0(vect);
//     ft::vector<int> tmp(1000, 4), tmp2(1000, 5);
//     tmp = tmp2;
//     ft::vector<int> tmp3(tmp);
//     ft::vector<int> tmp4(tmp.begin(), tmp.end());
//     v.push_back(tmp4.size());
//     v.push_back(tmp4.capacity());
//     v.push_back(tmp[2]);
//     v.push_back(tmp3[2]);
//     v.push_back(tmp4[2]);
//     try {
//         ft::vector<int> tmp5(-1, -1);
//         }
//     catch (std::exception &e) {
//         v.push_back(1);
//         // system("leaks a.out");
//         }
//     return v;
// }

// int main() {
//     std::vector<int> v1;
//     std::vector<int> v2;
//     std::vector<int> v4;
//     ft::vector<int>  v3;
//     v1 = constructor_test(v2);
//     v4 = constructor_test(v3);
//     for (int i =0; i < v1.size(); i++)
//         std::cout << v1[i] << std::endl;
//     std::cout << "---------------------------\n" << std::endl;
//     for (int i =0; i < v4.size(); i++)
//         std::cout << v4[i] << std::endl;
//     return (0);
// }

#include <iostream> // std::cout
#include <stack>    // std::stack
#include <vector>   // std::vector
#include <deque>    // std::deque


#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "../vector/vector.hpp"

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

int main()
{
        std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< vector tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " fill constructor "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- fill tow vectors with a 10 strings ------*/
        ft::vector<std::string> my_v(10, "fill constructor test");
        std::vector<std::string> v(10, "fill constructor test");
        /*---------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res;
        /*---------------------------------------------------------*/
        for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;

        for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;
        EQUAL(res == my_res);
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " range constructor "
              << "] --------------------]\t\t\033[0m";
    {
        /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
        std::vector<std::string> v(10, "range constructor test");
        ft::vector<std::string> my_v(10, "range constructor test");
                    std::cout << "\nsssss\n";

        ft::vector<std::string> my_v1(my_v.begin(), my_v.end()  ); // this one is to check if the range works with ft::vector
        
        // ft::vector<std::string> my_v1; // this one is to check if the range works with ft::vector
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res, my_res1;
        // /*--------------------------------------------------------*/
        // for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
        //     res += *it;

        // for (ft::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
        //     my_res += *it;

        // for (ft::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
        //     my_res1 += *it;
        EQUAL(res == my_res && my_res == my_res1);
    }
    // std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
    //           << "] --------------------]\t\t\033[0m";
  // {
  //   std::vector<int> myvector(5); // 5 default-constructed ints

  //   int i = 0;

  //   std::vector<int>::reverse_iterator rit = myvector.rbegin();
  //   for (; rit != myvector.rend(); ++rit)
  //     *rit = ++i;

  //   std::cout << "myvector contains:";
  //   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }
  // std::cout << "hello\n";
  // {
  //   ft::vector<int> myvector(5); // 5 default-constructed ints

  //   int i = 0;

  //   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
  //   for (; rit != myvector.rend(); ++rit)
  //     *rit = ++i;

  //   std::cout << "myvector contains:";
  //   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }

  return 0;
}

// int main ()
// {
// {  std::vector<int> mydeque (3,100);          // deque with 3 elements
//   std::vector<int> myvector (2,200);        // vector with 2 elements

//   std::stack<int> first;                    // empty stack
//   // std::stack<int> second (mydeque);         // stack initialized to copy of deque

//   std::stack<int,std::vector<int> > third;  // empty stack using vector
//   std::stack<int,std::vector<int> > fourth (myvector);

//   if (fourth > third)
//     std::cout << "forth greater than first: " << '\n';
//   else if (fourth < third)
//     std::cout << "first greater than forth:" << '\n';
//  else
//     std::cout << "forth and first are equal"<< '\n';}

//   { std::vector<int> mydeque (3,100);          // deque with 3 elements
//   ft::vector<int> myvector (2,200);        // vector with 2 elements

//   ft::stack<int> first;                    // empty stack
// //   ft::stack<int> second (mydeque);         // stack initialized to copy of deque

//   ft::stack<int,ft::vector<int> > third;  // empty stack using vector
//   ft::stack<int,ft::vector<int> > fourth (myvector);
//   if (fourth > third)
//     std::cout << "forth greater than first: " << '\n';
//   else if (fourth < third)
//     std::cout << "first greater than forth:" << '\n';
//  else
//     std::cout << "forth and first are equal"<< '\n';
//   }

//   return 0;
// }

// int main()
// {
//   ft::vector<std::string> my_v(10, "range constructor test");
//   ft::vector<std::string> my_v1(my_v.begin(), my_v.end());
//   return 0;
// }
