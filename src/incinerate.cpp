
#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define shuf(v) shuffle(all(v), rng)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
// const ll MOD = 1000000000;  // 10^9
// const ld PI = acos(-1.0);

void solve() {
    // Algorithm:
    // ==========
    //
    //
    // Time: O(nlogn)
    // Space: O(n)

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vi h(n), p(n);
        trav(i, h)
            cin >> i;
        trav(i, p)
            cin >> i;

        vi ord(n);
        iota(allit(ord), 0);  // forn(i, 0, n) ord[i] = i;

        // sort ord according to power values
        sort(allit(ord), [&](auto x, auto y) { return p[x] < p[y]; });

        int dmg = 0;
        bool flag = true;
        trav(i, ord) {
            if (h[i] <= dmg)
                continue;

            if (i != ord[0])
                k -= p[i];

            if (k > 0) {
                dmg += k;
                while (h[i] > dmg) {
                    k -= p[i];
                    if (k < 0)
                        break;
                    dmg += k;
                }
            }

            if (h[i] > dmg) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
