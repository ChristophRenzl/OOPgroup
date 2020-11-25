#include <iostream>
#include <vector>
#include <array>
#include "OOP10_Aufgabe5_Schurz_Prechtl_Renzl.h"

//Aufgabe c):
void Buffer::fillBuffer()
{
    int size = this->Size;
    int anzahl = 0;
    std::cout << "Bitte geben Sie die Anzahl der gewuenschte Anzahl der Byts an: ";
    std::cin >> anzahl;
    
    for (int i = 0; i < anzahl; i++)
    {     
        this->Daten.push_back(i+48);//+48 wegen ASSCI Table
    }
}

//Aufgabe d):
std::vector<char> Buffer::copyBuffer(int von, int bis)
{
    std::vector<char>::const_iterator it1 = Daten.begin() + von; //iterator auf einen vector, wir zeigen auf das erste elemen + von
    std::vector<char>::const_iterator it2 = Daten.begin() + (bis + 1);
    std::vector<char>NewBuffer(it1, it2);//neuer Vektor mit Inhalt vom alten Vektor mit von bis Begrenzung

    return NewBuffer;
}

//Aufgabe e):
void useBuffer(Buffer v)
{
    v.getID();
    v.getData();
}

//Aufgabe e):
Buffer createBuffer()
{
    Buffer b;
    b.fillBuffer();

    return b;
}

//Aufgabe i): nicht ganz gelöst!!!!
void array_vector()
{
    std::vector<Buffer>B;
    for (int i = 0; i < 10; i++)
    {
        B.push_back(createBuffer());
    }
    //std::array<Buffer, 10>B2;
    //for (int i = 0; i < 10; i++)
    //{
    //    B2.fill(createBuffer());
    //}
}



int main()
{
//Aufgabe a) test:
    std::cout << "Aufgabe a) Test:" << std::endl;
    
    Buffer b1 = { 2, '0'};

    std::cout << std::endl << std::endl << "Ende" << std::endl<< std::endl;
//########################################################################    

//Aufgabe b) test:
    std::cout << "Aufgabe b) Test:" << std::endl;

    std::cout << b1.getID()  << std::endl;
    b1.getData();
    b1.setData('1'); 
    b1.getData();

    std::cout << std::endl  << "Ende" << std::endl << std::endl;
//########################################################################

//Aufgabe c)  test:
    std::cout << "Aufgabe c) Test:" << std::endl;

    b1.fillBuffer();
    b1.getData();

    std::cout << std::endl << "Ende" << std::endl << std::endl;

//########################################################################

//Aufgabe d) test:
    std::cout << "Aufgabe d) Test:" << std::endl;
    
    std::vector<char>copyB = b1.copyBuffer(2,5);
    for (auto it = copyB.begin(); it < copyB.end(); it++)
    {
        std::cout << *it << "\t";
    }

    std::cout << std::endl << "Ende" << std::endl << std::endl;

//########################################################################

//Aufgabe e): test 
    std::cout << "Aufgabe e) Test:" << std::endl;

    std::cout << "Funktion useBuffer: " << std::endl;
    useBuffer(b1);

    std::cout << "Funktion createBuffer: " << std::endl;
    Buffer b2 = createBuffer();

    std::cout << std::endl << "Ende" << std::endl << std::endl;
//########################################################################

//Aufgabe g): tets 
    std::cout << "Aufgabe g) Test:" << std::endl;

    std::cout << "Buffer wird kopiert: " << std::endl;
    Buffer b3 = b1;
    b3.getData();

    std::cout << std::endl << "Ende" << std::endl << std::endl;
//########################################################################

//Aufgabe h):
    std::cout << "Aufgabe g) Test:" << std::endl;

    
    std::cout << "Buffer wird gemoved: " << std::endl;
    Buffer b4(std::move(b3));
    b4.getData();
    b3.getData();//b3 ist jz leer

    std::cout << std::endl << "Ende" << std::endl << std::endl;



}

