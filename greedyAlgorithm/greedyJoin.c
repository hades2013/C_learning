#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
   
struct join 
{ 
  int begin; 
  int end; 
}; 
   
int compare(const void *a, const void *b); 
   
int main() 
{ 
  int i, n, k; 
  struct join joins[1001], temp[1001]; 
   
  while(scanf("%d", &n) != EOF) 
  { 
    for(i = 0; i < n; i ++) 
    { 
      scanf("%d %d", &joins[i].begin, &joins[i].end); 
    } 
       
    qsort(joins, n, sizeof(joins[0]), compare); 
   
    k = 0; 
    temp[k] = joins[0]; 
    for(i = 1; i < n; i ++) 
    { 
      if(joins[i].begin >= temp[k].end) 
        temp[++ k] = joins[i]; 
    } 
    printf("%d\n", k + 1); 
  } 
     
  return 0; 
} 
   
int compare(const void *a, const void *b) 
{ 
  const struct join *p = a; 
  const struct join *q = b; 
   
  return p->end - q->end; 
} 