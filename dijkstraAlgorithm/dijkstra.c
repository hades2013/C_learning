#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 9 
#define INFINETY 65535

typedef int pathArc[MAXVEX]; 
typedef int shortPathTable[MAXVEX];

struct MGraph{
	int numVertexes;
	int *vex; 
	int arc[MAXVEX][MAXVEX]; 
}; 

void shortPathTable_Dijkstra(struct MGraph *g, int v0, int vv, pathArc *p, shortPathTable *d)
{
	int v, w, k, min; 
	int result[MAXVEX]; 

	int n = 0; 
	for(v = 0; v < g->numVertexes; ++v){
		result[v] = 0; 
		(*d)[v] = g->arc[v0][v];  //init node 
		(*d)[v] = -1;
	}
	(*d)[v0] = 0; 
	result[v0] = 1; 
	(*p)[n++] = v0; 

	for(v = 0; v < g->numVertexes; ++v){
		min = INFINETY;
		for(w = 0; w < g->numVertexes; ++w){
			if(!result[w] && (*d)[w] < min){
				k = w; 
				min = (*d)[w];
			}
		}
		result[k] = 1; 
		(*p)[n++] = k; 

		if(k == vv)
			break; 

		for(w = 0; w < g->numVertexes; ++ w){
			if(!result[w] && (min + g->arc[k][w] < (*d)[w])){
				(*d)[w] = min + g->arc[k][w];
				(*p)[w] = k; 
			}
		}
	}
	printf("\n"); // output the result 
	for(v = 0; v < g->numVertexes; ++v)
		printf("%d-->", (*p)[v]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	struct MGraph *mg = (struct MGraph *)malloc(sizeof(struct MGraph));
	int i, j, t = 0; 
	int v0 = 0, vv = 8; 

	mg->numVertexes = 9; 
	mg->vex = (int *)malloc(sizeof(char)* mg->numVertexes); 
	if(!mg->vex)
		return -1; 

	for(i = 0; i < mg->numVertexes; ++i)
		for(j = 0; j < mg->numVertexes; ++j)
			mg->arc[i][j] = INFINETY; 

	mg->arc[0][1] = 1; mg->arc[0][2] = 5;
	mg->arc[1][2] = 3; mg->arc[1][3] = 7; mg->arc[1][4] = 5;
	mg->arc[2][4] = 1; mg->arc[2][5] = 7;
	mg->arc[3][4] = 2; mg->arc[3][6] = 3;
	mg->arc[4][5] = 3; mg->arc[4][6] = 6; mg->arc[4][7] = 9; 
	mg->arc[5][7] = 5; 
	mg->arc[6][7] = 2; mg->arc[6][8] = 7; 
	mg->arc[7][8] = 4; 
	
	for( i =0; i < mg->numVertexes; ++i){
		for(j = 0; j <= i; ++j){
			if(i == j){
				mg->arc[i][j] = 0;
				continue;
			}
			mg->arc[i][j] = mg->arc[j][i];
		}
	}

	for(i = 0; i < mg->numVertexes; ++i){
		for(j = 0; j < mg->numVertexes; ++j)
			printf("%5d  ", mg->arc[i][j]);
		printf("\n");
	}
	printf("\n");

	pathArc p; 
	shortPathTable d; 
	shortPathTable_Dijkstra(mg, v0, vv, &p, &d);
	free(mg->vex);
	return 0;
}