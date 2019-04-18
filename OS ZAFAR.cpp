#include <stdio.h>
#include <stdlib.h>


int allocation[20][20],Max[20][20],available[10];
int Need[20][20];
int n,r;

void input(void )
{  
      int j,i;
    	
	printf("!!!!!ENTER THE NUMBER OF PROCESS!!!!!! : ");
    scanf("%d", &n);
    printf("\n\n\n !!!!!! ENTER THE NUMBER OF RESOURCES !!!!!!! : ");
    scanf("%d", &r);
    
    printf("\n\n!!!!!! ENTER THE MAX MATRIX FOR EACH PROCESS !!!!! : ");
    for(i = 0; i < n; i++)
    {
        printf("\nFOR PROCESS %d : ", i+1 );
        for(j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }

    printf("\n\n\n!!!!!! ENTER THE ALLOCATION MATRIX !!!!!! : ");
    for(i = 0; i < n; i++)
    {
        printf("\nFOR PROCESS %d : ",i+1);
        for(j = 0; j < r; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\n\n\n !!!!!! ENTER THE AVAILABLE RESOURCES !!!!!!!  : ");
    for(i = 0; i < r; i++)
        scanf("%d", &available[i]);	
}

void calculation(void )
{
	int i,j,count=0;
    int f[n], ans[n], ind = 0,k; 
    for (int k = 0; k < n; k++) { 
        f[k] = 0; 
    } 
     
    for (i = 0; i < n; i++) { 
        for (j = 0; j < r; j++) 
            Need[i][j] = Max[i][j] - allocation[i][j]; 
                    } 
                    
                    
    int y = 0; 
    for (k = 0; k < 5; k++) { 
        for (i = 0; i < n; i++) { 
            if (f[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < r; j++) { 
                    if (Need[i][j] > available[j]) 
                        flag = 1; 
                    break; 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    count++;
                    for (y = 0; y < r; y++) 
                        available[y] += allocation[i][y]; 
                    f[i] = 1; 
                } 
            } 
        } 
    } 
  if(count==n)
  {
  	printf("\n....YES,SYSTEM IS IN SAFE STATE..... ");
  
    printf("\n\n......FOLLOWING IS THE SAFE SEQUENCE.....\n"); 
    for (i = 0; i < n - 1; i++) 
        printf(" P%d ->", ans[i]); 
    printf(" P%d", ans[n - 1]); 
 }
 else
 {
 	printf("\n\t...NO,SYSTEM IS NOT IN SAFE STATE...");
 }
    
    
}
int main()
{
      input();
	  calculation();         
}
