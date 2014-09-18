#include<stdio.h>
#include<string.h>

void printRev(char str[10]){
   char temp;
   int i, j = 0;

   i = 0;
   j = strlen(str) - 1;

   while (i < j) {
      temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
   }
}


int main(){
   int i;
   int j;
   int k;
   int length;
   char input[500];
   char paresdInput[50][10];

   printf("Please enter your string: ");

   fgets(input, 499, stdin);
   length = strlen(input);

   j=0;
   k=0;
   for(i =0; i<length; i++){
      if(input[i] == ' ' || input[i] == '\n'){ 
         j++;
         k=0;
      }
      else{
         paresdInput[j][k++] = input[i];
      }
   }

   for(k=0; k<j; k++){
      printRev(paresdInput[k]);
      printf("%s ", paresdInput[k]);
   }

   printf("\n");
   return 0;
}
