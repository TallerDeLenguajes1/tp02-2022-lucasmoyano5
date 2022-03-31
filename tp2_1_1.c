
#include<stdio.h>
#include<ctime.h>
#include<iostream.h>
#include<cstdlib.h>

#define N 20

int main(){
             int i;
             double vt[N];
…
             for(i = 0;i<N; i++)
             {
                 vt[i]=1+rand()%100;
                 printf("%d ", vt[i]);
             }


    return 0;
}

