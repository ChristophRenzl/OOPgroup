#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <tuple>
#include <list>
#include <sstream>


std::tuple<std::string, std::string, std::string, std::string> make_Person(std::string Name, std::string Telefon, std::string Strasse, std::string Ort)
{
    return std::make_tuple(Name, Telefon, Strasse, Ort);
}


int main()
{
    //Addressbook

    // Name           Telefon           Straﬂe          Ort     <-mit "," getrennt
    std::vector<std::string> data;
    data.reserve(1001);
    std::string filename = "personen.csv";

    std::ifstream input(filename);

    if (!input)
    {
        std::cerr << "Datei beim Oeffnen der Datei " << filename << "\n";
        return 1;
    }

    std::string line;

    while (std::getline(input, line))
    {
        data.push_back(line);
    }

    std::vector<std::string> datasep;
    datasep.reserve(4004);

    auto seperate = [&datasep](std::string string)->void {
        char delimiter = ',';
        size_t pos = 0;
        std::string token;
        std::stringstream ss(string);
        
        while (std::getline (ss, token, delimiter))
        {
            datasep.push_back(token);
        }
    };

    std::for_each(data.begin(), data.end(), seperate);

    std::list <std::tuple<std::string, std::string, std::string, std::string>> list_Person;

    

    auto makeList = [&datasep, &list_Person]()->void {

        int i = 5;
        std::string Name, Telefon, Strasse, Ort;

        for (auto it = datasep.begin()+4; it != datasep.end(); it++)
        {
            unsigned long long int telephone;
           
            

            if (i % 4 == 1)
            {
                Name = *it;
            }
            else  if (i % 4 == 2)
            {
                Telefon = *it;
            }
            else  if (i % 4 == 3)
            {
                Strasse = *it;
            }
            else  if (i % 4 == 0)
            {
                Ort = *it;
            }



            if (i % 4 == 0 && i != 0)
            {
                auto t = make_Person(Name, Telefon, Strasse, Ort);
                list_Person.push_back(t);
            }
            i++;
        }

    };

    makeList();

    auto print = [](auto t) {
        std::cout<<std::get<0>(t)<<"\t"<<"\t";
        std::cout << std::get<1>(t)<<"\t";
        std::cout << std::get<2>(t)<<"\t";
        std::cout << std::get<3>(t)<<std::endl;
    };

    std::cout << "Size:" << datasep.size() << std::endl;
    std::cout << "Size:" << list_Person.size() << std::endl;

    //std::for_each(list_Person.begin(), list_Person.end(), print);
}