#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "8/8/8/1P6/8/8/8/8 w - - 32 132";
string fen1 = "8/8/3p4/1pP4P/1P2p3/p2P4/P5P1/8 w - - 0 1";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen1);
    game.PawnMov(0);
}