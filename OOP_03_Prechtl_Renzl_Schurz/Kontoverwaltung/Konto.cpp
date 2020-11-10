#include "Konto.h"

//Aufgabe b):
int Konto::Einzahlen(float betrag)
{
	if (betrag < 0)
		return -1; //bei negativem Betrag
	
	this->Kontostand += betrag;
	this->history.push_back(betrag);//push Einzahlung in history Vector
	std::cout << "Einzahlung auf " << this->Name << "  mit Wert: " << betrag << std::endl;

	return 0;
}


int Konto::Abheben(float betrag)
{
	if (betrag < 0)
		return -1; //bei negativem Betrag

	if (this->Kontostand - betrag < 0)
		return -2; //Zuwenig Geld am Konto
	
	this->Kontostand -= betrag;
	this->history.push_back(-betrag);//push Auszahlung in history Vector
	std::cout << "Abheben von " << this->Name << " mit Wert: " << betrag << std::endl;

	return 0;
}
//##################################################################################################

//Aufgabe c):
void Konto::Kontoauszug()
{
	std::cout << "############################################################"
		<< std::endl << "Kontoauszug: " << std::endl
		<< "############################################################"<<std::endl;

	float sum = 0;
	for (int i = 0; i < this->history.size(); i++) //For Loop für die 10 Transaktionen
	{
		sum += this->history[i];
		std::cout << this->history[i] << std::endl;

		if ((i+1) % 10 == 0) //(i+1) weil wir bei 0 starten
		{
			std::cout <<"Summe: "<< sum << std::endl; //nach 10 Transaktionen wird eine sum angezeigt
			std::cout << "[NEWPAGE]" << std::endl; //nach 10 Transaktionen wird eine neue Site gemacht
		}
	}
	std::cout << "Summe: " << sum << std::endl;//Damit auch die letzte Summe angezeigt wird
	std::cout << "############################################################"
		<< std::endl << "[END] " << std::endl
		<< "############################################################" << std::endl;

}
