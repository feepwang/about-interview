#ifndef AI_BUBBLE_SORT_H_
<<<<<<< HEAD
#define AI_BUBBLE_SORT_H_
=======
#define AI_BUBBLE
>>>>>>> add bubble_sort

#include <algorithm>
#include <functional>
#include <stdexcept>
#include <vector>

namespace sort {

<<<<<<< HEAD
/**
 * @brief Bubble sort algorithm.
 *
 * @tparam T Type of elements in the container.
 * @tparam Compare Function object that defines the comparison between two
 * elements.
 *
 * @param container Container to sort.
 * @param compare Comparison function object.
 */
template <typename T, typename Compare = std::less<T>>
void BubbleSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
                Compare compare = Compare()) {
=======
/*

*/
void BubbleSort(
    std::vector<int> arr, std::size_t beg, std::size_t end,
    std::function<bool(const int&, const int&)> compare = std::less<int>()) {
>>>>>>> add bubble_sort
    //    check range
    if (arr.size() < end)
        throw std::length_error("ERROR: vector isn't as long as expected");
    if (beg > end) {
        throw std::length_error("ERROR: beg greater than end");
    }
    if (beg == end) {
        return;
    }

<<<<<<< HEAD
    for (auto i = end - 1; i > beg; --i) {
=======
    for (auto i = end-1; i > beg; --i) {
>>>>>>> add bubble_sort
        for (auto j = beg; j < i; ++j) {
            if (compare(arr[j + 1], arr[j])) std::swap(arr[j], arr[j + 1]);
        }
    }
}

}  // namespace sort

#endif