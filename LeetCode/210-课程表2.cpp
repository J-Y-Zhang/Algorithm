#include "LeetCode.h"

class Solution {
public:
  vector<vector<int>> graph;
  vector<int> ans, inDegree;
  vector<int> findOrder(int n, vector<vector<int>> &pre) {
    //��ͼ
    graph.resize(n);
    inDegree.resize(n);
    for (const auto &e : pre)
      graph[e[1]].push_back(e[0]), inDegree[e[0]]++;

    //��ʼ�����Ϊ0�Ľ�����
    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!inDegree[i])
        q.push(i);

    //���Ͻ���ͷ�������г��ߵ���ȼ�һ, Ȼ��Ϊ0�����
    while (q.size()) {
      auto t = q.front();
      q.pop();
      ans.push_back(t);

      for (const auto &val : graph[t]) {
        inDegree[val]--;
        if (!inDegree[val])
          q.push(val);
      }
    }

    if (ans.size() != n)
      return {};
    return ans;
  }
};