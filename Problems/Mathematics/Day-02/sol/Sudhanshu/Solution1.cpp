#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        sort(v.begin(), v.end());

        int low = v[0];
        int high = v[n - 1];

        int adjust = (low == high) ? 2 : 1;

        int cLow = 0;
        int cHigh = 0;

        for (auto i : v)
        {
            if (i != low)
                break;
            cLow++;
        }
        reverse(v.begin(), v.end());

        for (auto i : v)
        {
            if (i != high)
                break;
            cHigh++;
        }

        cout << cHigh * cLow * 2 / adjust << endl;
    }

    return 0;
}

/*
APPROACH:

- Sort the array to easily identify minimum and maximum elements
- Find the minimum (low) and maximum (high) values
- Count occurrences of minimum value (cLow) and maximum value (cHigh)
- If all elements are equal (low == high), we need to choose any 2 elements from n,
    so answer = n * (n-1) (dividing by 2 would give combinations, but we want pairs)
- Otherwise, the answer is cLow * cHigh * 2 (considering both orderings of pairs)

TC: O(nlog n)
SC: O(n)
*/