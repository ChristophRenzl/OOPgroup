#include <iostream>
#include <vector>

//Aufgabe j):
static unsigned int zeahler = 1000;
static unsigned int next()
{
	return zeahler++;
}


class Buffer
{
private:
	unsigned int ID = { next() };
	std::vector<char>Daten;
	int Size = { 1 };

public:

//  Aufgabe a) Constructor:
	Buffer() = default;

	Buffer( int size, char byte)
		:ID{ next() }
	{
		Size = size;
		std::vector<char> Daten(Size);// = new std::vector<char>(Size);
		Daten.push_back(byte);
	}
	Buffer(char byte)
		:ID{ next() }
	{
		std::vector<char> Daten(Size);// = new std::vector<char>(Size);
		Daten.push_back(byte);
	}
	
//Destructor:
	~Buffer()
	{
		std::cerr << "Buffer destructor {" << ID  << "} aufgerufen" << std::endl;
		//delete Daten;
	}

//MoveConstructor
	Buffer(Buffer&& other) noexcept
	{
		printf("Moved\n");
		ID = other.ID;
		Daten = other.Daten; //es wird einfach nur der Wert gemoved

		//die Werte müssen auf NULL gesetzt werden:
		other.ID = 0;
		other.Daten.erase(other.Daten.begin(), other.Daten.end()); //damit der Pointer auch nicht mehr auf eine adresse zeigt
	}

//CopyConstructor
	Buffer(const Buffer& p2) { ID = next(); Daten = p2.Daten; Size = p2.Size; }

	
//Aufgabe b)
	unsigned int getID() const {return ID;}
	void getData()
	{ 
		if (Daten.empty())
			std::cerr << "Keine Daten" << std::endl;

		

		for (auto it = begin(Daten); it < end(Daten); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	void setData(char value) { Daten.push_back(value); }


//Aufgabe c):
	void fillBuffer();

//Aufgabe d):
	std::vector<char> copyBuffer(int von, int bis);


}; 

void useBuffer(Buffer v);