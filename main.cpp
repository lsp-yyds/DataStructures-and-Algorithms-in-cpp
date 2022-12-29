#include "Sorting/sorting.h"
#include <ctime>
#include <iostream>

int main(int argc, char const *argv[]) {
    int a[1000], step = 10;
    double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;

    std::cout << "The worst-case time, in milliseconds, are" << std::endl;
    std::cout << "n \tRepetitions \t Total Ticks \tTime per Sort" << std::endl;

    for (int n = 0; n <= 1000; n += step) {
        long numberOfRepetitions = 0;
        clock_t startTime = clock();
        do {
            numberOfRepetitions++;

            for (int i = 0; i < n; i++)
                a[i] = n - i;

            sorting::insertionSort(a, n);
        } while (clock() - startTime < 1000);

        double elapsedMillis = (clock() - startTime) / clocksPerMillis;
        std::cout << n << '\t' << numberOfRepetitions << '\t' << elapsedMillis
                  << '\t' << elapsedMillis / numberOfRepetitions << std::endl;

        if (n == 100)
            step = 100;
    }
    return 0;
}