#include <stdio.h>
#include <stdlib.h>

struct list
{
	int data;
	struct list *next;
};

struct list *g_list = NULL;

int list_init(struct list** root, int num)
{
	int i;
	struct list* cur = NULL;
	struct list* prv = NULL;

	if (*root != NULL) {
		printf("init faild root is not null\n");
		return -1;
	}

	if (num < 1) {
		printf("illegal num %d\n", num);
		return -1;
	}

	for (i = 0; i < num; i++) {
		cur = (struct list *)malloc(sizeof(struct list));
		if (!cur) {
			printf("malloc error\n");//tmp TODO
			return -1;
		}
		cur->data = i;
		cur->next = NULL;

		if (prv == NULL) {
			*root = prv = cur;
		}
		else
		{
			prv->next = cur;
			prv = cur;
		}
	}

	return 0;
}

int list_dump(struct list* root)
{
	struct list* cur = root;

	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}

	return 0;
}

int list_reserve(struct list** root)
{
	struct list* cur = *root;
	struct list* next = NULL;
	struct list* tmp = NULL;

	if ((*root == NULL) || (*root)->next == NULL) {
		return 0;
	}

	next = (*root)->next;
	(*root)->next = NULL;
	cur = next;
	while ((cur != NULL) && (cur->next != NULL)) {
		tmp = cur;
		next = cur->next;
		tmp->next = *root;
		*root = tmp;
		cur = next;
	}
	cur->next = *root;
	*root = cur;

	return 0;
}

int main()
{
	list_init(&g_list, 10);
	list_dump(g_list);
	list_reserve(&g_list);
	list_dump(g_list);
	list_reserve(&g_list);
	list_dump(g_list);
	return 0;
}

