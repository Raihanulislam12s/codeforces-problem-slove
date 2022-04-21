#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define F first
#define S second
#define all(c) (c).begin(), (c).end()

int sk;

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> sk;
    while (sk--)
    {
        int m, l;
        cin >> m >> l;
        vi g(m);
        for (auto &p : g)
            cin >> p;

        vi cox(31), sox(31);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < 31; j++)
                if (g[i] & (1 << j))
                    cox[j]++;
        }

        int available = l;

        for (int i = 30; i >= 0; i--)
        {
            int needed = m;
            int current = cox[i];

            int required = needed - current;
            if (required <= available)
            {
                sox[i] = 1;
                available -= required;
            }
        }

        int ans = 0;

        for (int i = 30; i >= 0; i--)
            if (sox[i] || cox[i] == m)
                ans |= (1 << i);
        cout << ans << '\n';
    }

    return 0;
}