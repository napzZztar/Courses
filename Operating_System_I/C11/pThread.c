#include <pthread.h>
#include <stdio.h>

int sum;
void *runner(void *param);

int main(){
   int i =10;
   int *j = &i;
   pthread_t tid;
   pthread_attr_t attr;

//   pthread_attr_inti(attr);

   pthread_create(&tid, &attr, runner,(void *)&i);
   pthread_join(tid, NULL);

   wait(tid, NULL);
   printf("EOT, sum = %d\n",  sum);

}

void *runner(void *param){
   int x = *((int *) param);
   printf("Inside thread, i = %d\n", x);
   sum = 3
   pthread_exit(0);
   
}
