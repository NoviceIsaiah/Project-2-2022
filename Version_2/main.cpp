/* File: main.cpp
 * Project 1 - Game of 21
 * Created by Isaiah Lopez
 * Date: 4/22/2022
 * Purpose: Create a singleplayer card game of 21. The user plays against the 
 * dealer and some fixes to card values are updated. 
 * This is for Project 1 of CSC 5.
 */
#include <iostream>
#include <ctime> 
#include <cstdlib> 

using namespace std;
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));//Sets random seed
    
    unsigned short pCard,pSuit,pFace,tCard,tSuit,tFace;//pCard is a random card, 
    //pSuit is the player cards suit and pFace is the player cards face
    unsigned short pValue=0,aceVal,tValue=0;//Player card value is 0 and aces have two 
    //values so it'll be set later
    string spCard,stCard;//spCard is the player's cards suit as a string
    char fpCard,pInp,ftCard;//fpCard is player face as a char, pInt is player input
    cout<<"\tPlayer Cards"<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=1;i<=2;i++){
        pCard=rand()%52+1;//Randomizes a card of a deck of 52 cards
        pSuit=pCard/13;//Finds the suit of the card 
        pFace=pCard%13;//Finds the face of the card

        //Determines which suit the Card belongs to by dividing by 13   
        if(pCard<=13)spCard="Spades";//If in first 13 cards the suit is Spades
        else if(pCard<=26)spCard="Hearts";//If in next 13 cards the suit is Hearts
        else if(pCard<=39)spCard="Diamonds";//If in next 13 cards the suit is 
        //Diamonds
        else if(pCard<=52)spCard="Clubs";//If in last 13 cards the suit is clubs

        //Based on the value of the card a char will represent the value for
        //the output on display
        if(pFace==1)fpCard='A';
        if(pFace==2)fpCard='2';
        if(pFace==3)fpCard='3';
        if(pFace==4)fpCard='4';
        if(pFace==5)fpCard='5';
        if(pFace==6)fpCard='6';
        if(pFace==7)fpCard='7';
        if(pFace==8)fpCard='8';
        if(pFace==9)fpCard='9';
        if(pFace==10)fpCard='X';//Char won't show 10 so it's shown as X
        if(pFace==11)fpCard='J';
        if(pFace==12)fpCard='Q';
        if(pFace==0)fpCard='K';
    
        if(fpCard=='A'){ //Aces can be 1 or 11 so the user will decide the val
            cout<<"Do you want Ace to be 1 or 11?"<<endl;
            cin>>aceVal;//User enters ace value
            if(aceVal!=1&&aceVal!=11)pValue+=1;//If the user doesn't input a value
            else pValue+=aceVal;               //it only adds one
        }
        else if(pFace==11||pFace==12||pFace==13)pValue+=10;
        else pValue+=pFace;
        if(pFace==0)pValue+=10;
        cout<<fpCard<<" of "<<spCard<<endl;
        cout<<"Player Value is "<<pValue<<"\n"<<endl;
    }
    cout<<"\tDealer Cards"<<endl;
    cout<<"--------------------------"<<endl;
    for(int i=1;i<=2;i++){
        tCard=rand()%52+1;//Randomizes a card of a deck of 52 cards
        tSuit=tCard/13;//Finds the suit of the card 
        tFace=tCard%13;//Finds the face of the card

        //Determines which suit the Card belongs to by dividing by 13   
        if(tCard<=13)stCard="Spades";//If in first 13 cards the suit is Spades
        else if(tCard<=26)stCard="Hearts";//If in next 13 cards the suit is Hearts
        else if(tCard<=39)stCard="Diamonds";//If in next 13 cards the suit is 
        //Diamonds
        else if(tCard<=52)stCard="Clubs";//If in last 13 cards the suit is clubs

        //Based on the value of the card a char will represent the value for
        //the output on display
        if(tFace==1)ftCard='A';
        if(tFace==2)ftCard='2';
        if(tFace==3)ftCard='3';
        if(tFace==4)ftCard='4';
        if(tFace==5)ftCard='5';
        if(tFace==6)ftCard='6';
        if(tFace==7)ftCard='7';
        if(tFace==8)ftCard='8';
        if(tFace==9)ftCard='9';
        if(tFace==10)ftCard='X';//Char won't show 10 so it's shown as X
        if(tFace==11)ftCard='J';
        if(tFace==12)ftCard='Q';
        if(tFace==0)ftCard='K';
    
        if(fpCard=='A'){ //Aces can be 1 or 11 so the user will decide the val
            cout<<"Do you want Ace to be 1 or 11?"<<endl;
            cin>>aceVal;//User enters ace value
            if(aceVal!=1&&aceVal!=11)tValue+=1;//If the user doesn't input a value
            else tValue+=aceVal;               //it only adds one
        }
        else if(tFace==11||tFace==12||tFace==13)tValue+=10;
        else tValue+=tFace;
        if(tFace==0)tValue+=10;
        cout<<ftCard<<" of "<<stCard<<endl;
        cout<<"Dealer Value is "<<tValue<<"\n"<<endl;
    }
    while(tValue<17){
        tCard=rand()%52+1;//Randomizes a card of a deck of 52 cards
        tSuit=tCard/13;//Finds the suit of the card 
        tFace=tCard%13;//Finds the face of the card

        //Determines which suit the Card belongs to by dividing by 13   
        if(tCard<=13)stCard="Spades";//If in first 13 cards the suit is Spades
        else if(tCard<=26)stCard="Hearts";//If in next 13 cards the suit is Hearts
        else if(tCard<=39)stCard="Diamonds";//If in next 13 cards the suit is 
        //Diamonds
        else if(tCard<=52)stCard="Clubs";//If in last 13 cards the suit is clubs

        //Based on the value of the card a char will represent the value for
        //the output on display
        if(tFace==1)ftCard='A';
        if(tFace==2)ftCard='2';
        if(tFace==3)ftCard='3';
        if(tFace==4)ftCard='4';
        if(tFace==5)ftCard='5';
        if(tFace==6)ftCard='6';
        if(tFace==7)ftCard='7';
        if(tFace==8)ftCard='8';
        if(tFace==9)ftCard='9';
        if(tFace==10)ftCard='X';//Char won't show 10 so it's shown as X
        if(tFace==11)ftCard='J';
        if(tFace==12)ftCard='Q';
        if(tFace==0)ftCard='K';
    
        if(fpCard=='A'){ //Aces can be 1 or 11 so the user will decide the val
            cout<<"Do you want Ace to be 1 or 11?"<<endl;
            cin>>aceVal;//User enters ace value
            if(aceVal!=1&&aceVal!=11)tValue+=1;//If the user doesn't input a value
            else tValue+=aceVal;               //it only adds one
        }
        else if(tFace==11||tFace==12||tFace==13)tValue+=10;
        else tValue+=tFace;
        if(tFace==0)tValue+=10;
        cout<<ftCard<<" of "<<stCard<<endl;
        cout<<"Dealer Value is "<<tValue<<"\n"<<endl;
    }
    do{
        cout<<"Would you like to draw another card?(y/n)"<<endl;
        cin>>pInp;//Input if they wanna draw another card or hold
        if(pInp=='y'){
            pCard=rand()%52+1;
            pSuit=pCard/13;
            pFace=pCard%13;
            if(pCard<=13)spCard="Spades";//If in first 13 cards the suit is Spades
            else if(pCard<=26)spCard="Hearts";//If in next 13 cards the suit is Hearts
            else if(pCard<=39)spCard="Diamonds";//If in next 13 cards the suit is 
            //Diamonds
            else if(pCard<=52)spCard="Clubs";
            //If in last 13 cards the suit is clubs
            
            //Based on the value of the card a char will represent the value for
            //the output on display
            if(pFace==1)fpCard='A';
            if(pFace==2)fpCard='2';
            if(pFace==3)fpCard='3';
            if(pFace==4)fpCard='4';
            if(pFace==5)fpCard='5';
            if(pFace==6)fpCard='6';
            if(pFace==7)fpCard='7';
            if(pFace==8)fpCard='8';
            if(pFace==9)fpCard='9';
            if(pFace==10)fpCard='X';//Char won't show 10 so it's shown as X
            if(pFace==11)fpCard='J';
            if(pFace==12)fpCard='Q';
            if(pFace==0)fpCard='K';

            if(fpCard=='A'){ //Aces can be 1 or 11 so the user will decide the val
                cout<<"Do you want Ace to be 1 or 11?"<<endl;
                cin>>aceVal;//User enters ace value
                if(aceVal!=1&&aceVal!=11)pValue+=1;//If they don't enter a value
                else pValue+=aceVal;               //it only adds 1
            }
            else if(pFace==11||pFace==12||pFace==13)pValue+=10;
            else pValue+=pFace;//If any other card at the original pFace to 
            if(pFace==0)pValue+=10;//If the card has no remainder than it's 
            //face is King and value is 13
            cout<<fpCard<<" of "<<spCard<<endl;//Displays card value
            cout<<"Player Value is "<<pValue<<"\n"<<endl;//Displays card value
        }
    }while(pValue<21&&pInp=='y');//If less than 21 the player can draw another card

    cout<<"Final Player Value is "<<pValue;//After the player selects cards the 
    //final value is displays
    cout<<"\tFinal Dealer Value is "<<tValue<<endl;
    cout<<"---------------------------------------------"<<endl;
    
    //Depending on your final value a messages is displayed
    if(tValue==21)cout<<"Dealer Wins!"<<endl;
    else if(pValue>21&&tValue>21)cout<<"It's a Push!\n   Tied";
    else if(pValue>21&&tValue<=21)cout<<"It's a Bust\nDealer Wins!"; //If the final value
    else if(tValue>21&&pValue<=21)cout<<"Dealer Bust\nYou Win!";
    else if(tValue>pValue&&tValue<=21)cout<<"Dealer wins!";
    else if(pValue>tValue&&pValue<=21)cout<<"You win!";
    else if(tValue==pValue)cout<<"It's a Push!\n   Tied";
    //is over 21 its a bust
    return 0;//Exit
}