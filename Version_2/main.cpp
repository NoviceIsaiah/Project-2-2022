/* 
 * File:   main.cpp
 * Author: Isaiah
 *
 * Created on June 5, 2022, 2:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
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
        cout<<"Dealer Cards"<<endl;
        cout<<"------------------"<<endl;
        cout<<drwDCrd()<<"\t"<<dValue<<endl;
        drwDCrd();
        cout<<"Blank\t"<<dValue<<endl;
        cout<<"Player Cards"<<endl;
        cout<<"------------------"<<endl;
        cout<<drwPCrd()<<"\t"<<pValue<<endl;
        cout<<drwPCrd()<<"\t"<<pValue<<endl;
        if(pValue<21){
            do{
            cout<<"Hit or Stand?(y/n)"<<endl;
            cin>>pInput;
            if(pInput=='y')cout<<drwPCrd()<<"\t"<<pValue<<endl;
            }while(pValue<21);
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
        cout<<"Do you want Ace to be 1 or 11?"<<endl;
        cin>>aceValue;
        if(aceValue==1||aceValue==11){
            pValue+=aceValue;
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
