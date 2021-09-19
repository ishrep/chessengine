#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "8/8/8/1P6/8/8/8/8 w - - 32 132";
string fen1 = "1K5r/8/8/4q3/8/8/1Q6/R2k4 w - - 0 1";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen1);

    game.QueenMov();

    game.PrintMoveList();

}