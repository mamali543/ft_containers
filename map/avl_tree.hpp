#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>

namespace ft{
    template <typename Pair>
    class Node
    {
    public:
        Pair *_data;
        Node<Pair> *_left;
        Node<Pair> *_right;
        Node<Pair> *_parent;
        int _height;
        int _balance_factor;
        Node() {}
        ~Node() {}
    };

    template <class T>
    Node<T> *min_node(Node<T> *node)
    {
        if (!node)
            return(node);
        while (node->_left)
            node = node->_left;
        return (node);
    }

    template <class T>
    Node<T> *max_node(Node<T> *node)
    {
        if (!node)
            return (node);
        while (node->_right)
            node = node->_right;
        return (node);
    }

    template <class T>
    Node<T> *increment(Node<T> *node, Node<T> *root)
    {
        if (!node)
            node = min_node(root);
        else
        {
            if (node->_right)
            {
                node = node->_right;
                while (node->_left)
                    node = node->_left;
            }
            else
            {
                Node<T> *tmp = node->_parent;
                while (tmp && node == tmp->_right)
                {
                    node = tmp;
                    tmp = node->_parent;
                }
                node = tmp;
            }
        }
        return(node);
    }

    template <class T>
    Node<T> *decrement(Node<T> *node, Node<T> *root)
    {
        if (!node)
            node = max_node(root);
        else
        {
            if (node->_left)
            {
                node = node->_left;
                while (node->_right)
                    node = node->_left;
            }
            else
            {
                Node<T> *tmp = node->_parent;
                while (tmp && node == tmp->_left)
                {
                    node = tmp;
                    tmp = node->_parent
                }
                node = tmp;
            }
        }
        return(node);
    }
    template < class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
        class Compare = std::less<Key>,                     // map::key_compare
        class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
        > class avl_tree
    {
    public:
        typedef Mapped_Type mapped_type;
        typedef Alloc allocator_type;
        typedef Key key_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Node<value_type> node_type;
        // typedef typename Alloc::template rebind<node_type>::other node_allocator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        node_type *_root;
        typedef bidirectional_iterator<node_type, value_type> iterator;
    private:
        size_type _size;
        Compare _compare;
        allocator_type _pair_allocator;
        // node_allocator _node_allocator;

        int tree_height(node_type* root) {
            if (!root)
                return 0;
            else {
                int left_height = tree_height(root->left);
                int right_height = tree_height(root->right);
                if (left_height >= right_height)
                    return left_height + 1;
                else
                    return right_height + 1;
            }
        }
    };
}


#endif