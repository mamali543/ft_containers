#ifndef ITERATOR_HPP
#define ITERATOR_HPP


namespace ft{
    
   template <class T>
    class iterator 
    {
    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;

    private:
        pointer _ptr;
    public:
        iterator() : _ptr(NULL) {}
        iterator(pointer ptr) : _ptr(ptr) {}
        ~iterator(){}
        iterator(const iterator& copy)
        {
            *this = copy;
        }
        iterator &operator=(const iterator &obj)
        {
            this->_ptr = obj._ptr;
            return (*this);
        }
        // template <class U>
        // bool operator==(const iterator<U> &obj) const
        // {
        //     return (this->_ptr == obj._ptr);
        // }

        // template <class U>
        // bool operator!=(const iterator<U> &obj) const
        // {
        //     return (this->_ptr != obj.base());
        // }
        iterator &operator++()
        {
            this->_ptr++;
            return *this;
        }
        
        iterator operator++(int)
        {
            iterator tmp(*this);
            this->_ptr++;
            return tmp;
        }
        iterator &operator--()
        {
            _ptr--;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            _ptr--;
            return tmp;
        }
        template <class U>
        bool operator==(const iterator<U> &obj) const
        {
            return (this->_ptr == obj.base());
        }
        template <class U>
        bool operator!=(const iterator<U> &obj) const
        {
            return (this->_ptr != obj.base());
        }
        template <class U>
        bool operator<=(const iterator<U> &obj) const
        {
            return (this->_ptr <= obj.base());
        }
        template <class U>
        bool operator<(const iterator<U> &obj) const
        {
            return (this->_ptr < obj._ptr);
        }
        template <class U>
        bool operator>(const iterator<U> &obj) const
        {
            return (this->_ptr > obj.base());
        }
        template <class U>
        bool operator>=(const iterator<U> &obj) const
        {
            return (this->_ptr >= obj.base());
        }
        // operator - returns distance between two iterators
        difference_type operator-(const iterator &obj) const
        {
            // * Subtraction gives you the distance >> the number of steps from one point to the other
            return (this->_ptr - obj.base());
        }
   
        reference operator*()
        {
            // * returning reference: references can never be null, so we are safe from tyring to dereference a null pointer
            // returns the value of the current object
            return *this->_ptr;
        }
      
        pointer operator->() const
        {
            //  returns the address of the object
            //  should return a reference if I want to use for modification
            return this->_ptr; // == return (*this)._ptr;
        }



        iterator operator+(difference_type n) const
        {
            return this->_ptr + n;
        }
        iterator operator-(difference_type n) const
        {
            return this->_ptr - n;
        }
        reference operator[](int n) const
        {
            return this->_ptr[n];
        }
        iterator &operator+=(int n)
        {
            this->_ptr += n;
            return *this;
        }
        iterator &operator-=(int n)
        {
            this->_ptr -= n;
            return *this;
        }
        operator iterator<const value_type>()
        {
            return iterator<const value_type>(_ptr);
        }
    };
}

#endif
