#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>


class Graph {

public:
    // Constructs new graph (without edges for now) of V vertices
    Graph(int V);

    // Add new edge (v-w) to the graph
    void addEdge(int vertex, int w);

    // Returns a collection of all vertices that are adjacent to given vertex v
    std::vector<int> adj(int v);

    // Returns number of vertices in the graph
    int V();

    // Returns number of edges in the graph
    int E();

    // Returns some string representation of the graph
    std::string toString();

    bool findConnection(int v, int v2);

    std::stack<int> findPath(int v1, int v2);

    void vanishStructs();

    int getConnectedComponent(int v);

    bool isBipartite();

private:
    std::vector<std::vector<int>> vec;
    std::set<int> v_set;
    std::vector<int> arrVer;
    std::map<int, int> mapOfSets;
    int res = 0;
    std::map<int, std::string> evenOdd;

    void dfs(int v);
};

Graph::Graph(int V) {
    arrVer.assign(V, -1);
    std::vector<int> cell = {};
    for (int i = 0; i < V; ++i) {
        vec.push_back(cell);
    }
}

void Graph::addEdge(int vertex, int nbVertex) {
    vec[vertex].push_back(nbVertex);
    vec[nbVertex].push_back(vertex);
}

std::vector<int> Graph::adj(int vertex) {
    if (vertex <= V() && vertex >= 0) {
        std::vector<int> value;
        value = vec[vertex];
        return value;
    } else {
        throw std::invalid_argument("There is no such vertex!");
    }
}

int Graph::V() {
    return vec.size();
}

int Graph::E() {
    int sum = 0;
    for (const auto &v:vec) {
        sum += v.size();
    }
    sum = sum / 2;
    return sum;
}

std::string Graph::toString() {
    std::string s;
    for (int i = 0; i < vec.size(); ++i) {
        s += std::to_string(i);
        s += ": ";
        for (int j = 0; j < vec[i].size(); ++j) {
            s += std::to_string(vec[i][j]);
            if (vec[i][j] != vec[i][vec[i].size() - 1] && vec[i][j + 1]) {
                s += ", ";
            }
        }
        s += "\n";
    }

    return s;
}

bool Graph::findConnection(int v, int v2) {
    vanishStructs();
    bool Flag = false;
    dfs(v);
    if (v_set.find(v2) != v_set.end()) {
        Flag = true;
    }
    return Flag;
}

void Graph::dfs(int v) {
    int count = 0;
    std::string even = "even";
    std::string odd = "odd";
    v_set.insert(v);
    evenOdd[0] = odd;
    while (!vec[v].empty() && count <= vec[v].size() - 1) {
        if (evenOdd.find(vec[v][count]) == evenOdd.end()){
            if (evenOdd[v] == "even"){
                evenOdd[vec[v][count]] = odd;
            }else{
                evenOdd[vec[v][count]] = even;
            }
        }else {
            count++;
            continue;
        }
        if (v_set.find(vec[v][count]) == v_set.end()) {
            arrVer[vec[v][count]] = v;
            dfs(vec[v][count]);
        }
        count++;
    }
}

std::stack<int> Graph::findPath(int v1, int v2) {
    vanishStructs();
    std::stack<int> path;
    dfs(v1);
    while (arrVer[v2] != -1) {
        path.push(v2);
        v2 = arrVer[v2];
    }
    path.push(v1);
    return path;
}

void Graph::vanishStructs() {
    arrVer.assign(V(), -1);
    v_set.clear();
}

int Graph::getConnectedComponent(int v) {
    if (!mapOfSets.empty()){
        if(mapOfSets.find(v) != mapOfSets.end()){
            return mapOfSets[v];
        }
    }
    vanishStructs();
    dfs(v);
    for (auto el:v_set){
        mapOfSets[el] = res;
    }
    return res++;
}

bool Graph::isBipartite() {
    return evenOdd.size() == V();
}


int main() {
//    Graph g(11);
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,6);
    g.addEdge(0,5);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(2,0);
    g.addEdge(3,1);
    g.addEdge(3,5);
    g.addEdge(4,6);
    g.addEdge(4,5);
    g.addEdge(5,0);
    g.addEdge(5,3);
    g.addEdge(6,0);
    g.addEdge(6,4);

//    g.addEdge(0, 1);
//    g.addEdge(0, 3);
//    g.addEdge(0, 4);
//    g.addEdge(1, 2);
//
//    g.addEdge(6, 7);
//    g.addEdge(7, 8);
//    g.addEdge(8, 9);
//    g.addEdge(9, 10);

    std::cout << "Path: ";
    std::stack<int> path = g.findPath(0, 4);
    int pathSize = path.size();
    for (int i = 0; i < pathSize; ++i) {
        std::cout << path.top() << " " << std::flush;
        path.pop();
    }
//
//    std::cout << std::endl;
//
//    std::cout << "Connection: " << g.findConnection(1, 10) << std::endl;
//
//    std::cout << "toPrint: " << g.toString() << std::endl;
//
//    std::cout << "ADJ: : " << std::endl;
//    for (auto v:g.adj(0)) {
//        if (v) {
//            std::cout << v;
//            if (v != g.adj(0)[g.adj(0).size() - 1]) {
//                std::cout << ", ";
//            }
//        }
//    }
//    std::cout << std::endl;
//
//    std::cout << "countVertices: " << g.V() << std::endl;
//    std::cout << "countEdges: " << g.E() << std::endl;
//
//    std::cout << "get CC: " << g.getConnectedComponent(1) << std::endl;
//    std::cout << "get CC: " << g.getConnectedComponent(7) << std::endl;
//    std::cout << "get CC: " << g.getConnectedComponent(5) << std::endl;

    return 0;
}
