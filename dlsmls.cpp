// ConsoleApplication4.cpp : Defines the entry point for the console application.
// up 22233444

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>;
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int n;//���������� ������
	int gone=0;//���������� �������� ������
	int m;//���������� ��������
	int k;//���������� ������ ������
	int xi, yi;//����� ������� � ����� �����
	string buff;
	int colours[101][101];
	int quantity[101];//����������
	int columns = 0;
	for (int i = 0; i < 101; i++) {// i ����� �� ����������� x
		for (int j = 0; j < 101; j++) {// j ����� �� ����������� y
			colours[i][j] = 0;
		}
	}
	for (int i = 0; i < 101; i++) {// i ����� �� ����������� x
			quantity[i] = 0;
	}
	ifstream data("C:/Users/Beforus/Desktop/input.txt");
	data >> n >> m >> k;
	for (int i = 1; i < n; i++) {
		data >> xi >> yi;
		quantity[xi]++;
		colours[xi][quantity[xi]] = yi;
	}
	data.close();
	ofstream transfer("C:/Users/Beforus/Desktop/output.txt");
	for (int i = 0; i < 101; i++) {
		if (quantity[i] != 0) {
			for (int j = 0; j < 101; j++) {
				if ((colours[i][j] == colours[i][j + 1])&&(colours[i][j]!=0)) {
					gone += 2;
					j += 1;
				}
			}
			}	
	}
	n = n - gone;
	transfer << n;
	transfer.close();
	cout << "���������� ������ ���������� �� ������ = " << n << endl;
	system("pause");
	return 0;
}