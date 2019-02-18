// test3PizzaPokazivaci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pizza {
private:
	static vector <Pizza*> pizze;
	string naziv;
	int osnovna_cijena;

	static void popis_pizza() {
		for (int i = 0; i < pizze.size(); i++) {
			cout << pizze[i]->get_naziv() << "\t" << pizze[i]->get_cijena() << " - " << i << endl;
		}
	}

public:
	Pizza() {
		cout << "Unesite naziv pizze: ";
		cin >> this->naziv;
		cout << "Unesite cijenu: ";
		cin >> this->osnovna_cijena;
	}
	void set_naziv(string n) {
		naziv = n;
	}
	string get_naziv() {
		return naziv;
	}
	void set_cijena(int c) {
		osnovna_cijena = c;
	}
	int get_cijena() {
		return osnovna_cijena;
	}

	void static nova_pizza() {
		Pizza* p = new Pizza();
		pizze.push_back(p);
	}

	static Pizza* odabir_pizze() {
		popis_pizza();
		int odabir;
		cout << "Odaberite redni broj pizze: ";
		cin >> odabir;
		return pizze[odabir];
	}
};

vector <Pizza*> Pizza::pizze;

class Dodatak {
private:
	static vector <Dodatak*> dodaci;
	string naziv;
	int cijena;

public:
	Dodatak()
	{
		string naziv;
		int cijena;
		cout << "Unesite naziv dodatka: ";
		cin >> naziv;
		cout << "Unesite cijenu: ";
		cin >> cijena;
		this->set_naziv(naziv);
		this->set_cijena(cijena);
	}

	static void novi_dodatak() {
		Dodatak* d = new Dodatak();
		dodaci.push_back(d);
	}

	static void popis_dodataka() {
		for (int i = 0; i < dodaci.size(); i++) {
			cout << dodaci[i]->naziv << "\t" << dodaci[i]->cijena << " - " << i << endl;
		}
		system("pause");
	}

	void set_naziv(string n) {
		naziv = n;
	}
	string get_naziv() {
		return naziv;
	}
	void set_cijena(int c) {
		cijena = c;
	}
	int get_cijena() {
		return cijena;
	}

	static Dodatak* odabir_dodatka() {
		popis_dodataka();
		int odabir;
		cout << "Odaberite redni broj dodatka: ";
		cin >> odabir;
		return dodaci[odabir];
	}
};

vector <Dodatak*> Dodatak::dodaci;

class Narudzba {
private:
	Pizza* pizza;
	vector <Dodatak*> dodaci;
	int izracun_cijene() {
		int cijena = 0;
		cijena += this->pizza->get_cijena();
		for (int i = 0; i < dodaci.size(); i++) {
			cijena += this->dodaci[i]->get_cijena();
		}
		return cijena;
	}
public:
	void slozi_pizzu() {
		char odabir;
		cout << "Dobrodosli!" << endl;
		pizza = Pizza::odabir_pizze();
		do {
			cout << "Zelite li neki dodatak (D/N): ";
			cin >> odabir;
			if (odabir == 'D' || odabir == 'd') {
				Dodatak* d = Dodatak::odabir_dodatka();
				dodaci.push_back(d);
			}
		} while (odabir == 'D' || odabir == 'd');
	}

	void ispis_pizze() {
		cout << "Vasa narudzba:\n";
		cout << "Osnova pizze je " << this->pizza->get_naziv() << ",\n";
		if (this->dodaci.size() > 0) {
			cout << "a na nju ste jos stavili:\n";
			for (int i = 0; i < dodaci.size(); i++) {
				cout << this->dodaci[i]->get_naziv() << endl;
			}
		}
		cout << "Cijena pizze je " << izracun_cijene() << " kn." << endl;
		system("pause");
	}
};

void Menu() {
	system("cls");
	cout << "Dobrodošli u pizzeriu \n" << endl;
	cout << "1. Popis pizza \n" << endl;
	cout << "2. Popis dodataka \n" << endl;
	cout << "3. Narudzba pizza \n" << endl;
	cout << "4. Unos pizza \n" << endl;
	cout << "5. Unos dodataka \n" << endl;
	cout << "6. Izlaz \n" << endl;
	cout << "Vas odabir: ";
	
}

int main()
{
	Menu();
	int b;
	Narudzba n;
	do{
		
		cin >> b;
		switch (b) {
		case 1:
			system("cls");
			Pizza::odabir_pizze();
			Menu();
			break;
		case 2:
			system("cls");
			Dodatak::popis_dodataka();
			Menu();
			break;
		case 3:
			system("cls");
			n.slozi_pizzu();
			n.ispis_pizze();
			Menu();
			break;
		case 4:
			system("cls");
			Pizza::nova_pizza();
			Menu();
			break;
			
		case 5:
			system("cls");
			Dodatak::novi_dodatak();
			Menu();
			break;
		case 6:
			b = 6;
		}

	} while (b != 6);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
