class Solution:
    def tribonacci(self, n: int) -> int:
        first = 0
        second = 1
        third = 1

        if n == 0:
            return 0
        elif n == 1 or n == 2:
            return 1

        next = 0

        for i in range (4, n+2, 1):
            next = first + second + third
            first = second
            second = third
            third = next
        
        return next