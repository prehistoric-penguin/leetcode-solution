// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
   int evalRPN(vector<string>& tokens) {
        enum Type {
            ADD,
            MINUS,
            MULTIPLY,
            DIV,
            NUMBER
        };
        auto getType = [](const std::string& str) -> Type{
            Type ans = NUMBER;
            size_t index = 0;
            if (str.size() == 1 && (index = std::string("+-*/").find_first_of(str)) != std::string::npos) {
                ans = static_cast<Type>(index);
            }
            return ans;
        };
        auto popTop = [](std::stack<int>& stk) {
            int val = stk.top();
            stk.pop();
            return val;
        };
        std::stack<int> numStack;
        int lhs = 0;
        int rhs = 0;
        for (auto& str : tokens) {
            Type type = getType(str);
            if (type == NUMBER) {
                numStack.push(std::stoi(str));
            } else {
                lhs = popTop(numStack);
                rhs = popTop(numStack);
                switch (type) {
                    case ADD: numStack.push(lhs + rhs); break;
                    case MINUS: numStack.push(rhs - lhs); break;
                    case MULTIPLY: numStack.push(lhs * rhs); break;
                    case DIV: numStack.push(rhs / lhs); break;
                }
            }
        }
        return numStack.top();
    }
};

