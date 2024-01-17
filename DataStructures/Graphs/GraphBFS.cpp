#include <iostream>
#include <queue>

// Breadth First Search

// Need
// 1. Array for visited vertices
// 2. Queue for BFS

using namespace std;

void BFS(int vtx, int A[][8], int n)
{

    queue<int> Q;
    int visited[8]{0}; // created a n-sized array to show if a vertex has been
                       // visited or not

    cout << vtx << ", " << flush; // Visit first vertex
    visited[vtx] = 1;
    Q.emplace(vtx); // emplace is enqueue

    // Explore
    while (!Q.empty())
    {
        int u = Q.front(); // Vertex u for exploring
        Q.pop();
        for (int v = 1; v <= n; v++)
        { // Adjacent vertices of vertex u (all on the same row)
            if (A[u][v] == 1 && visited[v] == 0)
            {                               // Adjacent vertex and not visited
                cout << v << ", " << flush; // Visit vertex
                visited[v] = 1;             // mark as visited
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main()
{

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8); // start with vertex 1

    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8); // start with vertex 4

    return 0;
}