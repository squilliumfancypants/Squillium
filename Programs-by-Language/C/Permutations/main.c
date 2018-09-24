//This program calculates permutations of r groups from n objects

#include<stdio.h>

#define MAX 9

//-----------------------------------------------------------------  Toolkit Declarations ---------------------------------------------------------------------------------
void SkipGarb();

//-----------------------------------------------------------------  Function Declarations ---------------------------------------------------------------------------------
int Permutations(int n,int r);

int Factorial(int n);

void LexicographicalOrderPrint(int n, int r);

int main() {
    int n, r;
   
    do{
        scanf("%d",&n);
       
        SkipGarb();
       
        scanf("%d",&r);
       
        SkipGarb();
       
    }while(n > MAX);
   
    //int aSize;
   
    //aSize = Permutations(n, r);
   
    //int array[aSize];
   
    LexicographicalOrderPrint(n, r);
}

//-----------------------------------------------------------------  Toolkit Definitions ---------------------------------------------------------------------------------
void SkipGarb(){
    while (getchar()!='\n'){
       
    }
}

//-----------------------------------------------------------------  Function Definitions ---------------------------------------------------------------------------------
int Permutations(int n, int r){
   
    int permNum;
	
	if (n!=r){
		permNum = (Factorial(n))/(Factorial(n - r));
	}
	
	else{
		permNum = (Factorial(n));
	}
   
    return permNum;
}

int Factorial(int n){
   
    if (n == 1){
        return 1;
    }
   
    else{
        return n*Factorial(n - 1);
    }
}

void LexicographicalOrderPrint(int n, int r){
	
	//as of 7/11/2018, this function only works correctly for P(n, n)
	//subsets must be implemented in order to calculate P(n, r)
    int perms = Permutations(n, r);
   
	int count = 0;
   
    int array[n];
    //int permArray[perms];
   
    for (int i = 0; i < n; i++){
        array[i] = i;
    }
	
   
    //print first permutation
    for (int i = 0; i < n; i++){
        printf("%d", array[i]);
    }
	count++;
	
    putchar('\n');
	int temp;
	int j, k;
    //Make new permutations, ordered alphabetically. To see if the permutations are new, check if new by comparing to permArray
	for (int i = 1; i < perms; i++){
		j = n - 2;
		k = n - 1;
		
		
		//find first value not in increasing order, starting from the right
		while (array[j] > array[k]){
			j--;
			k--;
		}
		
		k = n - 1;
		
		//find smallest value larger than array[k]
		while (array[j] > array[k]){
			k--;
		}
		
		//swap values of array[j] and array[k]
		temp = array[j];
		array[j] = array[k];
		array[k] = temp;
		
		//reverse digits to the right of the index
		j++;
		k = n - 1;
		
		while (j < k){
			temp = array[j];
			array[j] = array[k];
			array[k] = temp;
			j++;
			k--;
		}
		
		for (int l = 0; l < n; l++){
			printf("%d", array[l]);
			
		}
		putchar('\n');
		count++;
	}
	printf("%d", count);
}


