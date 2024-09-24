#include <stdio.h>
#include <stdlib.h>

const int tri(int *p, int n) {
    p[0] = 0; 
    p[1] = 1;  
    p[2] = 1; 

    for (int i = 3; i <= n; i++) {
        int next = p[0] + p[1] + p[2];
        p[0] = p[1];
        p[1] = p[2]; 
        p[2] = next;
    }
    
    return p[2];
}


int main(){
    int n;
    scanf("%d", &n);
    int nums[3];
    printf("%d", tri(nums, n));
    return 0;
}