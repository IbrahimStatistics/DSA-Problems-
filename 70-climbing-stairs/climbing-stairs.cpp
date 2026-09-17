class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2) return n;
        
        int first = 1;
        int second = 2;
        int next = 0;

        for(int i = 3; i<=n; i++) {
            next = first + second;
            first = second;
            second = next;
        }

        return next;
    }
};