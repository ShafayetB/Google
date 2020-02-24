
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int numVertices;
    int time;
    list<int> *adjLists;
    char *color;
    int *prev;
    int *d;
    int *f;

public:
    Graph(int vertices_count){
        numVertices = vertices_count;
        adjLists = new list<int>[vertices_count];
        color = new char[vertices_count];
        prev = new int[vertices_count];
        d = new int[vertices_count];
        f = new int[vertices_count];
        time=0;
    }
    void addEdge(int src, int dest){
        adjLists[src].push_back(dest);
    }
    void DFS(){
       for(int i=0;i<numVertices;i++){
            color[i]='W';
            prev[i]=-1;
            d[i]=-1;
            f[i]=-1;
        }
        for(int i=0;i<numVertices;i++){
            if(color[i]=='W'){
                DFS_Visit(i);
            }
        }
    }

    void DFS_Visit(int vertex){
        color[vertex]='G';
        time++;
        d[vertex]=time;
        list<int> adjList = adjLists[vertex];
        cout << vertex << " ";
        list<int>::iterator i;
        for(i = adjList.begin(); i != adjList.end(); ++i){
            if(color[*i]=='W'){
                prev[*i]=vertex;
                DFS_Visit(*i);
            }
        }
        color[vertex]='B';
        time++;
        f[vertex]=time;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.DFS();
    return 0;
}
