/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, vector<int>> graph;
    vector<int> answer;
    unordered_set<int> visited;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root, nullptr);

        answer.clear();
        visited.clear();
        visited.insert(target->val);

        dfs(target->val, 0, k);

        return answer;
    }

private:
    void buildGraph(TreeNode* cur, TreeNode* parent) {
        if (cur != nullptr && parent != nullptr) {
            graph[cur->val].push_back(parent->val);
            graph[parent->val].push_back(cur->val);
        }
        if (cur->left != nullptr) {
            buildGraph(cur->left, cur);
        }
        if (cur->right != nullptr) {
            buildGraph(cur->right, cur);
        }
    }

    void dfs(int cur, int distance, int k) {
        if (distance == k) {
            answer.push_back(cur);
            return;
        }
        for (int neighbor : graph[cur]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                dfs(neighbor, distance + 1, k);
            }
        }
    }
};