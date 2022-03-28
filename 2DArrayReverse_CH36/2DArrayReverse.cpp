#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<array<int, 3>, 2> myArray{};
    int i = 0;

    for (auto &row : myArray)
    {
        for (auto &col : row)
        {
            col = i;
            i++;
        }
    }
    for (auto const &row : myArray)
    {
        for (auto const &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    reverse(begin(myArray.at(0)), end(myArray.at(0)));
    reverse(begin(myArray.at(1)), end(myArray.at(1)));
    reverse(begin(myArray), end(myArray));

    cout << "Reverse order\n";
    for (auto const &row : myArray)
    {
        for (auto const &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}