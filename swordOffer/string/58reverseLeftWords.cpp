#include <iostream>
#include <string>
using namespace std;

/**
 *  题目：将字符串 s 之前的字符移动到串尾
 *  输入: s = "abcdefg", k = 2
 *  输出: "cdefgab"
 *  思路：
 *      1. 将字符串长度增加 n
 *      2. 将前 n 个字符移动到尾部
 *      3. 删除前 n 个字符串
*/
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        s.resize(len + n);              // 1. 将字符串长度增加 n
        for (int i = 0; i < n; i++) {
            s[len + i] = s[i];          // 2. 将前 n 个字符移动到尾部
        }
        s.erase(0, n);                  // 3. 删除前 n 个字符串
        return s;
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
    string s = "abcdefg";
    int n = 2;
    string res = sol.reverseLeftWords(s, n);
    sol.printStr(res);
}

