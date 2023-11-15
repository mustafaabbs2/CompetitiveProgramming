#include <iostream>
#include <stack>
// you can do this fairly easily with recursion, since recursion is a
// stack-based approach
using namespace std;

void DFS(int u, int A[][8], int n)
{
    // Initialize visit tracking array and stack
    int visited[8]{0};
    stack<int> stk;
    stk.emplace(u);

    // Visit start vertex u
    cout << u << ", " << flush;
    visited[u] = 1; // Visited vertex u

    // Initial Adjacent vertex
    int v = 0;

    while (!stk.empty())
    {
        while (v < n)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {                // if adjacent vertex is unvisited
                stk.push(u); // Suspend exploring current vertex u
                u = v; // Update current vertex as the next adjacent vertex

                // Visit current vertex u
                cout << u << ", " << flush;
                visited[u] = 1;
                v = -1; // Increment will make this 0
            }
            v++;
        }
        v = u;         // Can set v = 0 but setting v = u is better
        u = stk.top(); // Return to previous suspended vertex
        stk.pop();
    }
}

// Simpler and adds elements to stack from end
void DFS_Simple(int u, int A[][8], int n)
{
    int visited[8]{0};
    stack<int> stk;
    stk.emplace(u); // Add start vertex to stack

    while (!stk.empty())
    {
        u = stk.top(); // Get top element
        stk.pop();

        if (visited[u] != 1)
        { // If not visited
            cout << u << ", " << flush;
            visited[u] = 1;

            for (int v = n - 1; v >= 0; v--)
            { // Visit all adjacent vertices
                if (A[u][v] == 1 && visited[v] == 0)
                {
                    stk.emplace(
                        v); // Add every adjacent, unvisited vertex to stack
                }
            }
        }
    }
}

int main()
{

    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}};

    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;

    cout << "DFS_Simple Vertex: " << u << " -> " << flush;
    DFS_Simple(u, A, 8);
    cout << endl;

    return 0;
}