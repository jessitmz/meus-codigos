#include <vector>
#include <string>
#include <iostream>

using namespace std;

class HashTable {
    
    private:

        int numElements;
        string table[101];

        int hashFunction(string key) {
            long long h = 0;
            for (int i = 0; i < key.length(); i++) {
                h += (long long)key[i] * (i + 1);
            }
            return ((19 * h) % 101);
        }
        
        int getProbingPosition(int originalHash, int j) {
            return ((originalHash + (j * j) + (23 * j)) % 101);
        }

    public:
        
        HashTable() {
            numElements = 0;
            for (int i = 0; i < 101; i++) {
                table[i] = "";
            }
        }

        int find(const string& key) {
            int originalHash = hashFunction(key);

            for (int j = 0; j <= 19; j++) {
                int pos = getProbingPosition(originalHash, j);

                if (table[pos] == key) {
                    return pos;
                }
                if (table[pos] == "") {
                    return -1; // encontrou um espaço vazio válido, logo a chave não está na tabela
                }
            }
            return -1; // não encontrou após 20 tentativas
        }

        void insert(const string& key) {

            if (find(key) != -1) {
                return;
            }

            int originalHash = hashFunction(key);

            for (int j = 0; j <= 19; j++) {
                int pos = getProbingPosition(originalHash, j);

                if (table[pos] == "" || table[pos] == "#DELETED#") {
                    table[pos] = key;
                    numElements++;
                    return;
                }
            }
        }

        void remove(const string& key) {
            int pos = find(key);

            if (pos != -1) {
                table[pos] = "#DELETED#";
                numElements--;
            }
        }

        void print() {
            cout << numElements << "\n";
            for (int i = 0; i < 101; i++) {
                if (table[i] != "" && table[i] != "#DELETED#") {
                    cout << i << ":" << table[i] << "\n";
                }
            }
        }
};

int main() {
    
    int t;
    cin >> t;
    while (t > 0) {

        int n;
        cin >> n;
        HashTable ht;

        for (int i = 0; i < n; i++) {
            string op;
            cin >> op;

            string cmd = op.substr(0, 3);

            string key = op.substr(4);

            if (cmd == "ADD") {
                ht.insert(key);
            }
            else if (cmd == "DEL") {
                ht.remove(key);
            }
        }

        ht.print();

        t--;
    }

    return 0;
}