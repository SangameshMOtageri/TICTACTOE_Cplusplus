#include<iostream>
#include<string>
#include "Interface.h"
using namespace std;

#define max(a, b) (a>=b)?a:b
#define min(a, b) (a<=b)?a:b

char plays[2] = {'X', 'O'};
int finalBoardscore[2] = {5, -5};

int evaluateWinner(char board[3][3], unsigned int player){

    unsigned int r, c;
    for(r = 0; r < 3; r++){
        if((board[r][0] == board[r][1]) && (board[r][2] == board[r][1]) && ('-' != board[r][1]))
        {
            if(plays[player] == board[r][1]){
                return finalBoardscore[player];
            }
            else{
                return -1*finalBoardscore[player];
            }
        }
    }
    for(c = 0; c < 3; c++){
        if((board[0][c] == board[1][c]) && (board[2][c] == board[1][c]) && ('-' != board[1][c]))
        {
            if(plays[player] == board[1][c]){
                return finalBoardscore[player];
            }
            else{
                return -1*finalBoardscore[player];
            }
        }
    }
    //Diagonal
    if(((board[0][0] == board[1][1]) && (board[2][2] == board[1][1]) && ('-' != board[1][1])) ||
       ((board[0][2] == board[1][1]) && (board[2][0] == board[1][1]) && ('-' != board[1][1]))){
        if(plays[player] == board[1][1]){
            return finalBoardscore[player];
        }
        else{
            return -1*finalBoardscore[player];
        }   
    }
    return 0;
}
bool boardIsFull(char board[3][3]){
    unsigned int r, c;
    for(r = 0; r < 3; r++){
        for(c = 0; c < 3; c++){
            if(board[r][c] == '-')
                return false;
        }
    }
    return true;
}
int minmax(char board[3][3], bool ismax, unsigned int player){

/*Pass previous player ID, we want to know if the last move made resulted in a winner*/
    int score = evaluateWinner(board, (player + 1)%2);

    if(score != 0)
        return score;
    if(boardIsFull(board)){
        return 0;
    }

    unsigned int r, c;
    int curr_best = 0;
/*Computers turn*/
    if(ismax){
        curr_best = -5;
    
        for(r = 0; r < 3; r++){
            for(c = 0; c < 3; c++){
                if(board[r][c] != '-')
                    continue;
                board[r][c] = plays[player];

                //False means next move is opponents
                curr_best = max(curr_best, minmax(board, false, (player + 1)%2) );

                board[r][c] = '-';
            }
        }
    }
/*Opponents turn*/
    else{
        curr_best = +5;
    
        for(r = 0; r < 3; r++){
            for(c = 0; c < 3; c++){
                if(board[r][c] != '-')
                    continue;
                board[r][c] = plays[player];

                //True means next move is computers
                curr_best = min(curr_best, minmax(board, true, (player +1 )%2));

                board[r][c] = '-';
            }
        }
    }
    return curr_best;
}

struct turn_pos optimalMove(char board[3][3], unsigned int  player){

    int maxscore = -100;  //{'x', 'o'}
/*If player: 0, we get maxscore : -100, ismax: 'false', next move will be opponents, comp plays 'x'
  If player: 1, we get maxscore : +100, ismax: 'true' , next move will be oppenents, comp plays 'o'*/
/*we would want the comp to make the move to reduce maxscore, so pass 'true' for the opponents*/
    int score;
    struct turn_pos pos;

    unsigned int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[i][j] != '-')
                continue;
            board[i][j] = plays[player];
/*Computer is always planning to maximise his score, opponent tries to minimise*/
            score = minmax(board, false, (player+1)%2);

            board[i][j] = '-';

            if(score > maxscore){
                maxscore = score;
                pos.r = i;
                pos.c = j;
            }
        }
    }
    return pos;
}