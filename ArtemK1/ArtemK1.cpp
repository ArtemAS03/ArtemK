#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ifstream F_in("1.txt");
int main()
{
	system("chcp 1251");
	char q;
	int w = 0;
	while (F_in.peek() != EOF)
	{
		F_in.get(q);
		if (q == '\n')
		{
			w++;
		}
	}
	w++;
	string** mas = new string* [w + 1];
	int m = 3;
	for (int i = 0; i <= w; i++)
	{
		mas[i] = new string[m];
	}
	F_in.seekg(0);
	string r, slovo;
	int y;
	getline(F_in, r);
	string::size_type v = 0, pos = 0;
	for (int i = 0; i <= w; i++)
	{
		y = 0;
		v = r.find(" ", pos);
		while (v < r.length())
		{
			slovo = r.substr(pos, v - pos);

			mas[i][y] = slovo;
			y++;
			pos = v + 1;
			v++;
			v = r.find(" ", pos);
		}
		v = r.rfind(" ", r.length());
		slovo = r.substr(v + 1, r.length());
		mas[i][y] = slovo;
	}
	for (int i = 0; i <= w; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << mas[i][j];
		}
	}
	for (int i = 0; i <= w; i++) {
		delete[] mas[i];
	}
	delete[] mas;
	system("pause");
	return 0;
}