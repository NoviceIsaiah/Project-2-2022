/*
 * File:   main.cpp
 * Author: Isaiah Lopez
 * Created on June 7, 2022, 3:24 PM
 * 
 * Purpose: Create a game of 21
 * 
 * Patch Notes: This version fixes some formatting issues when drawing
 * an ace card. Also adds money to track score of the player. The player
 * can now wager money as long as they have more than $0.
 * 
 */


#include <iostream> //I/O Stream
#include <ctime> //Random gen Library
#include <iomanip> //I/O Manipulation 

using namespace std; //Using std namespace for the project

//Function Prototypes 
//Declares the functions up top to prevent any order errors since the actual 
//functions run after main driver

//Functions used for manipulation the deck and it's cards
void genDeck();
string drwPCrd();
string drwDCrd();

//Functions used to manipulate the bank of the player
int addMon(int ,int&);
int subMon(int,int&);
int bet(int,int);

//Function to manipulate the high score of the player
int highS(int cur);

//Some global variables
//Global variables shouldn't be included but were needed in the projects case
//to have the values change with functions, main driver, and structure
int dValue=0;
int pValue=0;
int high=1000;

//Main driver
int main(int argc, char** argv) {
    //Declare variables
    int bet=0;
    char pAgain='n';
    char pInput='n';
    
    //Set random num generator
    srand((unsigned)time(0));
    
    //Starts program with do while loop while player wants to keep playing
    do{
        int ttlMon=1000;
        cout<<"Bank: "<<ttlMon<<endl; //Displays initial bank amount: $1000
        
        do{
            cout<<"Place Bet: ";
            cin>>bet; //Asks user for bet amount
            cout<<"---------------------+----------------------------"<<endl;
            
            pValue=0;//Sets player value to 0 after each game
            dValue=0;//Sets dealer value to 0 after each game
            genDeck(); //Generates the deck
            
            //Draws 2 cards one for the player and one for the dealer
            cout<<"Player Cards"<<"\t     |\t      "<<"Dealer Cards |";
            cout<<"Inputs"<<endl;
            cout<<"---------------------+----------------------------"<<endl;
            cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
            cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
            cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
            cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
            
            //If the player has less than 21 they can test their luck
            if(pValue<21){
                do{ //Second do while to  keep looping as long as the player 
                    //chooses to keep drawing cards if they want or they can hold
                    
                    if(dValue==21){ //If the dealer hits 21 the game ends and 
                        //outputs bank before player can even hit
                        cout<<"---------------------+----------------------"<<endl;
                        cout<<"Dealer Wins"<<endl;
                        cout<<"Bank: "<<subMon(bet,ttlMon)<<endl;
                    }
                    
                    else{ //If not the player can hit again up until they go over
                        //a value of 21
                        cout<<setw(16)<<"Hit or Stand?(y/n)"<<right<<setw(4)<<"|";
                        cout<<setw(22)<<" |";
                        cin>>pInput;
                        
                        if(pInput=='y'){ //If input is yes the player draws 
                            //another card and is displayed
                            cout<<setw(16)<<drwPCrd()<<right<<setw(5)<<pValue<<left<<"|";
                            cout<<right<<setw(22)<<"     |"<<endl;
                        }
                    }
                }while(pValue<21&&pInput=='y'); //While statement for do-while        
                    
                while(dValue<17){ //After the player hits the dealer is forced
                //to hit until they reach 17 or more
                cout<<right<<setw(22)<<"|";
                cout<<setw(16)<<drwDCrd()<<right<<setw(5)<<dValue<<left<<"|"<<endl;
                }
                
                if(pValue==21){ //If player hits 21 after deal then it is 
                    //black jack. Player wins bet
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Player Wins"<<endl;
                    cout<<"Bank: "<<addMon(bet,ttlMon)<<endl;
                }
                
                if(pValue>dValue&&pValue<=21){ //If player value is closer to 21
                    //than the dealer then player wins bet
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Player Wins"<<endl;
                    cout<<"Bank: "<<addMon(bet,ttlMon)<<endl;
                }
                
                else if(dValue>pValue&&dValue<=21){ //If the dealer is closer to 
                    //21 then the dealer wins and player looses bet
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Dealer Wins"<<endl;
                    cout<<"Bank: "<<subMon(bet,ttlMon)<<endl;
                }
                
                else if(dValue>21&&pValue<=21){ //If dealer hits over 21 then 
                    //dealer bust and player wins bet
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Player Wins"<<endl;
                    cout<<"Bank: "<<addMon(bet,ttlMon)<<endl;
                }
                
                else if(pValue>21&&dValue<=21){ //If player bust then dealer wins
                    //and loses bet
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Dealer Wins"<<endl;
                    cout<<"Bank: "<<subMon(bet,ttlMon)<<endl;
                }
                
                else if(pValue==dValue&&pValue<=21&&dValue<=21){ //If player and
                    //dealer tie then nothing happens and plays again
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Push"<<endl;
                    cout<<"Bank: "<<ttlMon<<endl;
                }
                
                else if(pValue>21){//If player simply bust then player loses
                    //bet money
                    cout<<"---------------------+----------------------"<<endl;
                    cout<<"Bust"<<endl;
                    cout<<"Bank: "<<subMon(bet,ttlMon)<<endl;
                }
            }
            highS(ttlMon);
            //After  each win or loss determine if the new
            //amount of money is greater than the previous high score
            
        }while(ttlMon>0);//While loop for do-while loop. If player has money they
        //keep playing and continue to bet money until they hit 0
        
        cout<<"High score: "<<highS(ttlMon)<<endl;//After the play hits 0 it'll
        //display the highest amount of money the player had 
        
        cout<<"Play Again?(y/n)"<<endl;
        cin>>pAgain;
    }while(pAgain=='y');//While loop for first do-while loop. Player can choose 
    //to play again if they'd like.
    
    return 0; //Exit program
}


