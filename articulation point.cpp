#include<bits/stdc++.h>
using namespace std;
class Graph{
private:
    int V;
    list<int> *adj;
    void APUtil(int u, bool visited[], int parent[],
                int low[], int disc[], bool articulation[]);

public:
    Graph(int v){
        this->V = v;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void AP();
};

void Graph::APUtil(int u, bool visited[], int parent[],
                   int low[], int disc[], bool articulation[]){
    int static time = 0;
    visited[u] = true;
    int children = 0;
    disc[u] = low[u] = time++;

    for(auto p=adj[u].begin(); p!=adj[u].end(); p++){

        int v = *p;
        if(!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v, visited, parent, low, disc, articulation);

            low[u] = min(low[v], low[u]);

            if(parent[u]==-1 && children>1){
                articulation[u] = true;

            }

            if(parent[u]!=-1 && low[v]>=disc[u]){
                articulation[u] = true;

            }
        }
        else if(v!=parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }
}
void Graph::AP(){
    bool *visited = new bool[V];
    int *parent = new int[V];
    int *low = new int[V];
    int *disc = new int[V];
    bool *articulation = new bool[V];

    for(int i=0; i<V; i++){
        visited[i] = false;
        parent[i] = -1;
        articulation[i] = false;
    }

    for(int i=0; i<V; i++){
        if(!visited[i]){
            APUtil(i, visited, parent, low, disc, articulation);
        }
    }
    for(int i=0; i<V; i++){
        if(articulation[i]==true) cout<<i<<" ";
    }

}
int main(){


     Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.AP();


   return 0;

}
