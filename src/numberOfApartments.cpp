/* CF - 900 */
/*
A. Number of Apartments
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently a new building with a new layout was constructed in Monocarp's hometown. According to this new layout, the building consists of three types of apartments: three-room, five-room, and seven-room apartments. It's also known that each room of each apartment has exactly one window. In other words, a three-room apartment has three windows, a five-room — five windows, and a seven-room — seven windows.

Monocarp went around the building and counted n windows. Now he is wondering, how many apartments of each type the building may have.

Unfortunately, Monocarp only recently has learned to count, so he is asking you to help him to calculate the possible quantities of three-room, five-room, and seven-room apartments in the building that has n windows. If there are multiple answers, you can print any of them.

Here are some examples:

if Monocarp has counted 30 windows, there could have been 2 three-room apartments, 2 five-room apartments and 2 seven-room apartments, since 2⋅3+2⋅5+2⋅7=30;
if Monocarp has counted 67 windows, there could have been 7 three-room apartments, 5 five-room apartments and 3 seven-room apartments, since 7⋅3+5⋅5+3⋅7=67;
if Monocarp has counted 4 windows, he should have mistaken since no building with the aforementioned layout can have 4 windows.
Input
Th first line contains one integer t (1≤t≤1000) — the number of test cases.

The only line of each test case contains one integer n (1≤n≤1000) — the number of windows in the building.

Output
For each test case, if a building with the new layout and the given number of windows just can't exist, print −1.

Otherwise, print three non-negative integers — the possible number of three-room, five-room, and seven-room apartments. If there are multiple answers, print any of them.

Example
inputCopy
4
30
67
4
14
outputCopy
2 2 2
7 5 3
-1
0 0 2
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

void printNumber(int n) {
    if (n == 1 || n == 2 || n == 4) {
        cout << -1 << '\n';
        return;
    }

    if (n % 3 == 0)
        cout << n / 3 << " 0" << " 0" << '\n';
    else if (n % 3 == 1)
        cout << (n - 7) / 3 << " 0" << " 1" << '\n';
    else
        cout << (n - 5) / 3 << " 1" << " 0" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        printNumber(n);
    }

    return 0;
}
