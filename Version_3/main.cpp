/* 
 * File:   main.cpp
 * Author: Isaiah Lopez
 *
 * Created on June 7, 2022, 3:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
void genDeck();
string drwPCrd();
string drwDCrd();
/*
 * 
 */
string temp;
const int TCARDS=52;
int pValue,dValue;

int main(int argc, char** argv) {
    char pAgain='n',pInput='n';
    srand((unsigned)time(0));
    do{
        pValue=0;
        dValue=0;
        genDeck();
        cout<<"Player Cards"<<"\t     |\t      "<<"Dealer Cards |";
        cout<<"Inputs"<<endl;
        cout<<"---------------------+----------------------------"<<endl;
        cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
        cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
        cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
        cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
        if(pValue<21&&dValue!=21){
            do{
                if(dValue==21){
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Dealer Wins"<<endl;
                }
                else{
                    cout<<setw(16)<<"Hit or Stand?(y/n)"<<right<<setw(4)<<"|";
                    cout<<setw(22)<<" |";
                    cin>>pInput;
                    if(pInput=='y'){
                        cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
                        cout<<right<<setw(22)<<"     |"<<endl;
                    }
                }
            }while(pValue<21&&pInput=='y');
            while(dValue<17){
                cout<<right<<setw(22)<<"|";
                cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
            }
            if(pValue==21){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Player Wins"<<endl;
            }
            else if(pValue>dValue&&pValue<=21){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Player Wins"<<endl;
            }
            else if(dValue>pValue&&dValue<=21){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Dealer Wins"<<endl;
            }
            else if(dValue>21&&pValue<=21){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Player Wins"<<endl;
            }
            else if(pValue>21&&dValue<=21){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Dealer Wins"<<endl;
            }
            else if(pValue==dValue){
                cout<<"---------------------+----------------------"<<endl;
                cout<<"Push"<<endl;
            }
        }
        cout<<"Play Again?(y/n)"<<endl;
        cin>>pAgain;
    }while(pAgain=='y');
    return 0;
}

struct DefineCard{
    string suit;
    string face;
    int value;   // FACE => 10 POINTS & ACE's => 1 OR 11
} Deck[53]; // Deck[52] will be used when shuffling deck

void genDeck(){
    char face[]="A23456789XJQK";
    string suit[]={"Spades","Clubs","Hearts","Diamonds"};
    int values[]={11,2,3,4,5,6,7,8,9,10,10,10,10};
    for(int i=0;i<52;i++){
        Deck[i].face=face[i % 13];
        Deck[i].suit=suit[i / 13];
        Deck[i].value=values[i % 13];
    }
}

string drwPCrd(){
    int cardNum=rand()%52, aceValue=0;
    string disCard=Deck[cardNum].face + " of " + Deck[cardNum].suit;
    if(Deck[cardNum].value == 11){
        cout<<"ACE:1 or 11?";
        cin>>aceValue;
        cout<<right<<setw(4)<<" |";
        if(aceValue==1||aceValue==11){
            pValue+=aceValue;
        }
        else{
            pValue+=1;
        }
    }
    else pValue+=Deck[cardNum].value;
    return disCard;
}

string drwDCrd(){
    int cardNum=rand()%52;
    temp=Deck[cardNum].face + " of " + Deck[cardNum].suit;
    string disCard=Deck[cardNum].face + " of " + Deck[cardNum].suit;
    dValue+=Deck[cardNum].value;
    return disCard;
}

