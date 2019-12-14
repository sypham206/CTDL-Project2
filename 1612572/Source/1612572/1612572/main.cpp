/*
P1: Nén dữ liệu tập tin
- Input: file input.txt
- Output: file output.txt là kết quả nén theo thuật toán RLE
P2: Nén nâng cao*/



#include <iostream>
#include<fstream>
#include"compressString.h"

int main() {

	fstream inFile, outFile;
	//         
	string inPath = "input.txt";
	string outPath = "output.txt";
	string listString[MAX];
	int lenListString = 0;

	// Mở file
	inFile.open(inPath, ios::in);
	outFile.open(outPath, ios::out);
	if (inFile.fail())
		cout << "Failed to open this file!" << std::endl;
	while (!inFile.eof())
	{
		char temp[255];
		inFile.getline(temp, 255);
		listString[lenListString] = temp;
		lenListString++;
	}
	inFile.close();

	// In chuỗi
	cout << endl << "\nDATA ";
	cout << "\n------------------------------------------------";
	for (int i = 0; i < lenListString; i++)
	{
		cout << endl << listString[i];
	}
	cout << "\n------------------------------------------------";
	cout << endl << "\nCOMPRESSED DATA ";
	cout << "\n------------------------------------------------";
	for (int i = 0; i < lenListString; i++)
	{
		// In chuỗi được nén
		cout << endl<< compression(listString[i]);
		// Ghi vào file
		if (i > 0) outFile << endl;
		outFile << compression(listString[i]);
	}
	cout << "\n------------------------------------------------";

	cout << endl << "\nEXTRACTED DATA ";
	cout << "\n------------------------------------------------";
	for (int i = 0; i < lenListString; i++)
	{
		// In chuỗi được nén
		cout << endl << extraction(compression(listString[i]));
	}
	cout << "\n------------------------------------------------";
	outFile.close();

	cout << endl << endl;
	system("pause");
	return 0;
}