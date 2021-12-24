#include"LeetCode.h"

class Solution {
public:
    vector<vector<int>> graph;
    vector<int> inDegree;
    int cnt = 0;

    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        //建图
        graph.resize(n);
        inDegree.resize(n);
        for(const auto& e : pre)
            graph[e[1]].push_back(e[0]), inDegree[e[0]]++;
        
        //初始将入度为0的结点入队
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(!inDegree[i])
                q.push(i);
        
        //不断将对头结点的所有出边的入度减一, 然后为0就入队
        while(q.size())
        {
            auto t = q.front();
            q.pop();
            cnt++;

            for(const auto& val : graph[t])
            {
                inDegree[val]--;
                if(!inDegree[val])
                    q.push(val);
            }
        }

        return cnt == n;
    }
};