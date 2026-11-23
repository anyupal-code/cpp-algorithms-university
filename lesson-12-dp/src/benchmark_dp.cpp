#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

// Наивная рекурсия
long long fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// Мемоизация
long long fibMemo(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 40;
    
    // Бенчмарк наивной рекурсии
    auto start_naive = std::chrono::high_resolution_clock::now();
    long long result_naive = fibNaive(n);
    auto end_naive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_naive = end_naive - start_naive;

    // Бенчмарк мемоизации
    std::vector<long long> memo(n + 1, -1);
    auto start_memo = std::chrono::high_resolution_clock::now();
    long long result_memo = fibMemo(n, memo);
    auto end_memo = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_memo = end_memo - start_memo;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Вычисление " << n << "-го числа Фибоначчи:\n";
    std::cout << "Наивная рекурсия: " << elapsed_naive.count() << " сек. (Результат: " << result_naive << ")\n";
    std::cout << "Мемоизация:       " << elapsed_memo.count() << " сек. (Результат: " << result_memo << ")\n";
    
    if (elapsed_memo.count() > 0) {
        std::cout << "Мемоизация быстрее в " << (elapsed_naive.count() / elapsed_memo.count()) << " раз.\n";
    }

    return 0;
}