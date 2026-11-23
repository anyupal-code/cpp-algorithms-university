#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// Наивный способ поиска дубликата (O(n^2))
bool hasDuplicateNaive(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) return true;
        }
    }
    return false;
}

int main() {
    const int N = 100000;
    std::vector<int> data(N);
    
    // Заполняем массив уникальными числами от 0 до 99999
    // (В таком массиве дубликатов НЕТ, алгоритм переберет всё до конца)
    for (int i = 0; i < N; i++) {
        data[i] = i;
    }

    // Замеряем время
    auto start = std::chrono::high_resolution_clock::now();
    bool result = hasDuplicateNaive(data);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    
    std::cout << "Результат (Naive): " << (result ? "Дубликат найден" : "Дубликатов нет") << "\n";
    std::cout << "Время выполнения: " << std::fixed << std::setprecision(4) << elapsed.count() << " секунд\n";
    
    return 0;
}