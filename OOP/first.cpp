#include<bits/stdc++.h>
using namespace std;
//for packing the structure 
#pragma pack(1)

class hero {
    
    //properties
    int health;
    public:
    char level;
    char *name;
    static int timeRem;

    //default constructor
    hero(){
        cout<<"default constructor called"<<endl;
        name = new char[100];
    }

    //parameterized constructor
    hero(int health,char level){

        cout<<"this -> "<<this<<endl;
        this->health = health;
        this->level = level;
    }

    //copy constructor
    // hero(hero &h){
    //     cout<<"copy constructor called"<<endl;
    //     health = h.health;
    //     level = h.level;
    // }

    //deeep copy constructor
    hero(hero &h){
        cout<<"deep copy constructor called"<<endl;
        health = h.health;
        level = h.level;
        name = new char[strlen(h.name)+1];
        strcpy(name,h.name);
    }

    int getHeatlh(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h,string name){

        if(name == "may")
            health = h;
        else
            health = 0;
    }

    void setLevel(char l){
        level = l;
    }

    void setName(char *name){
        this->name = name;
    }

    void print(){
        cout<<"[ ";
        cout<<health<<" , "<<level<<" , "<<name;
        cout<<" ]"<<endl;
    }

    //static
    static void printTime(){
        cout<<"time : "<<timeRem<<endl;
    }

    //destructor
    ~hero(){
        cout<<"destructor called"<<endl;
        if(name != NULL){
            delete [] name;
            name = NULL;
        }
    }

    
};

int hero::timeRem = 100;

int main(){

    //cunstructor
    // hero may(70,'A');
    // cout<<"Address of may : "<<&may<<endl;

    //copy constructor
    // hero may(70,'A');
    // hero arc(may);
    // cout<<"health : "<<arc.getHeatlh()<<endl;
    // cout<<"level : "<<arc.getLevel()<<endl;

    //shallow and deep copy 
    // hero h1;
    // h1.setHealth(70,"may");
    // h1.setLevel('A');
    // char may[100] = "may";
    // h1.setName(may);

    // h1.print();
    // hero h2 = h1;
    // h2.print();

    // may[0] = 'a';
    // h1.print();
    // h2.print();

    //assignment operator 
    // hero h1;
    // h1.setHealth(70,"may");
    // h1.setLevel('A');
    // char may[100] = "may";
    // h1.setName(may);

    // h1.print();
    // hero h2;
    // h2.setName(may);
    // h2.setHealth(80,"may");
    // h2.setLevel('B');

    // h2.print();

    // h2 = h1;
    // h2.print();


    //static  created an object
    // hero may;

    
    //  cout<<"size : "<<sizeof(ptr)<<endl;
    // may.health = 70;
    // may.level = 'A';
    // may.setHealth(70,"may");
    // cout<<"health : "<<may.getHeatlh()<<endl;

    // cout<<may.health<<endl;
    // cout<<may.level<<endl;

    //dynamic
    // hero *ptr = new hero();
    // ptr->setHealth(70,"may");
    // ptr->setLevel('A');
    // cout<<"health : "<<ptr->getHeatlh()<<endl;
    // cout<<"level : "<<ptr->level<<endl;

    //static 
    cout<<"time : "<<hero::timeRem<<endl;
    hero::printTime();


    //destructor
    // hero may;
    // hero *ptr = new hero();
    // ptr->setHealth(70,"may");
    // ptr->setLevel('A');
    // cout<<"health : "<<ptr->getHeatlh()<<endl;
    // cout<<"level : "<<ptr->level<<endl;
    // delete ptr; 
        //--> for may automatically destructor will be called

    return 0;
} 