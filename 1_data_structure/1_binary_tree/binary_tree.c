#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int			data;
	struct node *l_child;
	struct node *r_child;
}node_t, *bitree;

node_t* creat_node(int data);
void free_node(node_t *node);
bitree creat_tree(int *arr);
void destroy_tree(bitree);
node_t* search(bitree root, int key);
void print_data(node_t *node);
void inorder_bitree(bitree root, void (*visit)(node_t *node));

int main(int argc, char *argv[])
{
	bitree root;
	int arr[20] = {
		29, 23, 45, 16, 18,
		17, 34, 38, 24, 19,
		0
	};

	root = creat_tree(arr);				// 构建顺序二叉树遇到 0 结束
	printf("/******************************************/\n");
	inorder_bitree(root, print_data);	// 中序遍历二叉树
	printf("/******************************************/\n");
	destroy_tree(root);					// 中序遍历释放内存
	
	return 0;
}

#if 0
void inorder_bitree(bitree root, void (*visit)(node_t *node))
{
	if (root != NULL) {
		printf("root");
		(*visit)(root);
		printf("left");
		inorder_bitree(root->l_child, visit);
		printf("right");
		inorder_bitree(root->r_child, visit);
	}
}
#endif

/*
 * 上面的函数有个bug 当visit函数释放root节点的时候会出错
 * 但gcc编译后，实际运行的时候没有遇到什么问题，主要应该是释放掉的内存
 * 还没被使用。
 */
void inorder_bitree(bitree root, void (*visit)(node_t *node))
{
	bitree l;
	bitree r;

	if (root == NULL) {
		return;
	}
	
	l = root->l_child;
	r = root->r_child;
	(*visit)(root);
	inorder_bitree(l, visit);
	inorder_bitree(r, visit);
}

bitree creat_tree(int *arr)
{
	int temp;
	bitree root = NULL;
	node_t *insert_des = NULL;
	node_t *node;

	if(arr == NULL) {
		return NULL;
	}

	temp = *arr;
	arr++;
	if (temp != 0) {
		root = creat_node(temp);
	} else {
		return NULL;
	}

	do {
		temp = *arr;
		arr++;
		if (temp != 0) {
			insert_des = search(root, temp);
			if (insert_des->data != temp) {
				printf("parent node data : %d\t", insert_des->data);
				node = creat_node(temp);	//TODO 返回值处理
				if (insert_des->data > temp) {
					printf("left\n");
					insert_des->l_child = node;
				} else {
					printf("right\n");
					insert_des->r_child = node;
				}
			}
		}
	} while(temp != 0);						//TODO 测试数组中不含0就会越界

	return root;
}

void destroy_tree(bitree root)
{
	inorder_bitree(root, free_node);
}

node_t *search(bitree root, int key)
{
	node_t *tem_node = root;
	node_t *p_node = NULL;

	while ((tem_node != NULL) && (tem_node->data != key)) {
		if (tem_node->data > key) {
			p_node = tem_node;
			tem_node = tem_node->l_child;
		} else {
			p_node = tem_node;
			tem_node = tem_node->r_child;
		}
	}

	/* if (tem_node->data == key)	//segmentation fault */
	if(tem_node == NULL)			//tem_node为空着key不存在，返回父节点
	{
		return p_node;
	} else {
		return tem_node; 
	}
}	

node_t *creat_node(int data)
{
	node_t *node;

	node = (node_t *)malloc(sizeof(node_t));
	if (node == NULL) {
		printf("create node error !\n");
		return node;
	}

	node->data = data;
	node->l_child = NULL;
	node->r_child = NULL;
	
	return node;
}

void free_node(node_t *node)
{
	if (node == NULL) {
		return;
	}

	printf("free node data: %d\n", node->data);
	free(node);
}

void print_data(node_t *node)
{
	if(node == NULL) {
		return;
	}

	printf("%d\n", node->data);
}
