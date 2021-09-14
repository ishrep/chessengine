#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Qkq e4 32 132";
using namespace std;
int main(){
    board game; 
    game.ParseFEN(fen);
}