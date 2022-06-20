#ifndef vector_HPP
#define vector_HPP

#include <iostream>
// #include <array>
// #include <memory>
#include "iterator.hpp"
#include "revers_iterator.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/is_integral.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef ft::iterator<value_type> iterator;
        typedef ft::iterator<const value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        typedef T *pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;

    private:
        size_type _capacity;
        size_type _size;
        pointer p;
        allocator_type allocc;

    public:
        class outofbounds : public std::exception
        {
        public:
            const char *what() const throw()
            {
                return ("index outofbounds");
            }
        };

        /*---------------------------- Constructors -------------------------*/

			//fill constructor, Constructs a container with n elements. Each element is a copy of val.

        explicit vector(const allocator_type &alloc = allocator_type()) : _capacity(0), _size(0), p(NULL), allocc(alloc)
        {
        }

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _capacity(0), _size(0), p(NULL), allocc(alloc)
        {
            if (n == 0)
                p = NULL;
            else
                p = allocc.allocate(n);
            // reserve(n);
            for (size_type i = 0; i < n; ++i)
                allocc.construct(&p[i], val);
            _size = n;
            _capacity = n;
        }

        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL) : _capacity(0), _size(0), p(NULL), allocc(alloc)
        {
            (void)f;
            reserve(last - first);
            for (; first != last; first++)
                allocc.construct(&p[_size++] , *first);
            // // ft::vector<value_type> vec;
            // // while (first != last)
            // // {
            // //     vec.push_back(*first);
            // //     first++;
            // // }
            // // if(vec.size() != 0)
            // //     insert(begin(), vec.begin(), vec.end());
            // // vec.clear();
            //     ft::vector<value_type> tmp;
            //     while (first != last)
            //     {


            //         tmp.push_back(*first);
            //         first++;
            //     }
            // std::cout << "yoo\n";

            //     if(tmp.size() != 0)
            //         insert(begin(), tmp.begin(), tmp.end());
            //     tmp.clear();
        }

        vector(const vector &x) : p(NULL), allocc(x.allocc)
        {
            *this = x;
        }
        /*---------------------------- Assignement operator -------------------------*/

        vector &operator=(const vector &x)
        {
            size_type i;
            if (_size != 0)
                allocc.deallocate(p, _size);
            _size = x._size;
            _capacity = x._capacity;
            p = allocc.allocate(_capacity);
            for (i = 0; i < _size; i++)
                allocc.construct(&p[i], x.p[i]);
            return (*this);
        }
        /*---------------------------- Destructor -------------------------*/

        ~vector()
        {
            for (size_type i = 0; i < _size; i++)
                allocc.destroy(&p[i]);
            allocc.deallocate(p, _capacity);
        }

        /*---------------------------- Capacity -------------------------*/

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (allocc.max_size());
        }

        size_type capacity() const
        {
            return (_capacity);
        }

        bool empty() const
        {
            if (_size == 0)
                return (1);
            else
                return 0;
        }

        void    reserve (size_type n)
        {
            if (n > _capacity)
            {
                pointer tmp = p;
                p = allocc.allocate(n);
                if (tmp != NULL)
                {
                    for (size_type i = 0; i < _size; i++)
                        allocc.construct(p + i, tmp[i]);
                    allocc.deallocate(tmp, _capacity);
                }
                _capacity = n;
            }
        }
        void resize(size_type n, value_type val = value_type())
        {
            size_type i;
            pointer tmp;
            tmp = p;
            if (n < _size)
            {
                for (i = n; i < _size; i++)
                    allocc.destroy(&p[i]);
                _size = n;
            }
            else if (n > _capacity)
            {
                if (n > (_capacity * 2))
                    reserve(n);
                else
                    reserve(_capacity * 2);
                for (i = _size; i < n; i++)
                    push_back(val);
            }
            else if (n > _size)
                for (i = _size; i < n; i++)
                    push_back(val);
        }

        /*---------------------------- Element access -------------------------*/

        reference at(size_type n)
        {
            if (n >= _size)
                throw std::out_of_range("vector");
            return (p[n]);
        }

        const_reference at(size_type _n) const
        {
            if (_n >= _size)
                throw std::out_of_range("vector");
            return (p[_n]);
        }

        reference operator[](size_type n)
        {
            return (p[n]);
        }

        const_reference operator[](size_type n) const
        {
            return (p[n]);
        }

        reference front()
        {
            return (p[0]);
        }
        const_reference front() const
        {
            return (p[0]);
        }

        reference back()
        {
            return (p[_size - 1]);
        }

        const_reference back() const
        {
            return (p[_size - 1]);
        }

        /*------------------Modifiers-------------------------*/

        void clear()
        {
            for (size_type i = 0; i < _size; i++)
                allocc.destroy(&p[i]);
            _size = 0;
        }

        void swap(vector &x)
        {
            pointer tmparr;
            size_type tmpcapacity;
            size_type tmpsize;

            tmparr = this->p;
            tmpcapacity = this->_capacity;
            tmpsize = this->_size;

            this->p = x.p;
            this->_capacity = x._capacity;
            this->_size = x._size;

            x.p = tmparr;
            x._capacity = tmpcapacity;
            x._size = tmpsize;
        }

        void push_back(const value_type &val)
        {
                if (_size == 0)
                    reserve(1);
                else if (_size == _capacity)
                    reserve(_capacity * 2);
                allocc.construct(p + _size, val);
                _size++;
    
        }

        void pop_back()
        {
            allocc.destroy(&p[_size]);
            _size--;
        }

        void assign(size_type n, const T &x)
        {
            if (n > _capacity)
            {
                allocc.deallocate(p, _capacity);
                p = allocc.allocate(n);
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                allocc.construct(&p[i] , x);
            _size = n;
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
        {
            (void)f;
            size_type n = last - first;
            if (n > _capacity)
            {
                allocc.deallocate(p, _capacity);
                p = allocc.allocate(n);
                _capacity = n;
            }
            for (size_type i = 0; i < n; ++i)
                allocc.construct(&p[i] , *first++);
            _size = n;
        }

        iterator erase(iterator pos)
        {
            for (size_type i = pos - p; i < _size - 1; ++i)
                p[i] = p[i + 1];
            _size--;
            return pos;
        }

        iterator erase(iterator first, iterator last)
        {
            size_type n = last - first;
            for (size_type i = first - p; i < _size - n; ++i)
                allocc.construct(&p[i] , p[i + n]);
            _size -= n;
            return first;
        }

        iterator insert(iterator position, const value_type &val)
        {
            size_type i = 0;
            size_type o = position - this->begin();
            if (_size == 0)
                push_back(val);
            else
            {
                if (_size + 1 > _capacity)
                    reserve(_capacity * 2);
                while (_size - i + 1 > 0)
                {
                    if (_size - i == o)
                    {
                        allocc.construct(&p[_size - i] , val);
                        break;
                    }
                    else
                        allocc.construct(&p[_size - i] , p[_size - i - 1]);
                    i++;
                }
                _size++;
            }
            return (p + o);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type o = position - this->begin();
            size_type i = 0;
            size_type k = n;
            if (_size + n > _capacity)
            {
                if (_size + n < _size * 2)
                    reserve(!(_size )? 1 : (_size * 2));
                else
                    reserve(!(_size + n)? 1 : (_size + n ));

            }
            while (_size - i + n > 0)
            {
                if (_size - i == o)
                {
                    while (k--)
                        allocc.construct(&p[_size - i + k] , val);
                    break;
                }
                else
                    allocc.construct(&p[_size - i + n - 1] , p[_size - i - 1]);
                i++;
            }
            _size += n;
        }

        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
        {
            (void)f;
            size_type n = std::distance(first, last);
            size_type i = 0;
            size_type pos = position - begin();
            if (_capacity < _size + n && n <= _size)
                reserve(_capacity * 2);
            else if (_size + n > _capacity)
                reserve(_capacity + n);
            while (_size + n - i > 0)
            {
                if (_size - i == pos)
                {
                    pos = n;
                    try
                    {
                        while (pos--)
                           allocc.construct(&p[_size - i + pos], *(--last));
                    }
                    catch (...)
                    {
                        for (size_type i = size(); i != 0; i--)
                        {

                            std::cout << "i =  " << i << std::endl;
                            allocc.destroy(&p[i - 1]);
                        }
                        _capacity = 0;
                        throw 3;
                    }
                    break;
                }
                else
                    allocc.construct(&p[_size - i + n - 1] ,  p[_size - i - 1]);
                i++;
            }
            _size += n;
        }

        /*------------------ Iterators -------------------------*/

        iterator begin()
        {
            return iterator(p);
        }

        const_iterator begin() const
        {
            return const_iterator(p);
        }

        iterator end()
        {
            return iterator(p + _size);
        }

        const_iterator end() const
        {
            return const_iterator(p + _size);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        /*------------------ Allocator -------------------------*/
        allocator_type get_allocator() const
        {
            return (allocc);
        }

        /*------------------ No member functions overload -------------------------*/
    };
    template <class M, class allocc>
    void swap(vector<M, allocc> &x, vector<M, allocc> &y)
    {
        x.swap(y);
    }

    template <class M, class alocc>
    bool operator==(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return (false);
        }
        return (true);
    }

    template <class M, class alocc>
    bool operator!=(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        return (!(lhs == rhs));
    }

    template <class M, class alocc>
    bool operator<(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        if (lhs.size() < rhs.size())
            return (true);
        else if (lhs.size() > rhs.size())
            return (false);
        size_t i;
        for (i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] < rhs[i])
                return (true);
            else if (lhs[i] > rhs[i])
                return (false);
        }
        return (false);
    }

    template <class M, class alocc>
    bool operator>(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        return (rhs < lhs);
    }

    template <class M, class alocc>
    bool operator<=(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        return (!(lhs > rhs));
    }

    template <class M, class alocc>
    bool operator>=(const ft::vector<M, alocc> &lhs, const ft::vector<M, alocc> &rhs)
    {
        return (!(rhs > lhs));
    }
}

/*---------------------- relational operators ------------------------*/

template <typename T>
std::ostream &operator<<(std::ostream &os, const ft::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); ++i)
        os << v[i] << " ";
    return os;
}

#endif
