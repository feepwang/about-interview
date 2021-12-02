#ifndef AI_AVL_TREE_H_
#define AI_AVL_TREE_H_

namespace ds {

class AVLTree {
    struct Node;

   public:
    AVLTree() = default;
    ~AVLTree() {
        if (root_) {
            Destroy();
        }
    }
    void Insert();
    void Delete(int val);

   private:
    void Destroy();

    struct Node {
        Node(int val, Node* parent) : val(val), parent(parent) {}
        int val;
        Node *left{}, *right{}, *parent{};
    };

    Node* root_;
};

}  // namespace ds

#endif