class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp; 
        vector<int> ans;
        unordered_set<int> seen;

        // Build the adjacency list
        for(auto& pair : adjacentPairs) {
            mp[pair[0]].push_back(pair[1]);
            mp[pair[1]].push_back(pair[0]);
        }

        // Find the starting point (a node with only one neighbor)
        int start = 0;
        for(auto& entry : mp) {
            if(entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }

        // DFS to reconstruct the array
        dfs(mp, start, seen, ans);

        return ans;
    }

private:
    void dfs(unordered_map<int, vector<int>>& mp, int node, unordered_set<int>& seen, vector<int>& ans) {
        ans.push_back(node);
        seen.insert(node);

        for(int neighbor : mp[node]) {
            if(seen.find(neighbor) == seen.end()) {
                dfs(mp, neighbor, seen, ans);
                break;  // Since each node has at most two neighbors, no need to explore further
            }
        }
    }
};
