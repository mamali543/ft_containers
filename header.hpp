#include <iostream>
#include <array>
#include <memory>

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
    size_t var;
    value_type *p;
    allocator_type allocc;
    public:
    explicit vector (const allocator_type& alloc = allocator_type()): var(0), p(NULL), allocc(alloc)
    {

    } 
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): var(n), p(NULL), allocc(alloc)
    {
        p = allocc.allocator(n);
        for (int i = 0; i < n; i++)
        {
            p.construct(&p[i], val);
        }
    }
    Vector (const Vector& x) : var(0), p(NULl), allocc(x.allocc)
	{
		*this = x;
	}
    vector& operator= (const vector& x)
    {
        if (var != 0)
            allocc.deallocate(p, var);
        var = x.var;
        p = allocc.allocator(var);
        for (int i = 0; i < var; i++)
        {
            p.construct(&p[i], x[i]);
        }
        return (*this);
    }

    ~vector()
    {
        if (var != 0)
            allocc.deallocate(p, var);
    }

    size_type size() const
    {
        
    }
};


