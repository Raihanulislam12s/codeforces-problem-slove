#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define FF first
#define LL second
#define all(c) (c).begin(), (c).end()

int sk;

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> sk;
    while (sk--)
    {
        int m, k;
        cin >> m >> k;
        vector<string> g(m);
        for (auto &l : g)
            cin >> l;

        for (int j = 0; j < k; j++)
        {

            // for each col, start from bottom row

            int place = m - 1, curr_rock_count = 0;
            vi temp;
            for (int i = m - 1; i >= 0; i--)
            {
                if (g[i][j] == 'o')
                {
                    temp.push_back(curr_rock_count);
                    curr_rock_count = 0;
                }
                else if (g[i][j] == '*')
                    curr_rock_count++;
            }

            temp.push_back(curr_rock_count);

            int lox = 0;

            for (int i = m - 1; i >= 0; i--)
            {
                if (lox >= temp.size())
                    break;
                if (g[i][j] == 'o')
                {
                    lox++;
                }
                else
                {
                    if (temp[lox])
                    {
                        g[i][j] = '*';
                        temp[lox]--;
                    }
                    else
                        g[i][j] = '.';
                }
            }
        }

        for (auto x : g)
        {
            cout << x << '\n';
        }
    }

    return 0;
}