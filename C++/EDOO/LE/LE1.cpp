#include <iostream>
#include <string>

using namespace std;

class Link {
    
    public:
    char element;
    Link* next;
    
    Link(char elemvalue, Link* nextvalue) {
        this->element = elemvalue;
        this->next = nextvalue;
    }
    
    Link(Link* nextvalue) {
        this->next = nextvalue;
    }
    
};

class LList {

    private:
        Link* head;
        Link* tail;
        Link* curr;
        int listSize;

        void init() {
            this->curr = this->tail = this->head = new Link(nullptr);
            this->listSize = 0;
        }

        void destroy() {
            while (this->head != nullptr) {
                curr = head;
                head = head->next;
                delete curr;
            }
        }

    public:
        LList() { init(); }
        ~LList() { destroy(); }

        void insert(const char& element) {
            curr->next = new Link(element, curr->next);
            if (curr == tail) {
                tail = curr->next;
            }
            curr = curr->next;
            listSize++;
        }

        void home() { curr = head; }
        void end() { curr = tail; }

        friend ostream& operator<<(ostream& os, const LList& list) {
            Link* temp = list.head->next;
            while (temp != nullptr) {
                os << temp->element;
                temp = temp->next;
            }
            return os;
        }
        
};

int main() {
    
    string input;
    
    while (getline(cin, input)) {
        LList mylist;

        for (char c : input) {
            if (c == '[') { mylist.home(); }
            else if (c == ']') { mylist.end(); }
            else { mylist.insert(c); }
        }

        cout << mylist << "\n";
    }

    return 0;
}