#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int         data;
    struct node *l_child;
    struct node *r_child;
}node_t, *bitree;

node_t *init_node(int data)
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

void dump_node(node_t *node)
{
    if(node == NULL) {
        return;
    }

    printf("%d\n", node->data);
}

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


node_t *search_bitree(bitree root, int key)
{
    node_t *current = root;
    node_t *parent = NULL;

    while ((current != NULL) && (current->data != key)) {
        if (current->data > key) {
            parent = current;
            current = current->l_child;
        } else {
            parent = current;
            current = current->r_child;
        }
    }

    return ((current == NULL) ? parent : current);
}

bitree create_bitree(int *arr)
{
    int temp;
    bitree root = NULL;
    node_t *insert_des = NULL;
    node_t *node;

    if(arr == NULL) {
        return NULL;
    }

    temp = *arr++;
    if (temp != 0) {
        root = init_node(temp);
    } else {
        return NULL;
    }

    do {
        temp = *arr++;
        if (temp != 0) {
            insert_des = search_bitree(root, temp);
            if (insert_des->data != temp) {
                printf("parent node data : %d\t", insert_des->data);
                node = init_node(temp);    //TODO 返回值处理
                if (insert_des->data > temp) {
                    printf("left\n");
                    insert_des->l_child = node;
                } else {
                    printf("right\n");
                    insert_des->r_child = node;
                }
            }
        }
    } while(temp != 0);                     //TODO 测试数组中不含0就会越界

    return root;
}

void destroy_bitree(bitree root)
{
    inorder_bitree(root, free_node);
}


int main(int argc, char *argv[])
{
    bitree root;
    int arr[20] = {
        29, 23, 45, 16, 18,
        17, 34, 38, 24, 19,
        0
    };

    root = create_bitree(arr);             // 构建顺序二叉树遇到 0 结束
    printf("/******************************************/\n");
    inorder_bitree(root, dump_node);       // 中序遍历二叉树
    printf("/******************************************/\n");
    destroy_bitree(root);                  // 中序遍历释放内存
    
    return 0;
}
