#include <stdio.h>
#include <stdlib.h>

int main(){
	int i=0;
	int counter = 0;
	int basement=0;
	int first_char_to_basement=0;
	char elem;
	
	while(scanf("%c",&elem) == 1){
		//Part I
		if(elem=='('){
			counter++;
		}
		else if(elem==')'){
			counter--;
		}

		//Part II
		if(counter==-1 && basement==0){
			basement=1;
			first_char_to_basement = i+1;
		}
		else{
			i++;
		}
	}

	printf("Part I: %d\nPart II: %d\n", counter, first_char_to_basement);

	return 0;
}