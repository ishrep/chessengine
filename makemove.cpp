#include<bits/stdc++.h>
using namespace std;

class makemove:public movegen{
    public:
    vector<int> CastleData ={ 
    13, 15, 15, 15, 12, 15, 15, 14,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
    15, 15, 15, 15, 15, 15, 15, 15,
     7, 15, 15, 15,  3, 15, 15, 11};
    void execmove(int move);
    void validMove(string mov);
};
void makemove::validMove(string mov){
    int move=0;
    move=move^(mov[0]-'a');
    move=(move)^((mov[1]-'1')<<3);
    move=(move)^((mov[2]-'a')<<6);
    move=(move)^((mov[3]-'1')<<9);
    int tempmove;
    for(int i=0;i<movelist.size();i++){
        tempmove=movelist[i] & 0xfff;
        if(tempmove==move){
            execmove(movelist[i]);
            return;
        }
    }
    cout<<"\nInvalid Move\n";

}
void makemove::execmove(int move){
    int ff =((move) & 7);
    int fr = ((move>>3)&7); 
    int tf = ((move>>6)&7);
    int tr = ((move>>9)&7);
    int pr = ((move>>12)&15);
    int ep = ((move>>16)&1);
    int cast = ((move>>17)&1);
    int sidedir[] = {-1,1};
    int pce = Brd[fr][ff];
    if(cast==1){
        ClearPiece(fr,ff);
        AddPiece(pce,tr,tf);
        
    }
    else if(pr==1){

    }
    else if(ep==1){

    }
    else{
        if(Brd[tr][tf]!= EMPTY){
            ClearPiece(tr,tf);
        }
        ClearPiece(fr,ff);
        AddPiece(pce,tr,tf);
    }
 
    if((pce == wP && tr== fr + 2 && fr == 1) || (pce == bP && tr == fr - 2 && fr == 6)){
        EnPassant = (tr - sidedir[side])*10 + tf;
    }

    
}