
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; i++) {
            int num = i;
            bool flag = true;

            while (num > 0) {
                int digit = num % 10;

                if (digit == 0 || i % digit != 0) {
                    flag = false;
                    break;
                }

                num /= 10;
            }

            if (flag) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
