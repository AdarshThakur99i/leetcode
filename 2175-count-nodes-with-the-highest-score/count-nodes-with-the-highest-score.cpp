class Solution {
public:
    vector<vector<int>> g;
    vector<long long> subtree;
    int n;
    
    long long dfs(int u) {
        long long size = 1;
        for (int v : g[u]) size += dfs(v);
        subtree[u] = size;
        return size;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        g.resize(n);
        subtree.resize(n);

        for (int i = 1; i < n; i++) {
            g[parents[i]].push_back(i);
        }

        dfs(0); // compute all subtree sizes

        long long maxScore = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            long long score = 1;
            long long rest = n - subtree[i];

            if (rest > 0) score *= rest; // nodes outside this subtree
            for (int v : g[i]) score *= subtree[v]; // child subtree sizes

            if (score > maxScore) {
                maxScore = score;
                count = 1;
            } else if (score == maxScore) {
                count++;
            }
        }

        return count;
    }
};
