#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iomanip>

int main() {
    const int N = 100000;
    const int REPEAT = 1000;
    
    // 1. Бенчмарк для вектора (линейный поиск максимума)
    std::vector<int> vec(N);
    for (int i = 0; i < N; i++) vec[i] = rand() % 1000000;
    
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < REPEAT; r++) {
        auto it = std::max_element(vec.begin(), vec.end());
        // В реальности мы бы удаляли элемент, но для честного сравнения 
        // с кучей (которая удаляет) просто имитируем поиск.
    }
    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_vec = end_vec - start_vec;

    // 2. Бенчмарк для приоритетной очереди (кучи)
    std::priority_queue<int> pq;
    for (int i = 0; i < N; i++) pq.push(rand() % 1000000);

    auto start_pq = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < REPEAT; r++) {
        pq.pop(); // Извлечение максимума за O(log n)
    }
    auto end_pq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_pq = end_pq - start_pq;

    // 3. Вывод результатов
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Извлечение максимума " << REPEAT << " раз из " << N << " элементов:\n";
    std::cout << "Вектор (max_element): " << elapsed_vec.count() << " сек.\n";
    std::cout << "Куча (priority_queue): " << elapsed_pq.count() << " сек.\n";
    
    if (elapsed_pq.count() > 0) {
        std::cout << "Куча быстрее в " << (elapsed_vec.count() / elapsed_pq.count()) << " раз.\n";
    }

    return 0;
}