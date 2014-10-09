//
//  randomnumbers.cpp
//
//  Created by Bob Polis on 19/09/14.
//  Copyright (c) 2014 Avans Hogeschool, 's-Hertogenbosch. All rights reserved.
//

#include <iostream>
#include <random>
using namespace std;

int main(int argc, const char * argv[])
{
    /*
     De standard library heeft uitgebreide mogelijkheden voor random getallen.
     Je kunt kiezen uit allerlei verschillende soorten random generatoren,
     elk met hun specifieke mogelijkheden en eigenschappen.
     
     Gelukkig is er ook een default versie, die doet wat je meestal wil:
     random ints die uniform verdeeld zijn tussen twee door jou gegeven grenzen.
     */
    
    default_random_engine dre;
    uniform_int_distribution<int> dist(1, 6);
    
    for (int i = 0; i < 20; ++i) {
        cout << dist(dre) << " ";
    }
    cout << endl;
    
    // voor meer informatie: http://en.cppreference.com/w/cpp/numeric/random
    
    return 0;
}
