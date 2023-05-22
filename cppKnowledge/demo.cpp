#include <iostream>
using namespace std;

#pragma pack(8)

struct S
{
    char c;     // 1-4
	int i;      // 4-8
	char d;   // 8-16
};

int main() {
    cout << sizeof(S) << endl;
}