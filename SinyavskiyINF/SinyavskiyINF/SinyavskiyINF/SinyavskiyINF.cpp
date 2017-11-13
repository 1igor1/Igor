#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string key;

void coding()
{
	int i = 0;
	int flag = 0;
	ofstream fout("Encoded.txt", std::ofstream::binary);
	ifstream finFlag("Original.txt", std::ifstream::binary);

	cout << "Enter the key:  ";
	cin >> key;
	
	while (!finFlag.eof()) 
	{
		char a;
		finFlag.get(a);
		flag++;
	}
	finFlag.close();

	ifstream fin("Original.txt", std::ifstream::binary); 

	for (int k = 0; k < flag - 1; k++)
	{
		char a;
		unsigned char b;

		fin.get(a);
		b = ((char)a + (char)key[i]) % 256;
											
		fout << b;
		i = i + 1;
		if (i == key.length()) i = 0;
	}
	fin.close();
	fout.close();
}

void decoding()
{
	ofstream fout1("Decoded.txt", ifstream::binary);
	ifstream finFl("Encoded.txt", ifstream::binary);
	int flag = 0;

	cout << "Enter the key:  ";
	cin >> key;

	while (!finFl.eof())
	{
		char a;
		finFl.get(a);
		flag++;
	}
	finFl.close();

	ifstream fin1("Encoded.txt", ifstream::binary);
	int i = 0;
	for (int k = 0; k < flag - 1; k++)
	{
		char a;
		unsigned char b;

		fin1.get(a);
		b = ((unsigned char)a - (unsigned char)key[i]) % 256;
		fout1 << b;
		i = i + 1;
		if (i == key.length()) i = 0;
	}
}

int menu()
{
	int k;

	cout << "1) Encode" << endl;
	cout << "2) Decode" << endl;
	cout << "3) Open original file" << endl;
	cout << "4) Open encoded file" << endl;
	cout << "5) Open decoded file" << endl;
	cout << "0) Exit" << endl;
	cout << endl << "Select item: ";
	cin >> k;
	cout << endl << endl << endl;
	
	return k;
}

int main()
{
	int k;

	do
	{
		k = menu();
		switch (k)
		{
			case 1: 
			{ 
				cout << "Encoding file." << endl;
				coding(); 
				break; 
			}
			case 2: 
			{ 
				cout << "Decoding file." << endl;
				decoding(); 
				break; 
			}
			case 3: 
			{ 
				cout << "Open original file." << endl;
				system("notepad Original.txt"); 
				break; 
			}
			case 4: 
			{ 
				cout << "Open encoded file." << endl;
				system("notepad Encoded.txt"); 
				break; 
			}
			case 5: 
			{ 
				cout << "Open decoded file." << endl;
				system("notepad Decoded.txt");
				break; 
			}
			case 0: 
			{ 
				return 0; 
			}
		}
	} while (k);

	return 0;
}
//system("notepad D:\\5 сем\\Леонов\\SinyavskiyINF\\SinyavskiyINF\\SinyavskiyINF\\Decoded.txt");