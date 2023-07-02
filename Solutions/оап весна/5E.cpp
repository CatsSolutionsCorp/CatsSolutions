#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int comp(int const &i, int const &j) {
    return i > j;
}
int paircomp(pair<int, int> const &i, pair<int, int> const &j) {
    return i.first > j.first;
}

int main() {
    
    int n;
    cin >> n;
    int a[n], ans[n];
    pair<int, int> b[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++){
        b[i].second = i;
        cin >> b[i].first;
    }

    sort(a, a+n, comp);
    sort(b, b+n, paircomp);

    bool flag = true;
    for (int i = 0; i < n; i++){
        if (a[i] <= b[i].first)
            ans[b[i].second] = a[i];
        else {
            flag = false;
            break;
        }
    }

    priority_queue<int> curr;
    if (flag) {
        int cur = 0;
        for (int i = 0; i < n; i++){
            while (cur < n and b[cur].first >= a[i]) {
                curr.push(b[cur].second);
                cur++;
            }
            ans[curr.top()] = a[i];
            curr.pop();
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
    else cout << "-1";
    
    return 0;
} 