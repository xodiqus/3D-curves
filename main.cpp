#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <atomic>
#include <iomanip>

#include "circle.h"
#include "ellipse.h"
#include "helix.h"

int main()
{
    // 1 - see curve.h, circle.h, ellipse.h, and helix.h.

    // 2)
    std::vector<std::unique_ptr<Exercise::Curve>> v1(100);

    auto rand_eng = std::default_random_engine(std::random_device()());
    std::uniform_real_distribution real_dist(0.1, 10.0);
    std::uniform_int_distribution  int_dist(0, 2);

    for (auto &curve : v1) {
        switch (int_dist(rand_eng))
        {
        case 0: curve.reset(new Exercise::Circle(real_dist(rand_eng)));							break;
        case 1: curve.reset(new Exercise::Ellipse(real_dist(rand_eng), real_dist(rand_eng)));   break;
        case 2: curve.reset(new Exercise::Helix(real_dist(rand_eng)));  						break;
        }
    }

    // 3)
    const auto default_precision = std::cout.precision();
    std::cout << std::setprecision(2);

    for (auto &curve : v1) {
        const auto t = std::numbers::pi / 4.0;
        std::cout << "C(" << t << ") = " << curve->At(t) << "; "
                  << "C'(" << t << ") = " << curve->Derivative(t) << ";" << std::endl;
    }

    std::cout << std::setprecision(default_precision);

    // 4)
    std::vector<Exercise::Circle*> v2;
    for (auto &curve : v1)
    {
        if (auto* p = dynamic_cast<Exercise::Circle*>(curve.get()))
        {
            v2.push_back(p);
        }
    }

    // 5)
    std::sort(v2.begin(), v2.end(), [](auto c1, auto c2 ) { return c1->Radii()[0] < c2->Radii()[0]; });

    // 7 - see CMakeLists.txt

    // 6, 8)
    std::atomic<double> total_sum = 0;
    {
        auto hc = std::thread::hardware_concurrency();
        if (hc == 0) hc = 1;

        std::vector<std::jthread> 	threads (hc);
        std::vector<double> 		part_sum(hc);

        for (size_t i = 0; i < threads.size(); ++i)
        {
            threads[i] = std::jthread([&, i] {
                auto& sum = part_sum[i];
                sum = 0.0;

                for (size_t j = i; j < v1.size(); j += hc)
                {
                    auto r = v1[j]->Radii();
                    sum += std::accumulate(r.begin(), r.end(), 0);
                }

                total_sum.store(total_sum.load() + sum);
            });
        }
    }

    std::cout << "Total sum: " << total_sum.load() << "." << std::endl;

    return 0;
}

/* 		Requirements achieved:
 * 1) The implementation used virtual methods.
 * 2) There are no explicit deallocation and memory leak.
 * 3) Radii are generated positive.
 * 4) Used STL only.
 * 5) Used the C++20 standard (see CMakeFiles.txt).
 * 6) Used GCC, but the code is able to compile with any compilator including msvc, clang and much other.
*/
