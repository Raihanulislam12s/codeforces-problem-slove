#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define P first
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
        string r;
        cin >> m>> r;

        bool flag = true;

        for (int i = 0; i < m; i++)
        {
            if (r[i] == 'W')
                continue;
            else
            {
                int j = i, cr = 0, cb = 0;
                while (j < m && r[j] != 'W')
                {
                    if (r[j] == 'R')
                        cr++;
                    else if (r[j] == 'B')
                        cb++;

                    j++;
                }

                if (cr == 0 || cb == 0)
                {
                    flag = false;
                }

                i = j - 1;
            }
        }

        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
