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
	int n;//количество ящиков
	int gone=0;//количество уехавших ящиков
	int m;//количество размеров
	int k;//количество разных цветов
	int xi, yi;//номер размера и номер цвета
	string buff;
	int colours[101][101];
	int quantity[101];//количество
	int columns = 0;
	for (int i = 0; i < 101; i++) {// i будут по кооридинате x
		for (int j = 0; j < 101; j++) {// j будут по кооридинате y
			colours[i][j] = 0;
		}
	}
	for (int i = 0; i < 101; i++) {// i будут по кооридинате x
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
	cout << "Количество ящиков оставшихся на складе = " << n << endl;
	system("pause");
	return 0;
}