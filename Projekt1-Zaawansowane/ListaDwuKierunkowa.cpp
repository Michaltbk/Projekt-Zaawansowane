#include "ListaDwuKierunkowa.h"
#include <iostream>
#include "Powiazanie.cpp"

using namespace std;

/**
 * @brief Konstruktor, który inicjalizuje listê jako pust¹
 * Ustawia wskaŸniki przod i tyl na nullptr, wskazuj¹c na brak elementów w liœcie.
 */
ListaDwuKierunkowa::ListaDwuKierunkowa() {
    przod = nullptr;
    tyl = nullptr;
}

/**
 * @brief Wyœwietla elementy listy od pocz¹tku do koñca.
 * Przechodzi przez listê i wypisuje dane ka¿dego elementu.
 * Jeœli lista jest pusta, wyœwietla komunikat o pustej liœcie.
 */
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

/**
 * @brief Wyœwietla elementy listy od koñca do pocz¹tku.
 * Przechodzi przez listê od ostatniego elementu do pierwszego, wypisuj¹c dane.
 * Jeœli lista jest pusta, wyœwietla komunikat o pustej liœcie.
 */
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

/**
 * @brief Dodaje nowy element na pocz¹tek listy.
 * Tworzy nowy obiekt Powiazanie, który zostaje dodany na pocz¹tek listy.
 * Jeœli lista by³a pusta, ustawia ten element jako pierwszy i ostatni.
 * @param x Wartoœæ, która zostaje przypisana do nowego elementu.
 */
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

/**
 * @brief Dodaje nowy element na koniec listy.
 * Tworzy nowy obiekt Powiazanie, który zostaje dodany na koniec listy.
 * Jeœli lista by³a pusta, ustawia ten element jako pierwszy i ostatni.
 * @param x Wartoœæ, która zostaje przypisana do nowego elementu.
 */
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

/**
 * @brief Usuwa element na pocz¹tku listy.
 * Usuwa pierwszy element listy i aktualizuje wskaŸnik przod.
 * Jeœli lista staje siê pusta, ustawia oba wskaŸniki przod i tyl na nullptr.
 */
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

/**
 * @brief Usuwa element na koñcu listy.
 * Usuwa ostatni element listy i aktualizuje wskaŸnik tyl.
 * Jeœli lista staje siê pusta, ustawia oba wskaŸniki przod i tyl na nullptr.
 */
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

/**
 * @brief Dodaje nowy element pod okreœlonym indeksem w liœcie.
 * Jeœli indeks wynosi 0, nowy element zostaje dodany na pocz¹tku listy.
 * Jeœli indeks jest wiêkszy od d³ugoœci listy, element zostaje dodany na koñcu.
 * @param val Wartoœæ, która zostaje przypisana do nowego elementu.
 * @param index Indeks, pod którym zostanie dodany nowy element.
 */
void ListaDwuKierunkowa::dodajPodIndeks(int val, int index) {
    if (index == 0) {
        dodajNaPrzod(val);
        return;
    }

    Powiazanie* aktualny = przod;
    for (int i = 0; i < index - 1; ++i) {
        if (!aktualny) {
            cout << "Indeks " << index << " nie istnieje." << endl;
            return;
        }
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

/**
 * @brief Usuwa element pod okreœlonym indeksem z listy.
 * Jeœli indeks wynosi 0, usuwa pierwszy element.
 * Jeœli element na danym indeksie nie istnieje, wyœwietla komunikat o b³êdzie.
 * @param index Indeks elementu do usuniêcia.
 */
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

/**
 * @brief Wyœwietla element nastêpuj¹cy po elemencie podanym przez indeks.
 * Sprawdza, czy element ma nastêpny element, jeœli tak, wypisuje jego dane.
 * Jeœli nie ma nastêpnego elementu, wyœwietla odpowiedni komunikat.
 * @param index Indeks, dla którego ma byæ wyœwietlony nastêpny element.
 */
void ListaDwuKierunkowa::wyswietlNastepny(int index) {
    Powiazanie* aktualny = przod;

    for (int i = 0; i < index; ++i) 
{
        if (!aktualny) {
            cout << "Indeks " << index << " nie istnieje." << endl;
            return;
        }
        aktualny = aktualny->nastepny;
    }

    if (aktualny && aktualny->nastepny) 
{
        cout << "Nastepny element dla indeksu " << index << ": " << aktualny->nastepny->dane << endl;
    }
    else {
        cout << "Brak nastepnego elementu dla indeksu " << index << "." << endl;
    }
}

/**
 * @brief Wyœwietla element poprzedzaj¹cy element podany przez indeks.
 * Sprawdza, czy element ma poprzedni element, jeœli tak, wypisuje jego dane.
 * Jeœli nie ma poprzedniego elementu, wyœwietla odpowiedni komunikat.
 * @param index Indeks, dla którego ma byæ wyœwietlony poprzedni element.
 */
void ListaDwuKierunkowa::wyswietlPoprzedni(int index) {
    Powiazanie* aktualny = przod;

    for (int i = 0; i < index; ++i) 
{
        if (!aktualny) {
            cout << "Indeks " << index << " nie istnieje." << endl;
            return;
        }
        aktualny = aktualny->nastepny;
    }

    if (aktualny && aktualny->poprzedni) 
{
        cout << "Poprzedni element dla indeksu " << index << ": " << aktualny->poprzedni->dane << endl;
    }
    else {
        cout << "Brak poprzedniego elementu dla indeksu " << index << "." << endl;
    }
}

/**
 * @brief Usuwa wszystkie elementy z listy.
 * Iteracyjnie usuwa wszystkie elementy, zaczynaj¹c od pierwszego.
 */
void ListaDwuKierunkowa::wyczysc() {
    while (przod) {
        usunPrzod();
    }
}

/**
 * @brief Testowa funkcja do ustawienia dwóch elementów listy.
 * Ustawia dwa elementy w liœcie i tworzy odpowiednie po³¹czenia.
 */
void ListaDwuKierunkowa::test() {
    Powiazanie* pierwszy = new Powiazanie(2);
    Powiazanie* drugi = new Powiazanie(6);

    pierwszy->nastepny = drugi;
    drugi->poprzedni = pierwszy;

    przod = pierwszy;
    tyl = drugi;
}
