#include"compressString.h"
using namespace std;

// Hàm nén chuỗi
string compression(const string& str) {
	int i = str.size();
	string letters;
	letters[0] = str[0];
	for (int j = 0; j < i; ++j) {
		int count = 1;
		while (str[j] == str[j + 1]) {
			count++;
			j++;
		}
		letters.push_back('0' + count);
		letters.push_back(str[j]);
	}
	return letters;
}