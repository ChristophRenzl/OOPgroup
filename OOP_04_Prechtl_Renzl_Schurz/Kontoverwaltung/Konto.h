#pragma once
#include <iostream>
#include <string>
#include<vector>



class Konto{

	bool Kontoasstatus = true; //flag ob Konto geschlossen oder nicht
	int ID{ 1000};
	std::string Name{ "Unbekannt" };
	float Kontostand{ 0 };
	std::vector<float>history; //für Historie aller Transaktionen für Aufgabe c)
	std::vector<std::string>history_zeit;
	std::vector<std::string>history_text;

public:

//Aufgabe a) Constructor
	Konto(const std::string& n, float betrag, int id)
		: Name{ n }, Kontostand{ betrag }, ID{id}
	{
	}

//Aufgabe b) CopieConstructor:
	Konto(const Konto& p2) { ID = p2.ID + 1; Name = p2.Name; Kontostand = 0; }


	int Kontoeroeffnung()
	{
		if (this->Kontostand < 0)
			return -1; // bei negativem Betrag 

		this->history = std::vector<float>{}; //neue Liste für die History, damit jedes Element der Kontoverwaltung die wir geladen haben nur einen Wert hat

		if (this->Kontostand > 0) //wenn Konto bei Eröffnung > 0 ist wird der neue Stand ausgegeben, wenn nicht wird nichts ausgegeben 
		{
			this->history.push_back(this->Kontostand);//pusht den Kontostand in den History Vector
			std::cout << "Einzahlung auf " << this->Name << "mit Wert: " << this->Kontostand << std::endl;

		}
	}

//Afgabe f) Dekonstruktor:
	~Konto()
	{
		std::cerr << "Konto " << this->Name << " mit ID " << this->ID << "  wurde beendet" << std::endl;
	}

	
	int Einzahlen(float Betrag, std::string text =  "Keine Angabe");
	int Abheben(float Betrag, std::string text = "Keine Angabe");
	std::string toString() //Funktion zum Speichern der Daten
	{
		return this->Name + "\n" + std::to_string(this->Kontostand) + "\n";
	}
	void Kontoauszug();
	
	//Aufgabe c)
	void Kontoschliessung();
	//Aufgabe d)
	std::string gettimestamp();


};

//Aufgabe e)
void Transaktion(Konto& ueberweiser, Konto& empfeanger, float betrag);