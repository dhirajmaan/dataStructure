#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int v, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < v; i++)
    {
        if (sv == i)
        {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i])
        {

            printDFS(edges, v, i, visited);
        }
    }
}
void DFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, v, i, visited);
        }
    }

    delete[] visited;
}
void printBFS(int **edges, int v, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertices = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertices << endl;
        for (int i = 0; i < v; i++)
        {
            if (edges[currentVertices][i] == 1 && !visited[i])
            {
                if (sv == i)
                {
                    continue;
                }
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, v, i, visited);
        }
    }

    delete[] visited;
}
int main()
{
    int v, e;
    cout << "Enter the no of vertices" << endl;
    cin >> v;
    cout << "enter the no of edges" << endl;
    cin >> e;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            edges[i][j] = 0;
        }
    }
    int from, to;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the edges as from : to" << endl;
        cin >> from >> to;
        edges[from][to] = 1;
        edges[to][from] = 1;
    }

    cout << "print DFS" << endl;
    DFS(edges, v);
    cout << "print BFS" << endl;
    BFS(edges, v);

    //deleteion
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}