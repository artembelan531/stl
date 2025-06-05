/* Belan Artem Vladislavovich
./stl st135609@student.spbu.ru*/
#include <iostream>
#include "include/cyclic_list.hpp"

int main() {
    CyclicList<int> list;

    std::cout << "Добавляем элементы: ";
    for (int i = 1; i <= 5; ++i) {
        list.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Элементы списка: ";
    for (int val : list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    std::cout << "После pop_back: ";
    for (int val : list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Размер списка: " << list.size() << std::endl;

    return 0;
}
