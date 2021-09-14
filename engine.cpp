#include<bits/stdc++.h>
#include "board.cpp"
#include "makemove.cpp"

string fen = "8/8/8/1P6/8/8/8/8 w - - 32 132";
using namespace std;
int main(){
    movegen game; 
    game.ParseFEN(fen);
    cout<<"\n"<<game.SqAttacked(52,1);
}