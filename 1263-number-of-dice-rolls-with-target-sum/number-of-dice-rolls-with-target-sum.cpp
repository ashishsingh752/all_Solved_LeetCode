class Solution {
public:
    int mod = 1e9 + 7;
    
    int memo(int n, int k, int target, vector<vector<int>>& dp_memo) {
        if (n == 0 and target == 0)
            return 1;
        if (n <= 0 or target <= 0)
            return 0;

        if (dp_memo[n][target] != -1)
            return (dp_memo[n][target] % mod);

        int ans = 0;
        for (int num = 1; num <= k; ++num) {
            if (num <= target)
                ans = ((ans % mod) + (memo(n - 1, k, target - num, dp_memo) % mod)) %
                      mod;
        }

        return dp_memo[n][target] = (ans % mod);
    }

    int numRollsToTarget(int n, int k, int target) {
//      MEMOISATION START      
        // vector<vector<int>> dp_memo(n + 1, vector<int>(target + 1, -1));
        // return memo(n, k, target, dp) % mod;
//      MEMOISATION END

//      TABULATION START
        vector<vector<int>> dp_tab(n + 1, vector<int>(target + 1, 0));
        dp_tab[0][0] = 1;

        for (int dice = 1; dice <= n; ++dice) {
            for (int curr = 1; curr <= target; ++curr) {
                int ans = 0;

                for (int num = 1; num <= k; ++num) {
                    if (num <= curr)
                        ans = ((ans % mod) + (dp_tab[dice - 1][curr - num] % mod)) % mod;
                }

                dp_tab[dice][curr] = (ans % mod);
            }
        }

        return dp_tab[n][target];
//      TABULATION END
    }
};