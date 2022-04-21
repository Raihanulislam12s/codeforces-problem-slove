#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define G first
#define O second
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

        if (m == 1)
            cout << "YES\n";
        else
        {
            bool flag = true;
            int parity_odd = g[0] & 1;
            int parity_even = g[1] & 1;

            for (int i = 2; i < m; i += 2)
                if ((g[i] & 1) != parity_odd)
                    flag = false;

            for (int i = 3; i < m; i += 2)
                if ((g[i] & 1) != parity_even)
                    flag = false;

            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}

