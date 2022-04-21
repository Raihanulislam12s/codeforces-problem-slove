#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define GG first
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
        vi g(m);
        for (auto &l : g)
            cin >> l;

        vi pref_sum(m), suff_sum(m);
        pref_sum[0] = g[0];
        suff_sum[m - 1] = g[m - 1];

        for (int i = 1; i < m; i++)
            pref_sum[i] = pref_sum[i - 1] + g[i];
        for (int i = m - 2; i >= 0; i--)
            suff_sum[i] = suff_sum[i + 1] + g[i];

        reverse(all(suff_sum));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int weight_alice = pref_sum[i];
            int cnt_alice = (i + 1);

            if (binary_search(all(suff_sum), weight_alice))
            {
                int cnt_bob = lower_bound(all(suff_sum), weight_alice) - suff_sum.begin() + 1;
                if (cnt_alice + cnt_bob <= m)
                    ans = max(ans, cnt_alice + cnt_bob);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}