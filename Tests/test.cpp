#include <FixedPoint.h>

#define PRINT_EXPRESSION(expr)\
    std::cout << #expr ": " << (expr) << "\n";

#define PRINT_TYPE(x)\
    std::cout << "Identifier: " #x ", value " << x << ", type: " << typeid(x).name(); 


int main()
{

    {
        Fixed<12, 4, 0> f(2.5);
        PRINT_TYPE(f);
        PRINT_EXPRESSION(f);
        PRINT_EXPRESSION(f + f);
        PRINT_EXPRESSION(f - f);
        PRINT_EXPRESSION(f * f);
    }
    {
        Fixed<7, 8, 1> f(-2.5);
        PRINT_TYPE(f);
        PRINT_EXPRESSION(f);
        PRINT_EXPRESSION(f + f);
        PRINT_EXPRESSION(f - f);
        PRINT_EXPRESSION(f * f);
    }
    return 0;
}