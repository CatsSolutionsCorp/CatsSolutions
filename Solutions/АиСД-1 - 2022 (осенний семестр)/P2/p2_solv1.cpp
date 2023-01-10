/**
 **********************************
 * Copyrighted by Artemiy Mametev *
 **********************************
 *             SALAM              *
 *             VORAM              *
 **********************************
**/

#include <fstream>
#include <algorithm>
#include <queue>

int main() {
    std::ifstream input("game.in");
    std::ofstream output("game.out");

    long long n, k;
    input >> n >> k;

    auto *a = new long long[n];
    for (long long i = 0; i < n; i++)
        input >> a[i];

    std::sort(a, a + n);

    long long l = 0, r = 0;
    long long combinations = 0;
    std::queue<long long> repeat_queue;
    long long twice_repeated = 0;
    while (r < n) {
        while (r < n && (a[r] / a[l] < k || a[r] / a[l] == k && a[r] % a[l] == 0)) {
            long long this_right = a[r];
            long long repeat_ctr = 0;
            while (r < n && a[r] == this_right) {
                r++;
                repeat_ctr++;
            }
            repeat_queue.push(repeat_ctr <= 3 ? repeat_ctr : 3);

            long long all = repeat_queue.size();

            if (all >= 2)
                combinations += 3 * (all - 1) * (all - 2) + 3 * twice_repeated;

            if (repeat_ctr >= 2) {
                combinations += 3 * (all - 1);
                twice_repeated++;
            }

            if (repeat_ctr >= 3)
                combinations++;
        }

        long long this_left = a[l];
        while (this_left == a[l])
            l++;

        if (repeat_queue.front() >= 2)
            twice_repeated--;

        repeat_queue.pop();
    }

    output << combinations;

    return 0;
}
