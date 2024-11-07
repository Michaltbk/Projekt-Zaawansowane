#include "ListaDwuKierunkowa.h"
#include <iostream>
#include "Powiazanie.cpp"

using namespace std;

/**
 * @brief Konstruktor, kt�ry inicjalizuje list� jako pust�
 * Ustawia wska�niki przod i tyl na nullptr, wskazuj�c na brak element�w w li�cie.
 */
ListaDwuKierunkowa::ListaDwuKierunkowa() {
    przod = nullptr;
    tyl = nullptr;
}

/**
 * @brief Wy�wietla elementy listy od pocz�tku do ko�ca.
 * Przechodzi przez list� i wypisuje dane ka�dego elementu.
 * Je�li lista jest pusta, wy�wietla komunikat o pustej li�cie.
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
 * @brief Wy�wietla elementy listy od ko�ca do pocz�tku.
 * Przechodzi przez list� od ostatniego elementu do pierwszego, wypisuj�c dane.
 * Je�li lista jest pusta, wy�wietla komunikat o pustej li�cie.
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
 * @brief Dodaje nowy element na pocz�tek listy.
 * Tworzy nowy obiekt Powiazanie, kt�ry zostaje dodany na pocz�tek listy.
 * Je�li lista by�a pusta, ustawia ten element jako pierwszy i ostatni.
 * @param x Warto��, kt�ra zostaje przypisana do nowego elementu.
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
 * Tworzy nowy obiekt Powiazanie, kt�ry zostaje dodany na koniec listy.
 * Je�li lista by�a pusta, ustawia ten element jako pierwszy i ostatni.
 * @param x Warto��, kt�ra zostaje przypisana do nowego elementu.
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
 * @brief Usuwa element na pocz�tku listy.
 * Usuwa pierwszy element listy i aktualizuje wska�nik przod.
 * Je�li lista staje si� pusta, ustawia oba wska�niki przod i tyl na nullptr.
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
 * @brief Usuwa element na ko�cu listy.
 * Usuwa ostatni element listy i aktualizuje wska�nik tyl.
 * Je�li lista staje si� pusta, ustawia oba wska�niki przod i tyl na nullptr.
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
 * @brief Dodaje nowy element pod okre�lonym indeksem w li�cie.
 * Je�li indeks wynosi 0, nowy element zostaje dodany na pocz�tku listy.
 * Je�li indeks jest wi�kszy od d�ugo�ci listy, element zostaje dodany na ko�cu.
 * @param val Warto��, kt�ra zostaje przypisana do nowego elementu.
 * @param index Indeks, pod kt�rym zostanie dodany nowy element.
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
 * @brief Usuwa element pod okre�lonym indeksem z listy.
 * Je�li indeks wynosi 0, usuwa pierwszy element.
 * Je�li element na danym indeksie nie istnieje, wy�wietla komunikat o b��dzie.
 * @param index Indeks elementu do usuni�cia.
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
 * @brief Wy�wietla element nast�puj�cy po elemencie podanym przez indeks.
 * Sprawdza, czy element ma nast�pny element, je�li tak, wypisuje jego dane.
 * Je�li nie ma nast�pnego elementu, wy�wietla odpowiedni komunikat.
 * @param index Indeks, dla kt�rego ma by� wy�wietlony nast�pny element.
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
 * @brief Wy�wietla element poprzedzaj�cy element podany przez indeks.
 * Sprawdza, czy element ma poprzedni element, je�li tak, wypisuje jego dane.
 * Je�li nie ma poprzedniego elementu, wy�wietla odpowiedni komunikat.
 * @param index Indeks, dla kt�rego ma by� wy�wietlony poprzedni element.
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
 * Iteracyjnie usuwa wszystkie elementy, zaczynaj�c od pierwszego.
 */
void ListaDwuKierunkowa::wyczysc() {
    while (przod) {
        usunPrzod();
    }
}

/**
 * @brief Testowa funkcja do ustawienia dw�ch element�w listy.
 * Ustawia dwa elementy w li�cie i tworzy odpowiednie po��czenia.
 */
void ListaDwuKierunkowa::test() {
    Powiazanie* pierwszy = new Powiazanie(2);
    Powiazanie* drugi = new Powiazanie(6);

    pierwszy->nastepny = drugi;
    drugi->poprzedni = pierwszy;

    przod = pierwszy;
    tyl = drugi;
}
