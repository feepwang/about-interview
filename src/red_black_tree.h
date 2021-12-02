#ifndef AI_RED_BLACK_TREE_H_
#define AI_RED_BLACK_TREE_H_

#include <functional>

namespace ds {

/**
 * @brief
 *
 * 红黑树的特征:
 * 1. 结点是红色或者黑色
 * 2. 根节点是黑色
 * 3. 所有叶子节点是黑色
 * 4. 每个红色节点的两个子节点都是黑色
 * 5. 从任意结点其每个叶子的所有路径都包含相同数目的黑色节点
 * 6. 最长路径不超过最短路径的两倍
 *
 * @tparam T
 * @tparam Compare
 */
template <typename T, typename Compare = std::less<T>>
class RedBlackTree {
    struct Node;

   public:
   private:
    struct Node {
        enum Color { BLACK, RED };
        Color color;
        int val;
        Node *parent;
        Node *left, *right;
    };
};

}  // namespace ds

#endif