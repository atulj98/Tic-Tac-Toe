#include<bits/stdc++.h>
using namespace std;
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7','8','9'}};
int row,column;
char token = 'X';
bool draw=false;
string n1="",n2="";
void functionOne(){    
    
    cout<<"   |     |"<<endl;
    cout<<" "<<space[0][0]<<" |  "<<space[0][1]<<"  | "<<space[0][2]<<endl;
    cout<<"___|_____|___"<<endl;
    cout<<"   |     |"<<endl;
    cout<<" "<<space[1][0]<<" |  "<<space[1][1]<<"  | "<<space[1][2]<<endl;
    cout<<"___|_____|___"<<endl;
    cout<<"   |     |"<<endl;
    cout<<" "<<space[2][0]<<" |  "<<space[2][1]<<"  | "<<space[2][2]<<endl;
    cout<<"   |     |"<<endl;
    
}

void functionTwo(){
    int digit;
    if(token=='X'){
        cout<<n1<<" Please Enter";
        cin>>digit;
    }
    if(token=='0'){
        cout<<n2<<" Please Enter";
        cin>>digit;
    }

    if(digit==1){
        row=0;
        column=0;
    }

    if(digit==2){
        row=0;
        column=1;
    }

    if(digit==3){
        row=0;
        column=2;
    }

    if(digit==4){
        row=1;
        column=0;
    }

    if(digit==5){
        row=1;
        column=1;
    }

    if(digit==6){
        row=1;
        column=2;
    }

    if(digit==7){
        row=2;
        column=0;
    }

    if(digit==8){
        row=2;
        column=1;
    }

    if(digit==9){
        row=2;
        column=2;
    }

    else if(digit<1 || digit>9){ 
        cout<<"INVALID!!!"<<endl;
    }
    if(token=='X' && space[row][column]!='X' && space[row][column]!='0'){
        space[row][column] = 'X';
        token = '0';
    }

   else if(token=='0' && space[row][column]!='X' && space[row][column]!='0'){
        space[row][column] = '0';
        token = 'X';
    }

    else 
    {
        cout<<"There is no empty space!"<<endl;
        functionTwo();
    }
    functionOne();
}

bool functionThree(){

    //to check whether someone has won the game or not
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return true;
        }
    }
        if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0]){
            return true;
        }

        //to check whether the game is still on or not
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(space[i][j]!='X' && space[i][j]!='0'){
                    return false;
                }
            }
        }
        draw=true;
        return false;
}

int main(){

    cout<<"Enter name of the first player: "<<endl;
    cin>>n1;
    cout<<"Enter name of the second player: "<<endl;
    cin>>n2;
    cout<<n1<<" is the first player so he/she will play first"<<endl;
    cout<<n2<<" is the second player so he/she will play second"<<endl;

    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token=='X' && draw==false){
        cout<<n2<<"Wins!"<<endl;
    }
    else if(token=='0' && draw==false){
        cout<<n1<<"Wins!"<<endl;
    }
    else cout<<"Its a draw!"<<endl;

    return 0;
}