#include<stdio.h>

int main(){
	int i =30,j=0;
if(j ==0){
	while(1){
		while(i--);           //thread synchronization  atomic variables 1) semaphores 2) mutex
		printf("here\n");

	}
}
else
{


	while(1){
		while(i==0);
		printf("nowhere\n");
		i=30;


}



}
