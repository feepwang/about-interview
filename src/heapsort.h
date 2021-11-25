#ifndef AI_HEAP_SORT_H_
#define AI_HEAP_SORT_H_

#include <functional>
#include <vector>

namespace sort {

void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)  //若子节点指标在范围内才做比较
    {
        if (son + 1 <= end &&
            arr[son] < arr[son + 1])  //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] >
            arr[son])  //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else  //否则交换父子内容再继续子节点和孙节点比较
        {
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

/**
 * @brief  Heap Adjustment
 *
 * @tparam T
 * @tparam Compare
 * @param arr
 * @param beg
 * @param end
 * @param compare
 */
template <typename T, typename Compare>
void AdjustMaxHeap(std::vector<T>& arr, std::size_t beg, std::size_t end,
                   Compare compare) {
    auto dad = beg, son = dad * 2 + 1;
    while (son < end) {
        //  父节点与子节点中最大的进行比较
        //  如果父节点小于该子节点,父节点与该字节的互换,同时继续向下比较
        if (son + 1 < end && compare(arr[son], arr[son + 1])) son++;
        if (compare(arr[son], arr[dad]))
            return;
        else {
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--) max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

/**
 * @brief
 *
 * @tparam T
 * @tparam Compare
 * @param arr
 * @param compare
 */
template <typename T, typename Compare = std::less<T>>
void HeapSort(std::vector<T>& arr, Compare compare = Compare()) {
    auto sz = arr.size();
    //  以大根堆为基础
    //  从最后一个父节点开始建立大根堆
    for (int i = sz / 2 - 1; i >= 0; i--)
        AdjustMaxHeap(arr, i, sz - 1, compare);

    //  每次把最后一个元素与堆顶交换,并在剩余的元素里重新建堆
    for (int i = sz - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        AdjustMaxHeap(arr, 0, i, compare);
    }
}

}  // namespace sort

#endif