#include<iostream>
#include<string>
#include "Interface.h"

using namespace std;

unsigned int x, y;

int players_turn(){

    printBoard();
    cout<<"Your's Move ::\n";
    cout<<" Row : ";
    cin>>x;
    cout<<" Column : ";
    cin>>y;
    
    system("CLS");
/*Update players move and evaluate position*/
    boards[x-1][y-1] = 'O';
    printBoard();
    if(evaluateWinner(boards, 1) == -5){
        cout<<"You Win!!\n\n";
        system("pause");
        return 1;
    }
    if(boardIsFull(boards)){
        cout<<"Game over\n\n";
        system("pause");
        return 1;
    }
    system("pause");
    system("CLS");
    return 0;
}
int computers_turn(){

    struct turn_pos best_pos;
/*Obtain best move for computer and update the board*/
    best_pos = optimalMove(boards, 0);
    boards[best_pos.r][best_pos.c] = 'X';

    printBoard();
    cout<<"Computer's Move :: Row : "<<(best_pos.r+1)<<" Column : "<<(best_pos.c+1)<<"\n";
/*Evaluate board after computer's move*/
    if(evaluateWinner(boards, 0) == 5){
        cout<<"Computer Wins!!\n\n";
        system("pause");
        return 1;
    }
    if(boardIsFull(boards)){
        cout<<"Game over\n\n";
        system("pause");
        return 1;
    }
    system("pause");
    system("CLS");
    return 0;
}
