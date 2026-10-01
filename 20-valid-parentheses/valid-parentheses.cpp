class Solution {
public:
    bool isOpening(char bracket) {
        if (bracket == '(' || bracket == '[' || bracket == '{')
            return true;

        return false;
    }

    bool closing(char stack_top, char ch) {
        if (stack_top == '(' && ch == ')') return true;
        if (stack_top == '[' && ch == ']') return true;
        if (stack_top == '{' && ch == '}') return true;

        return false;
    }

    bool isValid(string s) {
        if (s.size() % 2 != 0)
            return false;

        stack<char> st;

        for (char ch : s) {
            if (isOpening(ch)) {
                st.push(ch);
            }
            else {
                // Closing bracket but nothing to match
                if (st.empty())
                    return false;

                if (closing(st.top(), ch)) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Valid only if all opening brackets were matched
        return st.empty();
    }
};