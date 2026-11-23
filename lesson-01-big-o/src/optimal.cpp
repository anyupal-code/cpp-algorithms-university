#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <iomanip>

// Оптимальный способ поиска дубликата (O(n))
bool hasDuplicateOptimal(const std::vector<int>& arr) {
    std::unordered_set<int> seen;
    for (int x : arr) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    const int N = 100000;
    std::vector<int> data(N);
    
    // Заполняем массив уникальными числами от 0 до 99999
    for (int i = 0; i < N; i++) {
        data[i] = i;
    }

    // Замеряем время
    auto start = std::chrono::high_resolution_clock::now();
    bool result = hasDuplicateOptimal(data);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    
    std::cout << "Результат (Optimal): " << (result ? "Дубликат найден" : "Дубликатов нет") << "\n";
    std::cout << "Время выполнения: " << std::fixed << std::setprecision(4) << elapsed.count() << " секунд\n";
    
    return 0;
}