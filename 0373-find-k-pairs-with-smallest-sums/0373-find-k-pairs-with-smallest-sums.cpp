class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> minHeap(comp);
        
        if (nums1.empty() || nums2.empty() || k == 0)
            return result;
        
        for (int i = 0; i < nums1.size() && i < k; i++)
            minHeap.push({nums1[i], nums2[0], 0});
        
        while (k > 0 && !minHeap.empty()) {
            vector<int> pair = minHeap.top();
            minHeap.pop();
            
            result.push_back({pair[0], pair[1]});
            
            if (pair[2] < nums2.size() - 1)
                minHeap.push({pair[0], nums2[pair[2] + 1], pair[2] + 1});
            
            k--;
        }
        
        return result;
    }
};