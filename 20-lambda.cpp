#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

/*
    a comma-separated list of zero or more captures, optionally beginning with a capture-default.

    Capture list can be passed as follows (see below for the detailed description):

    [a,&b] where a is captured by copy and b is captured by reference.
    [this] captures the current object (*this) by reference
    [&] captures all automatic variables used in the body of the lambda by reference and current object by reference if exists
    [=] captures all automatic variables used in the body of the lambda by copy and current object by reference if exists
    [] captures nothing
*/

int main()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [x](int n) { return n < x; }), c.end());

    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << '\n';

    // the type of a closure cannot be named, but can be inferred with auto
    // since C++14, lambda could own default arguments
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';

    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';
}
