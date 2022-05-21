#include <FixedPoint.h>

int main()
{
    Fixed<16, 16, 0> f(2.7);
    
    std::cout << f << "\n";

    std::cout << Fixed<16, 16, 0>::s_unity << "\n";
    return 0;
}