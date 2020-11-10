#include <iostream>
#include "Konto.h"
#include <vector>
#include <string>
#include <fstream> //zum schreiben in die Datei

//###############################################################################################################
//Aufbau der Textdatei von b)
/*
=
Kontoname
Kontostand
=
Kontoname
Kontostand

*/
void toFile(std::string path, const std::vector<Konto>& Kontoverwaltung)
{
    std::ofstream myfile; //ofstream ist ein output file stream
    myfile.open(path);
    if (myfile.is_open()) //testet ob File geöffnet worden ist
    {
        for (auto c : Kontoverwaltung)
        {
            myfile << "*\n"; //nach jedem neuem Eintrag wird ein *  in die Textdatei eingefügt
            myfile << c.toString(); //Daten werden gespeichert
         }
            

        myfile.close();
    }
    else //wenn es nicht geöffnet werden kann wird error ausgegeben
        std::cerr << "Error opening file toFile" << std::endl;

}

std::vector<Konto>loadFile(std::string path)
{
    std::vector<Konto>Kontoverwaltung;

    std::ifstream myfile(path);
    if (myfile.is_open()) //testet ob File geöffnet worden ist
    {
        int count = 0;
        std::string cline = "";

        Konto temp{}; // Konto wird auserhalb der Loop erstell das spart Zeit
        while (std::getline(myfile, cline))
        {
            if (cline == "*") //nach jedem * wird count auf 0 gesetzt und beginnt mit neuem Konto
            {
                count = 0;
                count++;
                
                continue;
            }
            if (count == 1)
            {
                temp.Kontoeroeffnung(cline, 0); //count == 1 ist die erte Zeile wo Kontoname reingeschrieben wird
            }
            if (count == 2)
            {
                temp.Einzahlen(std::stof(cline));//2te Zeile mit dem Kontobetrag //stof = string to float
                Kontoverwaltung.push_back(temp);
            }
            count++;
        }
        myfile.close();
    }
    else
        std::cerr << "Error opening file in loadFile ";

    return Kontoverwaltung;
}
//###############################################################################################################



int main()
{
//Aufgabe a) Test:
#pragma region a
        std::cout << "Test Aufgabe c):" << std::endl;

        Konto k1{}; //Konto k1 wird initialisiert
        std::cout << k1.Kontoeroeffnung("Petra", -10) << std::endl; //es wird -1 zurückgegeben weil Konto mit negativen Betrag eröffnet wird
        k1.Kontoeroeffnung("Max ", 100);
        std::cout << k1.Abheben(50) << std::endl;//hier wird 0 zurückgegeben weil betrag pos ist
        std::cout << k1.Abheben(-20) << std::endl;//hier wird -1 zurückgegeben weil ein negativer Betrag eingegeben wurden 
        k1.Einzahlen(10);
        k1.Einzahlen(10);
        std::cout << k1.Einzahlen(10) << std::endl; //hier kommt 0 raus weil pos. Eingabe
        std::cout << k1.Einzahlen(-1000) << std::endl;//hier kommt -1 raus weil negative Eingabe (flasche eingabe)

        std::cout << std::endl;
        std::cout << std::endl;

#pragma endregion 
   
    
 //Aufgabe b) Test:
#pragma region b
    std::cout << "Test Aufgabe b):" << std::endl;

    std::vector<Konto>Kontoverwaltung = loadFile("Kontoverwaltung.txt");

    Kontoverwaltung.push_back(k1);

    for (int i = 0; i < 3; i++)
    {
        Konto temp{}; //neues Zwischenkonto wird erstellt
        temp.Kontoeroeffnung(std::to_string(i), 100);//i wird in einen string umgewandet (ist unser Name)
        temp.Einzahlen(10);
        temp.Einzahlen(10);
        temp.Abheben(25);

        Kontoverwaltung.push_back(temp);
    }
     
    toFile("Kontoverwaltung.txt",Kontoverwaltung);

    std::cout << std::endl;
    std::cout << std::endl;
#pragma endregion 

//Aufgabe c) Test:
#pragma region c
    std::cout << "Test Aufgabe c):"<< std::endl;

    for (int i = 0; i < 25; i++)
    {
        k1.Einzahlen(15);
    }
    k1.Abheben(100);
    k1.Abheben(100);

    std::cout  <<std::endl;
    k1.Kontoauszug();//Hier wird der Kontoauszug angezeigt
#pragma endregion 

    return 0;
}

