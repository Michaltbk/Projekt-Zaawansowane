#include "ListaDwuKierunkowa.h"
#include <iostream>
#include "Powiazanie.cpp"

using namespace std;
	ListaDwuKierunkowa::ListaDwuKierunkowa(){ przod=nullptr, tyl=nullptr;}

	void ListaDwuKierunkowa::wyswietl() {
		Powiazanie* aktualny = przod;

		if (!przod) {
			cout << "Lista jest pusta." << endl;
			return;
		}

		while (aktualny) {
			cout << aktualny->dane << " ";
			aktualny = aktualny->nastepny;
		}
		cout << endl;
	}

	void ListaDwuKierunkowa::wyswietlNaOdwrot() {
		Powiazanie* aktualny = tyl;

		if (!przod) {
			cout << "Lista jest pusta." << endl;
			return;
		}

		while (aktualny) {
			cout << aktualny->dane << " ";
			aktualny = aktualny->poprzedni;
		}
		cout << endl;
	}

	void ListaDwuKierunkowa::dodajNaPrzod(int x) {
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

	void ListaDwuKierunkowa::dodajNaTyl(int x) {
		Powiazanie* nowe = new Powiazanie(x);
		if (!tyl) {
			przod = tyl = nowe;
		}
		else {
			tyl->nastepny = nowe;
			nowe->poprzedni = tyl;
			tyl = nowe;
		}
	}

	void ListaDwuKierunkowa::usunPrzod() {
		if (!przod) return;

		Powiazanie* temp = przod;
		if (przod == tyl) {
			przod = tyl = nullptr;
		}
		else {
			przod = przod->nastepny;
			if (przod) {
				przod->poprzedni = nullptr;
			}
		}
		delete temp;
	}

	void ListaDwuKierunkowa::usunTyl() {
		if (!tyl) return;

		Powiazanie* temp = tyl;
		if (przod == tyl) {
			przod = tyl = nullptr;
		}
		else {
			tyl = tyl->poprzedni;
			if (tyl) {
				tyl->nastepny = nullptr;
			}
		}
		delete temp;
	}

	void ListaDwuKierunkowa::dodajPodIndeks(int val, int index) {
		if (index == 0) {
			dodajNaPrzod(val);
			return;
		}

		Powiazanie* aktualny = przod;
		for (int i = 0; i < index - 1; ++i) {
			if (!aktualny) { cout << "Indeks " << index << " nie istnieje." << endl; return; }  
			aktualny = aktualny->nastepny;
		}

		if (!aktualny || !aktualny->nastepny) {
			dodajNaTyl(val);
			return;
		}

		Powiazanie* nowe = new Powiazanie(val);
		nowe->nastepny = aktualny->nastepny;
		nowe->poprzedni = aktualny;
		aktualny->nastepny->poprzedni = nowe;
		aktualny->nastepny = nowe;
	}

	void ListaDwuKierunkowa::usunIndeks(int index) {
		if (index == 0) {
			usunPrzod();
			return;
		}

		Powiazanie* aktualny = przod;
		for (int i = 0; i < index; ++i) {
			if (!aktualny->nastepny) {
				cout << "Indeks " << index << " nie istnieje." << endl;
				return;
			}
			aktualny = aktualny->nastepny;
		}

		if (!aktualny) {
			cout << "Indeks " << index << " nie istnieje." << endl;
			return;
		}

		if (aktualny == tyl) {
			usunTyl();
			return;
		}



		delete aktualny;
	}

	void ListaDwuKierunkowa::wyswietlNastepny(int index) {
		Powiazanie* aktualny = przod;


		for (int i = 0; i < index; ++i) {
			if (!aktualny) {
				cout << "Indeks " << index << " nie istnieje." << endl;
				return;
			}
			aktualny = aktualny->nastepny;
		}


		if (aktualny && aktualny->nastepny) {
			cout << "Nastepny element dla indeksu " << index << ": " << aktualny->nastepny->dane << endl;
		}
		else {
			cout << "Brak nastepnego elementu dla indeksu " << index << "." << endl;
		}
	}

	void ListaDwuKierunkowa::wyswietlPoprzedni(int index) {
		Powiazanie* aktualny = przod;


		for (int i = 0; i < index; ++i) {
			if (!aktualny) {
				cout << "Indeks " << index << " nie istnieje." << endl;
				return;
			}
			aktualny = aktualny->nastepny;
		}


		if (aktualny && aktualny->poprzedni) {
			cout << "Poprzedni element dla indeksu " << index << ": " << aktualny->poprzedni->dane << endl;
		}
		else {
			cout << "Brak poprzedniego elementu dla indeksu " << index << "." << endl;
		}
	}

	void ListaDwuKierunkowa::wyczysc() {
		while (przod) {
			usunPrzod();
		}
	}


	void ListaDwuKierunkowa::test() {
		Powiazanie* pierwszy = new Powiazanie(2);
		Powiazanie* drugi = new Powiazanie(6);

		pierwszy->nastepny = drugi;
		drugi->poprzedni = pierwszy;

		przod = pierwszy;
		tyl = drugi;
	}
