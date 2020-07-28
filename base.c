#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void){
    int n;
    scanf("%d",&n);

    int v[n];

    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }

    bool print = false;

    for(int i = 0; i < n; i++){
        
        if(v[i] || i == n - 1){
            print = true;
            printf("%d",v[i]);
        }else{
            if(print){
                printf("%d",v[i]);
            }
        }
    }
    printf("\n");

    return 0;
}