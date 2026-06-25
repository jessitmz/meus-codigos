#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Entry {
    public:
        int key;
        string value;

        Entry(int k, string v) : key(k), value(v) {}
};

class HashTable {
    private:
        int m;
        int cntElements;
        vector<list<Entry>> H;

        int hashFunction(int k) { 
            return k % 10;
        }

    public:
        HashTable() : m(10), cntElements(0) { H.resize(m); }

        string find(int key) {
            int pos = hashFunction(key);

            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if (it->key == key) {
                    return it->value;
                }
            }
            return "";
        }
        
        void insert(int k, string v) {
            if (find(k) == "") {
                int pos = hashFunction(k);
                H[pos].push_back(Entry(k, v));
                cntElements++;
            }
        }
        
        void remove(int k) {
            if (find(k) != "") {
                int pos = hashFunction(k);
                for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                    if (it->key == k) {
                        H[pos].erase(it);
                        break;
                    }
                }
                
                cntElements--;
            }
        }
        
        int getCntElements() { return cntElements; }

        void print() {

            for (int i = 0; i < m; ++i) {

                cout << i << ":";

                if (!H[i].empty()) {

                    int counter = 1;

                    for (auto it = H[i].begin(); it != H[i].end(); ++it) {

                        cout << "(" << it->key << "," << it->value << ")";

                        if (counter < H[i].size()) {
                            cout << ",";
                        }
                        else { cout << "\n"; }

                        counter++;
                    }
                }
                else { cout << "\n"; }

            }
        }

};

int main() {

    
    int c;
    cin >> c;
    
    int cntCases = 1;
    
    while (c > 0) {
        HashTable dict;

        int op;
        cin >> op;
        
        while (op > 0) {
            
            string nameOp;
            int key;

            cin >> nameOp;

            if (nameOp == "add") {
                cin >> key;

                string value;
                cin >> value;

                dict.insert(key, value);
            }
            else if (nameOp == "del") {
                cin >> key;

                dict.remove(key);
            }

            op--;
        }

        cout << "caso " << cntCases << ":\n";
        cout << "alpha = " << dict.getCntElements() << "/10\n";
        dict.print();

        c--;
        cntCases++;
    }

    return 0;
}