#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>
#include <iomanip>

// Симуляция DFS (может долго блуждать)
bool dfs_search(const std::vector<std::vector<int>>& grid, int n, int m) {
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::stack<std::pair<int, int>> s;
    s.push({0, 0});
    visited[0][0] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();

        if (x == n - 1 && y == m - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
    return false;
}

// Симуляция BFS (всегда идет по кратчайшему пути)
bool bfs_search(const std::vector<std::vector<int>>& grid, int n, int m) {
    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) return true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    int n = 100, m = 100;
    std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));

    // Создаем простой лабиринт с одним выходом (в правом нижнем углу)
    // и множеством тупиков (создадим "стены" для ветвления)
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) {
            grid[i][m - 1] = 1; // Стена в конце строки
            grid[i][0] = 1;
        }
    }
    grid[n - 1][m - 1] = 0; // Оставляем выход

    // Бенчмарк DFS
    auto start_dfs = std::chrono::high_resolution_clock::now();
    dfs_search(grid, n, m);
    auto end_dfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_dfs = end_dfs - start_dfs;

    // Бенчмарк BFS
    auto start_bfs = std::chrono::high_resolution_clock::now();
    bfs_search(grid, n, m);
    auto end_bfs = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_bfs = end_bfs - start_bfs;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Поиск пути в лабиринте 100x100:\n";
    std::cout << "DFS (стек): " << elapsed_dfs.count() << " сек.\n";
    std::cout << "BFS (очередь): " << elapsed_bfs.count() << " сек.\n";
    if (elapsed_bfs.count() > 0) {
        std::cout << "BFS быстрее в " << (elapsed_dfs.count() / elapsed_bfs.count()) << " раз.\n";
    }

    return 0;
}