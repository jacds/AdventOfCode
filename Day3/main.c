#include <stdio.h>
#include <stdlib.h>

int** houses_presentedPartI;
int** houses_presentedPartII;
int sizePartI, sizePartII;

int check_presented(int pos[],int type){
	int i;

	if(type==1){
		for(i=0;i<sizePartI;i++){
			if(pos[0]==houses_presentedPartI[i][0] && pos[1]==houses_presentedPartI[i][1]){
				return 1;
			}
		}
	}
	else{
		for(i=0;i<sizePartII;i++){
			if(pos[0]==houses_presentedPartII[i][0] && pos[1]==houses_presentedPartII[i][1]){
				return 1;
			}
		}		
	}	
	return 0;
}

int main(){
	char c;

	//Part I
	sizePartI = 1;
	int PosActual[2] = {0,0};

	houses_presentedPartI = (int**) malloc(sizePartI*sizeof(int*));
	houses_presentedPartI[0] = (int*) malloc(2*sizeof(int));
	houses_presentedPartI[0][0] = 0;
	houses_presentedPartI[0][1] = 0;

	//Part II
	sizePartII=1;
	int Santa = 1; //If Santa=1, then Santa makes the delivery. If 0, then the robot does.
	int PosSanta[2] = {0,0};
	int PosRobot[2] = {0,0};

	houses_presentedPartII = (int**) malloc(sizePartII*sizeof(int*));
	houses_presentedPartII[0] = (int*) malloc(2*sizeof(int));
	houses_presentedPartII[0][0] = 0;
	houses_presentedPartII[0][1] = 0;
	

	while(scanf("%c",&c) && c!='\n'){		

		//Part I
		if(c == '^'){
			PosActual[1]++;
		}
		else if(c == '>'){
			PosActual[0]++;
		}
		else if(c == 'v'){
			PosActual[1]--;
		}
		else if(c == '<'){
			PosActual[0]--;
		}

		if(!check_presented(PosActual,1)){
			sizePartI++;
			houses_presentedPartI = (int**) realloc(houses_presentedPartI, sizePartI*sizeof(int*));

			houses_presentedPartI[sizePartI-1] = (int*) malloc(2*sizeof(int));
			houses_presentedPartI[sizePartI-1][0] = PosActual[0];
			houses_presentedPartI[sizePartI-1][1] = PosActual[1];
		}

		//Part II
		if(c == '^'){
			if(Santa)
				PosSanta[1]++;
			else
				PosRobot[1]++;
		}
		else if(c == '>'){
			if(Santa)
				PosSanta[0]++;
			else
				PosRobot[0]++;
		}
		else if(c == 'v'){
			if(Santa)
				PosSanta[1]--;
			else
				PosRobot[1]--;
		}
		else if(c == '<'){
			if(Santa)
				PosSanta[0]--;
			else
				PosRobot[0]--;
		}

		if(Santa){
			if(!check_presented(PosSanta,0)){
				sizePartII++;
				houses_presentedPartII = (int**) realloc(houses_presentedPartII, sizePartII*sizeof(int*));

				houses_presentedPartII[sizePartII-1] = (int*) malloc(2*sizeof(int));
				houses_presentedPartII[sizePartII-1][0] = PosSanta[0];
				houses_presentedPartII[sizePartII-1][1] = PosSanta[1];
			}
		}
		else{
			if(!check_presented(PosRobot,0)){
				sizePartII++;
				houses_presentedPartII = (int**) realloc(houses_presentedPartII, sizePartII*sizeof(int*));

				houses_presentedPartII[sizePartII-1] = (int*) malloc(2*sizeof(int));
				houses_presentedPartII[sizePartII-1][0] = PosRobot[0];
				houses_presentedPartII[sizePartII-1][1] = PosRobot[1];
			}
		}

		Santa = (Santa+1)%2;
	}

	printf("Part I: %d\nPart II: %d\n", sizePartI,sizePartII);

	free(houses_presentedPartII);
	free(houses_presentedPartI);
	return 0;
}