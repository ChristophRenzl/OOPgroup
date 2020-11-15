#include "Konto.h"
#include<ctime> 
#include <iostream>
#include <time.h>
#include <string>
#pragma warning(disable : 4996)

//Aufgabe c)
void  Konto::Kontoschliessung()
{
	this->Kontoasstatus = false;
	this->Kontostand = 0;
}

//Aufgabe d)
std::string Konto::gettimestamp()
{
	time_t rawtim;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtim);
	timeinfo = localtime(&rawtim);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);
	//return str;
	return std::string(str);
}

//Aufgabe e)
void Transaktion (Konto& ueberweiser, Konto& empfeanger, float betrag)
{
	std::cout << "Transaktionsgrund eingeben: ";
	std::string text;
	getline(std::cin, text);

	std::cout << std::endl <<text<<std::endl;
	ueberweiser.Abheben(betrag, text);
	empfeanger.Einzahlen(betrag,text);

	std::cout << "Transaktion erfolgreich!!!" << std::endl;

}



int Konto::Einzahlen(float betrag, std::string text)
{
	if (Kontoasstatus == false)
	{
		std::cout << "Konto "<< this->ID<<" wurde geschlossen" << std::endl;
		return -2;
	}

	if (betrag < 0)
		return -1; //bei negativem Betrag
	
	this->Kontostand += betrag;
	this->history.push_back(betrag);//push Einzahlung in history Vector
	this->history_zeit.push_back(gettimestamp());
	this->history_text.push_back(text);
	std::cout << "Einzahlung auf " << this->Name << "  mit Wert: " << betrag << std::endl;

	return 0;
}


int Konto::Abheben(float betrag, std::string text )
{
	if (Kontoasstatus == false)
	{
		std::cout << "Konto " << this->ID << " wurde geschlossen" << std::endl;
		return -2;
	}
	if (betrag < 0)
		return -1; //bei negativem Betrag

	if (this->Kontostand - betrag < 0)
		return -2; //Zuwenig Geld am Konto
	
	this->Kontostand -= betrag;
	this->history.push_back(-betrag);//push Auszahlung in history Vector
	this->history_zeit.push_back(gettimestamp());
	this->history_text.push_back(text);
	std::cout << "Abheben von " << this->Name << " mit Wert: " << betrag << std::endl;

	return 0;
}

void Konto::Kontoauszug()
{
	if (Kontoasstatus == false)
	{
		std::cout << "Konto " << this->ID << " wurde geschlossen" << std::endl;
	}
	else {
		std::cout << "############################################################"
			<< std::endl << "Kontoauszug von Konto " << ID << std::endl
			<< "############################################################" << std::endl;

		float sum = 0;

		for (int i = 0; i < this->history.size(); i++) //For Loop für die 10 Transaktionen
		{
			sum += this->history[i];
			std::cout << this->history[i] <<"$"<<"\t" <<this->history_zeit[i]<<"\t" << this->history_text[i]<< std::endl;

			if ((i + 1) % 10 == 0) //(i+1) weil wir bei 0 starten
			{
				std::cout << "Summe aller Transaktionen: " << sum << std::endl; //nach 10 Transaktionen wird eine sum angezeigt
				std::cout << "[NEWPAGE]" << std::endl; //nach 10 Transaktionen wird eine neue Site gemacht
			}
		}
		std::cout << "Kontostand: " << Kontostand << std::endl;//Damit auch die letzte Summe angezeigt wird
		std::cout << "############################################################"
			<< std::endl << "[END] " << std::endl
			<< "############################################################" << std::endl;
		}
}
