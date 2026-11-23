#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

// Структура для хранения ребра: (сосед, вес)
typedef std::pair<int, int> Edge;

void dijkstra(int start, const std::vector<std::vector<Edge>>& adj) {
    int n = adj.size();
    std::vector<int> dist(n, INF);
    dist[start] = 0;

    // Min-Heap: хранит пары (расстояние, вершина)
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

        // Если мы уже нашли более короткий путь, пропускаем
        if (d > dist[u]) continue;

        // TODO: Пройти по всем соседям вершины u (adj[u]).
        // Для каждого соседа v с весом w:
        // Если dist[u] + w < dist[v]:
        //   1. Обновить dist[v] = dist[u] + w.
        //   2. Добавить пару {dist[v], v} в pq.
    }

    // Вывод результатов
    std::cout << "Кратчайшие расстояния от вершины " << start << ":" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "До " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << std::endl;
    }
}

int main() {
    int n = 5;
    std::vector<std::vector<Edge>> adj(n);

    // Пример графа (взвешенный):
    // 0 - 1 (вес 4), 0 - 2 (вес 1)
    // 2 - 1 (вес 2), 1 - 3 (вес 1), 2 - 3 (вес 5), 3 - 4 (вес 3)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    dijkstra(0, adj);

    return 0;
}