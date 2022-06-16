#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
# include "avl_tree.hpp"

namespace ft{

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef typename ft::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename allocator_type::size_type size_type;
            typedef typename ft::avl_tree<Key, mapped_type, Compare, Alloc> tree;
            typedef ft::Node<value_type> node_type;
            // typedef ft::bidirectional_iterator<node_type, value_type> iterator;
            // typedef ft::const_bidirectional_iterator<node_type, value_type> const_iterator;
            // typedef ft::reverse_iterator<iterator> reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef ptrdiff_t difference_type;
            typedef class value_compare : public std::binary_function<value_type, value_type, bool>
            {
            protected:
                key_compare _compare;
            public:
            // typedef bool result_type;
            // typedef value_type first_argument_type;
            // typedef value_type second_argument_type;
           
            bool operator() (const value_type& x, const value_type& y) const
            {
                return _compare(x.first, y.first);
            }
            value_compare(key_compare c) : _compare(c) {}
            } value_compare;
        private:
            tree _tree;
            // size_type _size;
            key_compare _compare;
            allocator_type _allocator;
        public:
             map(): _tree() , _compare(), _allocator()
            {

            }
            void insert(value_type value)
            {
                _tree.insert(value);
            }
            // void iinsert(value_type value)
            // {
            //     _tree.insert(_tree._root, value->first);
            // }
            void print()
            {

                _tree.printBT();
            }

            void remove(key_type value)
            {
                _tree.remove(value);
            }
        
            int size()
            {
                return (_tree.size());
            }
            node_type* search(key_type x)
            {
                node_type* test =  _tree.search(_tree._root, x);
                // std::cout << "first _data->" << tmp->_data->first << "second " << tmp->_data->second;
                // std::cout << tmp;
                
                return (test);
            }
    };
}

#endif