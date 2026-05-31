#ifndef ALIST_H
#define ALIST_H

class AList {
    private:
        int maxSize;
        int listSize;
        int curr;
        int* listArrray;

    public:
        AList(int size);
        ~AList();
        
        void insertX(int it);
        int countX(int it);
        void remove();
        void prev();
        void next();
};

#endif