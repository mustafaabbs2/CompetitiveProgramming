// 547. Number of Provinces
// Medium

// There are n cities. Some of them are connected, while some are not. If city a
// is connected directly with city b, and city b is connected directly with city
// c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other
// cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
// ith city and the jth city are directly connected, and isConnected[i][j] = 0
// otherwise.

// Return the total number of provinces.

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                // Start DFS from unvisited city
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city)
    {
        visited[city] = true;

        // Visit connected cities
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor)
        {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor])
            {
                dfs(isConnected, visited, neighbor);
            }
        }
    }
};

int main()
{
    Solution solution;

    // Example usage
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    int provinces = solution.findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
