#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100005], seg[4 * 100005];

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    // seg[ind]=seg[2*ind+1]+seg[2*ind+2];//  can use for doing sum of two nodes
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]); // can use for doing maximum of two nodes
}

int query(int ind, int low, int high, int l, int r)
{
    if (r < low || l > high)
    {
        return INT_MIN;
    }
    if (l <= low && r >= high)
    {
        return seg[ind];
    }
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);

    return max(left, right);
}

int32_t main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(0,0,n-1);
    int q;
    cin>>q;

    while  (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r ) << endl;
    }
    

    return 0;
}