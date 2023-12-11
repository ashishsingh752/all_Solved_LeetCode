class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        int c=1,num=arr[0];
        double m_c=n/4+1;
        for(int i=1;i<n;i++){
            if(arr[i]==num)
                c++;
            else
                c=1,num=arr[i];
            if(c>=m_c)
                return arr[i];
        }
        return arr[0];
    }
};