#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++)
    {
        long long num;
        cin >> num;
        if(num%2 == 1 && num <= n/2 + 1)
            cout << (num + 1)/2 << endl;
        else
        {
            while(num%2 != 1)
            {
                long long half = num/2;
                num = half + n;
            }
            long long output = (num + 1)/2;
            cout << output << endl;
        }
    }
    return 0;
}
