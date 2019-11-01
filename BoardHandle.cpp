#include<iostream>
#include<string>
#include "Interface.h"

using namespace std;

char boards[3][3] = {{'-','-','-'},
                     {'-','-','-'},
                     {'-','-','-'}};

void printBoard(){
    cout<<"  Board state:\n";
    unsigned int i, j;
    for(i = 0; i < 50; i++)
        cout<<"**";
    cout<<"\n";
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
            cout<<"     "<<boards[i][j]<<"        ";
        cout<<"\n";
    }
    for(i = 0; i < 50; i++)
        cout<<"**";
    cout<<"\n";
}
int main(){

    bool playFirst;

    cout<<"Welcome to TIC-TAC-TOE!!\n";
    cout<<"Would you like to play first or let the computer play??\n";
    
    cin>>playFirst;

    if(playFirst)
        goto Player_First;
    else
        goto Computer_First;

    while(true){
/*Computers turn*/
        Computer_First:
        if(computers_turn())
            break;
/*Take players input*/
        Player_First:
        if(players_turn())
            break;
    }
}