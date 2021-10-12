
// problem : https://www.hackerrank.com/challenges/printing-pattern-2/problem
// solution : O(n²)====================================

/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 // O(n) function print pattren only need 
 // position => where increment & decrement should stop
 // range => range for make pattren for all 'n numbers' from 1 => n 
void generateRange(int n , int position , int range){
	// copy of N
    int N = n;
	
	// first loop from 1 to position 
    for(int l = 1; l <= position; l += 1){
        printf("%d ", N);
        N -= 1;
    }
    
	// update mid & n for next loop
    int mid = N;
    N = n;
    
	// next loop from position to next position
	// next position => is range - position
	// soo from position to (range - position) must be all the same int 
    for(int m = position ; m < (range - position) ; m += 1){
        printf("%d ", mid);        
    }
    
	// update mid for next loop
    mid += 1;
    
	// last loop from second position to the end of range
	// and this we should start += to the end of range
    for(int r = (range - position); r < range ; r += 1){
        //arr[r] = mid;
        printf("%d ", mid);        
        mid += 1;
    }
    
	// as last step new line for next line
    printf("\n");
}

int main(){

    int n;
    scanf("%d", &n);
    
	// range of n is (n + n - 1) that is soo important for making vaild block from 1 to => n
    int range = n+n-1;
	// mid_range => is a half range we need it for making the right block
    int mid_range = floor(range/2);
    	
	// O(n/2 * n)
	// first loop for first half of block we start from 0 going to half but +=
    for(int i = 0 ; i < mid_range ; i+= 1){
        generateRange(n,i,range); // o(n)
    }
	// O(n/2 * n)
	// second loop for second half we going from mid to end but in -=
    for(int i = mid_range ; i >= 0 ; i -= 1){
        generateRange(n,i,range); // o(n)
    }
    
    return 0;
}
*/

// ====================================================