#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Entry {

    public:
        string key;
        string value;

        Entry(string k, string v) : key(k), value(v) {}

};

class HashTable {

    private:
        int m;
        int cnt;
        vector<list<Entry>> H;

        int h(string K) { // sfold
            int intLength = K.length() / 4;
            long long sum = 0;

            for (int i = 0; i < intLength; i++) {
                string sub = K.substr(i * 4, 4);
                long long mult = 1;

                for (int j = 0; j < 4; j++) {
                    sum += sub[j] * mult;
                    mult *= 256;
                }
            }

            string sub = K.substr(intLength * 4);
            int mult = 1;
            int s = sub.length();
            for (int j = 0; j < s - 1; j++) {
                sum += sub[j] * mult;
                mult *= 256;
            }

            return abs(sum) % m;
        }

    public:
        HashTable(int size) : m(size), cnt(0) { H.resize(m); }

        string find(string key) {
            int pos = h(key);

            for (auto it = H[pos].begin(); it != H[pos].end(); ++it) {
                if (it->key == key) {
                    return it->value;
                }
            }
            return "";
        }

        void insert(string key, string value) {
            if (find(key) == "") {
                int pos = h(key);
                H[pos].push_back(Entry(key, value));
                cnt++;
            }
        }
};

int main() {

    HashTable dict(100003);

    string line;

    while (getline(cin, line) && line != "") {

        int spacePos = line.find(" ");

        if (spacePos > 0) {

            string english, foreing;
            english = line.substr(0, spacePos);
            foreing = line.substr(spacePos + 1);

            dict.insert(foreing, english);
        }
    }

    string word;
    
    while (cin >> word) {
        string translated = dict.find(word);

        if (translated != "") {
            cout << translated << "\n";
        }
        else {
            cout << "eh\n";
        }
    }

    return 0;
}