#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

// Пузырьковая сортировка (O(n^2))
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // TODO: Оптимизация: если за проход не было обменов, массив уже отсортирован (break).
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // TODO: Поменять arr[j] и arr[j+1] местами.
            }
        }
    }
}

// Быстрая сортировка (Quick Sort)
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Выбираем опорный элемент (последний)
        int pivot = arr[high];
        int i = (low - 1);

        // Разделяем массив
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        // Рекурсивно сортируем левую и правую части
        // TODO: Вызвать quickSort для левой части (low, pi - 1)
        // и для правой части (pi + 1, high).
    }
}

int main() {
    std::vector<int> testArr = {64, 34, 25, 12, 22, 11, 90};
    
    // Тест пузырьковой сортировки
    std::vector<int> bubbleArr = testArr;
    bubbleSort(bubbleArr);
    std::cout << "Пузырьковая: ";
    for (int x : bubbleArr) std::cout << x << " ";
    std::cout << std::endl;

    // Тест быстрой сортировки
    std::vector<int> quickArr = testArr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    std::cout << "Quick Sort: ";
    for (int x : quickArr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}