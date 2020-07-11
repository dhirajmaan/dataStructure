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
void printBFS(int **edges, int v, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

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

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    cout << "print DFS" << endl;
    printDFS(edges, v, 0, visited);
    cout << "printBFS" << endl;
    printBFS(edges, v, 0);

    //deleteion
    for (int i = 0; i < v; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}