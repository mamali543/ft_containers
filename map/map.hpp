#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
# include "avl_tree.hpp"
#include "bidirectional_iterator.hpp"
#include "../utils/make_pair.hpp"
#include "../utils/pair.hpp"
#include "../vector/vector.hpp"

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
            typedef ft::bidirectional_iterator<node_type, value_type> iterator;
            typedef ft::const_bidirectional_iterator<node_type, value_type> const_iterator;
            // typedef ft::reverse_iterator<iterator> reverse_iterator;
            // typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
            typedef ptrdiff_t difference_type;
            typedef class value_compare : public std::binary_function<value_type, value_type, bool>
            {
            protected:
                key_compare _compare;
            public:
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
            /* empty constructor */
            explicit map (const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type()):_tree(), _compare(comp), _allocator(alloc)
            {
                
            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type())
                {

                }

            map(const map &x)
            {
                *this = x;
            }

            // ! destructor
            ~map() {}

            // ! assignation operator
            map &operator=(const map &other)
            {
                if (this != &other)
                {
                    _tree = other._tree;
                    _compare = other._compare;
                    _allocator = other._allocator;
                }
                return *this;
            }
            /*              capacity            */
            bool empty() const
            {
                return (_tree.empty());
            }

            size_type size() const
            {
                return(_tree.size());
            }

            size_type max_size() const
            {
                return (this->_allocator.max_zize());
            }
            /*              Element access            */

            mapped_type& operator[] (const key_type& k)
            {
                ft::pair<key_type, mapped_type> p = ft::make_pair(k, mapped_type());
                _tree.insert(p);
                // std::cout << "first " << p.first << " second " << p.second << std::endl;
                node_type *node = _tree.search(_tree._root, p.first);
                return (node->_data->second);
            }

            /*             iterators            */

            iterator begin()
            {
                node_type *tmp = min_node(_tree._root);
                return (iterator(tmp, const_cast<node_type **>(&_tree._root)));
            }

            iterator end()
            {
                return iterator(NULL, const_cast<node_type **>(&_tree._root));
            }
            /*             modifiers            */

            void swap(map &other)
            {
                // std::swap(_tree, other._tree); // ! time out
                _tree.swap(other._tree);
                std::swap(this->_compare, other._compare);
                std::swap(this->_allocator, other._allocator);
            }

            void erase (iterator position)
            {
                value_type  a = *(position);
                _tree.remove(a.first);
            }

            size_type erase (const key_type& k)
            {
                return(_tree.remove(k));
            }

            void erase (iterator first, iterator last)
            {
                ft::vector<key_type> vect;
                while (first != last)
                {
                    vect.push_back(first->first);
                    first++;
                }
                typename ft::vector<key_type>::iterator it = vect.begin();
                while (it != vect.end())
                {
                    erase(*it);
                    it++;
                }
                // for (size_type i = 0; i < vect.size(); i++)
                // {
                //     erase(vect[i]);
                // }
            }

            pair<iterator,bool> insert (const value_type& val)
            {
                ft::pair<key_type, mapped_type> a = ft::make_pair(val.first, val.second);
                node_type   *node = _tree.search(_tree._root, val.first);
                if (node)
                {
                    return (pair<iterator, bool>(iterator(node, const_cast<node_type **>(&_tree._root)), false));
                }
                else
                {
                    _tree.insert(a);
                    node = _tree.search(_tree._root, val.first);
                    return(pair<iterator, bool>(iterator(node, const_cast<node_type **>(&_tree._root)), true));
                }
            }

            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                node_type *node = _tree.search(_tree._root, val.first);
                _tree.insert(val);
                return (iterator(node, &_tree._root));
            }

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for(; first != last; first++)
                    _tree.insert(*first);
            }

            void clear()
            {
                erase(begin(), end());
            }
            /*              Operations            */

            iterator find (const key_type& k)
            {
                node_type *tmp = _tree.search(_tree._root, k);
                if (tmp)
                    return iterator(tmp, &_tree._root);
                return (end());
            }

            const_iterator find (const key_type& k) const
            {
                node_type *tmp = _tree.search(_tree._root, k);
                if (tmp != NULL)
                    return const_iterator(tmp, const_cast<node_type **>(&_tree._root));
                return (end());
            }

            /*              Avl Treee            */

            // void insert(value_type value)
            // {
            //     _tree.insert(value);
            // }

            // void preOrder()
            // {
            //     _tree.preOrder(_tree._root);
            // }

            // void print()
            // {
            //     _tree.print2DUtil();
            // }

            // void remove(key_type value)
            // {
            //     _tree.remove(value);
            // }

            // node_type* search(key_type x)
            // {
            //     node_type* test =  _tree.search(_tree._root, x);
            //     return (test);
            // }
    };
}


#endif