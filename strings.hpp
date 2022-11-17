
#ifndef strings_h
#define strings_h
using namespace std;
#include <iostream>
#include <math.h>
#include <stdio.h>

int sumar (int a, int b){
    return (a+b);
}
int length (string s){
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}
int charCount(string s, char c){
    int i = 0;
    for (int j=0;s[j] != '\0'; j++) {
        if (s[j] == c) {
            i++;
        }
    }
    return i;
}
string substring (string s, int d,int h){
    string a ="";
    for (int i = 0; s[i] != '\0'; i++) {
        if (i >= d && i < h) {
            a= a + s[i];
        }
    }
    return a;
}
string substring(string s, int d){
    string a ="";
    for (int i = 0; s[i] != '\0'; i++) {
        if (i >= d){
            a = a + s[i];
        }
    }
    return a;
}
int indexOf(string s, char c){
    int a = 0;
    int veces = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] == c && veces == 0){
            a = i;
            veces ++;
        }
    }
    if (veces == 0) {
        a = -1;
    }
        return a;
}
int indexOf(string s, char c, int offset){
    int a = 0;
    int veces = 0;
    for (int i = offset; s[i] != '\0'; i++) {
        if (s[i] == c && veces == 0) {
            a = i;
            veces++;
        }
    }
    if (veces == 0) {
        a = -1;
    }
    return a;
}
int indexOf(string s, string toSearch){
    char a = toSearch[0];
    int veces = 0;
    int resultado = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == a && veces == 0) {
            resultado = i;
            veces++;
        }
    }
    if (veces == 0) {
        resultado = -1;
    }
    return resultado;
}
int indexOf (string s, string toSearch, int offset){
    int a = offset;
    char c = toSearch[0];
    while (s[a] != c) {
        a++;
    }
    return a;
}
int lastindexOf(string s, char c){
    int resultado = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            resultado = i;
        }
    }
    return resultado;
}
int indexOfN(string s, char c, int n){
    int resultado = 0;
    int veces = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c && veces != n) {
            resultado = i;
            veces ++;
        }
    }
    return resultado;
}
int charToInt(char c)
{
    int ret;
    if(c>='0' && c<='9'){
        ret = c-48;
    }else{
        if(c>= 'A' && c<= 'Z')
        {
            ret = c-65+10;
        }else
        {
            ret = c - 'a'+10;
        }
    }
   return ret;
}
char intToChar (int i){
    char c;
    if (i >= 0 && i <= 9) {
        c = i + 48;
    }else if (i >= 10 && i <= 35){
        c = i + 65 - 10;
    }else{
        c = i + 97 - 35;
    }
    return c;
}
int getDigit(int n, int i){
    i = i - 1;
    int aux = n;
    int k = 0;
    while (aux > 0 && k <= i) {
        aux = aux/10;
        k ++;
    }
    aux = aux % 10;
    n = aux;
    return n;
}
int digitCount (int n){
    int a = n;
    int rest = 0;
    while (a != 0) {
        rest++;
        a = a/10;
    }
    return rest;
}
string stringInvert(string i){
    string res = "";
    char g = ' ';
    for (int j = length(i) - 1; j >= 0; j--) {
        g = i[j];
        res = res + g;
    }
    return res;
}
string intToString (int i){
    string res = "";
    char g = ' ';
    int k;
    for (int j = digitCount(i) - 1; j >= 0; j--) {
        k = getDigit(i,j);
        g = intToChar(k);
        res = res + g;
    }
    return res;
}
int stringToInt(string s, int b)
{
    int res = 0;
    int exp = length(s) - 1;
    for (int i = 0; s[i] != '\0'; i++) {
        res = res + (charToInt(s[i]) * pow(b,exp));
        exp --;
    }
    return res;
}
int stringToInt(string s){
    int res = 0;
    int exp = length(s) - 1;
    for (int i = 0; s[i] != '\0'; i++) {
        res = res + (charToInt(s[i]) * pow(10,exp));
        exp --;
    }
    return res;
}
string charToString (char c){
    string s = "";
    s = s + c;
    return s;
}
char stringToChar (string s){
    char a = s[0];
    return a;
}
string stringToString (string s){
    return s;
}
string doubleToString (double d){
    string s;
    int entero = d;
    int dec = (d - entero) * 1000000;
    s = intToString(entero) + "." + intToString(dec);
    return s;
}
double stringToDouble (string s){
    int i = 0;
    int a = 0;
    string entero;
    string decimal;
    double res;
    for (int j = 0; s[j] != '.'; j++) {
        entero = entero + s[j];
        i++;
    }
    res = stringToInt(entero);
    while (s[i] != '\0') {
        i++;
        a++;
        decimal = decimal + s[i];
    }
    a--;
    res = res + (stringToInt(decimal) / pow(10, a));
    return res;
}
bool isEmpty (string s){
    if (length(s) == 0) {
        return true;
    }else{
        return false;
    }
}
bool startsWith(string s, string x){
    int s1 = length(x) - 1, i = 0;
    while (s[i] == x[i]) {
        if (s[i] == x[s1]) {
            return true;
        }
        i++;
    }
    return false;
}
bool endsWith(string s, string x){
    int i = 0, a = 0, b = length(x) - 1, c = length(s) - 1;
    while (s[i] != '\0') {
        while (s[i] == x[a]) {
            if (s[i] == x[a] and s[c] == x[b]) {
                return true;
                break;
            }
            i++;
            a++;
        }
        i++;
    }
    return false;
}

