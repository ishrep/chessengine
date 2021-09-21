#include<bits/stdc++.h>
#include "board.cpp"
#include "movegen.cpp"
#include "makemove.cpp"


string fen4 = "rnbqkbnr/pppppppp/8/8/4r3/8/PPPPPPPP/RNBQKBNR b Kkq d2 23 113";
string fen1 = "1K5r/8/8/4q3/8/8/1Q6/R2k4 w - - 0 1";
using namespace std;
int main(){
    makemove m;
    m.ParseFEN(fen4);
    m.generateFen();

}