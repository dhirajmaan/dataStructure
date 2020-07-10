#include <iostream>
#include <queue>
using namespace std;
void printDFS(int **edges, int v, int startingVertex, bool *visited)
{
    cout << startingVertex << endl;
    visited[startingVertex] = true;
    for (int i = 0; i < v; i++)
    {
        if (startingVertex == i)
        {
            continue;
        }
        if (edges[startingVertex][i] == 1 && !visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }
}
void printBFS(int **edges, int v, int startingVertex)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    queue<int> pendingVertice;

    pendingVertice.push(startingVertex);
    visited[startingVertex] = true;
    while (!pendingVertice.empty())
    {
        int currentVertices = pendingVertice.front();
        cout<<currentVertices<<endl;
        pendingVertice.pop();
        for (int i = 0; i < v; i++)
        {
            if(currentVertices==i){
                continue;
            }
            if (edges[currentVertices][i] && !visited[i])
            {
                pendingVertice.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    int v;
    cout << "enter no of vertices" << endl;
    cin >> v;
    int n;
    cout << "enter the no of edges" << endl;
    cin >> n;
    int from, to;
    int **edges = new int *[v];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "enter the connecting edges from and to" << endl;
        cin >> from >> to;
        edges[from][to] = 1;
        edges[to][from] = 1;
    }
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    cout << "print DFS" << endl;
    printDFS(edges, v, 0, visited);
    cout << "print BFS"<<endl;
    printBFS(edges, v, 0);

    //delete the memory;
    for (int i = 0; i < v; i++)
    {
       delete[]edges[i];
    }
    delete[]edges;
    delete[] visited;    

}