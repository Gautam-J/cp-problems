/* CF - 900 */
/*
N. Waste Sorting
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
The progress is not standing still in Berland. Recently all garbage containers in Bertown, the capital of Berland, were replaced by differentiated recycling bins, each accepting some category of waste. While this will definitely improve the ecological situation, for some citizens it's difficult to get used to the habit of sorting waste.

Monocarp is one of those citizens who tries to get used to waste sorting. Today he has to take out the trash from his house. There are three containers near the Monocarp's house, the first one accepts paper waste, the second one accepts plastic waste, and the third one — all other types of waste. It is possible to fit c1 items into the first container, c2 items into the second container and c3 items into the third container.

Monocarp has a lot of items to throw into containers. Some are made of paper, so Monocarp has to put them into the first container (he has a1 such items), some are made of plastic, so he has to put them into the second container (he has a2 such items), and some are neither paper nor plastic — so Monocarp has to put them into the third container (he has a3 such items).

Unfortunately, there are also two categories of items that Monocarp is unsure of: he has a4 items which are partially made of paper, so he will put each of these items either into the first container or into the third container. Similarly, he has a5 items partially made of plastic, so he has to put each of them either into the second container or into the third container. Obviously, this choice is made separately for each item — for example, Monocarp can throw several partially-plastic items into the second container, and all other partially-plastic items — into the third one.

Now Monocarp wonders: is it possible to put each item into some container so that the first container will hold no more than c1 items, the second one — no more than c2 items, and the third one — no more than c3 items?

Input
The first line contains one integer t (1≤t≤3⋅104) — the number of test cases.

Each test case consists of two lines. The first line of each test case contains three integers c1, c2, c3 (0≤c1,c2,c3≤108) — the capacities of the containers.

The second line of each test case contains five integers a1, a2, a3, a4, a5 (0≤ai≤108), where ai is the number of items of the i-th category Monocarp has to throw out (i=1 is paper waste, i=2 is plastic waste, i=3 is general waste, i=4 is partially-paper waste, i=5 is partially-plastic waste).

Output
For each test case, print either YES if it is possible to fit all items into containers, or NO otherwise. You may print each letter in any case (for example, YES, Yes, yes, yEs will all be recognized as positive answer).

Example
inputCopy
7
1 2 3
1 2 3 0 0
2 2 3
1 2 3 1 0
2 2 3
1 2 3 0 1
1 2 5
1 2 3 1 1
0 0 0
0 0 0 0 0
0 0 4
1 0 0 0 0
13 37 42
0 0 0 40 47
outputCopy
YES
YES
NO
YES
YES
NO
YES
Note
Explanations for the example test cases:

Monocarp can put 1 item of paper waste into the first container, 2 items of plastic waste into the second container, and 3 items of general waste into the third container;
Monocarp can put 1 item of paper waste and 1 item of partially-paper waste into the first container, 2 items of plastic waste into the second container, and 3 items of general waste into the third container;
there is no answer since either the second container should contain 3 items, or the third container should contain 4 items;
Monocarp can put 1 item of paper waste into the first container, 2 items of plastic waste into the second container, and 3 items of general waste, 1 item of partially-paper waste and 1 item of partially-plastic waste into the third container;
there is no waste at all, so all containers can be left empty;
there's no answer since it's impossible to put a paper item into the third container;
Monocarp can put 10 items of partially-paper waste into the first container, 37 items of partially-plastic waste into the second container, and 30 items of partially-paper waste and 10 items of partially-plastic waste into the third container.
*/

/* Time Complexity: O(1) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

bool canFit(vi& c, vi& a) {
    FOR(i, 3) {
        if (c[i] < a[i])
            return false;
    }

    FOR(i, 3)
        c[i] -= a[i];

    a[3] -= min(a[3], c[0]);
    a[4] -= min(a[4], c[1]);

    return c[2] >= (a[3] + a[4]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        vi capacities(3);
        vi waste(5);
        FOR(i, 3)
            cin >> capacities[i];
        FOR(i, 5)
            cin >> waste[i];

        cout << (canFit(capacities, waste) ? "YES\n" : "NO\n");

    }

    return 0;
}
