#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Поиск кратчайшего пути в лабиринте с помощью BFS
int shortestPath(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Если старт или финиш — стена, пути нет
    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    
    // Массив для хранения расстояний
    std::vector<std::vector<int>> dist(n, std::vector<int>(m, -1));
    dist[0][0] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
            return dist[x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1; // Путь не найден
}

int main() {
    // 0 - проход, 1 - стена
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int result = shortestPath(grid);
    if (result != -1) {
        std::cout << "Кратчайший путь: " << result << " шагов." << std::endl;
    } else {
        std::cout << "Путь не найден." << std::endl;
    }

    return 0;
}