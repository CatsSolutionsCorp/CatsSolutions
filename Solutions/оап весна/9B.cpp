#include <fstream>
#include <vector>

using namespace std;

void dfs(int v, vector<vector<int>> &graph, vector<bool> &visited) 
{
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int u = graph[v][i];
        if (!visited[u])
            dfs(u, graph, visited);
    }
}

int main() 
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) 
    {
        int a, b;
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    int count = 0;

    for (int i = 1; i <= n; i++)
        if (!visited[i]) 
        {
            dfs(i, graph, visited);
            count++;
        }
    
    fout << count << endl;

    return 0;
}