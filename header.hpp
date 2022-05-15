#include <iostream>
#include <array>
#include <memory>

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
    typedef typename __alloc_traits::pointer        	pointer;
    typedef typename __alloc_traits::const_pointer   	const_pointer;
    typedef std::size_t 								size_type;
    private:
        size_type value;
        size_type size;
        value_type *p;
        allocator_type allocc;
    public:

    class outofbounds : public std::exception
    {   public : 
            const char* what() const throw()
            {
                return("index outofbounds");
            }
    };
    explicit vector (const allocator_type& alloc = allocator_type()): value(0), p(NULL), size(0)
    {

    }

    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): size(n), p(NULL), allocc(alloc)
    {
        size_type i;
        p = allocc.allocate(n);
        for (i = 0; i < n; i++)
        {
            p.construct(&p[i], val);
        }
    }

    Vector (const Vector& x) : p(NULl), allocc(x.allocc)
	{
		*this = x;
	}
    
    vector& operator= (const vector& x)
    {
        size_type i;
        if (size != 0)
            allocc.deallocate(p, size);
        size = x.size;
        p = allocc.allocate(size);
        for (i = 0; i < size; i++)
        {
            p.construct(&p[i], x[i]);
        }
        return (*this);
    }

    ~vector()
    {
        if (size != 0)
            allocc.deallocate(p, size);
    }

    size_type size() const
    {
        retunr (size);
    }

    size_type max_size() const
	{
		return (allocc.max_size());
	}

    size_type capacity() const
    {
        return (size);
    }

    bool empty() const
	{
		if (size == 0)
			return (1);
		else
			return 0;
	}

    void reserve (size_type n)
    {
        value_type *tmp;
        size_type   i;
        tmp = p
        if (n > size)
        {
            p = allocc.allocate(p, n);
            for (i = 0; i < n; i++)
            {
                allocc.construct(&p[i], tmp[i]);
            }
            if (size > 0)
                allocc.deallocate(tmp, size);
            size = n;
        }
    }

    void resize (size_type n, value_type val = value_type())
    {
        size_type   i;
        value_type  *tmp;
        tmp = p
        if (n < size)
        {
            for (i = 0; i < n ; i++)
            {
                allocc.construct(&p[i], val);
            }
        }
        else if (n > 0)
        {
            p = allocc.allocate(n);
            for (i = 0; i < n; i++)
            {
                if (i < size)
                {
                    allocc.construct(&p[i], tmp[i]);
                }
                else
                    allocc.construct(&p[i], val);
            }
            if (size > 0)
                allocc.deallocate(tmp, size);
            size = n;
        }
        else
            p = NULL;
        value = n;
    }
/*------------------Element access-------------------------*/
    reference at (size_type n)
    {
        if (n < size && n >= 0)
            return (p[n]);
        throw outofbounds();

    }

    const_reference at (size_type _n) const
	{
		if (_n < size)
			return (p[n]);
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
        return (p[size - 1]);
    }

    const_reference back() const
    {
        return (p[size - 1]);
    }
/*------------------Modifiers-------------------------*/

};
}


