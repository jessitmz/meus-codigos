#include <iostream>

using namespace std;

class BSTNode {
    public:
        int key;
        int element;
        BSTNode* left;
        BSTNode* right;

        BSTNode(int k, int e) {
            key = k;
            element = e;
            left = right = nullptr;
        }
};

class BST {
    private:
        BSTNode* root;
        int nodecount;

        BSTNode* insert(BSTNode* rt, int k, int e) {
            if (rt == nullptr) return new BSTNode(k, e);

            if (k < rt->key) {
                rt->left = insert(rt->left, k, e);
            }    

            else {
                rt->right = insert(rt->right, k, e);
            }

            return rt;
        }

        void preorder(BSTNode* rt) {
            if (rt != nullptr) {
                cout << " " << rt->element;
                preorder(rt->left);
                preorder(rt->right);
            }
        }

        void inorder(BSTNode* rt) {
            if (rt != nullptr) {
                inorder(rt->left);
                cout << " " << rt->element;
                inorder(rt->right);
            }
        }

        void posorder(BSTNode* rt) {
            if (rt != nullptr) {
                posorder(rt->left);
                posorder(rt->right);
                cout << " " << rt->element;
            }
        }

    public:
        BST() {
            root = nullptr;
            nodecount = 0;
        }

        void insert(int k) {
            this->root = insert(this->root, k, k);
            this->nodecount++;
        }

        void preorder() { return preorder(this->root); }
        
        void inorder() { return inorder(this->root); }

        void posorder() { return posorder(this->root); }
};

int main() {
    BST bst;

    int n;
    cin >> n;

    int pi;
    for (int i = 0; i < n; i++) {
        cin >> pi;
        bst.insert(pi);
    }

    cout << "Pre order :";
    bst.preorder();
    cout << "\n";
    
    cout << "In order  :";
    bst.inorder();
    cout << "\n";
    
    cout << "Post order:";
    bst.posorder();
    cout << "\n";

    return 0;
}