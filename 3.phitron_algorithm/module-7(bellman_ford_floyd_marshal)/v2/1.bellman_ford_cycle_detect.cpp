#include <iostream>

using namespace std;

class Edge {
   public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edgelists;
    int dis[n];

    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }

    while (e--) {
        int u, v, c;
        cin >> u >> v >> c;

        edgelists.push_back(Edge(u, v, c));
    }

    dis[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge el : edgelists) {
            int u = el.u;
            int v = el.v;
            int c = el.c;

            if (dis[u] != INT_MAX && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }

    bool cycle = false;

    for (int i = 0; i < 1; i++) {
        for (Edge el : edgelists) {
            int u = el.u;
            int v = el.v;
            int c = el.c;

            if (dis[u] != INT_MAX && dis[u] + c < dis[v]) {
                cycle = true;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << "->" << dis[i] << endl;
    // }

    if (cycle) {
        cout << "cycle";

    } else {
        cout << "not cycle";
    }

    return 0;
}