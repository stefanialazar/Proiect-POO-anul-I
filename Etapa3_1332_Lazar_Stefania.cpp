#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <unordered_map>
#include <chrono>
#include <ctime>   
#include "Produse.h"
#include "Cos.h"
#include "Haine.h"
#include "Incaltaminte.h"

using namespace std;

ifstream in("IvyLakes.in");
ifstream haine_in("IvyLakeshaine.in");
ifstream incal_in("IvyLakesincal.in");
ofstream out("IvyLakes.out");

int i, j, k, alegere, task_user, task_admin, task_haine, task_incal, nr_reduceri, nr_inchis, nr_angajari, nr_haine, nr_incalt, nr_cos, pret_nou;


int main()
{
	set <pair<string, string>> reduceri; 
	set <pair<string, string>> inchis;   
	unordered_map <string, int> angajari;
	pair <string, string> perioada;
	std::vector <Haine> vect_haine;
	std::vector <Incaltaminte> vect_incal;
	string s0, s1;
	int a;
	in >> nr_reduceri >> nr_inchis >> nr_angajari;
	for (i = 0; i < nr_reduceri; i++)
	{
		in >> s0 >> s1;
		perioada.first = s0;
		perioada.second = s1;
		reduceri.insert(perioada);
	}
	for (i = 0; i < nr_inchis; i++)
	{
		in >> s0 >> s1;
		perioada.first = s0;
		perioada.second = s1;
		inchis.insert(perioada);
	}
	for (i = 0; i < nr_angajari; i++)
	{
		in >> s0 >> a;
		angajari.insert({ s0,a });
	}
	vector <Haine> haine_magazin;
	haine_in >> nr_haine;
	for (i = 0; i < nr_haine; i++) //citim din fisierul cu haine 
	{
		Haine h0 = Haine();
		h0.citireFisier(haine_in);
		haine_magazin.push_back(h0);
	}
	vector <Incaltaminte> incal_magazin;
	incal_in >> nr_incalt;
	for (i = 0; i < nr_incalt; i++) //citim din fisierul cu incaltaminte
	{
		Incaltaminte incal0 = Incaltaminte();
		incal0.citireFisier(incal_in);
		incal_magazin.push_back(incal0);
	}

	list <Cos> cosuri_magazin;
	Welcome hello;
	Haine h;
	Incaltaminte incal;
	hello.welcome();
	while (alegere != 3)
	{
		hello.alege();
		cin >> alegere;
		if (alegere == 1) //administrator
		{
			cout << "Bine ati revenit la munca :(. Ce task-uri indeplinim astazi? " << endl;
			task_admin = 0;
			while (task_admin != 13)
			{
				hello.task_admin();
				cin >> task_admin;
				Haine h0 = Haine();
				Incaltaminte incal0 = Incaltaminte();
				switch (task_admin) {
					case 1: // Sa vizionez toate tipurile de haine (bun)
						h.welcome();
						cout << endl;
						h.afisareTipdehaine();
						cout << endl;
						h.afisareMarimi();
						cout << endl;
						h.afisareCulori();
						cout << endl;
						break;
					case 2://Sa vizionez toate tipurile de incaltaminte (bun)
						incal.welcome();
						cout << endl;
						incal.afisareTipdeincalt();
						cout << endl;
						incal.afisareCuloriincalt();
						cout << endl;
						break;
					case 3://Adaug produse (bun)
						k = 0;
						cout << "Doriti sa adaugati haine sau incaltaminte? (introduceti numarul)" << endl;
						cout << "1. Haine" << endl;
						cout << "2. Incaltaminte" << endl;
						cout << "3. Inapoi la meniul principal" << endl;
						cin >> k;
						if (k == 1)
						{
							cin >> (Produse&)h0;
							cin >> h0;
							haine_magazin.push_back(h0);
						}
						else if (k == 2)
						{
							cin >> (Produse&)incal0;
							cin >> incal0;
							incal_magazin.push_back(incal0);
						}
						break;
					case 4://Elimin produse (bun)
						k = 0;
						while (k != 3)
						{
							cout << "Doriti sa eliminati haine sau incaltaminte? (introduceti numarul)" << endl;
							cout << "1. Haine" << endl;
							cout << "2. Incaltaminte" << endl;
							cout << "3. Inapoi la meniul principal" << endl;
							cin >> k;
							if (k == 1)
							{
								if (haine_magazin.size() != 0)
								{
									cout << endl << "Avem urmatoarele atribute pentru haine: " << endl;
									for (i = 0; i < haine_magazin.size(); i++)
									{
										cout << i + 1 << ". " << haine_magazin[i] << endl;
									}
									cout << endl << "Alegeti atributele ce doriti sa fie sterse: (introduceti numarul)" << endl;
									cin >> j;
									haine_magazin.erase(haine_magazin.begin() + (j - 1));
								}
								else
									cout << endl << "Nu avem atribute pentru haine introduse in sistem" << endl;
								
							}
							else if (k == 2)
							{
								if (incal_magazin.size() != 0)
								{
									cout << endl << "Avem urmatoarele atribute pentru incaltaminte: " << endl;
									for (i = 0; i < incal_magazin.size(); i++)
									{
										cout << i + 1 << ". " << incal_magazin[i] << endl;
									}
									cout << endl << "Alegeti atributele ce doriti sa fie sterse: (introduceti numarul)" << endl;
									cin >> j;
									incal_magazin.erase(incal_magazin.begin() + (j - 1));
								}
								else
									cout << endl << "Nu avem atribute pentru incaltaminte introduse in sistem" << endl;
							}
						}
						break;
					case 5://Schimb pretul unui produs (bun)
						k = 0;
						while (k != 3)
						{
							cout << "Doriti sa schimbati pretul pentru haine sau incaltaminte? (introduceti numarul)" << endl;
							cout << "1. Haine" << endl;
							cout << "2. Incaltaminte" << endl;
							cout << "3. Inapoi la meniul principal" << endl;
							cin >> k;
							if (k == 1)
							{
								if (haine_magazin.size() != 0)
								{
									cout << endl << "Avem urmatoarele atribute pentru haine: " << endl;
									for (i = 0; i < haine_magazin.size(); i++)
									{
										cout << i + 1 << ". " << haine_magazin[i] << endl;
									}
									cout << endl << "Alegeti carui produs doriti sa schimbati pretul: (introduceti numarul)" << endl;
									cin >> j;
									cout << endl << "Scrieti noul pret al produsului: " << endl;
									cin >> pret_nou;
									haine_magazin[j-1].setPret(pret_nou);
								}
								else
									cout << endl << "Nu avem atribute pentru haine introduse in sistem" << endl;
							}
							else if (k == 2)
							{
								if (incal_magazin.size() != 0)
								{
									cout << endl << "Avem urmatoarele atribute pentru incaltaminte: " << endl;
									for (i = 0; i < incal_magazin.size(); i++)
									{
										cout << i + 1 << ". " << incal_magazin[i] << endl;
									}
									cout << endl << "Alegeti carui produs doriti sa schimbati pretul: (introduceti numarul)" << endl;
									cin >> j;
									cout << endl << "Scrieti noul pret al produsului: " << endl;
									cin >> pret_nou;
									incal_magazin[j-1].setPret(pret_nou);
								}
								else
									cout << endl << "Nu avem atribute pentru incaltaminte introduse in sistem" << endl;
							}
						}
						break;
					case 6://Adaug perioada de reduceri (bun)
						cout << endl << "Introduceti inceputul perioadei de reducere (dd.mm.yyyy): ";
						cin >> s0;
						cout << endl << "Introduceti sfarsitul perioadei de reducere (dd.mm.yyyy): ";
						cin >> s1;
						perioada.first = s0;
						perioada.second = s1;
						reduceri.insert(perioada);
						break;
					case 7:// Sa vizionez perioadele de reduceri (bun)
						if (reduceri.size() == 0)
							cout << endl << "Nu avem perioade de reduceri" << endl;
						else
						{
							cout << reduceri.size() << endl;
							cout << "Perioadele de reduceri sunt: " << endl;
							for (auto it : reduceri)
								cout << it.first << "-" << it.second << endl;
						}
						break;
					case 8://Adaug perioada in care magazinul este inchis (bun)
						cout << endl << "Introduceti inceputul perioadei in magazinul este inchis (dd.mm.yyyy): ";
						cin >> s0;
						cout << endl << "Introduceti sfarsitul perioadei in magazinul este inchis (dd.mm.yyyy): ";
						cin >> s1;
						perioada.first = s0;
						perioada.second = s1;
					    inchis.insert(perioada);
						break;
					case 9://Sa vizionez perioadele cand este inchis magazinul (bun)
						if (inchis.size() == 0)
							cout << endl << "Nu avem perioade in care magazinul este inchis" << endl;
						else
						{
							cout << "Perioadele in care magazinul este inchis sunt: " << endl;
							for (auto it : inchis)
								cout << it.first << "-" << it.second << endl;
						}
						break;
					case 10://Adaug anunturi pentru angajare (bun)
						cout << endl << "Introduceti numele jobului pentru care cautati aplicanti: ";
						cin >> s0;
						cout << endl << "Introduceti numarul de locuri valabile pentru jobul respectiv: ";
						cin >> a;
						angajari.insert({ s0,a });
						break;
					case 11://Sa vizionez anunturile de angajare (bun)
						if (inchis.size() == 0)
							cout << endl << "Nu cautam aplicanti pentru niciun post" << endl;
						else
							for (auto it : angajari)
								cout << endl << "Cautam aplicanti pentru postul " << it.first << " si avem un numar de " << it.second << " locuri disponibile" << endl;
						break;
					case 12://Sa vizionez toate cosurile de cumparaturi de pana acum (bun)
						if (cosuri_magazin.size() == 0)
							cout << endl << "Nu s-a cumparat niciun cos pana acum" << endl;
						else
						{
							cout << endl << "Pana acum s-au cumparat urmatoarele cosuri: " << endl;
							nr_cos = 1;
							for (auto it : cosuri_magazin)
							{
								cout << nr_cos << ". " << it << endl;
								nr_cos++;
							}
						}
						break;
					case 13://Mi-am indeplinit task-urile, doresc sa ies din magazin (bun)
						task_admin = 13;
						break;		
				}
			}
		}
		else if (alegere == 2) //user
		{
			Cos cos = Cos();
			cout << "Ne bucuram ca ati ales magazinul nostru! Cum va numiti?" << endl;
			char* nume = new char[100]; //lol
			cin >> nume;
			cos.setNumeclient(nume);
			cout << "Ce ati dori sa faceti astazi, "<< nume <<"?" << endl;
			task_user = 0;
			while (task_user != 8 or task_user != 9)
			{	
				if (task_user == 8 or task_user == 9)
					break;
				hello.task_user();
				cin >> task_user;
				switch (task_user) {
				case 1: //Sa vizionez toate tipurile de haine (bun)
					h.welcome();
					cout << endl;
					h.afisareTipdehaine();
					cout << endl;
					h.afisareMarimi();
					cout << endl;
					h.afisareCulori();
					cout << endl;
					task_haine = 0;
					while (task_haine != 2)
					{
						h.alege_task();
						cin >> task_haine;
						if (task_haine == 1)  //aleg pt a cumpara
						{
							int tip, marime, culoare, produs;
							cout << endl << "Alegeti ce atribute doriti sa aiba produsul: " << endl;
							for (i = 0; i < haine_magazin.size(); i++)
							{
								cout << i + 1 << "." << endl;
								cout << haine_magazin[i] << endl;
							}
							cin >> produs;
							Haine h1;
							h1 = haine_magazin[produs - 1];
							cin >> h1;
							cout << endl << "Cate produse de acest tip doriti sa cumparati?" << endl;
							int prod;
							cin >> prod;
							h1.setAdaugate_cos(prod);
							cos.adauga_haina(h1);
						}
						else //meniu principal
							continue;
					}
					break;
				case 2: //Sa vizionez toate tipurile de incaltaminte (bun)
					incal.welcome();
					cout << endl;
					incal.afisareTipdeincalt();
					cout << endl;
					incal.afisareCuloriincalt();
					cout << endl;
					task_incal = 0;
					while (task_incal != 2)
					{
						incal.alege_task();
						cin >> task_incal;
						if (task_incal == 1)  //aleg pt a cumpara
						{
							int tip, marime, culoare, produs;
							cout << "Alegeti ce atribute doriti sa aiba produsul: ";
							for (i = 0; i < incal_magazin.size(); i++)
							{
								cout << i + 1 << "." << endl;
								cout << incal_magazin[i] << endl;
							}
							cin >> produs;
							Incaltaminte incal1;
							incal1 = incal_magazin[produs - 1];
							cin >> incal1;
							cout << "Cate produse de acest tip doriti sa cumparati?" << endl;
							int prod;
							cin >> prod;
							incal1.setAdaugate_cos(prod);
							cos.adauga_incal(incal1);
						}
						else //meniu principal
							continue;
					}
					break;
				case 3: // toate articolele din cos si pretul total (bun)
					cout << cos;
					break;
				case 4: //perioadele de reduceri (bun)
					if (reduceri.size() == 0)
						cout << endl << "Nu avem perioade de reduceri" << endl;
					else
					{
						cout << "Perioadele de reduceri sunt: " << endl;
						for (auto it : reduceri)
							cout << it.first << "-" << it.second << endl;
					}
					break;
				case 5: //Sa vizionez perioadele cand este inchis magazinul (bun)
					if (inchis.size() == 0)
						cout << endl << "Nu avem perioade in care magazinul este inchis" << endl;
					else
					{
						cout << "Perioadele in care magazinul este inchis sunt: " << endl;
						for (auto it : inchis)
							cout << it.first << "-" << it.second << endl;
					}
					break;
				case 6://Sa elimin articole din cos (bun)
					k = 0;
					while (k != 3)
					{
						cout << "Doriti sa eliminati haine sau incaltaminte? (introduceti numarul)" << endl;
						cout << "1. Haine" << endl;
						cout << "2. Incaltaminte" << endl;
						cout << "3. Inapoi la meniul principal" << endl;
						cin >> k;
						if (k == 1)
						{
							vect_haine = cos.getToate_hainele();
							if (vect_haine.size() == 0)
								cout << "Nu avem haine in cos" << endl;
							else
							{
								cout << "Ce produs doriti sa eliminati din cos? (introduceti numarul)" << endl;
								for (i = 0; i < vect_haine.size(); i++)
								{
									cout << i + 1 << ". " << vect_haine[i] << endl;
								}
								cin >> j;
								cos.elimina_haina(vect_haine[j - 1]);
							}
						}
						else if (k == 2)
						{
							vect_incal = cos.getToate_incal();
							if (vect_incal.size() == 0)
								cout << "Nu avem incaltaminte in cos" << endl;
							else
							{
								cout << "Ce produs doriti sa eliminati din cos? (introduceti numarul)" << endl;
								for (i = 0; i < vect_incal.size(); i++)
								{
									cout << i + 1 << ". " << vect_incal[i] << endl;
								}
								cin >> j;
								cos.elimina_incal(vect_incal[j - 1]);
								if (vect_incal.size() == 0)
									break;
							}
						}
					}
					break;
				case 7: //Sa vizionez anunturile de angajare (bun)
					if (inchis.size() == 0)
						cout << endl << "Nu cautam aplicanti pentru niciun post" << endl;
					else
						for (auto it : angajari)
							cout << endl << "Cautam aplicanti pentru postul " << it.first << " si avem un numar de " << it.second << " locuri disponibile" << endl;
					break;
				case 8://Sa cumpar articolele selectate, sa primesc bonul fiscal si sa parasesc magazinul (bun)
					if (cos.getToate_hainele().size() == 0 && cos.getToate_incal().size() == 0)
						cout << endl << "Cosul este gol!" << endl;
					else
					{
						cosuri_magazin.push_back(cos);
						out << "Bonul dvs. fiscal este:" << endl;
						out << cos << endl;
						auto start = chrono::system_clock::now();
						time_t end_time = chrono::system_clock::to_time_t(start);
						out << "Bonul eliberat la data: " << ctime(&end_time) << endl;
						task_user = 8;
						break;
					}
				case 9://Sa renunt la cosul de cumparaturi si sa ies din magazin(bun)
					task_user = 9;
					break;
				}
			}
		}
		else
			return 0;
	}
}
