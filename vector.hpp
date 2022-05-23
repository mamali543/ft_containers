#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <array>
#include <memory>
#include "iterator.hpp"
#include "revers_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class vector
{
	public :
    typedef T                                        	value_type;
    typedef Alloc 										allocator_type;
    typedef value_type&                            	  	reference;
    typedef const value_type&                       	const_reference;
    typedef ft::iterator<value_type>                    iterator;
    typedef ft::iterator<const value_type>              const_iterator;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef T *pointer;
    // typedef typename __alloc_traits::const_pointer   	const_pointer;
    typedef std::size_t 								size_type;
    private:
        size_type _capacity;
        size_type _size;
        pointer p;
        allocator_type allocc;
    public:

    class outofbounds : public std::exception
    {   public : 
            const char* what() const throw()
            {
                return("index outofbounds");
            }
    };

    /*---------------------------- Constructors -------------------------*/
    explicit vector (const allocator_type& alloc = allocator_type()): _capacity(0), p(NULL), _size(0), allocc(alloc)
    {

    }

    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(0), p(NULL), allocc(alloc), _capacity(0)
    {
        reserve(n);
        for (size_type i = 0; i < n; ++i)
            p[i] = val;
        _size = n;
    }

    vector (const vector& x) : p(NULL), allocc(x.allocc)
	{
		*this = x;
	}
    /*---------------------------- Assignement operator -------------------------*/
    
    vector& operator= (const vector& x)
    {
        size_type i;
        if (_size != 0)
            allocc.deallocate(p, _size);
        _size = x._size;
        _capacity = x._capacity;
        p = allocc.allocate(_capacity);
        for (i = 0; i < _size; i++)
            p[i] = x.p[i];
        return (*this);
    }
    /*---------------------------- Destructor -------------------------*/

    ~vector()
    {
        if (_capacity != 0)
            allocc.deallocate(p, _size);
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

    void reserve (size_type n)
    {
        pointer tmp;
        size_type   i;
        // tmp = p;
        if (n > max_size())
            throw std::length_error("length error");
        else if (n > _capacity)
        {
            pointer tmp = allocc.allocate(n);
            for (i = 0; i < _size ; i++)
                tmp[i] = p[i];
            allocc.deallocate(p, _size);
            p = tmp;
            _capacity = n;
        }
    }

    void resize (size_type n, value_type val = value_type())
    {
        size_type   i;
        pointer tmp;
        tmp = p;
        if (n < _size)
        {
            for (i = n; i < _size ; i++)
                allocc.destroy(&p[i]);
            _size = n;
        }
        else if (n > _capacity)
        {
            if (n > (_capacity * 2))
                reserve(n);
            else
                reserve(_capacity * 2);
            for (i = _size; i < n ; i++)
                push_back(val);
        }
        else if (n > _size)
            for (i = _size; i < n; i++)
                push_back(val);
    }

    /*---------------------------- Element access -------------------------*/

    reference at (size_type n)
    {
        if (n < _size)
            return (p[n]);
        throw outofbounds();

    }

    const_reference at (size_type _n) const
	{
		if (_n < _size)
			return (p[_n]);
		throw outofbounds();
	}

    reference operator[] (size_type n)
    {
        return (p[n]);
    }

    const_reference operator[] (size_type n) const
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

    void swap (vector& x)
    {
        vector  tmp;

        tmp = *this;
        *this = x;
        x = tmp;
    }

    void push_back(const value_type &val)
    {
        if (_size + 1 > _capacity)
            reserve(!_capacity   ? 1 : _capacity * 2);
        p[_size++] = val;
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
            p[i] = x;
        _size = n;
    }

    template <class InputIterator>
    void assign (InputIterator first, InputIterator last, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type *f = NULL)
    {
        size_type n = last - first;
        if (n > _capacity)
        {
            allocc.deallocate(p, _capacity);
            p = allocc.allocate(n);
            _capacity = n;
        }
        for (size_type i = 0; i < n; ++i)
            p[i] = *first++;
        _size = n;

    }

    iterator erase (iterator pos)
    {
        for (size_type i = pos - p; i < _size - 1; ++i)
            p[i] = p[i + 1];
        _size--;
        return pos;
    }

    iterator erase (iterator first, iterator last)
    {
        size_type i = 0;
        size_type j = 0;
        size_type n = first - this->begin();
        size_type a = last - first;
        while (i < n)
            i++;
        n = this->size() - a;
        while (j < n)
        {
            p[i] = p[i+a];
            i++;
            j++;
        }
        _size -= a;
        return (first);
    }

    iterator insert (iterator position, const value_type& val)
    {
        _size++;
        size_type j = this->size();
        size_type i = 0;
        size_type o = position - this->begin();
        pointer   tmp = allocc.allocate(j + 1);
        while (i < _size)
        {
            if (i == o)
                tmp[i] = val;
            else
            {
                if (!i)
                    tmp[i] = p[i];
                else
                    tmp[i] = p[i - 1];
            }
            i++;
        }
        allocc.deallocate(p, j);
        p = tmp;
        return (p + o);
    }

    void insert (iterator position, size_type n, const value_type& val)
    {
        
    }

/*------------------ Iterators -------------------------*/

    iterator begin()
    {
        return iterator(p);
    }

    const_iterator begin() const
    {
        return (p);
    }

    iterator end()
    {
        return iterator(p + _size);
    }

    const_iterator end() const
    {
        return (p + _size);
    }

    reverse_iterator rbegin()
    {
        return reverse_iterator(end());
    }

    // const_reverse_iterator rbegin() const
    // {
    //     return reverse_iterator(end());
    // }
    
    reverse_iterator rend()
    {
        return reverse_iterator(begin());
    }

    // const_reverse_iterator rend() const
    // {
    //     return reverse_iterator(begin());
    // }

/*------------------ Allocator -------------------------*/

    allocator_type get_allocator() const
    {
        return (allocc);
    }

/*------------------ No member functions overload -------------------------*/

// template <class T, class Alloc>
//   void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
//   {
//       x.swap(y);
//   };

};
}

#endif

