/* CF - 1000 */
/*
C. Polycarp Recovers the Permutation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp wrote on a whiteboard an array p of length n, which is a permutation of numbers from 1 to n. In other words, in p each number from 1 to n occurs exactly once.

He also prepared a resulting array a, which is initially empty (that is, it has a length of 0).

After that, he did exactly n steps. Each step looked like this:

Look at the leftmost and rightmost elements of p, and pick the smaller of the two.
If you picked the leftmost element of p, append it to the left of a; otherwise, if you picked the rightmost element of p, append it to the right of a.
The picked element is erased from p.
Note that on the last step, p has a length of 1 and its minimum element is both leftmost and rightmost. In this case, Polycarp can choose what role the minimum element plays. In other words, this element can be added to a both on the left and on the right (at the discretion of Polycarp).

Let's look at an example. Let n=4, p=[3,1,4,2]. Initially a=[]. Then:

During the first step, the minimum is on the right (with a value of 2), so after this step, p=[3,1,4] and a=[2] (he added the value 2 to the right).
During the second step, the minimum is on the left (with a value of 3), so after this step, p=[1,4] and a=[3,2] (he added the value 3 to the left).
During the third step, the minimum is on the left (with a value of 1), so after this step, p=[4] and a=[1,3,2] (he added the value 1 to the left).
During the fourth step, the minimum is both left and right (this value is 4). Let's say Polycarp chose the right option. After this step, p=[] and a=[1,3,2,4] (he added the value 4 to the right).
Thus, a possible value of a after n steps could be a=[1,3,2,4].

You are given the final value of the resulting array a. Find any possible initial value for p that can result the given a, or determine that there is no solution.

Input
The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the test.

Each test case consists of two lines. The first of them contains an integer n (1≤n≤2⋅105) — the length of the array a. The second line contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array a. All elements of the a array are distinct numbers.

It is guaranteed that the sum of the values n over all test cases in the test does not exceed 2⋅105.

Output
Print t lines, each of the lines must contain the answer to the corresponding set of input data: numbers p1,p2,…,pn  — any of the possible initial values of the array p, which will lead to the given array a. All elements of p are distinct integers from 1 to n. Thus, if there are several solutions, print any. If there is no solution, then print -1 on the line.

Example
inputCopy
4
4
1 3 2 4
1
1
5
1 3 5 4 2
3
3 2 1
outputCopy
3 1 4 2
1
-1
2 3 1
Note
The first test case in the example is clarified in the main section of the problem statement. There may be other correct answers for this test set.

In the second test case, n=1. Thus, there is only one permutation that can be the answer: p=[1]. Indeed, this is the answer to this test case.

In the third test case of the example, no matter what permutation you take as p, after applying the n steps, the result will differ from a=[1,3,5,4,2].
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

void solve(vi& a) {
    int n = sz(a);

    if (a[0] != n && a[n - 1] != n)
        cout << -1 << nl;
    else {
        for (int i = n - 1; i >= 0; i--)
            cout << a[i] << ' ';
        cout << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        vi a(n);
        trav(i, a)
            cin >> i;

        solve(a);
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
