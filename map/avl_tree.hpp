#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#define DEFAULT "\e[0;37m"
#define GREEN "\e[1;32m"
#define RED "\e[1;31m"

#include <iostream>
#include "../utils/pair.hpp"

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
                    tmp = node->_parent;
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
        typedef T mapped_type;
        typedef Alloc allocator_type;
        typedef Key key_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Node<value_type> node_type;
        typedef typename Alloc::template rebind<node_type>::other node_allocator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        node_type *_root;
        // typedef bidirectional_iterator<node_type, value_type> iterator;
    private:
        size_type _size;
        Compare _compare;
        bool __exists(node_type    *node, key_type k)const
        {
            if (!node)
                return (false);
            else if(equal(node->_data->first, k))
                return (true);
            else if (_compare(node->_data->first, k))
                return (__exists(node->_right, k));
            else
                return(__exists(node->_left, k));

        }
        allocator_type _pair_allocator;
        node_allocator _node_allocator;

        /*                 help methods                   */
        
        int tree_height(node_type* node) 
        {
            if (!node)
                return 0;
            else {
                int left_height = tree_height(node->left);
                int right_height = tree_height(node->right);
                if (left_height >= right_height)
                    return left_height + 1;
                else
                    return right_height + 1;
            }
        }

        int height() const
        {
            if (_root == NULL)
                return 0;
            return _root->_height;
        }


        bool equal(const key_type &keya, const key_type &keyb) const
        {
            return(_compare(keya, keyb) == false && _compare(keyb, keya) == false);
        }

        node_type   *max(node_type *node)const
        {
            while (node->_right)
                node = node->_right;
            return (node);
        }

        node_type   *min(node_type *node)const
        {
            while (node->_left)
                node = node->_left;
            return (node);
        }


        void swap(avl_tree &other)
        {
            std::swap(_size, other._size);
            std::swap(_root, other._root);
            std::swap(_compare, other._compare);
        }

    public:
        bool exists(key_type elem) const 
        {
            return (__exists(_root, elem));
        }
        avl_tree() : _root(NULL), _size(0), _compare(), _node_allocator(), _pair_allocator() {}

        avl_tree(const avl_tree &other) : _root(NULL), _size(other._size)
        {
            *this = other;
        }

        avl_tree(const Compare &comp, const allocator_type &alloc) : _root(NULL), _compare(comp), _pair_allocator(alloc), node_allocator(alloc) {}

        avl_tree &operator=(const avl_tree &other)
        {
            clear();
            node_type *tmp = other._root;
            copy(tmp);
            return *this;
        }

        void clear()
        {
            free_node(_root);
            _size = 0;
        }

        void free_node(node_type *node)
        {
            if (node)
            {
                node->_left = NULL;
                node->_right = NULL;
                _pair_allocator.destroy(node->_data);
                _pair_allocator.deallocate(node->_data, 1);
                _node_allocator.deallocate(node, 1);
            }
            node = NULL;
        }

        void copy(node_type *node)
        {
            if (node != NULL)
            {
                insert(*(node->_data));
                copy(node->_left);
                copy(node->_right);
            }
        }

        /*                 Search                   */

        Node<T> *search(Node<T> *node, key_type key)
        {
            if (!node)
                return (NULL);
            if (node->_data->first == key)
                return (node);
            else
            {
                if (_compare(node->_data->first, key))
                    return(search(node->_left, key));
                else
                    return(search(node->_right, key));
            }
        }
        /*                 Insert                   */
        node_type   *newNode(value_type x)
        {
            node_type *tmp = _node_allocator.allocate(1);
        _pair_allocator.allocate(1);
           tmp->_data = &x;
            tmp->_left = NULL;
            tmp->_right = NULL;
            tmp->_parent = NULL;
            tmp->_height = 0;
            tmp->_balance_factor = 0;
            return(tmp);
        }

        void    update(node_type *node)
        {
            int leftheight = (node->_left == NULL) ? -1 : node->_left->_height;
            int rightheight = (node->_right == NULL) ? -1 : node->_right->_height;
            node->_height = std::max(rightheight, leftheight) + 1;
            node->_balance_factor = rightheight - leftheight;
        }

        node_type *insert(node_type *node, value_type x)
        {
            std::cout << "yooooooo\n";
            if (node == NULL)
                return (newNode(x));
            if (_compare(node->_data->first, x.first))
            {
                node->_right = insert(node->_right, x);
                node->_right->_parent = node;
            }
            else if (_compare(x.first, node->_data->first))
            {
                node->_left = insert(node->_left, x);
                node->_left->_parent = node;
            }
            update(node);
            return balance(node);
        }

        bool    insert(value_type x)
        {
            if (!exists(x.first))
            {
                _root = insert(_root, x);
                _size++;
                return(true);
            }
            return (false);
        }
        /*                 Balance                   */
        node_type *right_rotate(node_type *node)
        {
            node->_left = node->_left->_right;
            if (node->_left->_right)
                node->_left->_right->_parent = node;
            node->_parent = node->_left;
            if (!node->_parent)
                _root = node->_left;
            else if (node == node->_parent->_left)
                node->_parent->_left = node->_left;
            else
                node->_parent->_right = node->_left;
            node->_left->_right = node;
            node->_left->_parent = node->_parent;
            update(node);
            update(node->_left);
            return (node->_left);
        }

        node_type *left_rotate(node_type *node)
        {
            node->_right = node->_right->_left;
            if (node->_right->_left)
                node->_right->_left->_parent = node;
            node->_parent = node->_right;
            if (!node->_parent)
                _root = node->_right;
            else if (node == node->_parent->_left)
                node->_parent->_left = node->_right;
            else
                node->_parent->_right = node->_right;
            node->_right->_left = node;
            node->_right->_parent = node->_parent;
            update(node);
            update(node->_right);
            return (node->_right);
        }

        node_type *lr_rotate(node_type *node)
        {
            node->_left = left_rotate(node->_left);
            return (right_rotate(node));
        }

        node_type *rl_rotate(node_type *node)
        {
            node->_right = right_rotate(node->_right);
            return (left_rotate(node));
        }

        node_type *balance(node_type *node)
        {
            if (node->_balance_factor < -1)
            {
                if (node->_left->_balance_factor <= 0)
                    return (left_rotate(node));
                else
                    return(lr_rotate(node));
            }
            else if(node->_balance_factor > 1)
            {
                if (node->_right->_balance_factor >= 0)
                    return(right_rotate(node));
                else
                    return (rl_rotate(node));
            }
            return (node);
        }
        /*           
              Remove                   */
        node_type *remove(node_type *node, key_type key)
        {
            if (node == NULL)
                return (NULL);
            if (_compare(node->_data->first, key))
                node->_right = remove(node->_right, key);
            else if (_compare(key, node->_data->first))
                node->_left = remove(node->_left, key);
            else
            {
                if (!node->_left && node->_right)
                {
                    node->_right->_parent = node->_parent;
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data,*( node->_right->_data));
                    _pair_allocator.destroy(node->_right->_data);
                    _pair_allocator.deallocate(node->_right->_data, 1);
                    _node_allocator.deallocate(node->_right, 1);
                    node->_right = NULL;
                }
                else if (node->_left && !node->_right)
                {
                    node->_left->_parent = node->_parent;
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(node->_left->_data));
                    _pair_allocator.destory(node->_left->_data, 1);
                    _pair_allocator.deallocate(node->_left->_data, 1);
                    _node_allocator.deallocate(node->_left, 1);
                    node->_left = NULL;
                }
                else if(!node->_left && !node->_right)
                {
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.deallocate(node->_data, 1);
                    _node_allocator.deallocate(node, 1);
                    node = NULL;
                }
                else
                {
                    node_type   *n = min_node(node->_right);
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(n->_data));
                    node->_right = remove(node->_right, n->_data->first);
                }
            }
            update(node);
            return(balance(node));
        }

        bool remove(key_type key)
        {
            if (!exists(key))
                return false;
            _root = remove(_root, key);
            _size--;
            return true;
        }

        void printTree(node_type *node, std::string indent, bool last)
        {
            (void)last;
            if (node != NULL)
            {
                std::cout << RED << indent << DEFAULT;
                if (last)
                {
                    std::cout << GREEN << "R---- " << DEFAULT;
                    indent += "   ";
                }
                else
                {
                    std::cout << RED << "L---- " << DEFAULT;
                    indent += "|  ";
                }
                std::cout << node->_data->first << std::endl;
                printTree(node->_left, indent, false);
                printTree(node->_right, indent, true);
            }
        }

        void print_it(avl_tree<int, int> &tree)
        {
            tree.printTree(tree._root, "", true);
        }

    };
}

#endif