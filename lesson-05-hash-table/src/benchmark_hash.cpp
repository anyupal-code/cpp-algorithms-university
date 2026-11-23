#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 100000;
    
    // 1. Бенчмарк для вектора (линейный поиск)
    std::vector<int> vec;
    for (int i = 0; i < N; i++) {
        vec.push_back(i);
    }
    
    int target = N + 1; // Ищем число, которого нет в массиве (худший случай)
    
    auto start_vec = std::chrono::high_resolution_clock::now();
    auto it = std::find(vec.begin(), vec.end(), target);
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    // 2. Бенчмарк для хеш-таблицы
    std::unordered_map<int, int> hash_map;
    for (int i = 0; i < N; i++) {
        hash_map[i] = i;
    }

    auto start_map = std::chrono::high_resolution_clock::now();
    auto it_map = hash_map.find(target);
    auto end_map = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_map = end_map - start_map;

    // 3. Вывод результатов
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Поиск в " << N << " элементах:\n";
    std::cout << "Вектор (std::find): " << elapsed_vec.count() << " сек.\n";
    std::cout << "Хеш-таблица (unordered_map): " << elapsed_map.count() << " сек.\n";
    
    if (elapsed_map.count() > 0) {
        std::cout << "Хеш-таблица быстрее в " << (elapsed_vec.count() / elapsed_map.count()) << " раз.\n";
    }

    return 0;
}