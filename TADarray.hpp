#ifndef TADarray_hpp
#define TADarray_hpp
using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "funciones.hpp"
#include "tokens.hpp"
#include "Array.hpp"
#include <stdio.h>

template <typename T>
struct Array{
    T* arr;
    int len;
    int cap;
};

template <typename T>
Array<T> arr(){
    Array<T> ret;
    ret.cap = 2;
    ret.arr = new T[ret.cap];
    return ret;
}
template <typename T>
int arrayAdd(Array<T>& a,T t){
    if (a.len == a.cap) {
        a.cap = a.cap*2;
        T* b = new T[a.cap];
        for (int i = 0; i<a.len; i++) {
            b[i] = a.arr[i];
        }
        b[a.len]=t;
        delete a.arr;
        a.arr = b;
    }else{
        a.arr[a.len]=t;
    }
    a.len++;
    return a.len-1;
}
template <typename T>
T* arrayGet(Array<T> a,int pos){
    T* ret = &a.arr[pos];
    return ret;
}
template <typename T>
void arraySet(Array<T>& a, int p, T t){
    T* b = arrayGet(a, p);
    *b = t;
}
template <typename T>
void arrayInsert(Array<T>& a,T t, int p){
    if(a.len + 1 == a.cap){
        T arrAnterior = a.arr[p];
        a.arr[p]=t;
        for (int i = 0 ; i < a.len; i++) {
            T arrActual = a.arr[i];
            a.arr[i]=arrAnterior;
            arrAnterior=arrActual;
        }
        arrayAdd<T>(a, arrAnterior);
    }else{
        insert<T>(a.arr,a.len,t,p);
    }
}
template <typename T>
int arraySize(Array<T> a){
    return a.len;
}
template <typename T>
T arrayRemove(Array<T>& a,int p){
    return remove<T>(a.arr,a.len,p);
}
template <typename T>
void arrayRemoveAll(Array<T>& a){
    for (int i = a.len; i > 0; i--) {
        arrayRemove(a, 0);
    }
}
template <typename T,typename K>
int arrayFind(Array<T> a, K k, int cmpTK(T,K)){
    return find<T,K>(a.arr,a.len,k,cmpTK);
}
template <typename T>
int arrayOrderedInsert(Array<T>& a, T t, int cmpTT(T,T)){
    int count = 0;
    while (cmpTT(a.arr[count],t)<0 && count < a.len) {
        count++;
    }
    arrayInsert(a, t, count);
    return count;
}
template <typename T>
void arraySort(Array<T>& a, int cmpTT(T,T)){
    sort<T>(a.arr,a.len,cmpTT); 
}
#endif /* TADarray_hpp */
