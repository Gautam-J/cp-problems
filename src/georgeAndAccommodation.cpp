/* CF - 800 */
/*
A. George and Accommodation
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
George has recently entered the BSUCP (Berland State University for Cool Programmers). George has a friend Alex who has also entered the university. Now they are moving into a dormitory.

George and Alex want to live in the same room. The dormitory has n rooms in total. At the moment the i-th room has pi people living in it and the room can accommodate qi people in total (pi ≤ qi). Your task is to count how many rooms has free place for both George and Alex.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of rooms.

The i-th of the next n lines contains two integers pi and qi (0 ≤ pi ≤ qi ≤ 100) — the number of people who already live in the i-th room and the room's capacity.

Output
Print a single integer — the number of rooms where George and Alex can move in.

Examples
inputCopy
3
1 1
2 2
3 3
outputCopy
0
inputCopy
3
1 10
0 10
10 10
outputCopy
2
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, rooms = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (b - a >= 2)
            rooms++;
    }

    cout << rooms << "\n";

    return 0;
}
