#include "AList.h"
#include <iostream>
#include <string>

int main() {

    int cases;
    std::cin >> cases;

    for (int n = 1; n <= cases; n++) {
        std::cout << "Caso " << n << ":\n";

        int operations;
        std::cin >> operations;
        AList lista(operations);

        for (int i = 1; i <= operations; i++) {
            std::string command;
            std::cin >> command;

            if (command == "insert") {
                int item;
                std::cin >> item;
                lista.insertX(item);
            }
            else if (command == "count") {
                int element;
                std::cin >> element;
                int value = lista.countX(element);
                std::cout << value << "\n";
            }
            else if (command == "remove") lista.remove();
            else if (command == "prev") lista.prev();
            else if (command == "next") lista.next();
        }
    }

    return 0;
}