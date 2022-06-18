# include<iostream>
#include <map>
#include "map.hpp"
#include "bidirectional_iterator.hpp"
// using namespace std;

int     main()
{

/* -------------insert test------------------ */

// {  std::map<char,int> mymap;

//   // first insert function version (single parameter):
//   mymap.insert ( std::pair<char,int>('a',100) );
//   mymap.insert ( std::pair<char,int>('z',200) );

//   std::pair<std::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( std::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }

//   // second insert function version (with hint position):
//   std::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   std::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
//   }
//     std::cout << "helloooo\n";
//   {
//   ft::map<char,int> mymap;

//   // first insert function version (single parameter):
//   mymap.insert ( ft::pair<char,int>('a',100) );
//   mymap.insert ( ft::pair<char,int>('z',200) );

//   ft::pair<ft::map<char,int>::iterator,bool> ret;
//   ret = mymap.insert ( ft::pair<char,int>('z',500) );
//   if (ret.second==false) {
//     std::cout << "element 'z' already existed";
//     std::cout << " with a value of " << ret.first->second << '\n';
//   }

//   // second insert function version (with hint position):
//   ft::map<char,int>::iterator it = mymap.begin();
//   mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
//   mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   // third insert function version (range insertion):
//   ft::map<char,int> anothermap;
//   anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
//   std::cout << "mymap contains:\n";
//   for (it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "anothermap contains:\n";
//   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';
//   }
/* -------------clear test------------------ */

/*{  std::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;
  mymap.clear();

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
    }
    std::cout << "hoooooo\n";
  {  ft::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;
  mymap.clear();

  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';}*/
/* -------------erase and find test------------------ */
/*
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';


}

{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  return 0;
}*/

/*  {std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  }
  std::cout << "heeeey\n";
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}*/
/* -------------Swap test------------------ */
/*{  std::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}
std::cout << "------------------------------\n";
  { 
    
  ft::map<char,int> bar;
  ft::map<char,int> foo;
  foo['x'] = 100;
  foo['y']= 200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);


  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;}*/
}