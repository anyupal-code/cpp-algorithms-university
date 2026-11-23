#include <iostream>
#include <vector>

// Наивная рекурсия (для сравнения)
long long fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// Мемоизация (сверху вниз)
long long fibMemo(int n, std::vector<long long>& memo) {
    if (n <= 1) return n;
    
    // TODO 1: Если memo[n] уже вычислено (не -1), вернуть memo[n].
    
    // TODO 2: Иначе вычислить значение: memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo).
    // И вернуть memo[n].
    
    return 0;
}

int main() {
    int n = 40;
    
    // Инициализация массива для мемоизации
    std::vector<long long> memo(n + 1, -1);
    
    std::cout << "Число Фибоначчи (n = " << n << "):" << std::endl;
    std::cout << "Мемоизация: " << fibMemo(n, memo) << std::endl;
    
    return 0;
}