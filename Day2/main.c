#include <stdio.h>
#include <stdlib.h>

int find_minimum(int a[], int n) {
  int c, min, index;
 
  min = a[0];
  index = 0;
 
  for (c = 1; c < n; c++) {
    if (a[c] < min) {
       index = c;
       min = a[c];
    }
  }
 
  return a[index];
}

int main(){
	int length=0, width=0, height=0;
	int totalPaper=0;
	int totalRibbon = 0;

	//2*l*w + 2*w*h + 2*h*l + (area of smallest side)
	while(scanf("%dx%dx%d",&length,&width,&height)==3){

		//Part I
		int arrayPaper[3] = {length*width, width*height, height*length};
		totalPaper += (2*arrayPaper[0] + 2*arrayPaper[1] + 2*arrayPaper[2] + find_minimum(arrayPaper,3));

		//Part II
		int arrayRibbon[3] = {2*length+2*width,2*length+2*height,2*width+2*height};
		totalRibbon += length*width*height + find_minimum(arrayRibbon,3);
	}

	printf("Part I: %d\nPart II: %d\n", totalPaper, totalRibbon);

	return 0;
}