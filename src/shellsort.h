#ifndef AI_SHELL_SORT_H_
#define AI_SHELL_SORT_H_

#include <cstddef>
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
 */
template <typename T, typename Compare = std::less<T>>
void ShellSort(std::vector<T>& arr, std::size_t beg, std::size_t end,
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

    //  希尔排序主要思路是 分组 + 插入排序
    //  是对插入排序的优化,减少大间距下更新左边分组的交换次数
    for (auto gap = (end - beg) / 2; gap; gap /= 2) {
        for (auto i = gap; i < end; ++i) {
            auto j = i - gap;
            T tmp = arr[i];
            while (j >= beg && compare(tmp, arr[j])) {
                arr[j + gap] = arr[j];
                if (j != 0)
                    j -= gap;
                else
                    break;
            }
            if (arr[i] != tmp) {
                if (j >= 0 && j < gap) {
                    arr[j] = tmp;
                } else {
                    arr[j + gap] = tmp;
                }
            }
        }
    }
}

}  // namespace sort

#endif