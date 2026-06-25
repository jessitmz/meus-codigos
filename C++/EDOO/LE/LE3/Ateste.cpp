#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BSTNode {
    public:
        char key;
        char element;
        BSTNode* left;
        BSTNode* right;

        BSTNode(char k, char e) {
            key = k;
            element = e;
            left = right = nullptr;
        }
};

class BST {
    private:
        BSTNode* root;
        int nodecount;

        BSTNode* insert(BSTNode* rt, char k, char e) {
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
                cout << rt->element;
                preorder(rt->left);
                preorder(rt->right);
            }
        }

    public:
        BST() {
            root = nullptr;
            nodecount = 0;
        }

        void insert(char k) {
            this->root = insert(this->root, k, k);
            this->nodecount++;
        }

        void preorder() { return preorder(this->root); }
};

int main() {

    int datacount = 0;
    vector<char> dataset;
    
    string input;
    cin >> input;
    
    while (input != "$") {
        
        if (input != "*" && input != "$") {
            for (char c : input) {
                dataset.push_back(c);
            }
        }
        
        cin >> input;
        
        if (input == "*" || input == "$") { // outro conjunto de dados

            BST bst;
            
            for (auto element = dataset.rbegin(); element != dataset.rend(); ++element) {
                bst.insert(*element);
            }
            
            bst.preorder();
            cout << "\n";
            
            dataset.clear();
        }

    }

    return 0;
}