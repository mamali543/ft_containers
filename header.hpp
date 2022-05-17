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
    explicit vector (const allocator_type& alloc = allocator_type()): _capacity(0), p(NULL), _size(0)
    {

    }

    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), p(NULL), allocc(alloc), _capacity(n)
    {
        size_type i;
        p = allocc.allocate(n);
        for (i = 0; i < n; i++)
        {
            allocc.construct(&p[i], val);
        }
    }

    vector (const vector& x) : p(NULL), allocc(x.allocc)
	{
		*this = x;
	}
    
    vector& operator= (const vector& x)
    {
        size_type i;
        if (_size != 0)
            allocc.deallocate(p, _size);
        _size = x._size;
        p = allocc.allocate(_size);
        for (i = 0; i < _size; i++)
        {
            allocc.construct(&p[i], x[i]);
        }
        return (*this);
    }

    ~vector()
    {
        if (_size != 0)
            allocc.deallocate(p, _size);
    }

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
        std::cout << n << std::endl;
        pointer tmp;
        size_type   i;
        tmp = p;
        if (n > max_size())
            throw std::length_error("length error");
        else if (n > _capacity)
        {
            pointer tmp = allocc.allocate(n);
            for (i = 0; i < _size ; i++)
                tmp[i] = p[i];
            allocc.deallocate(p, _size);
            p = tmp;
        }
        _capacity = n;
    }

    void resize (size_type n, value_type val = value_type())
    {
        size_type   i;
        pointer tmp;
        tmp = p;
        if (n < _size)
        {
            for (i = n; i < _size ; i++)
                allocc.destroy(p + i);
            _size = n;
        }
        else if (n > 0)
        {
            p = allocc.allocate(n);
            for (i = 0; i < n; i++)
            {
                if (i < _size)
                {
                    allocc.construct(&p[i], tmp[i]);
                }
                else
                    allocc.construct(&p[i], val);
            }
            if (_size > 0)
                allocc.deallocate(tmp, _size);
            _size = n;
        }
        else
            _size = n;
            p = NULL;
    }

/*------------------Element access-------------------------*/

    reference at (size_type n)
    {
        if (n < _size && n >= 0)
            return (p[n]);
        throw outofbounds();

    }

    const_reference at (size_type _n) const
	{
		if (_n < _size && _n >= 0)
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
        _size = 0;
    }

    void swap (vector& x)
    {
        pointer tmp;
        size_type   i;
        size_type   j;

        tmp = x.p;
        x.p = p;
        i = _size;
        j = _capacity;
        _size = x._size;
        _capacity = x._capacity;
        p = tmp;
        x._size = i;
        x._capacity = j;
    }

    void push_back(const value_type &val)
    {
        if (_size + 1 > _capacity)
            reserve(!_capacity   ? 1 : _capacity * 2);
        p[_size++] = val;
    }
};
}


