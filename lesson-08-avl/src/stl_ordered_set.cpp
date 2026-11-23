#include <iostream>
#include <set>
#include <vector>

int main() {
    // Список чисел с повторениями
    std::vector<int> numbers = {5, 2, 8, 1, 9, 2, 5, 1, 10};
    
    // std::set автоматически удаляет дубликаты и сортирует элементы
    std::set<int> uniqueNumbers(numbers.begin(), numbers.end());

    std::cout << "Уникальные числа в порядке возрастания:" << std::endl;
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}