#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 100000;
    
    // 1. Бенчмарк для вектора (имитация вырожденного дерева)
    std::vector<int> vec;
    // Заполняем по возрастанию (как если бы вставляли в обычное BST)
    for (int i = 0; i < N; i++) {
        vec.push_back(i);
    }
    
    int target = N + 1; // Ищем число, которого нет (худший случай)
    
    auto start_vec = std::chrono::high_resolution_clock::now();
    auto it = std::find(vec.begin(), vec.end(), target);
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    // 2. Бенчмарк для std::set (сбалансированное дерево)
    std::set<int> tree_set;
    for (int i = 0; i < N; i++) {
        tree_set.insert(i);
    }

    auto start_set = std::chrono::high_resolution_clock::now();
    auto it_set = tree_set.find(target);
    auto end_set = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_set = end_set - start_set;

    // 3. Вывод результатов
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Поиск в " << N << " элементах:\n";
    std::cout << "Вектор (вырожденное дерево): " << elapsed_vec.count() << " сек.\n";
    std::cout << "std::set (AVL/Красно-черное): " << elapsed_set.count() << " сек.\n";
    
    if (elapsed_set.count() > 0) {
        std::cout << "Дерево быстрее в " << (elapsed_vec.count() / elapsed_set.count()) << " раз.\n";
    }

    return 0;
}