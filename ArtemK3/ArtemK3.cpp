#include "iostream"
#include "fstream" // это библиотека для работы с файлами
#include "string" // строки
#include <vector> // логично
#include <algorithm> //это для сложной функции, потом увидишь
#include <iomanip> //  это для оформления, помечу единицой(1), потом поймешь где это


using namespace std;
ifstream f("1.txt");
// создаем структуру, 
struct work
{

	string fname, gender, education;
	int date, date_work;
	void print();
	void print1();
};
void work::print1() // эта хуйня нужна для вывода
{
	cout << setw(10) << "Фамилия" << setw(15) << "Год рождения" << setw(10) << "Пол" << setw(15) << "Образование" << setw(20) << "Год начала работы" << endl;
}
void work::print() // эта тоже
{
	cout << setw(10) << fname << setw(12) << date << setw(15) << gender << setw(11) << education << setw(16) << date_work << endl;

}



int main()
{
	system("chcp 1251");
	int n = 0;
	string s, l;
	if (!f.is_open()) // делаем проверку на файл
		cout << "Файл не удалось открыть!" << endl;
	vector<work> list; // этой хуйней создаем вектор
	work b;

	while (f.peek() != EOF) // тут мы заполняем вектор
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
	cout << endl << "Список всех работников: " << endl; // заебись, вектор заполнен, выводим его
	list[0].print1();
	for (int i = 0; i < n; i++)
	{
		list[i].print();
	}
	cout << endl;
	sort(list.begin(), list.end(), [](const work& a, const work& b) {return a.date < b.date;}); // це хуйня под названием функция сложной сортировки
	// основана на методе сортировки пузырька, только в 3 раза меньше по объему написанного кода. вот так вот.
	// Конечно же это дед Серега
	cout << "Самый старший сотрудник среди мужчин: " << endl;
	bool flag = false;
	int i = 0;
	while(flag == false) // флаг мне понадобился для того, чтобы сделать проверку на то, что я на мужчине, ибо после сортировки самым первым сотрудником
	// у меня может оказаться девушка, поэтому надо проверить
	{
		if (list[i].gender == "Мужской")
		{
			list[i].print1(); // ну и выводим
			list[i].print();
			flag = true;
		}
		i++;
	}
	cout << endl << "Список молодых работников (до 28 лет): " << endl; // тут без выебонов, так как сейчас 2022, выводим всех тех, кто родился позже 1996
	list[0].print1();
	for (int i = 0; i < n; i++)
	{
		if (list[i].date > 1996)
			list[i].print();
	}
	cout << endl;
	cout << endl;
	f.close();
	system("Pause");
	return 0;
}