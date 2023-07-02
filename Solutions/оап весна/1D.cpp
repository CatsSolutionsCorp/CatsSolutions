#include <fstream>
#include <algorithm>
#include <vector>

struct TeamResult {
    int team;
    int solved_count;
    int total_time;
};

struct Entry {
    int team;
    int problem;
    int time;
    int result;
};

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int teams, n;
    fin >> teams >> n;
    std::vector<Entry> entries;
    for (int i = 0; i < n; ++i) {
        int c, p, t, r;
        fin >> c >> p >> t >> r;
        entries.push_back(Entry {.team = c, .problem = p,
                                 .time = t, .result = r});
    }

    std::vector<TeamResult> team_results;
    for (int i = 1; i <= teams; ++i) {
        team_results.push_back(TeamResult {.team = i,
                                           .solved_count = 0,
                                           .total_time = 0});
    }

    for (int team = 1; team <= teams; ++team) {
        for (int problem = 1; problem <= 20; ++problem) {
            int min_time = INT32_MAX;
            for (const Entry &entry : entries) {
                if (entry.team == team and entry.problem == problem and entry.result == 1) {
                    min_time = std::min(min_time, entry.time);
                }
            }
            if (min_time != INT32_MAX)  {
                team_results[team - 1].solved_count++;
                team_results[team - 1].total_time += min_time;
                for (const Entry &entry : entries) {
                    if (entry.team == team and entry.problem == problem and
                        entry.time < min_time and entry.result == 0) {
                        team_results[team - 1].total_time += 20 * 60;
                    }
                }
            }
        }
    }


    std::sort(team_results.begin(), team_results.end(),
        [](TeamResult a, TeamResult b) {
            if (a.solved_count != b.solved_count) {
                return a.solved_count > b.solved_count;
            }
            if (a.total_time != b.total_time)
                return a.total_time < b.total_time;
            return a.team < b.team;
        });

    for (auto& team_result : team_results) {
        fout << team_result.team << " ";
    }

    return 0;
}