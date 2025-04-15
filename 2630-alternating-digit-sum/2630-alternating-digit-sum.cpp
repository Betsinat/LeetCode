class Solution {
public:
    int alternateDigitSum(int n) {
        int digits[10] = {0};
        int count = 0;
        int sign = 1;
        int sum = 0;
        if (n < 0) {
            n = -n;
        }
        while (n > 0) {
            digits[count++] = n % 10;
            n /= 10;
        }
        for (int i = count - 1; i >= 0; i--) {
            sum += digits[i] * sign;
            sign *= -1;
        }
        return sum;
    }
};