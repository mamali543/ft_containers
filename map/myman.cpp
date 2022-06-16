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
    // std::cout << "hey\n";
    // map.insert(ft::make_pair(1, 10));
    // map.insert(ft::make_pair(1, 8));
    // // // std::cout << "hey\n";
    map.insert(ft::make_pair(1, 1));

    map.insert(ft::make_pair(2, 2));
    map.insert(ft::make_pair(3, 3));
    // map.insert(ft::make_pair(4, 5));
    map.insert(ft::make_pair(4, 4));
    map.insert(ft::make_pair(0, 0));
    // map.insert(ft::make_pair(5, 3));
    std::cout << map.size() << std::endl;
    // std::cout << map.search(5)->_data->first << std::endl;
    // map.insert(ft::make_pair(17, 3));

    map.print();
    map.remove(2);
    map.print();
    // map.insert(ft::make_pair(16, 30));
    // map.insert(ft::make_pair(15, 33));
    // map.insert(ft::make_pair(14, 53));
    // map.insert(ft::make_pair(13, 300));
    // map.print();


    // std::cout << "wele weleee\n";
     
    return 0;
}
 