#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../vector/iterator_traits.hpp"

namespace ft
{
    template <typename Node, typename Pair>
    class bidirectional_iterator
    {
    public:
        typedef Node *node_pointer;
        typedef Pair *pair_pointer; // more readable
        typedef Pair *pointer;      // for iterator traits
        typedef Pair &reference;    // for iterator traits
        typedef Pair value_type;
        typedef Pair &pair_reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef std::ptrdiff_t difference_type;
        node_pointer _node;
        node_pointer *_root;

    public:
        bidirectional_iterator() : _node(NULL), _root(NULL) {}

        bidirectional_iterator(node_pointer node, node_pointer *root) : _node(node), _root(root) {}

        bidirectional_iterator(const bidirectional_iterator &other)
        {
            *this = other;
        }

        bidirectional_iterator &operator=(const bidirectional_iterator &other)
        {
            _node = other._node;
            _root = other._root;
            return *this;
        }

        ~bidirectional_iterator() {}

        pair_reference operator*() const
        {
            return (*(_node->_data));
        }

        pair_pointer operator->() const
        {
            return _node->_data;
        }

        bidirectional_iterator &operator++()
        {
            _node = increment(_node, *_root);
            return *this;
        }

        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp = *this;
            _node = increment(_node, *_root);
            return tmp;
        }

        bidirectional_iterator &operator--()
        {
            _node = decrement(_node, *_root);
            return *this;
        }

        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator tmp = *this;
            _node = decrement(_node, *_root);
            return tmp;
        }

        // operator ==
        bool operator==(const bidirectional_iterator &other) const
        {
            return (_node == other._node);
        }

        // operator !=
        bool operator!=(const bidirectional_iterator &other) const
        {
            return (_node != other._node);
        }

        operator ft::bidirectional_iterator<Node, const Pair>()
        {
            return ft::bidirectional_iterator<Node, const Pair>(_node, _root);
        }
    };

    template <typename Node, typename Pair>
    class const_bidirectional_iterator
    {
    public:
        typedef Node *node_pointer;
        typedef Pair *pair_pointer;
        typedef Pair *pointer;   // for iterator traits
        typedef Pair &reference; // for iterator traits
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef Pair value_type;
        typedef Pair &pair_reference;
        typedef std::ptrdiff_t difference_type;
        typedef ft::bidirectional_iterator<Node, Pair> bidirectional_iterator;
        node_pointer _node;
        node_pointer *_root;

        const_bidirectional_iterator() : _node(NULL), _root(NULL) {}

        const_bidirectional_iterator(node_pointer node, node_pointer *root) : _node(node), _root(root) {}

        const_bidirectional_iterator(Node node, node_pointer root) : _node(node), _root(root) {}

        const_bidirectional_iterator(const bidirectional_iterator &other)
        {
            _node = other._node;
            _root = other._root;
        }

        const_bidirectional_iterator(const const_bidirectional_iterator &other)
        {
            *this = other;
        }

        const_bidirectional_iterator &operator=(const const_bidirectional_iterator &other)
        {
            _node = other._node;
            _root = other._root;
            return *this;
        }

        ~const_bidirectional_iterator() {}

        pair_reference operator*() const
        {
            return *_node->_data;
        }

        pair_pointer operator->() const
        {
            return _node->_data;
        }

        const_bidirectional_iterator &operator++()
        {
            // use tree increment
            _node = increment(_node, *_root);
            return *this;
        }

        const_bidirectional_iterator operator++(int)
        {
            const_bidirectional_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        const_bidirectional_iterator &operator--()
        {
            _node = decrement(_node, *_root);
            return *this;
        }

        const_bidirectional_iterator operator--(int)
        {
            const_bidirectional_iterator tmp = *this;
            _node = decrement(_node, *_root);
            return tmp;
        }

        // operator ==
        bool operator==(const const_bidirectional_iterator &other) const
        {
            return (_node == other._node);
        }

        // operator !=
        bool operator!=(const const_bidirectional_iterator &other) const
        {
            return (_node != other._node);
        }

        operator ft::bidirectional_iterator<Node, const Pair>()
        {
            return ft::bidirectional_iterator<Node, const Pair>(_node, _root);
        }
    };
}

#endif