#include <iostream>
#include <array>
#include <memory>
#include <vector>

template <class T>
void ll(T y)
{
    std::cout << y << std::endl;
}

int     main()
{
    std::allocator<int> p;
    int *tmp = p.allocate(1);
    p.construct(tmp, 88);
    ll(*tmp);

}