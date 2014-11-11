#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int slNo =1;
int vSl = 1;
int lnNo = 1;
char *token;
char temp[1000];
int typeCount;

char *bType[100] = {"int", "char", "float", "double", "short","long", "FILE"};
char *clYpye[100] = {"if", "else if", "while", "for", "switch", "else"};
char var[100][3][30];

//==============================
//Misc functions
//==============================
int belongsTo(char *value, char *group[5], int gs){
    int i = 0;

    for(i=0; i<gs; i++){
        if(!strcmp(value, group[i]))
            return 1;
    }

    return 0;
}

int exists(char *str, char sy){
    unsigned i;
    for(i=0; i<strlen(str); i++){
        if(*(str+i) == sy)
            return 1;
    }
    return 0;
}

void printTable(){
    printf("SL No. \t Name \t\t S.Name \t Type\n");
    printf("_____________________________________________\n");
    int i = 1;
    while(strlen(var[i][2]) >= 2){
        if(strlen(var[i][0])<=5)
            printf("%d \t %s \t\t %s \t\t %s \n",i, var[i][0], var[i][1], var[i][2]);
        else
            printf("%d \t %s \t %s \t\t %s \n",i, var[i][0], var[i][1], var[i][2]);
        i++;
    }
}

char *trim(char *str){
    char *end;

    while((*str) == ' ' || (*str) == '\t') str++;

    if(*str == 0)  
        return str;

    end = str + strlen(str) - 1;
    while(end > str && ((*end) == ' ' || (*end) == '\n' || (*end) == ';')) end--;

    *(end+1) = 0;

    return str;
}

//==============================
//Find if statement is a header 
//==============================
int incLib(char buf[1000]){
    strcpy(temp, buf);
    token = strtok(temp, "<");

    if(!strcmp(token, "#include")){
        token = strtok(NULL, ">");
        printf("%d[%d]. Include Library -> %s \n", slNo++, lnNo, token);
        return 1;
    }else{
        return 0;
    }
}

//==============================
//Find if statement is method d
//==============================
int decMethod(char buf[1000]){
    strcpy(temp, buf);

    if(exists(temp, '(')){
        char *rt;
        char *name;
        char *perm;

        rt = strtok(temp, " ");
        name = strtok(NULL, "(");
        perm = strtok(NULL, ")");

        if(!strcmp(perm, "\n"))
            perm = (char*)"EMPTY";

        printf("%d[%d]. Declaration of \"%s\" function with \"%s\" return type and \"%s\" perm \n",slNo++, lnNo, name, rt, perm);
        return 1;
    }else
        return 0;
}

//==============================
//Find if statement is var d
//==============================
int decVar(char buf[1000]){
    char *type;
    char *c = (char*)",";
    if(exists(buf, '='))
        c = (char*)"=";

    strcpy(temp, buf);
    type = strtok(temp, " ");

    while((token = strtok(NULL, c)) != NULL){
        if(strcmp(token, "\n")){ //ignoring \n at the end the of the line
            //token = strtok(token, ";"); //canceling out ; if it's the end
            printf("%d[%d]. Variable declaration, Name: \"%s\"\tVariable Type: \"%s\" \n",slNo++, lnNo, trim(token), trim(type));
            strcpy(var[vSl][0], trim(token));
            strcpy(var[vSl][1] , "id");
            strcpy(var[vSl][2], trim(type));
            sprintf(var[vSl][1], "%s%d", var[vSl][1], vSl);
            vSl++;
        }
        if(!strcmp(c, "="))
            return 1; //when there is an assignemnt related
    }
    return 0;
}

void decnAsgn(char buf[1000]){
    char *token;
    token = strtok(buf, "=");
    token = strtok(NULL, ";");

    printf("--\t\"%s\" is assigned to the declared variable\n", trim(token));
}


int main(){
    char buf[1000];
    FILE *ptr_file;
    typeCount = 7;

    ptr_file =fopen("Lexar.c","r");
    if (!ptr_file)
        return 1;

    while (fgets(buf,1000, ptr_file)!=NULL) {
        trim(buf);
        if((*(buf)=='/' && *(buf+1)=='/') || !strcmp(buf,"\n")){
            printf("%d[%d]. ---- empty line or comment \n", slNo++, lnNo);
        }else  if ((!strcmp(buf, "}\n")) || (!strcmp(trim(buf), "}"))){
            printf("%d[%d]. ____ Closing curly bracket.\n\n", slNo++, lnNo);
        }else{
            if(!incLib(buf)){ // if the statement is not header
                strcpy(temp, buf);
                token = strtok(temp, ";");
                token = strtok(token, " ");

                // Methods and var
                if(!strcmp(token, "struct")){
                    token = strtok(NULL, "{");
                    printf("%d[%d]. Declaring Structure \"%s\" \n",slNo++, lnNo, token);
                    bType[typeCount++] = token;
                }else if(belongsTo(token, bType, typeCount)){
                    strcpy(temp, buf);
                    if(!decMethod(temp)){
                        strcpy(temp, buf);
                        if(decVar(temp)) //if assigned with declaration
                            decnAsgn(buf);
                        //printf("%d[%d]. Are Variable \n", slNo++, lnNo);
                    }
                }else{ 
                    while((*token) == '}') token++;

                    if(belongsTo(token = strtok(token, "("), clYpye, 6)){
                        printf("%d[%d]. Conditional Logic \"%s\"\n", slNo++, lnNo, token);
                    }else if(!strcmp(token, "return")){
                        printf("%d[%d]. End of function \n", slNo++, lnNo);
                    }else{
                        printf("%d[%d]. Function call for \"%s\"\n", slNo++, lnNo, token);
                    }
                }
            }
        }
        lnNo++;
    }

    fclose(ptr_file);

    printf("==============================\n\n\n");

    printTable();
    return 0;
}
