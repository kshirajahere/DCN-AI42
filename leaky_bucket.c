#include<stdio.h>
int main(){
    int bucket_capacity,output_rate;
    int incoming,stored=0;
    int n,i;
    
    printf("enter bucket capacity:");
    scanf("%d",&bucket_capacity);
    
    printf("enter outgoing rate:");
    scanf("%d",&output_rate);
    
    printf("enter no of iterations:");
    scanf("%d",&n);
    
    for(i=1;i<=n;i++){
    printf("\n Iteration %d\n",i);
    printf("Enter number of incoming packets:");
    scanf("%d",&incoming);
    
    
    if(incoming+stored<=bucket_capacity){
       stored+=incoming;
    }else{
       int dropped=(incoming+stored)-bucket_capacity;
       stored=bucket_capacity;
       printf("Packets dropped:%d\n",dropped);
      }
       if(stored>=output_rate){
       printf("Packets sent:%d\n",output_rate);
       stored-=output_rate;
       }else{
         printf("Packets sent:%d\n",stored);
         stored=0;
        }
        printf("Packets remaining in bucket:%d\n",stored);
       }
       return 0;
 }
