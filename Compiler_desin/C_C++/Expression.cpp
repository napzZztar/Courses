#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

char input[100];
char symb[4] = {'+', '-', '*', '/'};


void toInfix();
void toPrefix(int in);
void toPostfix(int in);

bool check(){
    int count = 0;
    for (int i = 0; i < (int)strlen(input); i++) {
       if(input[i] == '(')
           count++;
       else if(input[i] == ')')
           count--;
    }

    if(count)
        return false;
    else
        return true;
}

// ==============================
// Function to detect the input type
// infix 1, prefix 2, postfix 3
// ==============================

int detect(){
    int len = strlen(input) - 1;
    for (int i = 0; i < 4; i++) {
        if(input[0]==symb[i] || (input[0]=='(' && input[1]==symb[i]) ){
            // cout<<"prefix";
            return 2; 
        }else if(input[len]==symb[i] || (input[len]==')' && input[len-1]==symb[i]) ){
            // cout<<"postfix";
            return 3;
        }else
            return 1;
    }
}


void toPrefix(){

    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < 4;j++) {
            if(input[i] == symb[j]){
                input[i] = input[i-2];
                input[i-2] = symb[j];
                i +=2;
                break;
            }
        }
    }
    cout<<"The expression in Prefix \t: "<<input<<endl;
}

void toPostfix(int in){
    if(in==2){
        for (int i = 0; i < strlen(input); i++) {
            for (int j = 0; j < 4;j++) {
                if(input[i] == symb[j]){
                    input[i] = input[i+2];
                    input[i+2] = symb[j];
                    i +=2;
                    break;
                }
            }
        }
        cout<<"The expressin in Postfix\t: "<<input<<endl;
        toInfix(); //pre -> psot -> in

    }else if(in==1){
        for (int i = 0; i < strlen(input); i++) {
            for (int j = 0; j < 4;j++) {
                if(input[i] == symb[j]){
                    input[i] = input[i+1];
                    input[i+1] = symb[j];
                    i +=1;
                    break;
                }
            }
        }
        cout<<"The expressin in psotfix\t: "<<input<<endl;
        toPrefix();
    }else if (in == 3) {
        char temp[100];
        strcpy(temp, input);
        toPrefix();
        strcpy(input, temp);
        toInfix();
    }
}

void toInfix(){
    for (int i = 0; i < strlen(input); i++) {
        for (int j = 0; j < 4;j++) {
            if(input[i] == symb[j]){
                input[i] = input[i-1];
                input[i-1] = symb[j];
                i +=1;
                break;
            }
        }
    }

    cout<<"The expressin in Infix\t\t: "<<input<<endl;
}


int main(){
    cin.getline(input,100);
    //cout<<strlen(input);
    
    if (check()) {
        int dr = detect(); // infix 1, prefix 2, postfix 3

        toPostfix(dr);

    }else
        cout<<endl<<"WRONG INPUT!!"<<endl;

    return 0;
}
