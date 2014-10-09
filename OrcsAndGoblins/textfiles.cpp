//
//  textfiles.cpp
//
//  Created by Bob Polis on 19/09/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[])
{
    const string textfile("tekstbestand.txt");
    
    {
        // (1a) Tekst schrijven naar een file
        ofstream output_file(textfile);
        output_file << "10 0.38765 5 42\n"; // even wat getallen in tekst-vorm
        output_file << "Dit is een regel tekst.\nEn dit is er nog een.\n";
        // en zo kun je natuurlijk van alles en nog wat streamen :-)
        output_file << 42 << '\n'; // de int komt als tekst in de file (!)
    }
    
    {
        // (1b) Tekst toevoegen aan een bestaande file
        ofstream output_file(textfile, ios::app); // tweede param bepaalt de mode, in dit geval 'append'
        output_file << "Deze kwam er later bij!\n";
    }
    
    {
        // (2a) Tekst inlezen uit een file met de klasse std::ifstream (input file stream)
        ifstream input_file(textfile); // stack-based file object; deze constructie opent de file voor lezen
        string line;
        
        // getline() leest een regel die eindigt in een \n
        // (je kunt ook een 3e param meegeven als je een ander 'regeleinde' wil gebruiken)
        while (getline(input_file, line)) { // getline() geeft false zodra end-of-file is bereikt
            cout << line << '\n'; // getline() haalt de \n wel uit de stream, maar voegt die niet toe
        }
        // zodra input_file weer uit scope raakt (aan het eind van dit block) wordt de file automatisch gesloten
    }

    /*
     (2b) Tekst inlezen uit een file in losse brokjes met >>
     
     Je kunt een ifstream net als alle streams gebruiken met >> om losse dingen te lezen.
     Alle white space tussen stukjes tekst wordt automatisch overgeslagen.
     Je kunt dus bijvoorbeeld enkele getallen (in tekstvorm) in een bestand zetten, en
     die stuk voor stuk inlezen. De \n wordt ook gezien als white space, net als spatie en \t.
     
     Stel, je hebt een file met een paar getallen:
     10 0.38765 5 42
     
     Dan lees je die als volgt:
     */
    {
        // variabelen waarin de ingelezen waarden terecht komen
        int corner_radius;
        double wiggle_factor;
        double width;
        double height;
        
        // input file stream, opent textfile voor lezen
        ifstream input_file(textfile);
        
        // lees in de juiste volgorde de data in, die in voorbeeld 1a hierboven is weggeschreven
        input_file >> corner_radius >> wiggle_factor >> width >> height;
        
        // laat even zien wat we hebben gelezen
        cout << corner_radius << " " << wiggle_factor << " " << width << " " << height << endl;
    }

    return 0;
}
