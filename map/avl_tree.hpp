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
        typedef typename Alloc::template rebind<node_type>::other node_allocator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        node_type *_root;
        // typedef bidirectional_iterator<node_type, value_type> iterator;
    private:
        size_type _size;
        Compare _compare;
        allocator_type _pair_allocator;
        node_allocator _node_allocator;

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

        /*                 help methods                   */
        bool equal(const key_type &keya, const key_type &keyb)
        {
            return(_compare(keya, keyb) == false && _compare(keyb, keya) == false);
        }

        bool exist(node_type    *node, key_type k)
        {
            if (!node)
                return (false);
            else if(equal(node->_data->first, k))
                return (true);
            else if (_compare(node->_data->first, k))
                return (exist(node->_right, k);
            else
                return(exist(node->_left, k));

        }
    public:
        avl_tree() : _root(NULL), _size(0), _compare(), _pair_allocator() {}

        avl_tree(const avl_tree &other) : _root(NULL), _size(other._size)
        {
            *this = other;
        }

        avl_tree(const Compare &comp, const allocator_type &alloc) : _root(NULL), _compare(comp), _pair_allocator(alloc) {}

        avl_tree &operator=(const avl_tree &other)
        {
            clear();
            node_type *tmp = other._root;
            copy(tmp);
            return *this;
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
            node_type *tmp = node_allocator.alloc(1);
            tmp->_data = _pair_allocator.allocate(1);
            _pair_allocator.construct(tmp->_data, x);
            tmp->_left = NULL;
            tmp->_right = NULL;
            tmp->_parent = NULL;
            tmp->_height = 0;
            tmp->_balance_factor = 0;
            return(tmp);
        }

        node_type *insert(node_type *node, value_type x)
        {
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
        }

        bool    insert(value_type x)
        {
            if (x == NULL)
                return (false);
            if (!exist(x.first))
            {
                _root = insert(_root, x);
                _size++;
                return(true);
            }
            return (false);
        }

        void    update(node_type *node)
        {
            int leftheight = (node->_left == NULL) ? -1 : node->_left->_height;
            int rightheight = (node->_right == NULL) ? -1 : node->_right->_height;
            node->_height = std::max(rightheight, leftheight) + 1;
        }
    };
}


#endif