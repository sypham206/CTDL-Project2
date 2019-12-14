#pragma once
#include<iostream>
#include <string>
using namespace std;
#define MAX 100

/*	Hàm chuyển đổi số nguyên kiểu string về kiểu int
	Input: Số nguyên kiểu string
	Output: Số nguyên kiểu int */
int stringToInt(string str);

/*	Hàm nén chuỗi RLE
	Input: Chuỗi str
	Output: Chuỗi được nén theo thuật toán RLE */
string compression(const string& str);

/* Hàm giải nén chuỗi
	Input: Chuỗi str đã được bén
	Output: Chuỗi được giải nén */
string extraction(const string& str);