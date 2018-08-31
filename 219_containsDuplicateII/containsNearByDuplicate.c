#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true,
}bool;
#define SIZE 1000  
struct HashArray
{
    int key;
    int count;
    struct HashArray* next;
}Hash[SIZE];      
int addHash(int num,int i)   
{
    int temp=abs(num%SIZE);    
    if(Hash[temp].count==0)
    {
        Hash[temp].key=num;
        Hash[temp].count=i;
        return 0;
    }else if(Hash[temp].key==num)
    {
        int temp1=Hash[temp].count;
        Hash[temp].count=i;
        return i-temp1; 
    }else
    {
        struct HashArray *p=&Hash[temp]; 
        while(p->key!=num&&p->next!=NULL)    
        {p=p->next;}
        if(p->key==num&&p->count!=0)
        {
            int temp1=p->count;
            p->count=i;
            return i-temp1;
        }
        else
        {
            p->next=(struct HashArray*)malloc(sizeof(struct HashArray));
            p=p->next;
            p->key=num;
            p->count=i;
            p->next=NULL;
            return 0;
        }
    }   
}
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
     if(numsSize<2){return false;}
    for(int i=0;i<SIZE;i++){
        Hash[i].key=0;
        Hash[i].count=0;
        Hash[i].next=NULL;   
    }
    int temp=0;
    for(int i=0;i<numsSize;i++){
        temp=addHash(nums[i],i+1);
        if(temp!=0&&temp<=k){return true;}
    }
    return false;
    
}

int main()
{
    int nums[] = {1, 2, 3, 1, 2, 3};
    int k = 2; 
    bool ret = true;
    ret = containsNearbyDuplicate(nums,6, k);
    printf("ture or false: %d", (int)ret);
}