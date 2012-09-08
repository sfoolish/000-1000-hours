#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int         data;
    struct node *l_child;
    struct node *r_child;
}node_t, *bitree;

#define ARRY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void destroy_bitree(bitree root);

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

bitree create_bitree(int *arr, int size)
{
    int data           = 0;
    bitree root        = NULL;
    node_t *insert_des = NULL;
    node_t *node       = NULL;
    int i              = 0;

    if((arr == NULL) || (size <= 0)) {
        return NULL;
    }

    for (i = 0; i < size; ++i)
    {
        if ((data = arr[i]) == 0) {
            break;
        }

        if (root == NULL) {
            if ((root = init_node(data)) == NULL) {
                break;
            }
            continue;
        }

        insert_des = search_bitree(root, data);
        if (insert_des->data != data) {
            printf("parent node data : %d\t", insert_des->data);
            if ((node = init_node(data)) == NULL) {
                destroy_bitree(root);
                return NULL;
            }

            if (insert_des->data > data) {
                printf("left\n");
                insert_des->l_child = node;
            } else {
                printf("right\n");
               insert_des->r_child = node;
            }
        }
    }

    return root;
}

//TODO 参数改成二级指针更合理一些
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

    root = create_bitree(arr, ARRY_SIZE(arr));             // 构建顺序二叉树遇到 0 结束
    printf("/******************************************/\n");
    inorder_bitree(root, dump_node);       // 中序遍历二叉树
    printf("/******************************************/\n");
    destroy_bitree(root);                  // 中序遍历释放内存
    
    return 0;
}
