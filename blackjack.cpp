#include <bits/stdc++.h>
using namespace std;
    list<int> l;
    list<int> obb,me;
    int summe,sumobb;
    list<int> brainobb;
    bool check[12];
    bool stopobb;
    bool start;
    bool obbover,meover;
    int winme=0,winobb=0,draw=0;
    long long money;
    long long stmoney;
    bool inmoney;
    long long bet;
    int ro=1;
    char c;
    int fs;
    bool skip;
    int profit=0,losee=0;

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
    cout<<"\n\nYour crad : ";
    for(auto x:me)
        cout<<x<<" ";
    cout<<"\nSum = "<<summe;
}

void kitobb(){
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
}

void kitme(){
    turnme();
    if(summe>21){
        meover=true;
        return;
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
    stopobb=false;
    start=false;
    obbover=false;
    meover=false;
    skip=false;
    srand(time(NULL));
}

void showend(){
    cout<<"\n\n\nWin : "<<winme<<"\n";
    cout<<"Lose : "<<winobb<<"\n";
    cout<<"Draw : "<<draw;
    cout<<"\n\nDo you want to remach? (y/n)\n:";
}

void win(){
    cout<<"You Win";
    money+=bet;
    profit+=bet;
}

void lose(){
    cout<<"You Lose";
    money-=bet;
    losee+=bet;
}

void clear(){
    system("CLS");
    cout<<"Money : "<<money<<"\n";
    cout<<"Round : "<<ro<<"\n----------------\n\n";
}

void play(){
    int n=l.size();
        show();
        cout<<"\n\nCard left : "<<n<<"\n\n\n\n";
        printf("press 'd' to draw a card\npress 'f' to finish game\n");
        scanf(" %c",&c);
        while(c!='f'&&c!='d'){
            clear();
            cout<<"\nPlease try again !\n";
            show();
        cout<<"\n\nCard left : "<<n<<"\n\n\n\n";
        printf("press 'd' to draw a card\npress 'f' to finish game\n");
        scanf(" %c",&c);
        }

        if(c=='f'){
            while(!stopobb){
                kitobb();
            }
            skip=true;
            return;
        }
        if(c=='d'){
            kitme();
            if(meover){
                skip=true;
                return;
            }
        }
        clear();
}

int main(){
    if(!inmoney){
        cout<<"Please enter the amount\n: ";
        scanf("%lld",&money);
        stmoney=money;
        inmoney=true;
    }
    do{
        system("CLS");
        cout<<"Do you want to first or second? (f/s)\n: ";
        scanf(" %c",&c);
    }while(c!='f'&&c!='s');
    if(c=='f')
        fs=1;
    else fs=2;

    while(true){
    if(money==0){
        break;
    }
    reset();
    do{
        clear();
        cout<<"Please enter the amount you wish to wager\n: ";
        scanf("%lld",&bet);
    }while(bet>money);
    clear();
    for(int i=0;i<2;i++){
        turnobb();
        turnme();
        start=true;
    }

    while(true){
        if(fs==1){
        play();
        if(skip){
            break;
        }
        kitobb();
        if(obbover){
            break;
        }
        }else {
            kitobb();
            if(obbover)
                break;
            play();
            if(skip)
                break;
        }
    }
    
    clear();
    cout<<"Opp's card : ";
    for(auto x:obb)
        cout<<x<<" ";
    cout<<"\nObb Sum = "<<sumobb;
    cout<<"\n\nYour crad : ";
    for(auto x:me)
        cout<<x<<" ";
    cout<<"\nYour Sum = "<<summe;
    cout<<"\n\n\n";
    if(obbover){
        win();
        winme++;
    }else if(meover){
        lose();
        winobb++;
    }else if(summe>sumobb){
        win();
        winme++;
    }else if(summe<sumobb){
        lose();
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
        clear();
        ro++;
        continue;
    }
    if(c=='n'){
        break;
    }
    }
    clear();
    cout<<"Starting money : "<<stmoney<<"\n";
    cout<<"Profit : "<<profit<<"\n";
    cout<<"Lose : "<<losee<<"\n\n\n";
    cout<<"Thank for playing\nI love you all <3\n\n\n";
    cout<<"\t\tCreated by Nutnai\n";
    cout<<"\t\t\t27/5/2563";

    cin>>c;
    return 0;
}