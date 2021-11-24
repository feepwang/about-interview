#ifndef AI_SELECT_SORT_H_
#define AI_SELECT_SORT_H_

#include <functional>
#include <stdexcept>
#include <vector>

namespace sort {

/**
 * @brief Selection Sort Algorithm.
 *
 * @param arr
 * @param beg
 * @param end
 * @param compare
 */
template <typename T, typename Compare = std::less<T>>
void SelectionSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
                   Compare compare = Compare()) {
    //    check range
    if (arr.size() < end)
        throw std::length_error("ERROR: vector isn't as long as expected");
    if (beg > end) {
        throw std::length_error("ERROR: beg greater than end");
    }
    if (beg == end) {
        return;
    }

    for (size_t i = beg; i < end; ++i) {
        size_t mark{i};
        for (size_t j = i + 1; j < end; ++j) {
            if (compare(arr[j], arr[mark])) {
                mark = j;
            }
        }
        if (mark != i) std::swap(arr[mark], arr[i]);
    }
}

}  // namespace sort

#endif