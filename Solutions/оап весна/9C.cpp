#include <fstream>
#include <vector>

#define SIZE 100000
class Queue {
private:

    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() const {
        if (front == -1)
            return true;
        else
            return false;
    }

    void enQueue(int element) {
        if (front == -1) front = 0;
        rear++;
        items[rear] = element;
    }

    int getFront(){
        return items[front];
    }

    int deQueue() {
        int element;
        if (isEmpty()) {

            return (-1);
        } else {
            element = items[front];
            if (front >= rear) {
                front = -1;
                rear = -1;
            } else {
                front++;
            }

            return (element);
        }
    }
};


    int main() {
        std::ifstream in("input.txt");
        std::ofstream out("output.txt");

        int n, m;

        in >> n >> m;

        std::vector<std::vector<int>> graph(n + 1);
        std::vector<int> degree(n + 1, 0), result;
        Queue que;


        for (int i = 0; i < m; i++) {
            int a, b;

            in >> a >> b;

            graph[a].emplace_back(b);
            degree[b]++;
        }

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0)
                que.enQueue(i);
        }

        while (!que.isEmpty()) {
            int v = que.getFront();

            que.deQueue();
            result.emplace_back(v);

            for (int u: graph[v]) {
                degree[u]--;

                if (degree[u] == 0)
                    que.enQueue(u);
            }
        }

        if (result.size() != n) {
            out << -1;
        } else {
            for (auto v: result)
                out << v << " ";
        }

        return 0;
    }