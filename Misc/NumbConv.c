#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

char input[1000];
char bin[1000];
int dec;
char oct[10];
char hex[10];

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

int check(int it){ //Check if the input and selection is valid
    int i;
    for (i = 0; i < (int)strlen(input); i++) {
        if (it == 1){
            if(input[i]<'0' || input[i]>'9')
                return FALSE;
            
        }else if (it == 2) {

            if( (input[i] > 96 ) && (input[i] < 123) ) 
                input[i] = input[i] - 'a' + 'A';   //make upper

            if((input[i]<'0'||input[i]>'9') && (input[i]<'A'||input[i]>'F'))
                return FALSE;
        }else if (it == 3) {
            if(input[i]!='0' && input[i]!='1')
                return FALSE;
            
        }else if (it == 4) {
            if(input[i]<'0' || input[i]>'7')
                return FALSE;
            
        }else{
            printf("Please select a valid option\n");
            return FALSE;
        }
    }
    return TRUE;
}

void pO(){
    printf("Please select input type:\n");
    printf("1. Decimal\n");
    printf("2. Hexa Decimal\n");
    printf("3. Binary\n");
    printf("4. Octal\n");
}

char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}


void toBin(int it){
    int i;
    int j;
    int k=0;
    int x;
    int t;
    int temp;

    if(it == 1){
        dec = 0;
        strrev(input);

        for (i = 0; i < (int)strlen(input); i++) {
            x = 1;
            for (j = 1; j <= i; j++) {
                x *= 10;
                //printf("%d\n", x);
            }
            dec += (((int)input[i]-48) * x);
        }

        temp = dec;
        while(TRUE){
            for (i = 0; ; i++) {
                if(pow(2, i)> temp){
                    bin[i-1] = '1';
                    temp -= pow(2, (i-1));
                    break;
                }else
                    bin[i-1] = '0';
            }

            if(!temp)
                break;
        }

        printf("\n%d\n%s", dec, bin);
    
    }else if(it == 2){

        for (i = 0; i < (int)strlen(input); i++) {
            for (j = 3; j >= 0; j--) {
                x = pow(2,j);
                if(input[i]>= 'A' && input[i] <= 'F')
                    t = (int)input[i] - 55;
                else 
                    t = (int)input[i];

                if(t & x){
                    //printf("%d -> %d\n",x, (((int)input[i] - 30) & x));
                    bin[k++] = '1';
                }
                else
                    bin[k++] = '0';
            }
        }
        //strrev(bin);
    }
}

void toDec(){

}

void toOct(){

}




int main(){
    int it;
    
    pO();

    scanf("%d", &it);

    printf("Please input your number:\n");

    getchar();
    fgets(input, sizeof(input), stdin);
    trim(input);

    if(check(it))
        toBin(it);
    else
        printf("Your enterd numer is not valid");
    
    printf("%s\n", bin);

    return 0;
}
