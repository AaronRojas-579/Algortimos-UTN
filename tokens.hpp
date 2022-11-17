#ifndef tokens_hpp
#define tokens_hpp
using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>
#include "funciones.hpp"
int tokenCount(string s,char sep){
    int cont = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == sep) {
            cont ++;
        }
    }
    return cont;
}
void addToken (string& s, char sep, string t){
    s = isEmpty(s)?t:s+sep+t;
}
string getTokenAt(string s, char sep,int i){
    string res;
    int posInicial = indexOfN(s, sep, i);
    int posFinal = indexOfN(s,sep,i+1);
    if (i == 0) {
        res = substring(s, posInicial , posFinal);
    }else if (i != 0 && posFinal == posInicial){
        res = substring(s, posInicial + 1);
    }
    else{
        res = substring(s, posInicial + 1, posFinal);
    }
    return res;
}
void removeTokenAt(string& s, char sep, int i){
    string nuevoToken = "";
    string tokenRemove = getTokenAt(s,sep,i);
    for (int a = 0; a < tokenCount(s, sep); a++) {
        if (getTokenAt(s,sep,a) != tokenRemove) {
            if (tokenCount(s,sep)-1 == a) {
                nuevoToken += getTokenAt(s, sep,a);
                break;
            }
            nuevoToken += getTokenAt(s,sep,a) + sep;
        }
    }
    if (s[length(nuevoToken) - 1] == sep) {
        nuevoToken = substring(s, 0, length(nuevoToken)-1);
    }
    s = nuevoToken;
}
void setTokenAt (string& s, char sep, string t, int i){
    string nuevoToken = "";
    string tokenRemove = getTokenAt(s,sep,i);
    for (int a = 0; a < tokenCount(s, sep); a++) {
        if (getTokenAt(s,sep,a) != tokenRemove) {
            if (tokenCount(s,sep)-1 == a) {
                nuevoToken += getTokenAt(s, sep,a);
                break;
            }
            nuevoToken += getTokenAt(s,sep,a) + sep;
        }if (getTokenAt(s, sep, a) == tokenRemove){
            nuevoToken += t + sep;
        }
    }
    s = nuevoToken;
    if (nuevoToken[length(nuevoToken)-1] == sep) {
        s = substring(s, 0, length(nuevoToken)-1);
    }
}
int findToken(string s, char sep, string t){
    int res = 0;
    for (int i = 0; i < tokenCount(s, sep); i++) {
        if (getTokenAt(s, sep, i) == t) {
            res = i;
        }
    }
    return res;
}
#endif /* tokens_hpp */
