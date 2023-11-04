class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // return n ;
        int leftSize= left.size();
        int rightSize = right.size();
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        if(leftSize==0){
            return n-right[0];
        }
        if(rightSize==0){
            return left[leftSize-1];
        }
        int val = n-right[0];
        int val1 = left[leftSize-1];
        return max(val, val1);
    }
};