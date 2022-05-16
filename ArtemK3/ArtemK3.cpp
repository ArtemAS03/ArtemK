#include "iostream"
#include "fstream"
#include "string"
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;
ifstream f("1.txt");

struct work
{

	string fname, gender, education;
	int date, date_work;
	void print();
	void print1();
};
void work::print1()
{
	cout << setw(10) << "�������" << setw(15) << "��� ��������" << setw(10) << "���" << setw(15) << "�����������" << setw(20) << "��� ������ ������" << endl;
}
void work::print()
{
	cout << setw(10) << fname << setw(12) << date << setw(15) << gender << setw(11) << education << setw(16) << date_work << endl;

}



int main()
{
	system("chcp 1251");
	int n = 0;
	string s, l;
	if (!f.is_open())
		cout << "���� �� ������� �������!" << endl;
	vector<work> list;
	work b;

	while (f.peek() != EOF)
	{
		list.push_back(b);
		getline(f, l);
		list[n].fname = l;
		getline(f, l);
		list[n].date = stof(l);
		getline(f, l);
		list[n].gender = l;
		getline(f, l);
		list[n].education = l;
		getline(f, l);
		list[n].date_work = stof(l);
		n++;
		getline(f, l);
	}
	cout << endl << "������ ���� ����������: " << endl;
	list[0].print1();
	for (int i = 0; i < n; i++)
	{
		list[i].print();
	}
	cout << endl;
	sort(list.begin(), list.end(), [](const work& a, const work& b) {return a.date < b.date;});
	cout << "����� ������� ��������� ����� ������: " << endl;
	bool flag = false;
	int i = 0;
	while(flag == false)
	{
		if (list[i].gender == "�������")
		{
			list[i].print1();
			list[i].print();
			flag = true;
		}
		i++;
	}
	cout << endl << "������ ������� ���������� (�� 28 ���): " << endl;
	list[0].print1();
	for (int i = 0; i < n; i++)
	{
		if (list[i].date > 1996)
			list[i].print();
	}
	cout << endl;
	cout << endl;
	system("Pause");
	return 0;
}