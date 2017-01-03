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
    tuple<bool, int> checkResult = checkString("())6+23)-1=(5*(x+1)-2)=3()())", '(', ')');
    get<0>(checkResult) ? cout << "DA\n\n" : cout << "NU\nIndex Problema: " << get<1>(checkResult) << "\n\n";
    return 0;
}
