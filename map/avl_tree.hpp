#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#define DEFAULT "\e[0;37m"
#define GREEN "\e[1;32m"
#define RED "\e[1;31m"

#include <iostream>
#include "../utils/pair.hpp"
#include "../utils/make_pair.hpp"
#include "bidirectional_iterator.hpp"

namespace ft
{
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
    template <class U>
    Node<U> *increment(Node<U> *node, Node<U> *root)
    {
        if (!node)
            node = min_node(root);
        else
        {
            if (node->_right)
            {
                node = min_node(node->_right);
            }
            else
            {
                Node<U> *tmp = node->_parent;
                while (tmp && node == tmp->_right)
                {
                    node = tmp;
                    tmp = node->_parent;
                }
                node = tmp;
            }
        }
        return (node);
    }

    template <class U>
    Node<U> *decrement(Node<U> *node, Node<U> *root)
    {
        if (!node)
            node = max_node(root);
        else
        {
            if (node->_left)
            {
                node = max_node(node->_left);
            }
            else
            {
                Node<U> *tmp = node->_parent;
                while (tmp && node == tmp->_left)
                {
                    node = tmp;
                    tmp = node->_parent;
                }
                node = tmp;
            }
        }
        return (node);
    }

    template <class Key,                                           // map::key_type
              class T,                                             // map::mapped_type
              class Compare = std::less<Key>,                      // map::key_compare
              class Alloc = std::allocator<ft::pair<const Key, T> > // map::allocator_type
              >
    class avl_tree
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
        typedef bidirectional_iterator<node_type, value_type> iterator;

    private:
        size_type _size;
        Compare _compare;
        allocator_type _pair_allocator;
        node_allocator _node_allocator;

        bool __exists(node_type *node, key_type k) const
        {
            if (node == NULL)
                return (false);
            if (equall(node->_data->first, k))
                return (true);
            if (!_compare(k, node->_data->first))
                return (__exists(node->_right, k));
            else
                return (__exists(node->_left, k));
            return (false);
        }

    public:
        bool exists(key_type elem) const
        {
            return (__exists(_root, elem));
        }

        avl_tree() : _root(NULL), _size(0), _compare(), _pair_allocator(), _node_allocator() {}

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
        ~avl_tree()
        {
            clear();
        }

        void clear()
        {
            if (_root)
            {
                free_node(_root);
                _root = NULL;
            }
            _size = 0;
        }

