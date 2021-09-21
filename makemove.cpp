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
    bool execmove(int move);
    void validMove(string mov);
    void TakeMove(int move);
};
void makemove::validMove(string mov){
    int move=0, tempPce=EMPTY;
    int sidedir[]={1,-1};
    move=(move^(mov[0]-'a'));
    move=((move)^((mov[1]-'1')<<3));
    move=((move)^((mov[2]-'a')<<6));
    move=((move)^((mov[3]-'1')<<9));
    if((Brd[mov[1]-'1'][mov[0]-'a'] == wP && (mov[3]-'1' == 7)) 
    || Brd[mov[1]-'1'][mov[0]-'a'] == bP && (mov[3]-'1' == 1)){
        cout<<"Enter Promoted Piece: ";
        cin>>tempPce;
        if(!(tempPce>(sidedir[side]*6+1) && tempPce<(sidedir[side]*6+6))){
            cout<<"Invalid Piece Type";
            return;
        }
    }
    move=((move)^(tempPce<<12));
    int tempmove;
    for(int i=0;i<movelist.size();i++){
        tempmove=movelist[i] & 0xffff;
        if(tempmove==move){
            if(!execmove(movelist[i]))
                cout<<"Invalid Move";
            return;
        }
    }
    cout<<"\nInvalid Move\n";
    return;
}
bool makemove::execmove(int move){
    int ff =((move) & 7);
    int fr = ((move>>3)&7); 
    int tf = ((move>>6)&7);
    int tr = ((move>>9)&7);
    int pr = ((move>>12)&15);
    int ep = ((move>>16)&1);
    int cast = ((move>>17)&1);
    int sidedir[] = {1,-1};
    int pce = Brd[fr][ff];
    FiftyMoves++;
    TotalMoves++;
    if(cast==1){
        ClearPiece(fr,ff);
        AddPiece(pce,tr,tf);
        if((tr*10+tf)==2){
            ClearPiece(0,0);
            AddPiece(wR,0,3);
        }else if((tr*10+tf)==6){
            ClearPiece(0,7);
            AddPiece(wR,0,5);
        }else if((tr*10+tf)==72){
            ClearPiece(7,0);
            AddPiece(bR,7,3);
        }else if((tr*10+tf)==76){
            ClearPiece(7,7);
            AddPiece(bR,7,5);
        }
    }
    else if(pr!= 0){
        if(Brd[tr][tf]!= EMPTY){
            ClearPiece(tr,tf);
        }
        ClearPiece(fr,ff);
        AddPiece(pr,tr,tf);
        FiftyMoves = 0;
    }
    else if(ep==1){
        ClearPiece((EnPassant - sidedir[side]*10)/10,EnPassant%10);
        ClearPiece(fr,ff);
        AddPiece(pce,tr,tf);
        FiftyMoves=0;
    }
    else{
        if(Brd[tr][tf]!= EMPTY){
            ClearPiece(tr,tf);
            FiftyMoves = 0;
        }
        if(Brd[fr][ff] == wP || Brd[fr][ff] == bP){
            FiftyMoves = 0;
        }
        ClearPiece(fr,ff);
        AddPiece(pce,tr,tf);
    }
    CastlePerm= CastlePerm & (fr*10+ff);
    CastlePerm= CastlePerm & (tr*10+tf);
    EnPassant = OFFBOARD;
    if((pce == wP && tr== fr + 2 && fr == 1) || (pce == bP && tr == fr - 2 && fr == 6)){
        EnPassant = (tr - sidedir[side])*10 + tf;
        FiftyMoves = 0;
    }
    
    if(SqAttacked(PList[(side*6)+6][0])){
        TakeMove(move);
        return false;
    }
    side^=1;
    return true;
}

void makemove::TakeMove(int move){
    int ff =((move) & 7);
    int fr = ((move>>3)&7); 
    int tf = ((move>>6)&7);
    int tr = ((move>>9)&7);
    int pr = ((move>>12)&15);
    int ep = ((move>>16)&1);
    int cast = ((move>>17)&1);
    int sidedir[] = {1,-1};
    int pce = Brd[fr][ff];
    FiftyMoves++;
    TotalMoves++;
}