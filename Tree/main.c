#include "bintree.h"

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
    binTree->pRootNode->pLeftChild = NULL;
    binTree->pRootNode->pRightChild = NULL;
    return (binTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    return (pBinTree->pRootNode);
} // 루트 노드 반환

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) // 왼쪽 자식 노드 추가
{
	BinTreeNode *lChild;

	lChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (lChild == NULL || pParentNode == NULL)
        return (NULL);
	pParentNode->pLeftChild = lChild;
    *(pParentNode->pLeftChild) = element;
    pParentNode->pLeftChild->pLeftChild = NULL;
    pParentNode->pLeftChild->pRightChild = NULL;
    return (pParentNode);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *rChild;

	rChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (rChild == NULL || pParentNode == NULL)
        return (NULL);
    pParentNode->pRightChild = rChild;
    *(pParentNode->pRightChild) = element;
    pParentNode->pRightChild->pLeftChild = NULL;
    pParentNode->pRightChild->pRightChild = NULL;
    return (pParentNode);
} // 오른쪽 자식 노드 추가

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode == NULL) // 추가 논의
        return (NULL);
    return (pNode->pLeftChild);
} // 왼쪽 자식 노드 반환

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
  if (pNode == NULL)
        return (NULL);
    return (pNode->pRightChild);    
}// 오른쪽 자식 노드 반환

void    deleteBinTreeNode(BinTreeNode* pNode) // 이진 트리 노드 삭제
{
    if (pNode != NULL)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        printf("%c free\n", pNode->data);
        free(pNode);
        pNode = NULL;
    }
}

void deleteBinTree(BinTree* pBinTree) // 이진 트리 삭제
{
    BinTreeNode *temp;

    temp = pBinTree->pRootNode;
    if (pBinTree == NULL)
    {
        printf("This tree is NULL");
        return ;
    }
    deleteBinTreeNode(temp);
    free(pBinTree);
    pBinTree = NULL;
}

void    preOrder(BinTreeNode* pNode) // v - l - r
{
    if (pNode != NULL)
    {
        printf("%c ", pNode->data);
        preOrder(pNode->pLeftChild);
        preOrder(pNode->pRightChild);
    }
}

void    inOrder(BinTreeNode* pNode) // l - v - r
{
    if (pNode != NULL)
    {
        inOrder(pNode->pLeftChild);
        printf("%c ", pNode->data);
        inOrder(pNode->pRightChild);
    }
}

void    postOrder(BinTreeNode* pNode) // l - r - v
{
    if (pNode != NULL)
    {
        postOrder(pNode->pLeftChild);
        postOrder(pNode->pRightChild);
        printf("%c ", pNode->data);
    }
}

int main(void) 
{
    BinTree *binTree;

    BinTreeNode rootNode;
    BinTreeNode newNode[12];
    BinTreeNode *temp;
    BinTreeNode *temp1;
    
    rootNode.data = 'A';
    binTree = makeBinTree(rootNode); // 루트 노드 설정
    temp = binTree->pRootNode; // 루트 노드 임시 저장

    for (int i = 0; i < 12; i++)
        newNode[i].data = 'B' + i; // 트리 배열에 값 넣어주기

    temp = insertLeftChildNodeBT(temp, newNode[0]); // B
    temp = insertRightChildNodeBT(temp, newNode[1]); // C
	printf("\t\t\t\t\t\t%c\t\t\t\t\t\t\tlevel 1\n", binTree->pRootNode->data);
	printf("\t\t\t\t\n");
    printf("\t\t\t%c\t\t\t", binTree->pRootNode->pLeftChild->data);
    printf("\t\t\t%c\t\t\t\tlevel 2\n", binTree->pRootNode->pRightChild->data);
	printf("\t\t\t\t\n");
    
    temp = getLeftChildNodeBT(temp);
    temp = insertLeftChildNodeBT(temp, newNode[2]);
    temp = insertRightChildNodeBT(temp, newNode[3]);

	// printf("Parent: %c\n", temp->data);
    printf("\t\t%c\t", temp->pLeftChild->data);
    printf("\t%c\t", temp->pRightChild->data);

    temp = getRootNodeBT(binTree); 
    temp = getRightChildNodeBT(temp);
    temp = insertLeftChildNodeBT(temp, newNode[4]);
    temp = insertRightChildNodeBT(temp, newNode[5]);

    // printf("Parent: %c\n", temp->data);
    printf("\t\t\t%c\t", temp->pLeftChild->data);
    printf("\t%c\t\t\tlevel 3\n", temp->pRightChild->data);
    printf("\n");
    
    temp = getRootNodeBT(binTree);
	// printf("I'm roooot : %c\n", temp->data);
    
    temp = getLeftChildNodeBT(temp);
    temp = getLeftChildNodeBT(temp);
    temp = insertLeftChildNodeBT(temp, newNode[6]);
    temp = insertRightChildNodeBT(temp, newNode[7]);

    // printf("Parent: %c\n", temp->data);
    printf("\t%c\t", temp->pLeftChild->data); // H
    printf("  %c", temp->pRightChild->data); // I

    temp = getRootNodeBT(binTree);
    temp = getLeftChildNodeBT(temp); 
    temp = getRightChildNodeBT(temp);
    temp = insertLeftChildNodeBT(temp, newNode[8]);
    
    // printf("\nParent: %c\n", temp->data);
    printf("\t  %c ", temp->pLeftChild->data); // J
    //printf("Right: %c\n", temp->pRightChild->data);
    
    temp = getRootNodeBT(binTree);
	// printf("I'm roooot : %c\n", temp->data);
    
    temp = getRightChildNodeBT(temp);
    temp = getLeftChildNodeBT(temp);
    temp = insertRightChildNodeBT(temp, newNode[9]);

    // printf("Parent: %c\n", temp->data);
    //printf("Left: %c\n", temp->pLeftChild->data);
    printf("\t\t\t\t  %c", temp->pRightChild->data);
    
    temp = getRootNodeBT(binTree);
    temp = getRightChildNodeBT(temp);
    temp = getRightChildNodeBT(temp);
    temp = insertLeftChildNodeBT(temp, newNode[10]);
    temp = insertRightChildNodeBT(temp, newNode[11]);
    
    // printf("Parent: %c\n", temp->data);
    printf("\t  %c ", temp->pLeftChild->data);
    printf("\t%c\t\tlevel 4\n", temp->pRightChild->data);

    temp = getRootNodeBT(binTree);
	printf("\nI'm roooot : %c\n", temp->data);

    printf("\n+++++ Tree Traversal +++++\n");

    printf("\n====== preOrder ======\n");
    preOrder(temp);
    printf("\n======================\n");

    printf("\n====== inOrder ======\n");
    inOrder(temp);
    printf("\n======================\n");

    printf("\n====== postOrder ======\n");
    postOrder(temp);    
    printf("\n======================\n");

    printf("\n+++++ Delete Tree +++++\n");
    deleteBinTree(binTree);
    
    return 0;
}
