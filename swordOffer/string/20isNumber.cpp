#include <iostream>
#include <string>
using namespace std;

/**
 *  题目：判断字符串 s 字面值是否为数字
 *  输入：s = "  +3.4E-2   "
 *  输出：true
 *  思路：
 *      1. 首先去掉 s 头部和尾部的空格
 *          1.1 先去掉左边
 *          1.2 如果为空，或全为空格则为 false
 *          1.3 再去掉右边
 *      2. 根据点，数字，E，符号的标志位进行判断是否为数字
 *          2.1 依次遍历每一个字符，更新对应的标志位
 *          2.2 如果遇到 0-9 设 isNum 为 true
 *          2.3 如果遇到 . 且之前没有 . 和 E，则 isDot 为 true
 *          2.4 如果遇到 Ee，且之前没有 E，但有数字，则 isEe 为 true
 *          2.5 同时设 isNum = false 避免 E 结尾
 *          2.6 如果遇到 +-，且位于首位或 Ee 之前，则 isSign 为 true
 *          2.7 其他情况直接 false，不为数字
*/     
class Solution {
public:
    bool isNumber(string s) {                 
        if (s == "") return false;                      
        int left = 0, right = s.size() - 1;             // 1. 首先去掉 s 头部和尾部的空格
        while (left < s.size() && s[left] == ' ') {     // 1.1 先去掉左边
            left++;
        }
        if (left == s.size()) return false;             // 1.2 如果为空，或全为空格则为 false
        while (s[right] == ' ') {                       // 1.3 再去掉右边
            right--;
        }
        bool isNum = false;                             // 2. 根据点，数字，E，符号的标志位进行判断是否为数字
        bool isDot = false;
        bool isEe = false;
        bool isSign = false;
        for (int i = left; i <= right; i++) {           // 2.1 依次遍历每一个字符，更新对应的标志位
            if (s[i] >= '0' && s[i] <= '9') {           // 2.2 如果遇到 0-9 设 isNum 为 true
                isNum = true;
            } else if (s[i] == '.' && !isDot && !isEe) {// 2.3 如果遇到 . 且之前没有 . 和 E，则 isDot 为 true
                isDot = true;
            } else if ((s[i] == 'E' || s[i] == 'e') && !isEe && isNum) {
                isEe = true;                            // 2.4 如果遇到 Ee，且之前没有 E，但有数字，则 isEe 为 true
                isNum = false;                          // 2.5 同时设 isNum = false 避免 E 结尾
            } else if ((s[i] == '+' || s[i] == '-') && (i == left || s[i - 1] == 'E' || s[i - 1] == 'e')) {
                isSign = true;                          // 2.6 如果遇到 +-，且位于首位或 Ee 之前，则 isSign 为 true
            } else {
                return false;                           // 2.7 其他情况直接 false，不为数字
            }
        }
        return isNum;
    }
};

int main() {
    Solution sol;
    string s = "  +3.4E-2   ";
    bool isNum = sol.isNumber(s);
    cout << (isNum ? "true" : "false") << endl;
}
