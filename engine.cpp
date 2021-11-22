#include<bits/stdc++.h>
#include "board.cpp"
#include "movegen.cpp"
#include "makemove.cpp"
#include "alphabeta.cpp"

string DefaultFen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
using namespace std;
int main(){
    /*makemove m;
    m.ParseFEN(DefaultFen); //set default position (i.e. starting of the game)
    m.PrintBoard();
    int n=0;
    while(n!=3){                    //n=3 when user select exit option
        if(m.Check_FM()){
            cout<<"\nGame Drawn";       //check for fifity moves
            break;
        }
        if(m.IsCheckMate()){
            cout<<"\nGame Over";        //check for checkmate/stalemate
            break;
        }
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
    }*/
    alphabeta ab;
    ab.ParseFEN(DefaultFen);
   
    cout<<ab.minimax(3,true,-1000,1000)<<"\n";

    for(int i= 0;i<ab.movedata[0].size();i++){
        cout<<ab.movedata[0][i]<<"\t";
        cout<<ab.movedata[1][i]<<"\n";
    }
}