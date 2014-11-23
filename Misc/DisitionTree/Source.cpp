/****************************************/ 
/* Language C++ 2011                    */ 
/* Source.cpp                           */ 
/* Purpose: Find root using gini index  */ 
/* Note: Please paste your text in      */ 
/*       input.txt file                 */ 
/*                                      */ 
/*                                      */ 
/* @author ashik992                     */ 
/* @version 1.0 09-nov-2014             */ 
/****************************************/ 


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#define sizeOfArrays = 100;

using namespace std;

int nRow;
int nCol;
int cRow;
int totalX;
string input[50][50];
string cho[50][50];
int count[20][20];
double gxV[20];


double gstart();
double gX(int i);


char *trim(char *str){
    char *end;

    while((*str) == ' ') str++;

    if(*str == 0)
        return str;

    end = str + strlen(str) - 1;
    while(end > str && ((*end) == ' ' || (*end) == '\n')) end--;

    *(end+1) = 0;

    return str;
}

void openFile(){
    int i = 0;
    int j = 0;
    FILE *inFile;
    char line[100];
    char * token;

    inFile = fopen("input.txt", "r");

    if(inFile){
        while(fgets(line,100, inFile) != NULL){
            trim(line);
            token = strtok(line, " ");
            input[i][j++] = string(trim(token));

            while((token = strtok(NULL, " ")))
                input[i][j++] = string(token);

            nCol = j;
            j = 0;
            nRow = ++i;
        }

        for (int i = 0; i < nCol; i++)
            cho[0][i] = input[0][i];
    }else
        cout<<"Error!!!"<<endl<<"Can't open input File."<<endl;

}

void countF(){
    int top;
    int flag;

    for (int i = 0; i < nCol; i++) {
        top = 1;
        for (int j = 1; j < nRow; j++) {

            flag = 1;
            for (int t = 1; t <= top; t++) {
                if(!input[j][i].compare(cho[t][i])){
                    count[t][i]++;
                    flag = 0;
                    break;
                }

            }

            if(flag == 1){
                count[top][i] = 1;
                cho[top][i] = input[j][i];
                top++;
            }
        }

    }

    cRow = top;
    totalX = nRow - 1;
    
}



void ginni(){
    double smallest;
    double temp;
    double gst = gstart();
    string root = cho[0][0];

    cout<<"G(start) = \t"<<gst<<endl;

    smallest = gX(0);
    for (int i = 0; i < nCol-1 ; i++) {
        temp = gX(i);
        cout<<"G("<<cho[0][i]<<") = \t"<<temp<<endl;

        if(temp<smallest){
            smallest = temp;
            root = cho[0][i];
        }

    }


    cout<<"\t======================\t"<<endl;
    cout<<"=\t                    \t="<<endl;
    cout<<"=\t The Root is : "<<root<< "\t="<<endl;
    cout<<"=\t                    \t="<<endl;
    cout<<"\t======================\t"<<endl;

    
}

double gstart(){
    int i = 0;
    double sum = 0;
    double gsT = 0;

    for (i = 1; count[i][nCol]; i++) {
        sum += count[i][nCol-1];
    }

    for (i = 1; i < count[i][nCol]; i++)
        gsT += pow((count[i][nCol-1] / sum), 2);

    gsT = 1 - gsT;
    
    return gsT;
}

double gX(int i){
    int temp = 0;
    double tempX = 0;
    double gxT = 0;

    for (int k = 1; cho[k][i] != "";k++) { //for a11, a12
        for (int j = 1; cho[j][nCol-1] != ""; j++) { //for c1, c2

            for (int t = 1; t < nRow; t++) {
                //cout<<cho[k][i]<<"-"<<input[t][i]<<"\t"<<cho[j][nCol-1]<<"-"<<input[t][nCol-1];
                if((cho[k][i] == input[t][i])&&(cho[j][nCol-1] == input[t][nCol-1])){
                    temp++;
                }
            }

            tempX += pow(temp, 2);
            temp = 0;
        }

        gxT += tempX / count[k][i];
        tempX = 0;
    }

    gxT = 1 - (gxT / totalX);


    return gxT;
}


void test(){
    for (int i = 0; i<nRow; i++) {
        if(i==1)
            cout<<"\t____________________________________________"<<endl;
        cout<<"\t";
        for (int j = 0; j<nCol; j++) {
            cout<<input[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<endl<<endl<<endl;

    for (int i = 0; cho[i][0] != ""; i++) {
        for (int j = 0; cho[i][j] != ""; j++) {
            cout<<cho[i][j]<<"-"<<count[i][j]<<",\t";
            cRow = j;
        }
        cout<<endl;
    }
}

int main(){
    openFile();
    countF();
    ginni();

    //test();

    return 0;
}
