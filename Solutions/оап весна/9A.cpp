#include <fstream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
int n, m;

bool dfs(int v, int parent) {
    visited[v] = true;

    for (auto u: graph[v]) {
        if (!visited[u]) {
            if (dfs(u, v))
                return true;
            
        } else if (u != parent)
            return true;
        
    }
    return false;
}

int main() 
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    fin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) 
    {
        int a, b;

        fin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool isTree = true;
    int countConnected = 0, countEdges = 0;

    for (int i = 1; i <= n; i++) 
    {
        if (!visited[i]) {
            countConnected++;

            if (countConnected > 1 || (countEdges > 0)) 
            {
                isTree = false;
                break;
            }

            if (dfs(i, -1)) 
            {
                isTree = false;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        countEdges += graph[i].size();


    if (isTree && countEdges == 2 * (n - 1))
        fout << "YES";
    else
        fout << "NO";

    return 0;
}