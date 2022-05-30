#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "./vector.hpp"
#include <stack>

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename Container::size_type size_type;
    protected:
        container_type _container;
    public:
        explicit stack(const container_type &container = container_type()) : _container(container)  {}

        void push(const T &value) { _container.push_back(value); }

        void pop() { _container.pop_back(); }

        value_type& top()  { return _container.back(); }

        const value_type &top() const { return _container.back(); }

        bool empty() const { return _container.empty(); }

        size_type size() const { return _container.size(); }
        
        template<class stack_type, class container_type>
        friend bool operator==(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container == rhs._container;
        }
        template<class stack_type, class container_type>
        friend bool operator!=(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container != rhs._container;
        }
        template<class stack_type, class container_type>
        friend bool operator>(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container > rhs._container;
        }
        template<class stack_type, class container_type>
        friend bool operator<(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container < rhs._container;
        }
        template<class stack_type, class container_type>
        friend bool operator>=(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container >= rhs._container;
        }
        template<class stack_type, class container_type>
        friend bool operator<=(const stack<stack_type, container_type> &lhs, const stack<stack_type, container_type> &rhs)
        {
            return lhs._container <= rhs._container;
        }

    };
}
#endif