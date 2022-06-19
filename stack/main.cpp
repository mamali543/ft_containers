#include "stack.hpp"
#include "../vector/vector.hpp"
#include <vector>

template <class T>
std::vector<int> constructor_test(std::stack<T> stk)
{
	std::vector<int> v;
	std::deque<int> deque;
	for (int i = 0; i < 10; ++i)
		deque.push_back(i);
	for (int i = 100; i < 20; ++i)
		stk.push(i);
	// g_start1 = timer();
	std::stack<int> stack(deque);
	std::stack<int> stack2(stk);
	std::stack<int> stack3;
	stack3 = stack2;
	// g_end1 = timer();
	while (stack.size() > 0)
	{
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0)
	{
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

template <class T>
std::vector<int> constructor_test(ft::stack<T> stk)
{
	std::vector<int> v;
	ft::vector<int> deque;
	for (int i = 0; i < 10; ++i)
		deque.push_back(i);
	for (int i = 100; i < 20; ++i)
		stk.push(i);
	// g_start2 = timer();
	ft::stack<int> stack(deque);
	ft::stack<int> stack2(stk);
	ft::stack<int> stack3;
	stack3 = stack2;
	// g_end2 = timer();
	while (stack.size() > 0)
	{
		v.push_back(stack.top());
		stack.pop();
	}
	while (stack2.size() > 0)
	{
		v.push_back(stack2.top());
		stack2.pop();
	}
	return v;
}

int main()
{

	std::stack<int> s;
ft:
	stack<int> a;
	std::vector<int> b;
	std::vector<int> c;

	b = constructor_test(a);
	c = constructor_test(s);
	for (int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;
	for (int i = 0; i < c.size(); i++)
		std::cout << c[i] << std::endl;
	system("leaks a.out");
	return 0;
}