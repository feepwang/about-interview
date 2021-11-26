#ifndef AI_BINARY_SEARCH_H_
#define AI_BINARY_SEARCH_H_

#include <cstddef>
#include <vector>
namespace search {

/**
 * @brief 非递归版本
 *
 * @tparam T
 * @param arr
 * @param beg
 * @param end
 * @param val
 * @return T*
 */
template <typename T>
T* BinarySearch(std::vector<T>& arr, std::size_t beg, std::size_t end,
                const T& val) {
    auto mid = beg + (end - beg) / 2;
    while (end - beg > 1) {
        if (arr[mid] == val)
            return &arr[mid];
        else if (arr[mid] < val) {
            mid = mid + (end - mid) / 2;
        } else
            mid = beg + (mid - beg) / 2;
    }
    return nullptr;
}

/**
 * @brief 递归版本
 *
 * @tparam T
 * @param arr
 * @param beg
 * @param end
 * @param val
 * @return T*
 *
template <typename T>
T* BinarySearch(std::vector<T>& arr, std::size_t beg, std::size_t end,
                const T& val) {
    auto mid = beg + (end - beg) / 2;
    if (end - beg > 1) {
        if (arr[mid] == val)
            return &arr[mid];
        else if (arr[mid] < val)
            return BinarySearch(arr, mid, end, val);
        return BinarySearch(arr, beg, mid, val);
    }
    return nullptr;
}
 */

}  // namespace search

#endif