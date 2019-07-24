//#include<iostream>
//#include<vector>

#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define SIZE 100
int adj [SIZE] [SIZE];
int colour [SIZE];
int parent [SIZE];
int dis [SIZE];

void bfs (int adj[][SIZE],int vertex,int s);
void printPath(int s,int endNode);


int main () {
    vector <int> vec[8];
    int vertex;
    int edge;
    int choice;
    int n;


    while (1) {
        //cout<<"----------------------------"<<endl;
        cout<<"1.Adjacency nodes of a node. \n2. Shortest path from a node."<<endl;
        cout<<"Please enter your choice: ";
        cin>>choice;


        if(choice==1) {
        cout<<"enter a node:"<<endl;
        cin>>n;

    vector <int>vec[5];
    int vertex;
    int edge;
    cin>>vertex>>edge;
    cout<<"vertex is :"<<vertex <<endl;
    cout<<"Edge is :"<<edge<<endl;

    int node1,node2;
    for (int i=0;i<edge;i++) {
        cin>>node1>>node2;
        vec[node1].push_back(node2);
        vec[node2].push_back (node1);

    }
    for (int i=0;i<vec[n].size();i++) {
    cout<<vec[n][i];
    }

    break;
    }

    if(choice==2) {

    int vertex;
    int edge;
    cin>>vertex>>edge;
    cout<<"vertex is :"<<vertex <<endl;
    cout<<"Edge is :"<<edge<<endl;

    int node1,node2;
    for (int i=0;i<edge;i++) {
        cin>>node1>>node2;
        adj[node1][node2]=1;
        adj[node2][node1]=1;

    }

    for(int i=0;i<vertex;i++) {
        for(int j=0;j<vertex;j++) {
            cout<<adj[i][j]<<" ";

        }
        cout<<endl;
    }
    bfs(adj,vertex,0);
    cout<<endl;
    printPath(0,8);
    break;
    }

    else

        cout<<"exit the program"<<endl;

    break;

    }
}

void bfs (int adj[][SIZE],int vertex,int s) {
     for (int i=0;i<vertex;i++) {
         if(i!=s) {
             colour[i]=WHITE;
             dis[i]=INT_MIN;  // Infinity
             parent[i]=-1;    // Null
         }
     }
     colour[s]=GRAY;
     dis[s]=0;
     parent [s]=-1;  // Null
     queue<int>bfsQueue;
     bfsQueue.push(s);

    cout<<"BFS is:";
    while (!bfsQueue.empty()) {
     int u=bfsQueue.front();
     cout<<u<<"";
     bfsQueue.pop();
     for(int i=0;i<vertex;i++) {
         if(adj[u][i]!=0) {
             int v=i;
             if(colour[v]==WHITE) {
                 colour[v]=GRAY;
                 dis[v]=dis [u]+1;
                 parent[v]=u;
                 bfsQueue.push(v);
             }
         }
     }
     colour[u]=BLACK;
  }
 }
void printPath(int s,int endNode) {

     if(endNode==s) {
         cout<<s<<endl;
     }
         else if(parent[endNode]==0) {
                cout<<"No Path Exist"<<endl;
          }
           else {
                printPath(s,parent[endNode]);
                cout<<endNode<<endl;
          }
}
