# include<iostream>
# include "../utils/make_pair.hpp" 
# include "../utils/pair.hpp" 
# include "map.hpp" 


// void preOrder(ft::Node<int> *root)
// {
//     if(root != NULL)
//     {
//         std::cout << root->_data.first << " ";
//         preOrder(root->_left);
//         preOrder(root->_right);
//     }
// }

int main()
{
    ft::map<int , int > map;
    // std::cout << "wele weleee\n";
    std::cout << "hey\n";
    map.insert(ft::make_pair(0, 0));
    map.insert(ft::make_pair(1, 1));
    std::cout << "hey\n";
    map.insert(ft::make_pair(2, 2));

    map.insert(ft::make_pair(3, 3));

    map.print();

    // std::cout << "wele weleee\n";
     
    return 0;
}
 