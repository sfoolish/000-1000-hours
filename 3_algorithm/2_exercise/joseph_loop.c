#include <stdio.h>
#include <stdlib.h>
/*#define MAX_SDUDENTS 20;用这个宏定义数组大小时出现
*expected ']' before ';' token
*expected expression before ']' token
*/
/*
*run first time :segmentation fault
*gdb -> 59 pre_tmp->next = tmp
*/

typedef struct l_node
{
	int number;
	int key;
	struct l_node *next;
}l_node, *list, *p_l_node;
list init_list(int *key);
void joseph(list head, int m);

int main()
{
	int m = 20;
	int key[20] = {3, 1, 7, 2, 4, 8, 4};
	list head;
	
	head = init_list(key);
	joseph(head, m);
	head = NULL;
	return 0;
}

list init_list(int *key)
{
	int i = 1;
	p_l_node head;
	p_l_node tmp;
	p_l_node pre_tmp;
	while (*key != 0)
	{	
		if (i == 1)
		{
			tmp = (p_l_node)malloc(sizeof(l_node));
			if (tmp == NULL)
				return NULL;
			else
			{
				head = tmp;
				pre_tmp = tmp;
			}	
		}
		else
		{
			pre_tmp = tmp;
			tmp = (p_l_node)malloc(sizeof(l_node));
			if (tmp == NULL)
				return NULL;
		}

		tmp->number = i;
		tmp->key = *key;
		tmp->next = NULL;
		pre_tmp->next = tmp;
		i++;
		key++;	
	}
	tmp->next = head;
	return head;
}

void joseph(list head, int m)
{
	int i;
	p_l_node cur_node = head;
	p_l_node del_node;
	while ((cur_node->next != cur_node) && (NULL != cur_node))
	{
		for (i = 1; i < m; i++)
			cur_node = cur_node->next;
		del_node = cur_node->next;
		cur_node = del_node->next;
		printf("%d\t", del_node->number);
		free(del_node);				
	}
	if(NULL != cur_node)
	{
		printf("%d\t", cur_node->number);
		free(cur_node);
	}
}
