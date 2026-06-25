#include <iostream>
#include <string>

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
        
        int find(BSTNode* rt, int k) {
            if (rt == nullptr) return -1;
            
            if (k < rt->key) return find(rt->left, k);
            else if (k == rt->key) return rt->element;
            else return find(rt->right, k);
        }

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

        BSTNode* remove(BSTNode* rt, int k) {
            if (rt == nullptr) return nullptr;

            if (k < rt->key) {
                rt->left = remove(rt->left, k);
            }
            else if (k > rt->key) {
                rt->right = remove(rt->right, k);
            }
            else {
                if (rt->left == nullptr) return rt->right;
                else if (rt->right == nullptr) return rt->left;
                else {
                    BSTNode* temp = getmin(rt->right);
                    rt->element = temp->element;
                    rt->key = temp->key;
                    rt->right = deletemin(rt->right);
                }
            }

            return rt;
        }

        BSTNode* getmin(BSTNode* rt) {
            if (rt->left == nullptr) return rt;
            return getmin(rt->left);
        }
    
        BSTNode* deletemin(BSTNode* rt) {
            if (rt->left == nullptr) return rt->right;
            rt->left = deletemin(rt->left);
            return rt;
        }

        void posorder(BSTNode* rt) {
            if (rt != nullptr) {
                posorder(rt->left);
                posorder(rt->right);
                cout << rt->element << "\n";
            }
        }

    public:
        BST() {
            root = nullptr;
            nodecount = 0;
        }

        int find(int k) { return find(this->root, k); }

        void insert(int k) {
            int e = k;
            this->root = insert(root, k, e);
            nodecount++;
        }
        
        int remove(int k) {
            int temp = find(this->root, k);
            if (temp != -1) {
                this->root = remove(this->root, k);
                this->nodecount--;
            }
            else exit;
            return temp;
        }

        void getNodeCount() {
            cout << nodecount << "\n";
        }

        void posorder() { posorder(this->root); }
};

int main() {
    BST bst;

    int c;
    cin >> c;

    string command;
    int number;

    for (int i = 0; i < c; i++) {
        cin >> command;
        cin >> number;

        if (command == "ins") bst.insert(number);
        else if (command == "rem") bst.remove(number);
    }

    bst.getNodeCount();
    bst.posorder();

    return 0;
}