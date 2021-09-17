#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "8/8/8/1P6/8/8/8/8 w - - 32 132";
string fen1 = "8/8/8/8/7b/8/8/R3K2R w KQ - 0 1";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen1);

    game.CastleMov();

    game.PrintMoveList();

}