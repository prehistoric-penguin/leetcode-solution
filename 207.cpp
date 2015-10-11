// https://leetcode.com/problems/course-schedule/
class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (!numCourses) {
      return false;
    }
    if (prerequisites.empty()) {
      return true;
    }
    std::vector<std::vector<int>> vec(numCourses);
    for (const auto& p : prerequisites) {
      vec[p.first].push_back(p.second);
    }
    std::vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; ++i) {
      std::stack<int> stk;
      // for disjoint graph
      std::vector<int> onpath(numCourses, 0);
      visited[i] = 1;
      onpath[i] = 1;
      stk.push(i);

      while (!stk.empty()) {
        int val = stk.top();
        stk.pop();

        for (int v : vec[val]) {
          if (!visited[v]) {
            visited[v] = 1;
            onpath[v] = 1;
            stk.push(v);
            break;
          } else if (onpath[v]) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
