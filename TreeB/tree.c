//
// Created by Yann Derré on 29/11/2021.
//
#include <stdbool.h>
#include <stdlib.h>
#include "tree.h"

bool estVide(BTree t){
    return (t=NULL);
}

bool IsLeaf(BTree t){
    return(t->rchild == NULL) && (t->lchild == NULL);
}

BTree Root(TreeNode *rt, BTree l, BTree r) {
    rt->lchild=l;
    rt->rchild=r;
    return rt;
}

bool NewLeaf(BTree t, int e){
    TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
    l->value=e;
    return Root(l, NULL, NULL);
}


BTree removeleaves(BTree t, int e){
    if(estVide(t)){
        return t;
    }else{
        if(estFeuille(t) &&  t->value==e){
            free(t);
            return NULL;
        }else{
            return Root(t, removeleaves(t->lchild, e), removeleaves(t->rchild, e));
        }
    }
}

bool contains(BTree t, int e){
    if(estVide(t)){
        return false;
    }else{
        if(t->value==e){
            return true;
        }
        else{
            return contains(t->lchild, e) || contains(t->rchild, e);
        }
    }
}