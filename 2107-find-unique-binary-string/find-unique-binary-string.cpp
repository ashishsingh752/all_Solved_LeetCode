// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         // int n =nums.size();
//         // map<int, vector<string>>mp;

//         // for(int i =0;i<n;i++){
//         //     int cnt =0;
//         //     for(int j=0;j<n;j++){
//         //         int a = nums[i][j]-'0';
//         //         if(a==1) cnt++;
//         //     }
//         //     mp[cnt].push_back(nums[i]);
//         // }
//         // bool check 
//         // for(int i =0;i<=n;i++){
//         //     if(mp.find(i)!=mp.end()){
//         //         string str ="";
//         //         for(int j =0;j<n;j++) str.push_back('1');
//         //         return str;
//         //     }
//         // }
//         // return "";

        
        
//     }
// };
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string result;

        for (int i = 0; i < nums.size(); ++i) {
            result += (nums[i][i] == '0' ? '1' : '0');
        }

        return result;
    }
};