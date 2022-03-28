#include <iostream>
#include <random>
#include <chrono>
#include <array>
#include "boost/asio.hpp"
#include "boost/asio/thread_pool.hpp"

using namespace std;

int main(int argc, char **argv)
{
    mt19937 gen32{};
    uint32_t gen;
    array<uint32_t, 6> rollCount{};
    uint32_t dicerolls{};
    float mean{};

    gen32.seed(static_cast<uint_fast32_t>(chrono::system_clock::now().time_since_epoch().count()));

    // Take input
    char *inputs = *(argv + 1);
    dicerolls = static_cast<uint32_t>(atoi(inputs));
    cout << "Number of dicerolls: " << dicerolls << endl;

    // Launch the pool with four threads.
    boost::asio::thread_pool pool(4);

    // Submit a function to the pool.
    boost::asio::post(pool, [&]()
                      {
        for (int i = 0; i < dicerolls; ++i)
        {
            auto gen = gen32();
            ++rollCount.at(gen % rollCount.size());
        } });

    pool.join();

    cout << endl;

    uint32_t i{};
    for (auto const &iter : rollCount)
    {
        mean += iter;
        cout << i + 1 << ": " << iter << endl;
        ++i;
    }
    mean /= rollCount.size();
    cout << "mean: " << mean << endl;

    auto stddev = pow(mean / rollCount.size(), 0.5);
    cout << "std dev: " << stddev << endl;
}