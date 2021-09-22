#include<bits/stdc++.h>
#include "board.cpp"
#include "movegen.cpp"
#include "makemove.cpp"


string DefaultFen = "r1b1kbnr/pp1ppppp/n1p5/q7/4P3/7N/PPPP1PPP/RNBQKB1R w KQkq - 0 1";
string fen1 = "1K5r/8/8/4q3/8/8/1Q6/R2k4 w - - 0 1";
using namespace std;
int main(){
    makemove m;
    m.ParseFEN(DefaultFen);
    m.PrintBoard();
    int n=0;

    while(n!=3){
        string fen;
        string mov;
        cout<<"\n1. fen\n2. move\n3. exit\nEnter choice:";
        cin>>n;
        switch(n){
            case 1: cout<<"Enter FEN: ";
                    getchar();
                    getline(cin, fen,'\n');
                    m.ParseFEN(fen);break;
            case 2: cout<<"Enter move: ";
                    cin>>mov;
                    m.validMove(mov);break;
            case 3: break;
            default: cout<<"Invalid choice";
        }
        cin.clear();
    }
}