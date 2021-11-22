class alphabeta:public makemove{
    const int MAX = 1000;
    const int MIN = -1000;
    public:
    alphabeta(){
        vector<int> moves;
        movedata.push_back(moves);
        movedata.push_back(moves);
    }
    vector<vector<int>> movedata;
    int DEPTH=3;
    int eval = 0;
    int AlphaBeta(int depth, int alpha, int beta);
    int minimax(int depth,
            bool maximizingPlayer, int alpha,
            int beta);
    int Evaluate();
};
int alphabeta::Evaluate(){
    
    return ++eval;
}
/*int alphabeta::AlphaBeta(int depth, int alpha, int beta)
{   
    vector<int> movelist1;
    if (depth == 0)
        return Evaluate();
    movelist.clear();
    GenerateAllMoves();
    movelist1 = movelist;
    string PrevFen;
    for (int i = 0; i<movelist1.size(); i++) {
        PrevFen = generateFen();
        execmove(movelist1[i]);
        int val = AlphaBeta(depth - 1, -beta, -alpha);
        ParseFEN(PrevFen);
        if (val >= beta)
            return beta;
        if (val > alpha)
            alpha = val;
    }
    return alpha;
}*/
int alphabeta::minimax(int depth, bool maximizingPlayer, int alpha, int beta){
    vector<int> movelist1;

    if (depth == 0){
        return Evaluate();
    }
    if (maximizingPlayer)
    {   

        int best = MIN;
        movelist.clear();
        GenerateAllMoves();
        movelist1 = movelist;
        string PrevFen;
        PrevFen = generateFen();
        for (int i = 0; i < movelist1.size(); i++)
        { 
            execmove(movelist1[i]); 
            int val = minimax(depth - 1, false, alpha, beta);
            if(depth == DEPTH){
                movedata[0].push_back(movelist1[i]);
                movedata[1].push_back(val); 
            }
            ParseFEN(PrevFen);
            best = max(best, val);
            alpha = max(alpha, best);
            if (beta <= alpha){
                break;}
        }
        
        return best;
    }
    else
    {
        int best = MAX;
        movelist.clear();
        GenerateAllMoves();
        movelist1 = movelist;
        string PrevFen;
        PrevFen = generateFen();
        for (int i = 0; i < movelist1.size(); i++)
        {
            execmove(movelist1[i]);
            int val = minimax(depth - 1,true, alpha, beta);
            if(depth == DEPTH){
                movedata[0].push_back(movelist1[i]);
                movedata[1].push_back(val); 
            }
            ParseFEN(PrevFen);
            best = min(best, val);
            beta = min(beta, best);
            if (beta <= alpha){
                 break;
            }   
        }
        return best;
    }
}