#ifndef TADMap_hpp
#define TADMap_hpp
using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "funciones.hpp"
#include "tokens.hpp"
#include "Array.hpp"
#include "TADarray.hpp"
#include <stdio.h>

template <typename K, typename V>
struct Map
{
    Array<K> key;
    Array<V> value;
};


template <typename K, typename V>
Map<K,V> map(){
    Map<K,V> ret;
    ret.key<K> arr();
    ret.value<V> arr();
    return ret;
}



#endif /* TADMap_hpp */
