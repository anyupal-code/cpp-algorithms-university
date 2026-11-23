#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <iomanip>
#include <limits>

const int INF = std::numeric_limits<int>::max();
typedef std::pair<int, int> Edge;

// Функция Дейкстры (для замера)
int dijkstra(int start, int end, const std::vector<std::vector<Edge>>& adj) {
    int n = adj.size();
    std::vector<int> dist(n, INF);
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
        if (u == end) return dist[u];

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[end];
}

int main() {
    const int V = 100;
    const int E = 500;

    // Генерация случайного взвешенного графа
    std::vector<std::vector<Edge>> adj(V);
    for (int i = 0; i < E; i++) {
        int u = rand() % V;
        int v = rand() % V;
        int w = rand() % 100 + 1; // Вес от 1 до 100
        if (u != v) {
            adj[u].push_back({v, w});
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    int result = dijkstra(0, V - 1, adj);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Дейкстра на графе " << V << " вершин и " << E << " ребер:\n";
    std::cout << "Кратчайший путь (0 -> " << V - 1 << "): " << (result == INF ? -1 : result) << "\n";
    std::cout << "Время работы: " << elapsed.count() << " сек.\n";
    
    return 0;
}