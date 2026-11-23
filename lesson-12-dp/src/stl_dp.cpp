#include <iostream>
#include <vector>
#include <algorithm>

// Задача о рюкзаке (0/1)
int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    // Таблица dp: (n+1) строк, (W+1) столбцов
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Максимум из: взять предмет или не взять
                dp[i][w] = std::max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                // Предмет не помещается, берем значение с предыдущего шага
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10; // Вместимость рюкзака
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 8};

    int maxValue = knapsack(W, weights, values);
    std::cout << "Максимальная стоимость в рюкзаке: " << maxValue << std::endl;

    return 0;
}