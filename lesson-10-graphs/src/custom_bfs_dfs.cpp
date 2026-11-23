#include <iostream>
#include <vector>
#include <stack>
#include <queue>

// Функция DFS (в глубину) с использованием стека
void dfs(int start, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);
    std::stack<int> s;
    s.push(start);

    std::cout << "DFS (в глубину): ";
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            visited[v] = true;
            std::cout << v << " ";

            // Добавляем соседей в стек
            // TODO: Пройти по всем соседям вершины v (adj[v]) и добавить их в стек,
            // если они еще не посещены.
        }
    }
    std::cout << std::endl;
}

// Функция BFS (в ширину) с использованием очереди
void bfs(int start, const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(adj.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    std::cout << "BFS (в ширину): ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        std::cout << v << " ";

        // Добавляем соседей в очередь
        // TODO: Пройти по всем соседям вершины v (adj[v]) и добавить их в очередь,
        // если они еще не посещены (и сразу помечать visited).
    }
    std::cout << std::endl;
}

int main() {
    // Создаем граф (список смежности)
    // 0 - 1, 0 - 2, 1 - 3, 2 - 4
    std::vector<std::vector<int>> adj = {
        {1, 2},    // 0
        {0, 3},    // 1
        {0, 4},    // 2
        {1},       // 3
        {2}        // 4
    };

    dfs(0, adj);
    bfs(0, adj);

    return 0;
}