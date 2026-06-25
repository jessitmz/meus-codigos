#include<string>
#include<iostream>

using namespace std;

int main() {
    string str;

    cin >> str;

    cout << str << "\n";

    string sub = str.substr(0, 3);
    cout << str << ", " << sub << "\n";

    string val = str.substr(4);
    cout << val << "\n";

    int num = stoi(val);
    cout << num;

    

    return 0;
}