#include<bits/stdc++.h>
#include "board.cpp"
using namespace std;

class movegen: public board{
    int kingMov[]= {-1,1,-10,10,9,11,-9,-11};               //stores the value for which the king can move on the board.
    int queenMov[] = {1,-1,10,-10,-9, -11, 9 , 11};         //stores the value for which the Queen can move on the board.
    int bishopMov[] = {-9, -11, 9 , 11};                    //stores the value for which the Bishop can move on the board.
    int knightMov[] = {8,-8,12,-12,19,-19,21,-21};          //stores the value for which the Knight can move on the board.
    int rookMov[] = { 10,-10, 1,-1};                        //stores the value for which the Rook can move on the board.
    int PawnMov[ ] = {10,9,11,-10,-9,-11};
    
    vector<int> movList[256];                                       // stores the indexes from and to for all available moves. 

    bool SqAttacked(int sq);
    void PawnMov(int side);
    void KingMov(int side);
    void KnightMov(int side);
    void RQMov(int side);
    void BQMov(int side);
    void CastleMov(int side);
};

bool movegen::SqAttacked(int sq, int side){
    //King
    for(int i=0;i<8;i++){
        int tsq=sq+kingMov[i];
        int f=tsq%10;
        int r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(side==0){
                if(Brd[r][f]==bK){
                    return true;
                }
            }else{
                if(Brd[r][f]==wK){
                    return true;
                }
            }
        }
    }
    // Queen
    for(int i=0;i<8;i++){
        int tsq=sq+queenMov[i];
        int f=tsq%10;
        int r=tsq/10;
        while(f>=0 && f<=7 && r>=0 && r<=7){
            if(side==0){
                if(Brd[r][f]==bQ){
                    return true;
                }
            }else{
                if(Brd[r][f]==wQ){
                    return true;
                }
            }
            if(Brd[r][f]!=EMPTY){
                break;
            }
            tsq=tsq+queenMov[i];
            f=tsq%10;
            r=tsq/10;
        }
    }
    // Rook
    for(int i=0;i<4;i++){
        int tsq=sq+RookMov[i];
        int f=tsq%10;
        int r=tsq/10;
        while(f>=0 && f<=7 && r>=0 && r<=7){
            if(side==0){
                if(Brd[r][f]==bR){
                    return true;
                }
            }else{
                if(Brd[r][f]==wR){
                    return true;
                }
            }
            if(Brd[r][f]!=EMPTY){
                break;
            }
            tsq=tsq+RookMov[i];
            f=tsq%10;
            r=tsq/10;
        }
    }
    // Bishop
    for(int i=0;i<4;i++){
        int tsq=sq+BishopMov[i];
        int f=tsq%10;
        int r=tsq/10;
        while(f>=0 && f<=7 && r>=0 && r<=7){
            if(side==0){
                if(Brd[r][f]==bB){
                    return true;
                }
            }else{
                if(Brd[r][f]==wB){
                    return true;
                }
            }
            if(Brd[r][f]!=EMPTY){
                break;
            }
            tsq=tsq+BishopMov[i];
            f=tsq%10;
            r=tsq/10;
        }
    }
    // knight
    for(int i=0;i<8;i++){
        int tsq=sq+knightMov[i];
        int f=tsq%10;
        int r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(side==0){
                if(Brd[r][f]==bN){
                    return true;
                }
            }else{
                if(Brd[r][f]==wN){
                    return true;
                }
            }
        }
    }
    //Pawn
    if(side==0){
        tsq=sq+9;
        f=tsq%10;
        r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(Brd[r][f]==bP){
                return true;
            }
        }
        tsq=sq+11;
        f=tsq%10;
        r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(Brd[r][f]==bP){
                return true;
            }
        }
    }
    else{
        tsq=sq-9;
        f=tsq%10;
        r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(Brd[r][f]==wP){
                return true;
            }
        }
        tsq=sq-11;
        f=tsq%10;
        r=tsq/10;
        if(f>=0 && f<=7 && r>=0 && r<=7){
            if(Brd[r][f]==wP){
                return true;
            }
        }
    }
    return false;
}

void movegen::PawnMov(int side){
    pawnside = side*6 + 1;
    int sidemove[] = {1,-1};
    for(int i = 0; i<PieceNum[pawnside]; i++){
        int sq = PList[pawnside][i];
        int rank = sq/10;
        int column = sq%10;
        if(Brd[rank+ sidemove[side]][column] == EMPTY){
            int move = 0;
            move = move^column;
            move = move^(rank<<3);
            move = move^(column)<<6;
            move = move^(rank+sidemove[side]<<9);
            if(rank == 6){
                 for(int i = 1;i<=4;i++){
                     move = move^((pawnside+i)<<12);
                     movelist.push_back(move);
                     move = move^((pawnside+i)<<12);
                 }
            }
            movelist.push_back(move);
            if(rank == side*5 + 1 && Brd[rank+sidemove[side]*2][column] == EMPTY){
                int move = 0;
                move = move^column;
                move = move^(rank<<3);
                move = move^(column)<<6;
                move = move^(rank + sidemove[side]*2<<9);
                movelist.push_back(move);
            }
        }
        if(Brd[rank + sidemove[side]][column + sidemove[side]] >6 && Brd[rank+ sidemove[side]][column + sidemove[side]] <13){
            move = move^column;
            move = move^(rank<<3);
            move = move^(column + sidemove[side])<<6;
            move = move^(rank + sidemove[side]*2<<9);
            movelist.push_back(move);
        }
        if(Brd[rank + sidemove[side]][column - sidemove[side]] >6 && Brd[rank + sidemove[side]][column - sidemove[side]] <13){
            move = move^column;
            move = move^(rank<<3);
            move = move^(column + sidemove[side])<<6;
            move = move^(rank + sidemove[side]*2<<9);
            movelist.push_back(move);
        }
    }
}