// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> chStack;
        for (size_t i = 0, sz = s.size(); i < sz; ++i) {
            switch (s[i]) {
                case ']':
                    if (chStack.empty() || chStack.top() != '[') return false;
                    chStack.pop();
                    break;
                case '}':
                    if (chStack.empty() || chStack.top() != '{') return false;
                    chStack.pop();
                    break;
                case ')':
                    if (chStack.empty() || chStack.top() != '(') return false;
                    chStack.pop();
                    break;
                default:
                    chStack.push(s[i]);
                    break;
            }
        }
        return chStack.empty();
    }
};

