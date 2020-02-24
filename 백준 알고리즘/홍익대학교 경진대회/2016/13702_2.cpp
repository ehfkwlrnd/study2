#include <iostream>
using namespace std;
const int INF = 1 << 31 - 1;
const int MAX = 10000 + 1;
int N, K;
int kettle[MAX];
bool overK(int amount)
{
        int cnt = 0;
        for (int i = 1; i <= N; i++)
        {
                 cnt += kettle[i] / amount;
                 if (cnt >= K)
                         return true;
        }
        return false;
}
int binarySearch(void)
{
        int low = 0, high = INF;
        while (high >= low)
        {
                 int mid = (low + high) / 2;
                 if (overK(mid))
                         low = mid + 1;
                 else
                         high = mid - 1;
        }
        return high;
}
int main(void)
{
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
                 cin >> kettle[i];
        int result = binarySearch();
        if (result == -1)
            cout << 0 << endl;
        else
            cout << result << endl;
        return 0;
}
