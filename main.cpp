#ifndef _MAIN
#define _MAIN
#include "funciones.hpp"
#include "tokens.hpp"
#include "coll.hpp"
#include "files.hpp"
#include "Array.hpp"
#include "TADarray.hpp"
#include "TADMap.hpp"
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;
using std::stoi;
int main() {
    
    Array<int> a = arr<int>();
    
    arrayAdd(a, 3);
    arrayAdd(a, 4);
    arrayAdd(a, 5);
    arrayAdd(a, 6);
    
    for (int i = 0; i<a.len; i++) {
        cout<<arrayGet(a, i)<<endl;
    }
    
    
    return 0;
}
#endif
