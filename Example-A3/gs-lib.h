#ifndef GSLIB
#define GSLIB

#include <iostream>
#include <limits>
#include <string>

// You can create your own lib.h file and namespace to reuse code.
namespace gs {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    void ignoreToEndline() {
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void readInt(string prompt, int &num) {
        bool next = true;

        while (next) {
            cout << prompt;
            cin >> num;

            if (!cin) {
                cout << "Invalid input! Please try again!!" << endl;
                cin.clear();
                ignoreToEndline();

            } else {
                next = false;
            }
        }
    }

    void readDouble(string prompt, double &num) {
        bool next = true;

        while (next) {
            cout << prompt;
            cin >> num;

            if (!cin) {
                cout << "Invalid input! Please try again!!" << endl;
                cin.clear();
                ignoreToEndline();

            } else {
                next = false;
            }
        }
    }

    // Refactored for templates with chatgpt: https://chatgpt.com/s/t_68ebb99394c8819193d09c5906097c0a
    // Generic selection sort with manual swapping (demonstration version)
    template <typename KeyType, typename ParallelType>
    void selectionSortParallel(KeyType arrKey[], ParallelType arr2[], int count) {
        for (int i = 0; i < count - 1; ++i) {
            int min = i;  // set current element as minimum

            // find the smallest element in the rest of the array
            for (int j = i + 1; j < count; ++j) {
                if (arrKey[j] < arrKey[min]) {
                    min = j;
                }
            }

            // swap the found minimum with the current element
            if (min != i) {
                // manual swap for arrKey
                KeyType tempKey = arrKey[i];
                arrKey[i] = arrKey[min];
                arrKey[min] = tempKey;

                // manual swap for parallel array
                ParallelType tempPar = arr2[i];
                arr2[i] = arr2[min];
                arr2[min] = tempPar;
            }
        }
    }

    template <typename T>
    bool between(const T& value, const T& low, const T& high) {
        return (value >= low && value <= high);
    }


} // namespace gs

#endif