#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>

const int INF = std::numeric_limits<int>::max();

typedef std::pair<int, int> Edge; // (сосед, вес)

int main() {
    // Граф: 0=A, 1=B, 2=C, 3=D, 4=E
    int n = 5;
    std::vector<std::vector<Edge>> adj(n);
    std::vector<std::string> names = {"A", "B", "C", "D", "E"};

    // A(0) - B(1) = 4, A(0) - C(2) = 1
    // C(2) - B(1) = 2, B(1) - D(3) = 1, C(2) - D(3) = 5, D(3) - E(4) = 3
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    int start = 0; // A
    int end = 4;   // E

    std::vector<int> dist(n, INF);
    std::vector<int> parent(n, -1);
    dist[start] = 0;

    std::priority_queue<
        std::pair<int, int>, 
        std::vector<std::pair<int, int>>, 
        std::greater<std::pair<int, int>>
    > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u; // Запоминаем, откуда пришли
                pq.push({dist[v], v});
            }
        }
    }

    // Восстановление пути
    if (dist[end] == INF) {
        std::cout << "Путь не найден." << std::endl;
    } else {
        std::vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());

        std::cout << "Кратчайший путь от " << names[start] << " до " << names[end] << ":" << std::endl;
        for (size_t i = 0; i < path.size(); i++) {
            std::cout << names[path[i]];
            if (i < path.size() - 1) std::cout << " -> ";
        }
        std::cout << "\nДлина пути: " << dist[end] << std::endl;
    }

    return 0;
}