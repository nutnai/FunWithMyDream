#include <bits/stdc++.h>
using namespace std;
    list<int> l;
    list<int> obb,me;
    int summe,sumobb;
    list<int> brainobb;
    bool check[12];
    bool stopme,stopobb;
    bool start;
    bool obbover,meover;
    int winme=0,winobb=0,draw=0;

int random(){
    int r;
    do{
        r = rand() % 12;
    }while(check[r]||r==0);
    check[r]=true;
    l.remove(r);
    return r;
}

void turnobb(){
    int r=random();
    obb.push_back(r);
    sumobb+=r;
}

void turnme(){
    int r=random();
    me.push_back(r);
    summe+=r;
    if(start){
        brainobb.remove(r);
    }
}

void show(){
    int i=0;
    cout<<"Opp's card : ";
    for(auto x:obb){
        if(i==0){
            cout<<"X ";
            i++;
        }else cout<<x<<" ";
    }
    cout<<"\nYour crad : ";
    for(auto x:me)
        cout<<x<<" ";
    cout<<"\nSum = "<<summe;
}

void kit(){
    if(!stopobb){
        int rob=brainobb.size();
        int p=0;
        for(auto x:brainobb){
            if(sumobb+x<=21)
            p++;
            else break;
        }
        float np=(p*1.0)/rob;
        if(np>=0.5)
            turnobb();
        else {
            stopobb=true;
            return;
        }
        if(sumobb>21){
            obbover=true;
            return;
        }
    }
    if(!stopme){
        turnme();
    if(summe>21){
        meover=true;
        return;
    }
    }
}

void reset(){
     l = {1,2,3,4,5,6,7,8,9,10,11};
    obb.clear();
    me.clear();
    summe=0;
    sumobb=0;
    brainobb={1,2,3,4,5,6,7,8,9,10,11};
    for(int i=0;i<12;i++)
        check[i]=false;
    stopme=false;
    stopobb=false;
    start=false;
    obbover=false;
    meover=false;
    srand(time(NULL));
}

void showend(){
    cout<<"\n\n\nWin : "<<winme<<"\n";
    cout<<"Lose : "<<winobb<<"\n";
    cout<<"Draw : "<<draw;
    cout<<"\nDo you want to remach? (y/n)\n:";
}

int main(){
    while(true){
    reset();
    char c;

    for(int i=0;i<2;i++){
        turnobb();
        turnme();
        start=true;
    }

    while(true){
        int n=l.size();
        show();
        cout<<"\n\nCard left : "<<n<<"\n";
        printf("press 'd' to draw a card\npress 'f' to finish game\n");
        scanf(" %c",&c);
        if(c=='f'){
            stopme=true;
            while(!stopobb){
                kit();
            }
            break;
        }
        if(c=='d'){
            kit();
            if(meover || obbover)
                break;
        }
        system("CLS");
        if(c!='f'&&c!='d'){
            cout<<"\nPlease try again !\n";
        }
    }
    system("CLS");
    cout<<"Opp's card : ";
    for(auto x:obb)
        cout<<x<<" ";
    cout<<"\nObb Sum = "<<sumobb;
    cout<<"\nYour crad : ";
    for(auto x:me)
        cout<<x<<" ";
    cout<<"\nYour Sum = "<<summe;
    cout<<"\n\n\n";
    if(obbover){
        cout<<"You Win";
        winme++;
    }else if(meover){
        cout<<"You Lose";
        winobb++;
    }else if(summe>sumobb){
        cout<<"You Win";
        winme++;
    }else if(summe<sumobb){
        cout<<"You Lose";
        winobb++;
    }else {
        cout<<"Draw";
        draw++;
    }
    
    showend();
    do{
        scanf(" %c",&c);
        cout<<"\b";
    }while(c!='y'&&c!='n');
    
    if(c=='y'){
        system("CLS");
        continue;
    }
    if(c=='n'){
        break;
    }
    }
    system("CLS");
    cout<<"Thank for playing\nI love you all <3\n\n\n";

    return 0;
}