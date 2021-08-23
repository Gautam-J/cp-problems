/* CF - 900 */
/*
B. Sale
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Once Bob got to a sale of old TV sets. There were n TV sets at that sale. TV set with index i costs ai bellars. Some TV sets have a negative price — their owners are ready to pay Bob if he buys their useless apparatus. Bob can «buy» any TV sets he wants. Though he's very strong, Bob can carry at most m TV sets, and he has no desire to go to the sale for the second time. Please, help Bob find out the maximum sum of money that he can earn.

Input
The first line contains two space-separated integers n and m (1 ≤ m ≤ n ≤ 100) — amount of TV sets at the sale, and amount of TV sets that Bob can carry. The following line contains n space-separated integers ai ( - 1000 ≤ ai ≤ 1000) — prices of the TV sets.

Output
Output the only number — the maximum sum of money that Bob can earn, given that he can carry at most m TV sets.

Examples
inputCopy
5 3
-6 0 35 -2 4
outputCopy
8
inputCopy
4 2
7 0 0 -7
outputCopy
7
*/

/* Time Complexity: O(n log n) */
/* Space Complexity: O(N) where N is the number of negative numbers. */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define trav(i, a) for (auto& i : a)
#define debug(x) cout << "[DEBUG] " << #x << "=" << x << '\n'

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

int maxTV(vi& a, int m) {
    priority_queue<int> profit;

    trav(i, a) {
        if (i < 0)
            profit.push(i);
    }

    while (!profit.empty() && (int)profit.size() > m)
        profit.pop();

    int res = 0;
    while(!profit.empty()) {
        res += profit.top();
        profit.pop();
    }

    return res * -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi a(n);
    trav(i, a)
        cin >> i;

    cout << maxTV(a, m) << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
