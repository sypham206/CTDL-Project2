#include"compressString.h"
using namespace std;

/* Hàm chuyển đổi số nguyên kiểu string về kiểu int */
int stringToInt(string str)
{
	int result = 0;
	if (str[0] == '-')
	{
		int tmp = 0;
		for (int i = 1; i < str.length(); i++)
		{
			tmp = tmp * 10 + int(str[i]) - '0';
		}
		result = 0 - tmp;
	}
	else
		for (int i = 0; i < str.length(); i++)
		{
			result = result * 10 + int(str[i]) - '0';
		}
	return result;
}
/*  Hàm nén chuỗi */
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

/* Hàm giải nén chuỗi */
string extraction(const string& str) {
	int i = str.size();
	string letters;
	int pos = 0; // Vị trí hiện tại con trỏ	
	int start; // Vị trí bắt đầu của số
	int end; // Vị trí kết thúc số
	while (pos < i)
	{
		// Vị trí start là pos
		start = pos;
		// Kiểm tra nếu end là kí tự số => Tìm được vị trí end
		end = start;
		while (str[end+1] >= '0' && str[end+1] <= '9')
			end++;
		// Kí tự cần tìm ngay sau end
		int char_pos = end + 1;
		string num = "";
		for (int j = start; j <= end; j++) num += str[j];
		for (int j = 0; j < stringToInt(num); j++) letters.push_back(str[char_pos]);
		// Đưa con trỏ sau kí tự
		pos = char_pos + 1;
	}
	return letters;
}
