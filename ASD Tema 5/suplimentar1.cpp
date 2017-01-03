//
//  main.cpp
//  ASD Tema 5
//
//  Created by Marius Ilie on 02/01/17.
//  Copyright © 2017 University of Bucharest - Marius Ilie. All rights reserved.
//

#include "Queue.h"
#include "sup1&2.h"

int main(int argc, const char * argv[]) {
    tuple<bool, int> checkResult = checkString("abababababab", 'a', 'b');
    get<0>(checkResult) ? cout << "DA\n\n" : cout << "NU\n\n";
    return 0;
}
