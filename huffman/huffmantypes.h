#ifndef __HUFFMAINTYPES__
#define __HUFFMAINTYPES__
typedef struct{
    char element;
    unsigned int occurrence;
} OccurenceElement;

typedef struct Node
{
    OccurenceElement* element;
    unsigned int element_size;
    unsigned int total_occurence;
    struct Node* leftNode;
    struct Node* rightNode;
} Node;

typedef Node* Tree;
#endif