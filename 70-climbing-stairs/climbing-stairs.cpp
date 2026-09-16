class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3) return n;
        
        int first = 0;
        int second = 1;
        int next;

        for(int i = 1; i<=n; i++) {
            next = first + second;
            first = second;
            second = next;
        }

        return next;
    }
};