#include <iostream>
#include <cstdlib>
#include <ctime>
#define MAX_NUM 13
using namespace std;
// Poker's representation between char & numbers 
class Poker{
  public:
    string card;
    int number;
};

//To determine if the deck is empty or full of cards
bool isEmpty(int front, int rear){
    return(front==rear);
}
bool isFull(int front, int rear){
    return ((rear+1)%MAX_NUM==front);
}

//Delete Cards from the deck
void Delete(Poker* poker, int& front, int& rear){
    if(isEmpty(front,rear)){
        return;
    }
    else{
        //replace the original number with 0 as meaning of no cards
        poker[front].card="";
        poker[front].number=0;
        front=(front+1)%MAX_NUM;
    }
}

void Add(Poker* poker, int& front, int& rear, Poker add){
    if(isFull(front,rear)||(rear==MAX_NUM-1&&front == -1)){cout<<"The deck is full";}
    else{
        rear = (rear+1)%MAX_NUM;
        poker[rear].number = add.number;
        poker[rear].card = add.card;
    }
}

//shuffle cards
void shuffle(Poker* poker, int num){
    int random;
    Poker tmp;
    srand(time(NULL));
    for(int i=0;i<num;i++){
        //let random positions of two 2 cards exchange
        random = rand()%13;
        tmp = poker[i];
        poker[i] = poker[random];
        poker[random] = tmp;
    }   
}
//Print the whole deck 
void Print_Deck(Poker* poker, int front, int rear){
    if(front<=rear){
        //If there is no need to circulate the queue
        int i=front;
        while(i<MAX_NUM){
            cout<<poker[i].card<<" ";
            i++;
        }
    }
    else{
        //Print from front to the end of the array first
        int i=front;
        while(i<MAX_NUM){
            cout<<poker[i].card<<" ";
            i++;
        }
        i=0;
        //print from start of the array untill the end of the deck
        while(i<=rear){
            cout<<poker[i].card<<" ";
            i++;
        }
    }
    cout<<endl;
}
int main(){
    int front=0;
    int rear=12;
    int num=MAX_NUM;
    Poker poker[14];
    //Create the card deck 
    string index[13] = {"A","2","3","4","5","6"
    ,"7","8","9","10","J","Q","K"};
    for(int i=0;i<num;i++){
        poker[i].number = i+1;
        poker[i].card= index[i];
    }
    //shuffle cards
    shuffle(poker, num);
    Poker add;
    Print_Deck(poker,front,rear);
    //start drawing cards
    while(num>0&&front!=rear){
        add=poker[front];
        if(poker[front].number==num){
            //if cards' numbers are same than delete the card from the deck
            Delete(poker,front,rear);
            //turn to next number
            num--;
            }
        else{
            //Take the card to the end of the deck
            Delete(poker,front,rear);
            Add(poker,front,rear,add);
        }
        Print_Deck(poker, front, rear);
    }
}