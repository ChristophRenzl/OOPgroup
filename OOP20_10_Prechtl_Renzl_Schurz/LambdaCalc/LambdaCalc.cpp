#include <iostream>

int main()
{
    //LamdaCalc
    int x = 5;
    int y = 2;
    char op = '+';
    float test;

    auto lamdaCalc = [](auto x, auto y, auto op) ->float {
        if (op == '+')
        {
            return x + y;
        }
        else if (op == '-')
        {
            return x - y;
        }
        else if (op == '*')
        {
            return x * y;
        }
        else if (op == '/')
        {
            return x / y;
        }
        else return -1;
    };

    test = lamdaCalc(x, y, op);
    std::cout << test << std::endl;
}
