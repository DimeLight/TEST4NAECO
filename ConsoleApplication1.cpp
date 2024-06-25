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

//функция, прореживающая последовательность отсчетов
void Proryadit(vector<Otschet> posledovatelnost, int n) {
	int i = 0, //номер шага
		akty, //актуальное у на шаге
		akti = i, //номер последнего элемента
		schetchik = 1; //счетчик у
	akty = posledovatelnost[i].getY();
	i++;
	do
	{
		if (akty == posledovatelnost[i].getY()) {
			schetchik++;
			if (schetchik == n)
				schetchik = 0;
			posledovatelnost[akti] = posledovatelnost[i];
			akti++;
		}
		else
		{
			akty = posledovatelnost[i].getY();
			schetchik = 1;
			posledovatelnost[akti] = posledovatelnost[i - 1];
			akti++;
			posledovatelnost[akti] = posledovatelnost[i];
			akti++;
		}
	} while (posledovatelnost.size() < i);
	do
	{
		posledovatelnost.pop_back();
		akti++;
	} while (akti < i);
};

int main() {
	Otschet* posledovatelnost{
		new Otschet[11] {
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
			Otschet(11, 10),
			NULLptr
		} };
	i = 0;
	do
		cout << posledovatelnost[i].get; //вывод
	i++;
	while
		(posledovatelnost + i != nullptr)

		posledovatelnost = Proryadit(posledovatelnost, 3);

	i = 0;
	do
		cout << posledovatelnost[i].get; //вывод
	i++;
	while
		(posledovatelnost + i != nullptr)
		delete[] posledovatelnost;
	return 0;
}