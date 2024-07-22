#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, char> Pair;

// Dijkstra's Algorithm function
void dijkstra(unordered_map<char, vector<Pair>>& graph, char start, unordered_map<char, int>& distances, unordered_map<char, char>& previous) {
    for (const auto& pair : graph) {
        distances[pair.first] = INT_MAX;
        previous[pair.first] = '\0';
    }
    
    set<Pair> pq;
    pq.insert({0, start});
    distances[start] = 0;
    
    while (!pq.empty()) {
        auto it = pq.begin();
        int current_distance = it->first;
        char current_vertex = it->second;
        pq.erase(it);
        
        for (const auto& neighbor : graph[current_vertex]) {
            char next_vertex = neighbor.first;
            int weight = neighbor.second;
            int new_distance = current_distance + weight;
            
            if (new_distance < distances[next_vertex]) {
                auto found = pq.find({distances[next_vertex], next_vertex});
                if (found != pq.end()) {
                    pq.erase(found);
                }
                distances[next_vertex] = new_distance;
                previous[next_vertex] = current_vertex;
                pq.insert({new_distance, next_vertex});
            }
        }
    }
}

// Function to print the shortest path
void printPath(char start, char end, unordered_map<char, char>& previous) {
    vector<char> path;
    for (char at = end; at != '\0'; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    
    if (path[0] == start) {
        cout << "The shortest path from " << start << " to " << end << " is: ";
        for (char vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No path exists from " << start << " to " << end << "." << endl;
    }
}

int main() {
    // Hard-coded example graph based on the given structure
    unordered_map<char, vector<Pair>> graph = {
        {'A', {{'B', 10}, {'E', 3}}},
        {'B', {{'C', 2}, {'E', 1}}},
        {'C', {{'D', 9}}},
        {'D', {}},
        {'E', {{'B', 4}, {'D', 2}}}
    };
    
    char start, end;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the end node: ";
    cin >> end;
    
    unordered_map<char, int> distances;
    unordered_map<char, char> previous;
    
    dijkstra(graph, start, distances, previous);
    
    if (distances[end] == INT_MAX) {
        cout << "No path exists from " << start << " to " << end << "." << endl;
    } else {
        cout << "The cost of the shortest path is: " << distances[end] << endl;
        printPath(start, end, previous);
    }
    
    return 0;
}
