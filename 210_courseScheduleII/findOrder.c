#include <stdio.h>
#include <stdlib.h>


typedef enum {
    false,
    true,
}bool;
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct dependentNode {
    int dependentCourse;
    struct dependentNode* next;
}dependentNode;

typedef struct dependentTable {
    dependentNode** table;   //table[i] is a linked list of courses that depend on course i
    int numOfCourses;
}dependentTable;

void initDependTable(dependentTable* t, int n);
void freeLinkList(dependentNode* head);
void deinitDependTable(dependentTable* t);
void pushDependTable(dependentTable* t, int courseIdx, int dependentCourseIdx);

typedef struct dependedNode {
    int* listOfDependedCourse;
    int numDependedCourses;
}dependedNode;
typedef struct dependedTable {
    dependedNode* table;   //table[i] is an array of courses that course i depends on
    int numOfCourses;
}dependedTable;

void initDependedTable(dependedTable* t, int n);
void deinitDependedTable(dependedTable* t);
void pushDependedTable(dependedTable* t, int courseIdx, int dependedCourseIdx);
void removeDependedTable(dependedTable* t, int courseIdx, int dependedCourseIdx);
bool isCourseAvailable(dependedTable* t, int courseIdx);

int constructTwoTables(int* result, int numCourses, int** prerequisites, int prerequisitesRowSize, dependentTable* dTable, dependedTable* pTable);

int* findOrder(int numCourses, int** prerequisites, int prerequisitesRowSize, int *prerequisitesColSizes, int* returnSize) {
     if(numCourses == 0)
    {
        *returnSize = 0;
        return(NULL);
    }
    int* result = (int*)malloc(sizeof(int)*numCourses);
    if(prerequisites == NULL || prerequisitesRowSize == 0)
    {
        for(int i = 0; i<numCourses; i++)
            result[i] = i;
        *returnSize = numCourses;
        return(result);
    }
    dependentTable dTable;
    dependedTable pTable;
    initDependTable(&dTable, numCourses);
    initDependedTable(&pTable, numCourses);
    int freeCourseCnt = constructTwoTables(result, numCourses, prerequisites, prerequisitesRowSize, &dTable, &pTable);
//printf("freeCourseCnt = %d\n", freeCourseCnt);    
    if(freeCourseCnt == 0)
    {
        free(result);
        deinitDependTable(&dTable);
        deinitDependedTable(&pTable);
        *returnSize = 0;
        return(NULL);
    }
    for(int i =0; i<freeCourseCnt; i++)
    {
        int freeCourseIdx = result[i];
//printf("freeCourseCnt = %d, freeCourseIdx = %d\n", freeCourseCnt, freeCourseIdx);         
        //tranverse list: dTable.table[freeCourseIdx]  //type: dependentNode*
        dependentNode* tempPtr = dTable.table[freeCourseIdx];
        while(tempPtr != NULL)
        {
            int dependentCourseIdx = tempPtr->dependentCourse;
            removeDependedTable(&pTable, dependentCourseIdx, freeCourseIdx);
            if( isCourseAvailable(&pTable, dependentCourseIdx) )
            {
                result[freeCourseCnt] = dependentCourseIdx;
                freeCourseCnt++;
            }
            tempPtr = tempPtr->next;
        }
        //during the loop, we also will update the freeCourseCnt
    }
    deinitDependTable(&dTable);
    deinitDependedTable(&pTable);
    if(freeCourseCnt != numCourses)
    {
        free(result);
        *returnSize = 0;
        return(NULL);
    }
    *returnSize = numCourses;
    return(result);
}


void initDependTable(dependentTable* t, int n)
{ //assume that n > 0, t!= NULL
    t->numOfCourses = n;
    t->table = (dependentNode**)malloc(sizeof(dependentNode*)*n);
    for(int i = 0; i<n; i++)
    {
        t->table[i] = NULL;
    }
    return;
}
void freeLinkList(dependentNode* head)
{
    while(head != NULL)
    {
        dependentNode* next = head->next;
        free(head);
        head = next;
    }
    return;
}
void deinitDependTable(dependentTable* t)
{
    for(int i = 0; i<t->numOfCourses; i++)
    {
        freeLinkList(t->table[i]);
    }
    free(t->table);
    t->numOfCourses = 0;
    return;
}
void pushDependTable(dependentTable* t, int courseIdx, int dependentCourseIdx)
{
    dependentNode* newNode = (dependentNode*)malloc(sizeof(dependentNode));
    newNode->dependentCourse = dependentCourseIdx;
    newNode->next = NULL;
    if(t->table[courseIdx] == NULL)
    {
        t->table[courseIdx] = newNode;
        return;
    }
    dependentNode* head = t->table[courseIdx];
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    return;
}

void initDependedTable(dependedTable* t, int n)
{
    t->numOfCourses = n;
    t->table = (dependedNode*)malloc(sizeof(dependedNode)*n);
    for(int i = 0; i<n; i++)
    {
        t->table[i].listOfDependedCourse = NULL;
        t->table[i].numDependedCourses = 0;
    }
    return;
}

void deinitDependedTable(dependedTable* t)
{
   for(int i = 0; i<t->numOfCourses; i++)
   {
       if(t->table[i].listOfDependedCourse != NULL)
            free(t->table[i].listOfDependedCourse);
   }
   free(t->table);
   t->table = NULL;
   t->numOfCourses = 0;
   return;
}
void pushDependedTable(dependedTable* t, int courseIdx, int dependedCourseIdx)
{
    t->table[courseIdx].numDependedCourses += 1;
    return;
}
void removeDependedTable(dependedTable* t, int courseIdx, int dependedCourseIdx)
{
    t->table[courseIdx].numDependedCourses -= 1;
    return;
}
bool isCourseAvailable(dependedTable* t, int courseIdx)
{
    return( t->table[courseIdx].numDependedCourses <= 0);
}

int constructTwoTables(int* result, int numCourses, int** prerequisites, int prerequisitesRowSize, dependentTable* dTable, dependedTable* pTable)
{
    for(int i = 0; i<prerequisitesRowSize; i++)
    {
        int preReqCourse = prerequisites[i][1];
        int dependentCourse = prerequisites[i][0];
        pushDependTable(dTable, preReqCourse, dependentCourse);
        pushDependedTable(pTable, dependentCourse, preReqCourse);
    }
    int freeCourseCnt = 0;
    for(int i =0; i<numCourses; i++)
    {
        if(pTable->table[i].numDependedCourses == 0)
        {
            result[freeCourseCnt] = i;
            freeCourseCnt++;
        }
    }
    return(freeCourseCnt);
}

int main(void)
{
    int i, course_num = 3, pair_num = 1;
    int **pairs = malloc(pair_num * sizeof(int *));
    pairs[0] = malloc(2 * sizeof(int));
    pairs[0][0] = 1;
    pairs[0][1] = 0;
    //pairs[1] = malloc(2 * sizeof(int));
    //pairs[1][0] = 2;
    //pairs[1][1] = 1;
    //pairs[2] = malloc(2 * sizeof(int));
    //pairs[2][0] = 3;
    //pairs[2][1] = 2;
    //pairs[3] = malloc(2 * sizeof(int));
    //pairs[3][0] = 4;
    //pairs[3][1] = 0;
    //pairs[4] = malloc(2 * sizeof(int));
    //pairs[4][0] = 0;
    //pairs[4][1] = 5;

    int count = 0;
    int *ids = findOrder(course_num, pairs, pair_num, 2, &count);
    for (i = 0; i < count; i++) {
        printf("%d ", ids[i]);
    }
    printf("\n");
    return 0;
}