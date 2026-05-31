#include "AList.h"
#include <iostream>

AList::AList(int size) {
    maxSize = size;
    listSize = curr = 0;
    listArrray = new int[maxSize];
}

AList::~AList() { delete[] listArrray; }

void AList::insertX(int it) {
    if (listSize >= maxSize) {
        return;
    }
    else {
        for (int c = listSize; c > curr; c--) {
            listArrray[c] =  listArrray[c-1];
        }
        listArrray[curr] = it;
        listSize++;
    }
}

int AList::countX(int it) {
    int counter = 0;
    for (int i = 0; i < listSize; i++) {
        if (listArrray[i] == it) counter++;
    }
    return counter;
}

void AList::remove() {
    if ( curr < 0 || curr >= listSize) {
        return;
    }
    else {
        for (int c = curr; c < (listSize - 1); c++) {
            listArrray[c] = listArrray[c+1];
        }
        listSize--;
    }
}

void AList::prev() {
    if (curr <= 0) {
        return;
    }
    else {
        curr--;
    }
}

void AList::next() {
    if (curr >= listSize) {
        return;
    }
    else {
        curr++;
    }
}