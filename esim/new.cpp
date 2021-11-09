#include <iostream>

template <int N>

int foo()
{
    return N*foo<N-1>;
}

template <>
int foo<0>()
{
    return 1;
}
