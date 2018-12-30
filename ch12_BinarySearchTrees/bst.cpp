#include <iostream>
#include <vector>

using namespace std;

struct node {
    int keyValue;
    node *left;
    node *right;
};

class bst {
public:
    bst();
    ~bst();
    void insert(int key);
    node *search(int key);
private:
    void insert(int key, node *leaf);
    node *search(int key, node *leaf);
    void destroy(node *leaf);
    node *root;
};

bst::bst() {
    root = nullptr;
}

bst::~bst() {
    destroy(root);
}

void bst::destroy(node *leaf) {
    if(leaf != nullptr) {
        destroy(leaf->left);
        destroy(leaf->right);
        delete leaf;
    }
}

void bst::insert(int key, node *leaf) {
    if(key < leaf->keyValue) {
        if(leaf->left != nullptr) {
            insert(key, leaf->left);
        } else {
            leaf->left = new node;
            leaf->left->keyValue = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    if(key >= leaf->keyValue) {
        if(leaf->right != nullptr) {
            insert(key, leaf->right);
        } else {
            leaf->right = new node;
            leaf->right->keyValue = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}

void bst::insert(int key) {
    if(root != nullptr) {
        insert(key, root);
    }
    else {
        root = new node;
        root->keyValue = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

node *bst::search(int key, node *leaf) {
    if(leaf != nullptr) {
        if(key == leaf->keyValue) {
            return leaf;
        }
        else if(key < leaf->keyValue) {
            return search(key, leaf->left);
        }
        else if(key > leaf->keyValue) {
            return search(key, leaf->right);
        }
    }
    return nullptr;
}

node *bst::search(int key) {
    return search(key, root);
}

int main(int argc, char **argv) {
    vector<int> v = {12, 324, 123, 23, 10, 132, 3434, 345, 121};
    bst b;
    for (auto &x: v) {
        b.insert(x);
    }

    return 0;
}

