/* CF - 900 */
/*
B. The Great Hero
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
The great hero guards the country where Homer lives. The hero has attack power A and initial health value B. There are n monsters in front of the hero. The i-th monster has attack power ai and initial health value bi.

The hero or a monster is said to be living, if his or its health value is positive (greater than or equal to 1); and he or it is said to be dead, if his or its health value is non-positive (less than or equal to 0).

In order to protect people in the country, the hero will fight with monsters until either the hero is dead or all the monsters are dead.

In each fight, the hero can select an arbitrary living monster and fight with it. Suppose the i-th monster is selected, and the health values of the hero and the i-th monster are x and y before the fight, respectively. After the fight, the health values of the hero and the i-th monster become x−ai and y−A, respectively.
Note that the hero can fight the same monster more than once.

For the safety of the people in the country, please tell them whether the great hero can kill all the monsters (even if the great hero himself is dead after killing the last monster).

Input
Each test contains multiple test cases. The first line contains t (1≤t≤105) — the number of test cases. Description of the test cases follows.

The first line of each test case contains three integers A (1≤A≤106), B (1≤B≤106) and n (1≤n≤105) — the attack power of the great hero, the initial health value of the great hero, and the number of monsters.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106), where ai denotes the attack power of the i-th monster.

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤106), where bi denotes the initial health value of the i-th monster.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print the answer: "YES" (without quotes) if the great hero can kill all the monsters. Otherwise, print "NO" (without quotes).

Example
inputCopy
5
3 17 1
2
16
10 999 3
10 20 30
100 50 30
1000 1000 4
200 300 400 500
1000 1000 1000 1000
999 999 1
1000
1000
999 999 1
1000000
999
outputCopy
YES
YES
YES
NO
YES
Note
In the first example: There will be 6 fights between the hero and the only monster. After that, the monster is dead and the health value of the hero becomes 17−6×2=5>0. So the answer is "YES", and moreover, the hero is still living.

In the second example: After all monsters are dead, the health value of the hero will become 709, regardless of the order of all fights. So the answer is "YES".

In the third example: A possible order is to fight with the 1-st, 2-nd, 3-rd and 4-th monsters. After all fights, the health value of the hero becomes −400. Unfortunately, the hero is dead, but all monsters are also dead. So the answer is "YES".

In the fourth example: The hero becomes dead but the monster is still living with health value 1000−999=1. So the answer is "NO".
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

bool canKill(int A, int B, vector<int>& attack, vector<int>& health) {
    int n = attack.size();
    int64_t damage = 0;

    for (int i = 0; i < n; i++)
        damage += int64_t(health[i] + A - 1) / A * attack[i];
    for (int i = 0; i < n; i++)
        if (B - (damage - attack[i]) > 0)
            return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, A, B, n;
    cin >> t;

    while (t--) {
        cin >> A >> B >> n;

        vector<int> attack(n);
        for (int i = 0; i < n; i++)
            cin >> attack[i];

        vector<int> health(n);
        for (int i = 0; i < n; i++)
            cin >>health[i];

        cout << (canKill(A, B, attack, health) ? "YES\n" : "NO\n");
    }

    return 0;
}
