
#define MAX 100

typedef int data_t;//这样定义的目的是为了代码便于维护，如果下次表中数据类型为char，修改比较方便；
typedef struct {
	data_t	data[MAX];
	int	last; 	/* pointer to the position 
			 * in the array 'data' where 
			 * stores the last element of
			 * the list
			 */
} seqlist_t;
