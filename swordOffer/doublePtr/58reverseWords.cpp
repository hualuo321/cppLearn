#include <iostream>
#include <string>
using namespace std;

/**
 *  题目：反转字符串里的单词
 *  输入: "  hello world!  "
 *  输出: "world! hello"
 *  思路：
 *      1. 定义双指针，目的是为了圈出一个个单词
 *      2. 从串尾开始遍历，如果有空格，两指针向左移动，寻找单词
 *      3. 找到单词后，左指针移动，直到找到完整单词
 *      4. 添加到 res 中，重复 2，3 过程，继续找单词
*/

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int p1 = s.size() - 1, p2 = s.size() - 1;
        while (p1 >= 0) {
            while (p1 >= 0 && s[p1] == ' ') {
                p1--;
                p2 = p1;
            }
            while (p1 >= 0 && s[p1] != ' ') p1--;
            if (p2 >= 0) {
                res.append(s.substr(p1 + 1, p2 - p1));
                res.append(" ");
            }
            cout << p1 << " " << p2 << " " << s.substr(p1 + 1, p2 - p1) << endl;
        }
        return res.substr(0, res.size() - 1);
    }
};

int main() {
    string s = "123";
    Solution sol;
    string res = sol.reverseWords(s);
    cout << "#" << res << "#" << endl;
}

// #  aaa  bbb  ccc  #
//   1
//      2