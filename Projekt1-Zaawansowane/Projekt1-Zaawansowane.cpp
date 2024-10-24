#include <iostream>
using namespace std;

struct Powiazanie {
	int dane;
	Powiazanie* nastepny;
	Powiazanie* poprzedni;

	Powiazanie(int wartosc) : dane(wartosc), nastepny(nullptr), poprzedni(nullptr) {}
};

class ListaDwuKierunkowa
{
private:
	Powiazanie* przod;
	Powiazanie* tyl;

public:
	ListaDwuKierunkowa() : przod(nullptr), tyl(nullptr) {}

	void wyswietl()
	{
		Powiazanie* aktualny = przod;

		while (aktualny)
		{
			cout << aktualny->dane << " ";
			aktualny = aktualny->nastepny;
		}
		cout<<endl;
	}

	void dodajNaPrzod(int x) {
		Powiazanie* nowe = new Powiazanie(x);
		if (!przod) {
			przod = tyl = nowe;
		}
		else {
			nowe->nastepny = przod;
			przod->poprzedni = nowe;
			przod = nowe;
		}
	}

	void dodajNaTyl(int x) {
		Powiazanie* nowe = new Powiazanie(x);
		if (!tyl) {
			przod = tyl = nowe;
		}
		else {
			nowe->poprzedni = przod;
			tyl->nastepny = nowe;
			tyl = nowe;
		}
	}

	void usunPrzod() {
		if (!przod) return;

		Powiazanie* temp = przod;
		if (przod == tyl) {
			przod = tyl = nullptr;
		}
		else {
			przod = przod->nastepny;
			przod->poprzedni = nullptr;
		}
		delete temp;
	}



	void test() {
		Powiazanie* pierwszy = new Powiazanie(2);
		Powiazanie* drugi = new Powiazanie(6);

		pierwszy->nastepny = drugi;
		drugi->poprzedni = pierwszy;

		przod = pierwszy;
		tyl =drugi;
	}

};


int main()
{
	ListaDwuKierunkowa lista;

	lista.test();

	lista.wyswietl();

	lista.dodajNaPrzod(10);

	lista.wyswietl();
	
	lista.dodajNaTyl(103);

	lista.wyswietl();

	lista.usunPrzod();

	lista.wyswietl();



	return 0;
}


