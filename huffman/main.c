#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "huffmantypes.h"

Tree createTree(char* str){
    int i,j,root_size=0,last_index=0,total_occurence;
    Tree tree;
    OccurenceElement *tmpRoot;
    tree = (Tree)malloc(sizeof(Node));
    tmpRoot = (OccurenceElement *)malloc(sizeof(OccurenceElement)*strlen(str));

    total_occurence = strlen(str);
    for(i=0;i<strlen(str);i++){
        last_index = -1;
        for(j=0;j<root_size;j++){
            if (tmpRoot[j].element==str[i]){
                last_index = j;
                break;
            }
        }
        if (last_index <0){
            last_index = root_size;
            root_size+=1;    
            tmpRoot[last_index].occurrence = 0;
        }
        tmpRoot[last_index].element = str[i];
        tmpRoot[last_index].occurrence+=1;
    }

    tree->element_size = root_size;
    tree->total_occurence = total_occurence;
    tree->element = tmpRoot;
    tree->leftNode = NULL;
    tree->rightNode = NULL;
    populate_tree(tree);
    return tree;
}
void populate_tree(Node* node){
    if (node == NULL) return;
    unsigned int half_occurrence,i,tmp_occurrences,switchNode=0,occurrence_index=0,rightNodeInit=0;
    OccurenceElement* elements;
    Node *leftNode, *rightNode,*current_node;
    if (node->element_size == 1){
        return;
    }
    half_occurrence = node->total_occurence / 2;
    current_node = (Node *)malloc(sizeof(Node));
    current_node->element = (OccurenceElement *)malloc((half_occurrence+1)  * sizeof(OccurenceElement));
    current_node->leftNode = NULL;
    current_node->rightNode = NULL;
    elements = node->element;
    tmp_occurrences = 0;
    switchNode = 0;
    occurrence_index = 0;

    for (i = 0; i < node->element_size; i++)
    {
        tmp_occurrences+=elements[i].occurrence;
        current_node->element[occurrence_index++] = elements[i];
        current_node->element_size = occurrence_index;
        current_node->total_occurence = tmp_occurrences;

        if (tmp_occurrences >=half_occurrence)
            if (!switchNode){
                node->leftNode =  current_node;
                switchNode = 1;
                current_node = (Node *)malloc(sizeof(Node));
                current_node->element = (OccurenceElement *)malloc((half_occurrence+1)  * sizeof(OccurenceElement));
                current_node->leftNode = NULL;
                current_node->rightNode = NULL;
                occurrence_index = 0;
                tmp_occurrences = 0;
            }else{
                rightNodeInit = 1;
                node->rightNode = current_node;
            }   
    }

    if (!rightNodeInit){
        node->rightNode = current_node;
    }

    populate_tree(node->leftNode);
    populate_tree(node->rightNode);
}

void print_occurrence_array(OccurenceElement* array,int size){
    int i;
    for(int i=0;i<size;i++)
    {
        printf("%c(%d) ",array[i].element,array[i].occurrence);
    }
}

void print_tree(Tree tree)
{
    print_tree_internal(tree,20,5);
}

void print_tree_internal(Tree tree,int x, int y){    
    if (tree== NULL)
        return;
    gotoxy(x,y);
    print_occurrence_array(tree->element,tree->element_size);
    print_tree_internal(tree->leftNode,x-5,y+1);
    print_tree_internal(tree->rightNode,x+20,y+1);
}

void gotoxy(int x,int y){
    printf("%c[%d;%df",0x1B,y,x);
}
int main(){
    Tree tree;
    char inputString[30];
    int i;
    printf("Inserisci la frase da comprimere:");
    scanf("%s",inputString);
    tree = createTree(inputString);
    print_tree(tree);
    return 0;
}