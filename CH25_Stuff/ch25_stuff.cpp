#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    float input{};
    float numberAverage{};
    unsigned int numberOfNumbers{};

    cout << "How many numbers?: ";
    cin >> numberOfNumbers;

    cout << "Enter return-separated numbers\n";
    for (int i = 0; i < numberOfNumbers; i++)
    {
        cin >> input;
        numberAverage += input;
    }
    numberAverage /= numberOfNumbers;

    cout << "Average: " << numberAverage << endl;
}