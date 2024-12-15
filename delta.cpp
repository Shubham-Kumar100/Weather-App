#include <iostream>
#include <vector>
using namespace std;

int countCombinations(int N, int K, vector<int> &A)
{
    // dp[i] will store the number of ways to form the sum i
    vector<int> dp(K + 1, 0);
    dp[0] = 1; // There is exactly one way to form the sum 0, by choosing nothing.

    // Process each element of array A
    for (int i = 0; i < N; ++i)
    {
        // Traverse dp array backwards to ensure we don't reuse the same element
        for (int j = K; j >= A[i]; --j)
        {
            dp[j] += dp[j - A[i]];
        }
    }

    // The answer is the number of ways to form the sum K
    return dp[K];
}

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    int result = countCombinations(N, K, A);
    cout << result << endl;

    return 0;
}
