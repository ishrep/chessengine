#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w Qkq e4 32 132";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen);
    cout<<"hell"<<game.SqAttacked(21,1)<<"hellp";
}