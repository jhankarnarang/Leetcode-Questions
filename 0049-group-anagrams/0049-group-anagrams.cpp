class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> m;
        vector<vector<string>> ans;
        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            sort(str.begin(),str.end());

            if(m.find(str) != m.end()) {
                ans[m[str]].push_back(strs[i]);
            }
            else {
                m[str] = ans.size(); 
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};