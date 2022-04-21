#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define O first
#define LL second
#define all(c) (c).begin(), (c).end()

int sk;

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> sk;
    while (sk--)
    {
        int m;
        cin >> m;
        map<char, int> first_pos;
        map<char, int> second_pos;

        vector<string> g(m);

        map<string, int> cntr;

        for (auto &k : g)
            cin >> k;

        int ans = 0;

        for (int i = m - 1; i >= 0; i--)
        {

            int temp = first_pos[g[i][0]] + second_pos[g[i][1]] - 2 * cntr[g[i]];
            ans += temp;

            cntr[g[i]]++;
            first_pos[g[i][0]]++;
            second_pos[g[i][1]]++;
        }

        cout << ans << '\n';
    }

    return 0;
}