bool contains (string s, char c){
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

string replace (string s, char oldChar, char newChar){
    string res = "";
    for (int i = 0 ; s[i] != '\0'; i++) {
        if (s[i] == oldChar) {
            res = res + newChar;
        }else{
            res = res + s[i];
        }
    }
    return res;
}

string insertAt(string s, int pos, char c){
    string res = "";
    for (int i = 0; s[i] != '\0'; i++) {
        res += s[i] ;
        if (i == pos) {
            res += c;
        }
    }
    return res;
}

string Itrim(string s){
    int i = 0;
    string res = "";
    if (s[i] == ' ') {
        while (s[i] == ' ') {
            i++;
        }
        while (s[i] != '\0') {
            res += s[i];
            i++;
        }
    }
    else{
        res = s;
    }
    
    return res;
}

string rtrim (string s){
    string res = "";
    int len = length(s) - 1;
    int i = len;
    if (s[len] == ' ') {
        while (s[i] == ' ') {
            i--;
        }
        while (s[i] != '\0') {
            res = s[i] + res;
            i--;
        }
    }
    else{
        res = s;
    }
    return res;
}
string trim (string s){
    string res = "";
    int i = 0;
    int fin = length(s) - 1;
    while (s[i] == ' ') {
        i++;
    }
    while (s[fin] == ' ') {
        fin--;
    }
    while (i <= fin) {
        res += s[i];
        i++;
    }
    return res;
}
string replicate(char c, int n)
{
  string reply = "";
  int i = 0;
  while (i != n)
  {
     reply = reply + c;
     i++;
  }
   return reply;
}
string spaces(int n)
{
  string spa = "";
  char espacio = 32;
  int i=0;
  while (i != n)
  {
     spa = spa + espacio;
     i++;
  }
   return spa;
}
string lpad(string s, int n, char c)
{
  string cad = "";
  int larg = length (s);
  int dif = n - larg;
  while (dif != 0)
  {
   cad = cad + c;
   dif--;
  }
   cad = cad + s;

   return cad;
}
string rpad(string s, int n, char c)
{
 string cad = "";
 int largS = length (s), dif = n-largS ;
  while (dif != 0)
  {
     cad = cad + c;
     dif--;
  }
  cad = s + cad;

   return cad;
}
string cpad(string s, int n, char c)
{
 string cad = "";
 int larg = length (s), dif = (n - larg)/2;
 while (dif != 0)
 {
    cad = cad + c;
    dif--;
 }
  cad = cad + s + cad;
   return cad;
}
bool isDigit (char c){
    if ('0' <= c && c <= '9') {
        return true;
    }else{
        return false;
    }
}
bool isLetter(char c){
    if ((c >= 65 && c < 91 )||(c >= 97 && c < 123)) {
        return true;
    }else{
        return false;
    }
}
bool isUpperCase(char c){
    if (c >= 65 && c < 91) {
        return true;
    }else{
        return false;
    }
}
bool isLowerCase(char c){
    if (c >= 97 && c < 123) {
        return true;
    }else{
        return false;
    }
}
char toUpperCase(char c){
    char res = ' ';
    if (isLowerCase(c)) {
        res = c - 32;
    }else{
        res = c;
    }
    return res;
}
char toLowerCase(char c){
    char res = ' ';
    if (isUpperCase(c)) {
        res = c + 32;
    }else{
        res = c;
    }
    return res;
}
string toUpperCase(string s){
    string res = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (isLowerCase(s[i])) {
            res += toUpperCase(s[i]);
        }else{
            res += s[i];
        }
    }
    return res;
}
string toLowerCase(string s){
    string res = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if(isUpperCase(s[i])){
            res += toLowerCase(s[i]);
        }else{
            res += s[i];
        }
    }
    return res;
}
int cmpString (string a, string b){
    int res, la = length(a), lb = length(b);
    res = lb - la;
    return res;
}
int cmpDouble(double a, double b){
    int res ;
    if (a < b) {
        res = -1;
        return res;;
    }else if (a > b){
        res = 1;
        return res;
    }else{
        res = 0;
        return res;
    }
}


#endif /* strings_h */
