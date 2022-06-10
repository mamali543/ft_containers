#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>


namespace ft{

template < class Key,                                     
           class T,                                       
           class Compare = std::less<Key>,                     
           class Alloc = std::allocator<std::pair<const Key,T> >    
    > class map
    {
        public:
            typedef Key key_type;
            typedef Mapped_Type mapped_type;
            typedef typename std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::size_type size_type;
            typedef typename ft::avl_tree<Key, mapped_type, Compare, Alloc> tree;
            // typedef ft::Node<value_type> node_type;
            // typedef ft::bidirectional_iterator<node_type, value_type> iterator;
            // typedef ft::const_bidirectional_iterator<node_type, value_type> const_iterator;
            // typedef ft::reverse_iterator<iterator> reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef ptrdiff_t difference_type;
    }
}

#endif