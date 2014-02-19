#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
   int pid;
   int count;
   char ch;
   char *part;
   char input[100];
   char *args[20];

   printf("\t\tWelcome to me@My-PC\n\n");
   printf("Enter your input : ");

   while(1){

      count = 0;
      gets(input);

      part = strtok(input, " ");

      if(!strcmp(part, "exit")){
         args[0] = "exit";
         args[1] = NULL;
         execvp(args[0], args);
         break;
      }else if(input == " " || input == "\n"){
         continue;
      }

      while(part && count<20){
         args[count++] = part;
         part = strtok(NULL, " ");
      }

      args[count] = NULL;

      if(!strcmp(args[0], "cat") && !strcmp(args[1], ">")){
         FILE *newFile = fopen(args[2], "w+");
         while((ch=getchar())!='^'){
            putc(ch, newFile);
         }
         fclose(newFile);
      }else{
         pid = fork();
         if(!pid) execvp(args[0], args);
      }
   }
   return 0;
}
