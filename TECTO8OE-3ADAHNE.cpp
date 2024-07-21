#include <iostream>
#include <string>
#include <vector>

using namespace std;

// описание структуры отсчета (одного)
struct Otschet
{
private:
	int x, y;

public:
	Otschet(int Xin, int Yin) {
		this->x = Xin;
		this->y = Yin;
	};
	int getY() { return this->y; };
	string get_to_string() {
		return "(" + to_string(this->x) + ", " + to_string(this->y) + ")";
	};
};

// вывод последовательности
static void Posledovatelnost_cout(vector<Otschet>* posled) {
	int last_in_posled = posled->size() - 1;
	for (auto i = 0; i < last_in_posled; i++)
		cout << (*posled)[i].get_to_string() << ", ";
	cout << (*posled)[last_in_posled].get_to_string() << endl;

};

// функция, прореживающая последовательность отсчетов, оставляя первый, последний, и каждый n-ый отсчёт из последовательности идентичных
void Proryadit(vector<Otschet>* posledovatelnost, int n) {

	int schetchik = 1; // счётчик до n 
	// +1, т.к. 0 элемент учли
	auto iterator = posledovatelnost->begin() + 1; // итератор вектора
	// +1, т.к. 0 элемент учли

	while (iterator != posledovatelnost->end()) // перебор вектора
		if ((iterator - 1)._Ptr->getY() != iterator._Ptr->getY()) { // если y не совпадает
			schetchik = 1; // теперь y`ов всего 1
			iterator++; // идём дальше
		}
		else // если y совпадает
		{
			schetchik++; // тогда y +1
			if (schetchik == n) { // если y уже n
				schetchik = 0; // сбрасываем счётчик
				iterator++; // идём дальше
			}
			else if (iterator._Ptr->getY() != (iterator + 1)._Ptr->getY()) { // иначе если на следующем y меняется
				iterator += 2; // перепрыгиваем сразу конец и начало /последовательностей идентичных отсчётов/
				schetchik = 1; // теперь y`ов всего 1
			}
			else // в любом другом случае
				iterator = posledovatelnost->erase(iterator); //удаляем отсчёт
		}
};

int main() {
	setlocale(LC_ALL, "Russian");

	vector<Otschet>* posledovatelnost = new vector<Otschet>{
			Otschet(1, 10),
			Otschet(2, 11),
			Otschet(3, 11),
			Otschet(4, 11),
			Otschet(5, 11),
			Otschet(6, 10),
			Otschet(7, 11),
			Otschet(8, 11),
			Otschet(9, 11),
			Otschet(10, 11),
			Otschet(11, 10)
	};
	cout << "Исходная: ";
	Posledovatelnost_cout(posledovatelnost);

	Proryadit(posledovatelnost, 3);
	cout << "Результат при n = 3: ";
	Posledovatelnost_cout(posledovatelnost);

	delete posledovatelnost;

	posledovatelnost = new vector<Otschet>{
			Otschet(1, 10),
			Otschet(2, 11),
			Otschet(3, 11),
			Otschet(4, 11),
			Otschet(5, 11),
			Otschet(6, 10),
			Otschet(7, 11),
			Otschet(8, 11),
			Otschet(9, 11),
			Otschet(10, 11),
			Otschet(11, 10)
	};

	Proryadit(posledovatelnost, 4);
	cout << "Результат при n = 4: ";
	Posledovatelnost_cout(posledovatelnost);

	return 0;
}