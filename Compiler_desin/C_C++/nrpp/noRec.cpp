#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <string>

using namespace std;

#define len 10


char input[len][1000];
char vars[len][100];
stack<char*> fst[len];

char *trim(char *str){
    char *end;

    while((*str) == ' ' || (*str) == '\t') str++;

    if(*str == 0)  
        return str;

    end = str + strlen(str) - 1;
    while(end > str && ((*end) == ' ' || (*end) == '\n')) end--;

    *(end+1) = 0;

    return str;
}

bool ifvar(char str[100]){
    int i = 0;
    bool flag = true;

    while(vars[i] != NULL && i<len){
        if(!strcmp(vars[i], str))
            flag = false;


        i++;
    }
    

    return flag;
}

void inputf(){
    int i = 0;
    int j = 0;
    char buf[1000];
    FILE *inf;
    char *temp;

    inf = fopen("grammer.txt", "r+");
    if(!inf){
        cout<<"file not found";
        return;
    }
    
    while(fgets(buf, 1000, inf) != NULL){
        strcpy(input[i], trim(buf));
        // cout<<input[i++];

        temp = trim(strtok(buf, " "));
        if(ifvar(temp))
            strcpy(vars[j++], temp);
        i++;
    }
}

void findFirst(int x){
    char *temp;
    char inputx[len][1000];

    for (int i = 0; i!=len; i++) {
        for (int j = 0; j < 1000; j++) {
            inputx[i][j] = input[i][j];
        }
        
    }

    for (int i = 0; strcmp(inputx[i], ""); i++) {

        temp = strtok(inputx[i], " ");
        trim(temp);

        if(!strcmp(vars[x], temp)){
            for (int j = 0; strcmp(vars[j], ""); j++) {
                if(!strcmp(vars[j], inputx[i])){
                    temp = strtok(NULL, " ");
                    temp = strtok(NULL, " ");

                    if(ifvar(temp)){
                        fst[x].push(temp);
                        cout<<vars[x]<<"-> "<<fst[x].top()<<endl;
                    }
                        // cout<<"Is Var"<<endl;
                }
            }
        }
    }
}

int main(){
    int i = 0;
    inputf();

    while(strcmp(vars[i], "")){
        findFirst(i);
        i++;
    }

    i = 0;

    while(strcmp(vars[i], "")){
        cout<<endl<<vars[i]<<" - ";
        while(!fst[i].empty()){
            cout<<fst[i].top();
            fst[i].pop();
        }
        i++;
    }

    return 0;
}
