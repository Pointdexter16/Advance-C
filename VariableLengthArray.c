#include <inttypes.h>
#include <stdio.h>
#include <alloca.h>

int main(){
	//Warning don't initialize large arrays on stack as it is small and limited use malloc
	//or heap memory calls instead alloca allocates memory on stack 
 	int Length=100;
	int *a=(int *)alloca(Length*sizeof(int));
	for(int i=0;i<Length;i++){
		a[i]=i;
	}
	for(int i=0;i<Length;i++){
		printf("%d\n",a[i]);
	}	
	return 0;
}
