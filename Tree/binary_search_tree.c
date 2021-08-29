#include <stdlib.h>
#include <stdio.h>

typedef struct BinTreeNodeType
{
	int key;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode) // 이진 트리 생성(루트 노드만 만드는)
{
    BinTree *binTree;

    binTree = (BinTree *)malloc(sizeof(BinTree));
    if (binTree == NULL)
        return (NULL);
	binTree->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if (binTree->pRootNode == NULL)
        return (NULL);
    *(binTree->pRootNode) = rootNode;
    return (binTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    return (pBinTree->pRootNode);
} // 루트 노드 반환

BinTreeNode *newNode(int key)
{
    BinTreeNode *new;

    new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
    new->key = key;
    new->pLeftChild = NULL;
    new->pRightChild = NULL;
    return (new);
}

BinTreeNode *Insert(BinTreeNode *rootNode, int key)
{
    if (rootNode == NULL)
        return (newNode(key));
    else if (key > rootNode->key)
        rootNode->pRightChild = Insert(rootNode->pRightChild, key);
    else if (key < rootNode->key)
        rootNode->pLeftChild = Insert(rootNode->pLeftChild, key);
    else
        printf("Failed to Insert: Key %d is already exist.\n", key);
    return (rootNode);
}

BinTreeNode* find_minimum(BinTreeNode *rootNode)
{
    if(rootNode == NULL)
        return NULL;
    else if(rootNode->pLeftChild != NULL) // node with minimum value will have no left child
        return find_minimum(rootNode->pLeftChild); // left most element will be minimum
    return (rootNode);
}

BinTreeNode *Delete(BinTreeNode *rootNode, int key)
{
    if (rootNode == NULL)
    {
        printf("case_1\n");
        return (NULL);
    }
    if (key > rootNode->key)
    {
        printf("case_2\n");
        BinTreeNode *temp = rootNode->pRightChild;
        printf("2 >> %d:%d\n", temp->key, key);
        rootNode->pRightChild = Delete(rootNode->pRightChild, key);
    }
    else if (key < rootNode->key)
    {
        printf("case_3\n");
        BinTreeNode *temp = rootNode->pLeftChild;
        // printf("3 >> %d:%d\n", temp->key, key);
        rootNode->pLeftChild = Delete(rootNode->pLeftChild, key);
    }
    else
    {
        if (rootNode->pLeftChild == NULL && rootNode->pRightChild == NULL) // no children
        {
            printf("case_4\n");
           // printf("4 >> %d\n", rootNode->key);
            free(rootNode);
            rootNode = NULL;
            return (NULL);
        }
        else if ((rootNode->pLeftChild == NULL) || (rootNode->pRightChild == NULL)) // one child
        {
            printf("case_5\n");
            BinTreeNode *temp;
            
            if (rootNode->pLeftChild == NULL)
                temp = rootNode->pRightChild;
            else
                temp = rootNode->pLeftChild;
            free(rootNode);
            rootNode = NULL;
            return (temp);
        }
        else // two children
        {
            printf("case_5\n");
            BinTreeNode *temp;

            temp = find_minimum(rootNode->pRightChild);
            rootNode->key = temp->key;
            rootNode->pRightChild = Delete(rootNode->pRightChild, temp->key);
        }
    }
    return (rootNode);
}

void    InOrder(BinTreeNode *rootNode)
{
    if (rootNode != NULL)
    {
        InOrder(rootNode->pLeftChild);
        printf("%d ", rootNode->key);
        InOrder(rootNode->pRightChild);
    }
}

int main()
{
    BinTree     *rootTree;
    BinTreeNode rootNode;

    rootNode.key = 20;
    rootNode.pLeftChild = NULL;
    rootNode.pRightChild = NULL;
    rootTree = makeBinTree(rootNode);
    Insert(&rootNode, 5);
    Insert(&rootNode, 1);
    Insert(&rootNode, 15);
    Insert(&rootNode, 9);
    Insert(&rootNode, 7);
    Insert(&rootNode, 12);
    Insert(&rootNode, 30);
    Insert(&rootNode, 40);
    Insert(&rootNode, 82);
    Insert(&rootNode, 95);

    Delete(&rootNode, 5);
    InOrder(&rootNode);
    printf("\n");
    printf("%d %d %d", rootNode.key, rootNode.pLeftChild->key, rootNode.pLeftChild->pLeftChild->key);
    printf("\n");
    printf("%d %d %d", rootNode.pLeftChild->pRightChild->key, rootNode.pLeftChild->pRightChild->pLeftChild->key, rootNode.pLeftChild->pRightChild->pLeftChild->pRightChild->key);
    printf("\n");

}