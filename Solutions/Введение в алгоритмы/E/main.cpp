#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::vector<std::string> outputs;

    int n;
    input >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i) {
        input >> a[i];
    }

    int buffered_doc = -1;
    for (int i = 1; i <= n; ++i) {
        while (a[i] != i) {
            if (buffered_doc == -1) {
                buffered_doc = a[i];
                std::stringstream out;
                out << '-' << a[i] << ' ' << i << '\n';
                outputs.push_back(out.str());
                a[i] = -1;
            }
            else {
                if (a[buffered_doc] == -1) {
                    a[buffered_doc] = buffered_doc;
                    std::stringstream out;
                    out << buffered_doc << ' ' << buffered_doc << '\n';
                    outputs.push_back(out.str());
                    buffered_doc = -1;
                }
                else {
                    std::stringstream out;
                    out << '-' << a[buffered_doc] << ' ' << buffered_doc << '\n';
                    outputs.push_back(out.str());
                    out = std::stringstream();
                    out << buffered_doc << ' ' << buffered_doc << '\n';
                    outputs.push_back(out.str());
                    std::swap(a[buffered_doc], buffered_doc);
                }
            }
        }
    }

    output << outputs.size() << '\n';
    for (auto & out : outputs) {
        output << out;
    }
}
