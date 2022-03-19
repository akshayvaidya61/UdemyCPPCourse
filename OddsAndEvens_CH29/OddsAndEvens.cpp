#include <iostream>
#include <numeric>
#include <array>

using namespace std;

int main()
{
    array<int, 51> listOfIntegers{};
    iota(begin(listOfIntegers), end(listOfIntegers), 0);

    for (auto const &iter : listOfIntegers)
    {
        auto isEven = iter % 2 == 0 ? "Even" : "Odd";
        cout << iter << " is " << isEven << endl;
    }
}