        void free_node(node_type *node)
        {
            if (node)
            {
                free_node(node->_right);
                free_node(node->_left);
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

        int tree_height(node_type *node)
        {
            if (!node)
                return 0;
            else
            {
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

        bool equall(const key_type &keya, const key_type &keyb) const
        {
            return (_compare(keya, keyb) == false && _compare(keyb, keya) == false);
        }
        /*                 Search                   */
        node_type *search(node_type *node, key_type key) const
        {
            if (node == NULL)
                return (node);
            if (equall(key, node->_data->first))
                return (node);
            else
            {
                if (!_compare(node->_data->first, key))
                    return (search(node->_left, key));
                else
                    return (search(node->_right, key));
            }
            // return (NULL);
        }
        /*                 Insert                   */
        node_type *newNode(value_type x)
        {
            node_type *tmp = _node_allocator.allocate(1);
            tmp->_data = _pair_allocator.allocate(1);
            _pair_allocator.construct(tmp->_data, x);
            tmp->_left = NULL;
            tmp->_right = NULL;
            tmp->_parent = NULL;
            tmp->_height = 0;
            tmp->_balance_factor = 0;
            return (tmp);
        }

        void update(node_type *node)
        {
            int leftheight = (node->_left == NULL) ? -1 : node->_left->_height;
            int rightheight = (node->_right == NULL) ? -1 : node->_right->_height;
            node->_height = std::max(rightheight, leftheight) + 1;
            node->_balance_factor = rightheight - leftheight;
        }

        node_type *insert(node_type *node, value_type x)
        {
            if (node == NULL)
                return (newNode(x));
            else if (_compare(x.first, node->_data->first))
            {
                node->_left = insert(node->_left, x);
                node->_left->_parent = node;
            }
            else
            {
                node->_right = insert(node->_right, x);
                node->_right->_parent = node;
            }
            update(node);
            return balance(node);
        }

        bool insert(value_type x)
        {
            if (!exists(x.first))
            {
                _root = insert(_root, x);
                _size++;
                return (true);
            }
            return (false);
        }
        /*                 Balance                   */
        node_type *right_rotate(node_type *node)
        {
            node_type *tmp = node->_left;
            node->_left = tmp->_right;
            if (tmp->_right != NULL)
                tmp->_right->_parent = node;
            tmp->_right = node;
            tmp->_parent = node->_parent;
            node->_parent = tmp;
            if (tmp->_parent != NULL)
            {
                if (_compare(node->_data->first, tmp->_parent->_data->first) == true)
                    tmp->_parent->_left = tmp;
                if (_compare(tmp->_parent->_data->first, node->_data->first) == true)
                    tmp->_parent->_right = tmp;
            }
            update(node);
            update(tmp);
            return tmp;
        }
        node_type *left_rotate(node_type *node)
        {
            node_type *tmp = node->_right;
            node->_right = tmp->_left;
            if (tmp->_left != NULL)
                tmp->_left->_parent = node;
            tmp->_left = node;
            tmp->_parent = node->_parent;
            node->_parent = tmp;
            if (tmp->_parent != NULL)
            {
                if (_compare(node->_data->first, tmp->_parent->_data->first) == true)
                    tmp->_parent->_left = tmp;
                if (_compare(tmp->_parent->_data->first, node->_data->first) == true)
                    tmp->_parent->_right = tmp;
            }
            update(node);
            update(tmp);
            return tmp;
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
                    return (right_rotate(node));
                else
                    return (lr_rotate(node));
            }
            else if (node->_balance_factor > 1)
            {
                if (node->_right->_balance_factor >= 0)
                    return (left_rotate(node));
                else
                    return (rl_rotate(node));
            }
            return (node);
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
        void preOrder(node_type *root)
        {
            if (root != NULL)
            {
                std::cout << root->_data->first << " ";
                preOrder(root->_left);
                preOrder(root->_right);
            }
        }

        // Driver Code
        void print2DUtil(node_type *root, int space)
        {
            // Base case
            if (root == NULL)
                return;

            // Increase distance between levels
            space += 10;

            // Process right child first
            print2DUtil(root->_left, space);

            // Print current node after space
            // 10
            std::cout << std::endl;
            for (int i = 10; i < space; i++)
                std::cout << " ";
            std::cout << root->_data->first << "\n";

            // Process left child
            print2DUtil(root->_right, space);
        }

        void print2DUtil()
        {
            std::cout << "SIZE: " << this->_size << std::endl;
            std::cout << "\n\n";
            print2DUtil(this->_root, 1);
            std::cout << "\n\n";
        }

        void printBT(const std::string &prefix, const node_type *_node, bool isLeft)
        {
            if (_node != NULL)
            {
                std::cout << prefix;
                std::cout << (_node->_parent == NULL ? "\e[1;35m[R]" : (isLeft ? "\e[1;32m├──[L]" : "\e[1;34m└──[R]"));
                std::cout << "[" << _node->_data->second << "]\n";
                printBT(prefix + (isLeft ? "│   " : "   "), _node->_left, true);
                printBT(prefix + (isLeft ? "│   " : "   "), _node->_right, false);
                // if (_node->parent != NULL )
                //     std::cout <<"node : " << _node->data->first << " parent : " << _node->parent->data->first << "\n";
            }
            else
                return;
        }

        void printBT()
        {
            std::cout << "SIZE: " << this->_size << std::endl;
            std::cout << "\n\n";
            printBT("", this->_root, false);
            std::cout << "\n\n";
        }

        int size() const
        {
            return (this->_size);
        }
        /*                Remove                   */
        node_type *remove(node_type *node, key_type key)
        {
            // std::cout << "hey\n";
            if (node == NULL)
                return (NULL);

            if (_compare(node->_data->first, key))
                node->_right = remove(node->_right, key);
            else if (_compare(key, node->_data->first))
            {
                node->_left = remove(node->_left, key);
            }
            else
            {
                if (!node->_left && node->_right)
                {
                    node->_right->_parent = node->_parent;
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(node->_right->_data));
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
                    _pair_allocator.destroy(node->_left->_data);
                    _pair_allocator.deallocate(node->_left->_data, 1);
                    _node_allocator.deallocate(node->_left, 1);
                    node->_left = NULL;
                }
                else if (!node->_left && !node->_right)
                {
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.deallocate(node->_data, 1);
                    _node_allocator.deallocate(node, 1);
                    node = NULL;
                    return (NULL);
                }
                else
                {
                    node_type *n = min_node(node->_right);
                    _pair_allocator.destroy(node->_data);
                    _pair_allocator.construct(node->_data, *(n->_data));
                    node->_right = remove(node->_right, n->_data->first);
                }
            }
            update(node);
            return (balance(node));
        }

        bool remove(key_type key)
        {

            if (!exists(key))
                return false;
            // std::cout << "hey\n";

            _root = remove(_root, key);
            _size--;
            return true;
        }

        /*                 help methods                   */
        node_type *max(node_type *node) const
        {
            while (node->_right)
                node = node->_right;
            return (node);
        }

        // node_tyoe   *lower_bound(node_type *node, key_type  k)
        // {
        //     node_type *n = min_node(node);
        //     while (n)
        //     {
        //         if (n->_data->first >= k)
        //             return (n);

        //     }

        // }

        node_type *min(node_type *node) const
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

        bool empty() const
        {
            return (_size == 0);
        }
    };

    template <class U>
    Node<U> *min_node(Node<U> *node)
    {
        if (!node)
            return (node);
        while (node->_left)
            node = node->_left;
        return (node);
    }

    template <class U>
    Node<U> *max_node(Node<U> *node)
    {
        if (!node)
            return (node);
        while (node->_right)
            node = node->_right;
        return (node);
    }

}

#endif