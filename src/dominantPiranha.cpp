/* CF - 900 */
/*
C. Dominant Piranha
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n piranhas with sizes a1,a2,…,an in the aquarium. Piranhas are numbered from left to right in order they live in the aquarium.

Scientists of the Berland State University want to find if there is dominant piranha in the aquarium. The piranha is called dominant if it can eat all the other piranhas in the aquarium (except itself, of course). Other piranhas will do nothing while the dominant piranha will eat them.

Because the aquarium is pretty narrow and long, the piranha can eat only one of the adjacent piranhas during one move. Piranha can do as many moves as it needs (or as it can). More precisely:

The piranha i can eat the piranha i−1 if the piranha i−1 exists and ai−1<ai.
The piranha i can eat the piranha i+1 if the piranha i+1 exists and ai+1<ai.
When the piranha i eats some piranha, its size increases by one (ai becomes ai+1).

Your task is to find any dominant piranha in the aquarium or determine if there are no such piranhas.

Note that you have to find any (exactly one) dominant piranha, you don't have to find all of them.

For example, if a=[5,3,4,4,5], then the third piranha can be dominant. Consider the sequence of its moves:

The piranha eats the second piranha and a becomes [5,5–,4,5] (the underlined piranha is our candidate).
The piranha eats the third piranha and a becomes [5,6–,5].
The piranha eats the first piranha and a becomes [7–,5].
The piranha eats the second piranha and a becomes [8–].
You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (2≤n≤3⋅105) — the number of piranhas in the aquarium. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤109), where ai is the size of the i-th piranha.

It is guaranteed that the sum of n does not exceed 3⋅105 (∑n≤3⋅105).

Output
For each test case, print the answer: -1 if there are no dominant piranhas in the aquarium or index of any dominant piranha otherwise. If there are several answers, you can print any.

Example
inputCopy
6
5
5 3 4 4 5
3
1 1 1
5
4 4 3 4 4
5
5 5 4 3 2
3
1 1 2
5
5 4 3 5 5
outputCopy
3
-1
4
3
3
1
Note
The first test case of the example is described in the problem statement.

In the second test case of the example, there are no dominant piranhas in the aquarium.

In the third test case of the example, the fourth piranha can firstly eat the piranha to the left and the aquarium becomes [4,4,5,4], then it can eat any other piranha in the aquarium.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int findDom(vi& a) {
    int mx = 0, n = a.size();
    FOR(i, n)
        mx = max(mx, a[i]);

    int idx = -1;
    FOR(i, n) {
        if (a[i] != mx)
            continue;
        if (i > 0 && a[i - 1] != mx)
            idx = i + 1;
        if (i < n - 1 && a[i + 1] != mx)
            idx = i + 1;
    }

    return idx;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vi a(n);
        FOR(i, n)
            cin >> a[i];

        cout << findDom(a) << '\n';
    }

    return 0;
}
