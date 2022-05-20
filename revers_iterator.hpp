#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::difference_type difference_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;

    private:
        iterator_type _it;

    public:
        reverse_iterator() : _it() {}
        explicit reverse_iterator(iterator_type it) : _it(it) {}
        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _it(rev_it.base()) {}
        // base
        iterator_type base() const { return _it; }
        
        reference operator*() const
        {

            iterator_type tmp = _it;
            return *--tmp;
            
            // return *(_it - 1);
            // it returns it -  1 because reverse iterator points to the element before the current one
        }
        reverse_iterator &operator++()
        {
            --_it;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            --_it;
            return tmp;
        }
        reverse_iterator &operator--()
        {
            ++_it;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++_it;
            return tmp;
        }
        bool operator==(const reverse_iterator &obj) const
        {
            return _it == obj._it;
        }
        bool operator!=(const reverse_iterator &obj) const
        {
            return _it != obj._it;
        }
        pointer operator->() const
        {
            iterator_type tmp(_it);
            --tmp;
            return tmp.operator->();
        }
        reference operator[](difference_type n) const
        {
            return *(_it - n - 1);
        }
        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(_it - n);
        }
        // reverse_iterator operator-(difference_type n) const
        // {
        //     return reverse_iterator(_it + n);
        // }

        reverse_iterator operator-(difference_type n) const
        {
            reverse_iterator tmp(_it + n);
            return (tmp);
        }

        reverse_iterator &operator+=(difference_type n)
        {
            _it -= n;
            return *this;
        }
        reverse_iterator &operator-=(difference_type n)
        {
            _it += n;
            return *this;
        }
        operator iterator<const value_type>()
        {
            return iterator<const value_type>(_it);
        }
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() == rhs.base();
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() != rhs.base();
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() > rhs.base();
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() >= rhs.base();
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() < rhs.base();
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return lhs.base() <= rhs.base();
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> &rev_it)
    {
        return rev_it + n;
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
    {
        return rhs.base() - lhs.base();
    }
}

#endif