#include<bits/stdc++.h>
using namespace std;

struct setting{
    char first;
}st;

char game[4][4];
int turn,empty=9;
bool over,stop;

void show(){
    printf(" %c | %c | %c\n",game[1][1],game[1][2],game[1][3]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",game[2][1],game[2][2],game[2][3]);
    printf("-----------\n");
    printf(" %c | %c | %c\n\n\n",game[3][1],game[3][2],game[3][3]);
}
void ui(){

}

void player(){
    
}
void bot(){

}

main(){
do{

    char a;
    do{
        cout<<"Who first? (p/b)\n:";
        scanf("%c",&a);
        system("cls");
    }while(a!='p' && a!='b');
    turn=st.first='p'?1:0;
    while(!over){
        turn%=2;
        if(turn==1){
            player();
        }else{
            bot();
        }
        empty--;
        turn++;
        if(empty==0)break;
    }


}while(!stop);
}
