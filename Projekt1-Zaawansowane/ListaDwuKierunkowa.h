#pragma once
#include "Powiazanie.cpp"
class ListaDwuKierunkowa {
protected:
	Powiazanie* przod;
	Powiazanie* tyl;

public:
	ListaDwuKierunkowa();

	void wyswietl();

	void wyswietlNaOdwrot();

	void dodajNaPrzod(int x);

	void dodajNaTyl(int x);

	void usunPrzod();

	void usunTyl();

	void dodajPodIndeks(int val, int index);

	void usunIndeks(int index);

	void wyswietlNastepny(int index);

	void wyswietlPoprzedni(int index);

	void wyczysc();

	void test();
};

