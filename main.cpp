/* 
 * File:   main.cpp
 * Author: Isaiah Lopez
 * 
 * Created on May 27, 2022, 10:01 PM
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
/*
 * 
 */
int deck[52],pValue=0,dValue=0;

int drawCard();//Function for drawing a random card
void dPCard();//Function for drawing player cards
void dDCard();//Function for drawing dealer cards

int main(int argc, char** argv) {
    srand((unsigned)time(0)); 
    cout<<"      GAME OF BLACKJACK"<<endl;
    cout<<"______________________________"<<endl;
    dPCard();
    dPCard();
    cout<<"\tPlayer Value: "<<pValue<<endl;
    cout<<"------------------------------"<<endl;
    dDCard();
    dDCard();
    cout<<"\tDealer Value: "<<dValue<<endl;
    cout<<"------------------------------"<<endl;
    return 0;
}
int drwCard(){
    int card=rand()%52+1;
    return card;
}
int drawCard(){
    int card=drwCard(),faceN;
    string suit,face;
    if(card<=13)suit="Diamonds";
    else if(card<=26)suit="Hearts";
    else if(card<=39)suit="Clubs";
    else if(card<=52)suit="Spades";
    
    if((card%13)==0)face="King";
    if((card%13)==1)face="Ace";
    if(card%13==2)face="2";
    if(card%13==3)face="3";
    if(card%13==4)face="4";
    if(card%13==5)face="5";
    if(card%13==6)face="6";
    if(card%13==7)face="7";
    if(card%13==8)face="8";
    if(card%13==9)face="9";
    if(card%13==10)face="10";
    if(card%13==11)face="Jack";
    if(card%13==12)face="Queen";
    cout<<face<<" of "<<suit<<endl;
    if((card%13)==0)faceN=10;
    if((card%13)==1)faceN=1;
    if(card%13==2)faceN=2;
    if(card%13==3)faceN=3;
    if(card%13==4)faceN=4;
    if(card%13==5)faceN=5;
    if(card%13==6)faceN=6;
    if(card%13==7)faceN=7;
    if(card%13==8)faceN=8;
    if(card%13==9)faceN=9;
    if(card%13==10)faceN=10;
    if(card%13==11)faceN=10;
    if(card%13==12)faceN=10;
    return faceN;
}
void dPCard(){
    int aceVal=0,temp;
    temp=drawCard();
    if(temp==0)pValue+=10;
    else if(temp==1){
        cout<<"1 or 11?"<<endl;
        while(aceVal!=1 && aceVal!=11){
            cin>>aceVal;
        }
        pValue+=aceVal;
    }
    else if(temp==2)pValue+=2;
    else if(temp==3)pValue+=3;
    else if(temp==4)pValue+=4;
    else if(temp==5)pValue+=5;
    else if(temp==6)pValue+=6;
    else if(temp==7)pValue+=7;
    else if(temp==8)pValue+=8;
    else if(temp==9)pValue+=9;
    else if(temp==10)pValue+=10;
    else if(temp==11)pValue+=10;
    else if(temp==12)pValue+=10;
}
void dDCard(){
    int aceVal=0,t,low,high;
    t=drawCard();
    if(t==0)dValue+=10;
    else if(t==1){
        low=1;
        high=11;
    }
    else if(t==2)dValue+=2;
    else if(t==3)dValue+=3;
    else if(t==4)dValue+=4;
    else if(t==5)dValue+=5;
    else if(t==6)dValue+=6;
    else if(t==7)dValue+=7;
    else if(t==8)dValue+=8;
    else if(t==9)dValue+=9;
    else if(t==10)dValue+=10;
    else if(t==11)dValue+=10;
    else if(t==12)dValue+=10;
}
