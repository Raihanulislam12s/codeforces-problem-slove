#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pi pair<int, int>
#define G first
#define Z second
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
        vi k(m);
        for (auto &l : k)
            cin >> l;

        map<int, int> cntr;
        for (auto l : k)
            cntr[l]++;

        int val = -1;
        for (auto it = cntr.begin(); it != cntr.end(); it++)
            if (it->Z >= 3)
                val = it->G;
        cout << val << '\n';
    }

    return 0;
}

