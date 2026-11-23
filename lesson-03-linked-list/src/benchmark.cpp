#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 50000;
    
    // Бенчмарк для вектора
    std::vector<int> vec;
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        vec.insert(vec.begin(), i); // Вставка в начало (O(n))
    }
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    // Бенчмарк для списка
    std::list<int> lst;
    auto start_lst = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        lst.push_front(i); // Вставка в начало (O(1))
    }
    auto end_lst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_lst = end_lst - start_lst;

    // Вывод результатов
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Вставка " << N << " элементов в начало:\n";
    std::cout << "std::vector: " << elapsed_vec.count() << " сек.\n";
    std::cout << "std::list:   " << elapsed_lst.count() << " сек.\n";
    
    if (elapsed_lst.count() > 0) {
        std::cout << "Разница:     в " << (elapsed_vec.count() / elapsed_lst.count()) << " раз.\n";
    }

    return 0;
}