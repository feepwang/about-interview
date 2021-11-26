#ifndef AI_MERGE_SORT_H_
#define AI_MERGE_SORT_H_

#include <cstddef>
#include <functional>
#include <vector>

namespace sort {

/**
 * @brief Merge Sort
 *
 * @tparam T
 * @tparam Compare
 * @param arr
 * @param beg
 * @param mid
 * @param end
 * @param result
 * @param compare
 */
template <typename T, typename Compare>
void Merge(std::vector<T>& arr, std::size_t beg, std::size_t mid,
           std::size_t end, std::vector<T>& result, Compare compare) {
    auto i{beg}, j{mid}, k{beg};
    while (i < mid && j < end) {
        if (arr[i] < arr[j])
            result[k++] = arr[i++];
        else
            result[k++] = arr[j++];
    }
    while (i < mid) result[k++] = arr[i++];
    while (j < end) result[k++] = arr[j++];

    for (i = beg; i < end; ++i) arr[i] = result[i];
}

template <typename T, typename Compare = std::less<T>>
void MergeSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
               std::vector<T>& result, Compare compare = Compare()) {
    if (end - beg > 1) {
        auto mid = beg + (end - beg) / 2;
        MergeSort(arr, beg, mid, result, compare);
        MergeSort(arr, mid, end, result, compare);
        Merge(arr, beg, mid, end, result, compare);
    }
}

}  // namespace sort
#endif