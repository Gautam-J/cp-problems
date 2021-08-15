/* CF - 900 */
/*
A. Digit Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Everyone knows that agents in Valorant decide, who will play as attackers, and who will play as defenders. To do that Raze and Breach decided to play t matches of a digit game...

In each of t matches of the digit game, a positive integer is generated. It consists of n digits. The digits of this integer are numerated from 1 to n from the highest-order digit to the lowest-order digit. After this integer is announced, the match starts.

Agents play in turns. Raze starts. In one turn an agent can choose any unmarked digit and mark it. Raze can choose digits on odd positions, but can not choose digits on even positions. Breach can choose digits on even positions, but can not choose digits on odd positions. The match ends, when there is only one unmarked digit left. If the single last digit is odd, then Raze wins, else Breach wins.

It can be proved, that before the end of the match (for every initial integer with n digits) each agent has an ability to make a turn, i.e. there is at least one unmarked digit, that stands on a position of required parity.

For each of t matches find out, which agent wins, if both of them want to win and play optimally.

Input
First line of input contains an integer t (1≤t≤100)  — the number of matches.

The first line of each match description contains an integer n (1≤n≤103)  — the number of digits of the generated number.

The second line of each match description contains an n-digit positive integer without leading zeros.

Output
For each match print 1, if Raze wins, and 2, if Breach wins.

Example
inputCopy
4
1
2
1
3
3
102
4
2069
outputCopy
2
1
1
2
Note
In the first match no one can make a turn, the only digit left is 2, it's even, so Breach wins.

In the second match the only digit left is 3, it's odd, so Raze wins.

In the third match Raze can mark the last digit, after that Breach can only mark 0. 1 will be the last digit left, it's odd, so Raze wins.

In the fourth match no matter how Raze plays, Breach can mark 9, and in the end there will be digit 0. It's even, so Breach wins.
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef vector<int> vi;

int getWinner(int n, string s) {
    bool odd = false, even = false;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1)
            odd |= ((s[i - 1] - '0') % 2 == 1);
        else
            even |= ((s[i - 1] - '0') % 2 == 0);
    }

    if (n % 2 == 1)
        if (odd)
            return 1;
        else
            return 2;
    else
        if (even)
            return 2;
        else
            return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n;
    string s;
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;
        cout << getWinner(n, s) << '\n';
    }

    return 0;
}