struct DefineCard{ //Sets structure for a card
    string suit; //String for suit
    string face; //String for face
    int value;   // FACE => 10 POINTS & ACE's => 1 OR 11
    
} Deck[52]; //Sets deck array and amount of elements

//Function to generate deck and delcare the values for each array element
void genDeck(){
    char face[]="A23456789XJQK";//Sets face elements for each possible face
    
    string suit[]={"Spades","Clubs","Hearts","Diamonds"};// Sets suit elements
    //for each possible suit
    
    int values[]={11,2,3,4,5,6,7,8,9,10,10,10,10}; //Sets element values for 
    //card 
    for(int i=0;i<52;i++){ //Loops i for each card in the deck
        Deck[i].face=face[i % 13]; //Face is the remainder of 13
        Deck[i].suit=suit[i / 13]; //Suit is i/13
        Deck[i].value=values[i % 13];//Value is same as face but represented 
        //as an int
    }
}

//Function to draw players card
string drwPCrd(){
    int cardNum=rand()%52;
    int aceValue=0; //Declares variables for function
    string disCard=Deck[cardNum].face + " of " + Deck[cardNum].suit;
    //Sets disCard to string to be return based on values
    
    if(Deck[cardNum].value == 11){
        cout<<setw(16)<<"ACE:1 or 11?"<<right<<setw(6)<<"|";
        cout<<setw(22)<<right<<"|";
        cin>>aceValue; //Asks for value of ace 
        cout<<setw(16)<<left;
        if(aceValue==1||aceValue==11){ //If ace value is 1 or 11 then the 
            pValue+=aceValue;          //pValue adds aceValue
        }
        else{
            pValue+=1; //If 1 or 11 isn't chosen then 1 is added to pVlaue
        }
    }
    else pValue+=Deck[cardNum].value;//If not ace then player value is added by 
    //the cards value
    
    return disCard; //Returns string disCard
}

//Function to draw dealer card
string drwDCrd(){
    int cardNum=rand()%52;
    string disCard=Deck[cardNum].face + " of " + Deck[cardNum].suit;
    dValue+=Deck[cardNum].value; //Adds deck value to dValue
    
    return disCard; //Returns string disCard
}

//Function to add money to bank
int addMon(int amt,int& total){
    if(amt<=total){
        total=total+amt;
    }
    else total=total;
    
    return total;//Return new total
}

//Function to subtract money from bank
int subMon(int amt,int& total){
    if(amt<=total){
        total=total-amt;
    }
    else total=total;
    
    return total;//Return new total
}

//Function to determine high score for the player
int highS(int cur){
    if (cur>high){
        high=cur;
    }
    
    return high;//Return new high score
}