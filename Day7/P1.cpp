#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

static unordered_map<string, int> IdColorMap;
static int Identity = 0;

struct Vertex {
    int id;
    int quantity;
    string color;

    Vertex(int id, string color) :id(id), color(color) {
    }

    Vertex(int id, string color, int quantity) :id(id), color(color), quantity(quantity) {
    }
};

class Graph {
    int v;
    vector<Vertex>* adj;
    vector<Vertex>* ref;

public:
    Graph(int v) :v(v) {
        adj = new vector<Vertex>[600];
        ref = new vector<Vertex>[600];
    }

    void AddEdge(Vertex u, Vertex v) {
        adj[u.id].push_back(v);
        ref[v.id].push_back(u);
    }

    int BFS(Vertex v, bool rev = false) {
        vector<Vertex>* arr;
        if(rev) arr = ref;
        else arr = adj;
        
        int count = 0;
        bool visited[600];
        for (int i = 0; i < 600; i++) {
            visited[i] = false;
        }

        queue<Vertex> que;
        visited[v.id] = true;
        que.push(v);

        while (!que.empty()) {
            v = que.front();
            que.pop();

            for (auto i : arr[v.id]) {
                if (!visited[i.id]) {
                    count++;
                    visited[i.id] = true;
                    que.push(i);
                }
            }
        }
        return count;
    }
};

int getId(string& color) {
    unordered_map<string, int>::iterator got = IdColorMap.find(color);
    if (got != IdColorMap.end())
        return got->second;
    IdColorMap[color] = ++Identity;
    return Identity;
}

int parseInt(string& x) {
    int n = 0;
    for (auto& ch : x) {
        if (ch > '0' || ch < '9')
            n = n * 10 + ch - '0';
    }
    return n;
}

void parseLine(Graph& g, string& line) {
    vector<string> words;
    string word = "";
    for (auto& ch : line) {
        if (ch == ' ') {
            words.push_back(word);
            word = "";
        }
        else word += ch;
    }
    string parent = words[0] + words[1];
    vector<pair<string, int> > childrens;
    int num, i = 4;
    string color;
    while (i < words.size()) {
        if (words[i] == "no") break;
        num = parseInt(words[i]);        
        color = words[i + 1] + words[i + 2];
        childrens.push_back(make_pair(color, num));
        i += 4;
    }
    for (auto& child : childrens) {
        g.AddEdge(Vertex(getId(parent), parent), Vertex(getId(child.first), child.first, child.second));
    }

}

int main() {
    ifstream input;
    input.open("input.txt");
    Graph g(600);
    string line;
    int i = 0;
    while (getline(input, line)) {
        parseLine(g, line);
    }
    string color = "shinygold";
    int bag = 0;
    bag = getId(color);

    cout << g.BFS(Vertex(bag, color), true) << "\n";

    input.close();
    return 0;
}
