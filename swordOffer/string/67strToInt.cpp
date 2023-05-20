#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

/**
 *  题目：判断字符串 s 从第一个非空字符串起是是个数字，是的话转为 Int 型数字
 *  输入："  -4193 with words "
 *  输出: -4193
 *  思路：
 *      1. 先对字符串进行预处理
 *          1.1 去掉字符串前面的空格
 *          1.2 如果 s 为空 或者全为空格，则返回 0
 *          1.3 设置 +- 标志位
 *      2. 依次遍历每一个字符
 *          2.1 迭代计算数字的值
 *          2.2 时刻判断 res 是否超出取值范围
*/
class Solution {
public:
    int strToInt(string s) {
        if (s == "") return 0;                      // 1. 先对字符串进行预处理
        int left = 0;
        long res = 0;
        while (left < s.size() && s[left] == ' ') { // 1.1 去掉字符串前面的空格
            left++;
        }
        if (left == s.size()) return 0;             // 1.2 如果 s 为空 或者全为空格，则返回 0
        int sign = 1;
        if (s[left] == '-' || s[left] == '+') {     // 1.3 设置 +- 标志位
            if (s[left] == '-') sign = -1;
            left++;
        }
        for (int i = left; i < s.size() && isdigit(s[i]); i++) {    // 2. 依次遍历每一个字符
            res = 10 * res + (s[i] - '0');                          // 2.1 迭代计算数字的值
            if (res > INT_MAX) {
                if (sign == 1) {            // 8, 9 -> 7            // 2.2 时刻判断 res 是否超出取值范围
                    return INT_MAX; 
                } else if (sign == -1) {    // 8, 9 -> -8
                    return INT_MIN; 
                }
            }
        }    
        return sign * res;                       
    }
};

int main() {
    Solution sol;
    string s = "  -3235435341321abcd";
    int res = sol.strToInt(s);
    cout << res << endl;
}