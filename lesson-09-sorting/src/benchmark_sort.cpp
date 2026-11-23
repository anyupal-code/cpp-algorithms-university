#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iomanip>

// Функция пузырьковой сортировки (для сравнения)
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    const int N = 10000;
    
    // Создаем исходный массив случайных чисел
    std::vector<int> original(N);
    for (int i = 0; i < N; i++) {
        original[i] = rand() % 100000;
    }

    // 1. Бенчмарк пузырьковой сортировки
    std::vector<int> bubbleArr = original;
    auto start_bubble = std::chrono::high_resolution_clock::now();
    bubbleSort(bubbleArr);
    auto end_bubble = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_bubble = end_bubble - start_bubble;

    // 2. Бенчмарк std::sort
    std::vector<int> stdArr = original;
    auto start_std = std::chrono::high_resolution_clock::now();
    std::sort(stdArr.begin(), stdArr.end());
    auto end_std = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_std = end_std - start_std;

    // 3. Вывод результатов
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Сортировка " << N << " элементов:\n";
    std::cout << "Пузырьковая (O(n^2)): " << elapsed_bubble.count() << " сек.\n";
    std::cout << "std::sort (O(n log n)): " << elapsed_std.count() << " сек.\n";
    
    if (elapsed_std.count() > 0) {
        std::cout << "std::sort быстрее в " << (elapsed_bubble.count() / elapsed_std.count()) << " раз.\n";
    }

    return 0;
}