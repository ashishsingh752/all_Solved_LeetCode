class Solution {
    int findCount(vector<int>& bloomDay, int mid, int k) {
        int cnt = 0;
        int size = bloomDay.size();
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (bloomDay[i] <= mid) {
                counter++;
            } else {
                cnt += counter / k;
                counter = 0;
            }
        }
        cnt += counter / k;
        return cnt;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxDays = INT_MIN;
        int minDays = INT_MAX;

        int size = bloomDay.size();

        long long int requiredFlowers = m*1ll * k*1ll;

        if (size < requiredFlowers) return -1;

        int cnt = 0;

        for (auto it : bloomDay) {
            maxDays = max(maxDays, it);
            minDays = min(minDays, it);
        }
        int start = minDays, end = maxDays;

        while (start <= end) { 
            int mid = start + (end - start) / 2;
            int count = findCount(bloomDay, mid, k);
            if (count >= m) end= mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};
