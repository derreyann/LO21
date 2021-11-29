//
// Created by Yann Derré on 29/11/2021.
//

#ifndef TREEB_TREE_H
#define TREEB_TREE_H

typedef struct elem{
    int value;
    struct treelem* rchild;
    struct treelem* lchild;
}TreeNode;

typedef TreeNode* BTree;

bool estVide(BTree);

bool estFeuille(BTree);

void enraciner();

#endif //TREEB_TREE_H
