
#include <stdio.h>
#define size 5
int findMax(int num[]);
 void printAr(int myAr[]) ;
void addone(int number[], int add[]); // fix size
void addtwo(int number[], int pos[], int x); //fix size
void addthree(int number[], int pos[][2], int k);//fix size
int main() {
	int number[5] = {20,50,100,99,9};
    int add[size] = {1,2,3,4,5};
    int pos[] = {1,3,5};
    int pos3[3][2] = {{1,5},{3,10},{5,-2}};
	int max;
    addone(number,add);
    printf("\n");
    addtwo(number,pos,5);
    printf("\n");
    addthree(number,pos3, 3);
	max = findMax(number);
    printAr(number);
	printf("Maximum of these number is %d\n",max);
}

int findMax(int num[]) {
	int maximum,i=0;
	maximum = num[i];

	for(i=0;i<5;i++) {
		if(num[i] > maximum)
			maximum = num[i];
	}
	return maximum;
}
 void printAr(int myAr[]) {
    for(int i = 0;i<size;i++){
        printf("%d ",myAr[i]);
    }
    printf("\n");
 }
void addone(int number[], int add[]){
    for(int i = 0;i<size;i++){
        number[i]+=add[i];
        printf("%d ",number[i]);
    }
} // fix size
void addtwo(int number[], int pos[], int x){
    for(int i =0;i<size;i++){
        for(int j =0;j<3;j++){
            if(i+1==pos[j]){
            number[i]+=x;;
        }
        }
        printf("%d ",number[i]);
    }
}
 //fix size
void addthree(int number[], int pos[][2], int k) {
    for (int i = 0; i < k; i++) {
        int p = pos[i][0];   
        int x = pos[i][1];   

        if (p >= 1 && p <= size) {
             printf("Add %d to number[%d]\n", x, p);
            number[p - 1] += x;   
        }
    }
}

/* result
number[1] : 20
number[2] : 50
number[3] : 100
number[4] : 99
number[5] : 9
Maximum of these number is 100
*/

