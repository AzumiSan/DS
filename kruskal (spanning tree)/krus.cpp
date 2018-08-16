/* kruskal algorithm */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef  pair<int, int> iPair;
struct Graph
{
    int V, E;
    vector< pair<int, iPair> > edges;

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w);
    int kruskalMST();
};
void Graph :: addEdge(int u, int v, int w)
{
    edges.push_back({w, {u, v}});
}
struct Disconnect
{
    int *parent, *rnk;
    int n;
// tuhain  graph tsikl uussen nuu ugui yu gedguug shalgaj
    Disconnect
    (int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

 //jing hapuulah

int Graph::kruskalMST()
{
    int mst_wt = 0;
    //mininum cost ggargah
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    Disconnect ds(V);

    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

    // tsikl uusj bgaa yu ugui yu gedgiig shalgah
        if (set_u != set_v)
        {
            // uuseegui bhiin bol opoinuudaa hevleh
            cout << u << " - " << v << endl;
            // jinguudee gargah
            mst_wt += it->first;
        // ihees ni baga puu epemblen baga jingee avj bgaa heseg
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
}
int main()
{
    /* unidrected graph */
    int V = 9, E = 14;
    Graph g(V, E);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << "ipmeguud \n";
    int mst_wt = g.kruskalMST();

    cout << "\nniit jin " << mst_wt;
    return 0;
}
