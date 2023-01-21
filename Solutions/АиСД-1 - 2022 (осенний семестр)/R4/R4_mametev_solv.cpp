/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>
#include <vector>
#include <stack>
#include <memory>

struct Node;

struct Run {
    std::shared_ptr<Node> destination;
    int start_time;
    int dest_time;
};

struct Node {
    int min_time = -1;
    std::vector<Run> _runs;

    void Add(const Run &run) {
        _runs.push_back(run);
    }
};

struct Graph {
    std::vector<std::shared_ptr<Node>> _nodes;

    void Add(std::shared_ptr<Node> node) {
        _nodes.push_back(std::move(node));
    }

    auto operator[](int index) {
        return _nodes[index];
    }
};


int main() {
    std::ifstream input("a.in");
    std::ofstream output("a.out");

    int n, e, m;
    input >> n >> e >> m;

    Graph graph;
    for (int i = 0; i < n; i++)
        graph.Add(std::make_shared<Node>());

    for (int i = 0; i < m; i++) {
        int k;
        input >> k;

        int start_n, start_time;
        input >> start_n >> start_time;
        start_n--;
        for (int j = 1; j < k; j++) {
            int dest_n, dest_time;
            input >> dest_n >> dest_time;
            dest_n--;

            graph[start_n]->Add(
                    {
                            graph[dest_n],
                            start_time,
                            dest_time
                    }
            );

            start_n = dest_n;
            start_time = dest_time;
        }
    }

    std::stack<std::shared_ptr<Node>> calc_stack;
    calc_stack.push(graph[0]);
    graph[0]->min_time = 0;

    while (!calc_stack.empty()) {
        auto this_node = calc_stack.top();
        calc_stack.pop();
        std::vector<Run> &this_runs = this_node->_runs;

        auto it = this_runs.begin();
        while (it != this_runs.end()) {
            auto dest = it->destination;
            if (this_node->min_time <= it->start_time) {
                if (it->dest_time < dest->min_time || dest->min_time == -1) {
                    calc_stack.push(it->destination);
                    dest->min_time = it->dest_time;
                }
                it = this_runs.erase(it);
            } else {
                it++;
            }
        }
    }
    output << graph[e - 1]->min_time;
}
