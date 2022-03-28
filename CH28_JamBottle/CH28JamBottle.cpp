#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    cout << "Select the Jam package\n";

    bool validPlanInput{false};
    string input{};
    while (!validPlanInput)
    {
        cout << "A: $8 for 2 bottle/month,Each additional bottle for $5\n";
        cout << "B: $12 for 4 bottle/month,Each additional bottle for $4\n";
        cout << "C: $15 for 6 bottle/month,Each additional bottle for $3\n";
        cout << ">> ";
        cin >> input;

        if (input.find_first_not_of("ABC") != string::npos)
        {
            cout << "Invalid input\n";
        }
        else
        {
            validPlanInput = true;
        }
    }

    string jamBottles{};
    unordered_map<string, array<int, 3>> priceTable = {
        {"A", {8, 2, 5}},
        {"B", {12, 4, 4}},
        {"C", {15, 6, 3}},
    };
    bool validBottleInput{false};

    while (!validBottleInput)
    {
        cout << "Total jam bottles you want to buy: ";
        cin >> jamBottles;

        if (jamBottles.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Invalid input\n";
        }
        else
        {
            validBottleInput = true;
        }
    }
    auto basePrice = priceTable.at(input).at(0);
    auto planBottleQuantity = priceTable.at(input).at(1);
    auto additionalBottlePrice = priceTable.at(input).at(2);

    int finalPrice{};
    auto jamBottles_int = atoi(jamBottles.c_str());
    if (jamBottles_int < planBottleQuantity)
    {
        finalPrice = basePrice;
    }
    else
    {
        finalPrice = basePrice + ((jamBottles_int - planBottleQuantity) * additionalBottlePrice);
    }
    cout << "Total monthly bill is: $" << finalPrice << endl;
}
