#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "8/8/8/1P6/8/8/8/8 w - - 32 132";
string fen1 = "rnbqkbnr/ppp1pp1p/3p4/4P2p/6PP/8/PPPP1P2/RNBQKBNR w KQkq - 0 1";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen1);
    game.PawnMov(0);
}