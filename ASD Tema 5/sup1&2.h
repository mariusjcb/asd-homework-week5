//
//  sup1&2.h
//  ASD Tema 5
//
//  Created by Marius Ilie on 03/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#ifndef sup1_2_h
#define sup1_2_h

#include <tuple>

tuple<bool, int> checkString(char sir[], char start, char end) {
    bool ok = true;
    int poz = -1, i;
    
    function<void (string)> okToFalse = [&ok, &i, &poz] (string mesaj) -> void {
        ok = false;
        poz = i;
    };
    
    Stack<int> stiva = *new Stack<int>();
    for(i = 0; i<=strlen(sir) && ok; i++) {
        if(sir[i] == start)
            stiva.push(start);
        else if(sir[i] == end) {
            stiva.pop(okToFalse);
        }
    }
    
    if(!stiva.empty())
        ok = false;
    
    return tuple<bool, int> { ok, poz };
}

#endif /* sup1_2_h */
