#ifndef AI_QUICK_SORT_H_
#define AI_QUICK_SORT_H_

#include <algorithm>
#include <functional>
#include <vector>

namespace sort {

/**
 * @brief
 *
 * @tparam T
 * @tparam Compare
 * @param arr
 * @param beg
 * @param end
 * @param compare
 * @return std::size_t
 */
template <typename T, typename Compare = std::less<T>>
std::size_t Partition(std::vector<T>& arr, std::size_t beg, std::size_t end,
                      Compare compare) {
    auto flag = end - 1, pivot = beg;
    auto val = arr[flag];
    for (auto i = beg; i < flag; ++i) {
        if (compare(arr[i], val)) {
            std::swap(arr[i], arr[pivot]);
            ++pivot;
        }
    }
    std::swap(arr[pivot], arr[flag]);
    return pivot;
}

/**
 * @brief Quick Sort Algorithm.
 *
 * @tparam T
 * @tparam Compare
 * @param arr
 * @param beg
 * @param end
 * @param compare
 */
template <typename T, typename Compare = std::less<T>>
void QuickSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
               Compare compare = Compare()) {
    if ((end - beg) > 1) {
        auto pivot = Partition(arr, beg, end, compare);
        QuickSort(arr, beg, pivot);
        QuickSort(arr, pivot + 1, end);
    }
}

}  // namespace sort

#endif