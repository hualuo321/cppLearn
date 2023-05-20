#include <iostream>
#include <string>
using namespace std;

/** 
 *  题目：把字符串 s 中的每个空格替换成 "%20"
 *  输入：s = "We are happy."
 *  输出："We%20are%20happy."
 *  思路：
 *      1. 依次遍历每个字符串 s 中的每个字符 for (auto &c : s) {...}
 *      2. 如果是空格则添加 '%' '2' '0' 三个字符 
 *      3. 如果不是空格则添加 c
 */
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto &c : s) {             // 1. 依次遍历每个字符串 s 中的每个字符 for (auto &c : s) {...}
            if (c == ' ') {             // 2. 如果是空格则添加 '%' '2' '0' 三个字符 
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            } else {                    // 3. 如果不是空格则添加 c
                res.push_back(c);
            }
        }
        return res;
    }

    void printStr(string s) {
        for (auto &c : s) {
            cout << c;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;
    string s = "we are happy.";
    string res = sol.replaceSpace(s);
    sol.printStr(res);
}