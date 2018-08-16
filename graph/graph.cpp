/*
*Graph
*addEdge
*BFS
*DFS
*/
#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class graph
{
private:
    int V;//no of vertices
    list<int>*adj;// pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);
    // a function used by DFS
public:
    graph(int V);
    void addEdge(int v, int w); //add edge- ipmeg
    void dfs(); // depth first tarversal
    void bfs(int s); // breadth first traversal
    bool isConnected(int v, int w);
};
//constructor of graph
graph::graph(int V)// vertex - opoi
{
    this->V=V;
    adj= new list<int>[V];
}
void graph::addEdge(int v, int w) //vertex- opoi w- ipmeg
{
    adj[v].push_back(w);//add w to v's list
}
// tyhain opoin huvid busad impeg ni zojilson esehiig shalgah
void graph::DFSUtil(int v, bool visited[])
{
/* tyhain opoin huvid zojilson ni unen bol tuhain zojilson opoi hevleh
marj visited current node as visited and print it
*/
    visited[v] = true;
    cout<< v <<" " ;
// opoin togsgold bgaa buh opoinuudiig davtah
//recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i=adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
// the function to do DFS traversal. it uses recursive DFSUTIl
void graph::dfs()
{
//mark all the verticesa as not visited
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;
//call the recursive helper function to print DFs traverssal
//starting from all vertices one by one
    for(int i=0; i<V; i++)
        if(visited[i]==false)
            DFSUtil(i,visited);
}
void graph::bfs(int s)
{
/*mark all the vertices as not visited
 buh opoin huivd zojlooguig temdegleh
*/
    bool *visited = new bool[V];
    for(int i=0; i<=V; i++)
        visited[i]=false;
/*create a  queue for bfs
shineer bfs daraalal uusgeh
*/
    list<int> queue;
//mark txhe current node as visited and queue it
// odoo baigaa opoi deer zojlood tuuniig daraalald enqueue hiih
    visited[s] = true;
    queue.push_back(s);
    cout << "Breadth first Search starting from vertex ";
    cout << s << " : " << endl;
//i will be used to get all adjacent
//vertices of a vertex
    list<int>::iterator i;
    while(!queue.empty())
    {
        //dequeue a vertex from and print it
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
//get all adacent vertices of the dequequed
//vertex s. if a adjacent hasnt been visited
//then mark it visited and enqueue it
        for(i=adj[s].begin(); i!=adj[s].end(); i++)
        {
            if(!visited[*i])
            {
                visited[*i]=true;
                queue.push_back(*i);
            }
        }
    }
}
/*Ibool graph::isConnected(int v, int w) {
    return (adj[v-1][w-1] == 1);
}
*/
int main ()
{
    graph g(10);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,1);
    g.addEdge(2,5);
    g.addEdge(3,0);
    g.addEdge(3,6);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(4,6);
    g.addEdge(5,2);
    g.addEdge(6,4);
    g.addEdge(6,7);
    g.addEdge(7,6);
    g.addEdge(7,8);
    g.addEdge(8,7);
    cout<<"dfs traversel"<<endl;
    cout<<endl;
    g.dfs();

    cout<<endl;
    cout<<"bfs traversal"<<endl;
    cout<<endl;
    g.bfs(5);
    //cout<<(char)true;
    return 0;
}
