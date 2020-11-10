#pragma once
#include <iostream>
#include <string>
#include<vector>

class Konto{

//Aufgabe a):

	std::string Name;
	float Kontostand;
	std::vector<float>history; //für Historie aller Transaktionen für Aufgabe c)

public:
	int Kontoeroeffnung(std::string _Name, float _Kontostand)
	{
		if (_Kontostand < 0)
			return -1; // bei negativem Betrag 

		this->Name = _Name; //this Zeigt auf Objekt Konto //inline Funktion weil es ziemlich kurz ist
		this->Kontostand = _Kontostand;
		this->history = std::vector<float>{}; //neue Liste für die History, damit jedes Element der Kontoverwaltung die wir geladen haben nur einen Wert hat

		if (_Kontostand > 0) //wenn Konto bei Eröffnung > 0 ist wird der neue Stand ausgegeben, wenn nicht wird nichts ausgegeben 
		{
			this->history.push_back(_Kontostand);//pusht den Kontostand in den History Vector
			std::cout << "Einzahlung auf " << this->Name << "mit Wert: " << this->Kontostand << std::endl;

		}
	}

	int Einzahlen(float Betrag);
	int Abheben(float Betrag);


//Aufgabe b):

	std::string toString() //Funktion zum Speichern der Daten
	{
		return this->Name + "\n" + std::to_string(this->Kontostand) + "\n";
	}

//Aufgabe c):

	void Kontoauszug();


};

