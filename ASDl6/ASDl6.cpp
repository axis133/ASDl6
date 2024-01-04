#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct Edge {
    int to;
    int weight;
};

int findMinimumDistance(const std::vector<std::vector<Edge>>& graph, int source, int numNodes) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    std::vector<int> dist(numNodes, std::numeric_limits<int>::max());

    dist[source] = 0;

    pq.push(std::make_pair(source, dist[source]));

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;

                pq.push(std::make_pair(v, dist[v]));
            }
        }
    }

    int minDistance = 0;
    for (int i = 0; i < numNodes; ++i) {
        minDistance += dist[i];
    }

    return minDistance;
}

int main() {
    int numNodes = 7;

    std::vector<std::vector<Edge>> graph(numNodes);

    graph[0].push_back({ 2, 4 });
    graph[0].push_back({ 1, 3 });
    graph[0].push_back({ 5, 5 });
    graph[0].push_back({ 3, 7 });
    graph[1].push_back({ 3, 6 });
    graph[1].push_back({ 6, 9 });
    graph[1].push_back({ 4, 4 });
    graph[2].push_back({ 5, 6 });
    graph[3].push_back({ 5, 3 });
    graph[3].push_back({ 6, 6 });
    graph[4].push_back({ 6, 7 });
    graph[5].push_back({ 6, 6 });

    int source = 0;

    int minimumDistance = findMinimumDistance(graph, source, numNodes);

    std::cout << "Минимальная сумма дистанций: " << minimumDistance << std::endl;

    return 0;
}
