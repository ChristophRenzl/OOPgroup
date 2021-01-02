#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    //oddeven
    int odd = 0;
    int even = 0;
    int bigger = 0;
    int smaller = 0;
    auto print = [](auto& x)->void {
        std::cout << x << std::endl;
    };

    auto OddEven = [&odd, &even, &bigger, &smaller](const int& x)->void {
        if (x % 2 == 0)
        {
            even++;
        }
        else if (x % 2 != 0)
        {
            odd++;
        }

        if (x <= 50)
        {
            smaller++;
        }
        else if (x > 50)
        {
            bigger++;
        }
    };

    std::vector<int> vec;
    vec.reserve(50);

    for (int i = 0; i <= 50; i++)
    {
        int numrand = rand() % 101;
        vec.push_back(numrand);
    }


    std::for_each(vec.begin(), vec.end(), print);
    std::for_each(vec.begin(), vec.end(), OddEven);
    std::cout << "Gerade:" << even << " \t Ungerade:" << odd << std::endl;
    std::cout << "<=50:" << smaller << " \t >50:" << bigger << std::endl;
}
