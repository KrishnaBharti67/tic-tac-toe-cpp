#include <iostream>
#include <ctime>

void board(char *spaces);
void playermove(char *spaces,char player);
void computermove(char *spaces,char computer);
bool checkwinner(char *spaces,char player,char computer);
bool checktie();
int main() {
    srand(time(NULL));

    char spaces[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running=true;

    
    while(running==true){
        board(spaces);
        playermove(spaces,player);
        if (checkwinner(spaces,player,computer)==true){
            running=false;
            break;
        }

        computermove(spaces,computer);
        
    }
}

void board(char *spaces){
    std::cout<<"  "<<" | "<<" "<<" | "<<'\n';
    std::cout<<" "<<spaces[0]<<" | "<<spaces[1]<<" | "<<spaces[2]<<"  "<<'\n';
    std::cout<<"__"<<"_|_"<<"_"<<"_|__"<<'\n';
    std::cout<<"  "<<" | "<<" "<<" | "<<'\n';
    std::cout<<" "<<spaces[3]<<" | "<<spaces[4]<<" | "<<spaces[5]<<"  "<<'\n';
    std::cout<<"__"<<"_|_"<<"_"<<"_|__"<<'\n';
    std::cout<<"  "<<" | "<<" "<<" | "<<'\n';
    std::cout<<" "<<spaces[6]<<" | "<<spaces[7]<<" | "<<spaces[8]<<"  "<<'\n'<<'\n';

}

void playermove(char *spaces,char player){
    int choice;
    do{
        std::cout<<"Enter position to place(1-9):";
        std::cin>>choice;
        choice--;
    
        if (spaces[choice]==' '){
            spaces[choice]=player;
            board(spaces);
            break;
            }    
    }while(choice>=0 && choice<9);  
}
void computermove(char *spaces,char computer){
    int choice=rand()%9;

    //IF CHOICE ALREADY FILLED, CHANGING VALUE
    while(spaces[choice]!=' '){
        choice=rand()%9;
    }
    spaces[choice]=computer;
    std::cout<<"New board"<<'\n';
    board(spaces);
}

bool checkwinner(char *spaces,char player,char computer){
    if (spaces[0]==player && spaces[1]==player && spaces[2]==player && spaces[0]!=' '){
        spaces[0]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[3]==player && spaces[4]==player && spaces[5]==player && spaces[3]!=' '){
        spaces[3]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[6]==player && spaces[7]==player && spaces[8]==player && spaces[6]!=' '){
        spaces[6]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[0]==player && spaces[4]==player && spaces[8]==player && spaces[0]!=' '){
        spaces[0]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[2]==player && spaces[4]==player && spaces[6]==player && spaces[2]!=' '){
        spaces[2]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[0]==player && spaces[3]==player && spaces[6]==player && spaces[0]!=' '){
        spaces[0]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[1]==player && spaces[4]==player && spaces[7]==player && spaces[1]!=' '){
        spaces[1]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else if (spaces[2]==player && spaces[5]==player && spaces[8]==player && spaces[2]!=' '){
        spaces[2]==player ? std::cout<<"YOU WIN\n" : std::cout<<"YOU LOSE \n";
    }
    else{
        return false;
    }
    return true;
}