# include<iostream>
# include "../utils/make_pair.hpp" 
# include "map.hpp" 

int main()
{
    ft::map<int , int > map;
    std::cout << "wele weleee\n";
    map.insert(ft::make_pair(0, 0));
    std::cout << "wele weleee\n";
    map.insert(ft::make_pair(1, 1));
    std::cout << "wele weleee\n";
    map.insert(ft::make_pair(2, 2));
    std::cout << "wele weleee\n";
    map.insert(ft::make_pair(3, 3));
    std::cout << "wele weleee\n";
    map.print();
    std::cout << "wele weleee\n";
     
    return 0;
}
 