#ifndef AI_INSERT_SORT_H_
#define AI_INSERT_SORT_H_

#include <cstddef>
#include <functional>
#include <vector>

namespace sort {

/**
 * @brief Insertion Sort Algorithm
 *
 * @tparam T = value_type
 * @tparam Compare = compare function
 * @param arr
 * @param beg
 * @param end
 * @param compare
 */
template <typename T, typename Compare = std::less<T>>
void InsertionSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
                   Compare compare = Compare()) {
    //    check range
    if (arr.size() < end)
        throw std::length_error("ERROR: vector isn't as long as expected");
    if (beg > end) {
        throw std::length_error("ERROR: beg is greater than end");
    }
    if (beg == end) {
        return;
    }

    for (size_t i = beg + 1; i < end; ++i) {
        size_t j = i - 1;
        T tmp = arr[i];
        while (j >= beg && compare(tmp, arr[j])) {
            arr[j + 1] = arr[j];
            if (j != 0)
                --j;
            else
                break;
        }
        if (arr[i] != tmp) {
            if (j == 0) {
                arr[j] = tmp;
            } else {
                arr[j + 1] = tmp;
            }
        }
    }
}

}  // namespace sort

#endif