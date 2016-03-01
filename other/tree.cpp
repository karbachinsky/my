#include <iostream>
#include <memory>


template<class T>
class BinaryTree {
public:
    BinaryTree() {}

    void add(T & t);
    NodeRef search() const;
private:
    class Node;
    typedef std::shared_ptr<Node> NodeRef;

    class Node {
    private:
        NodeRef left_;
        NodeRef right_;
    };

    NodeRef root_;
};

void BinaryTree::add(T & t) {
    NodeRef node = root_;

    
}

void BinaryTree::search(T & t) {
    NodeRef node = root_;

    
}




int main() {
    BinaryTree tree;

    tree.add();

}
