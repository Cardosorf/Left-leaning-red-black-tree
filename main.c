#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int key;
    int isRed;
    struct _node* left;
    struct _node* right;
} node;


node* insert(node* pt, int x);
node* insertLLRN(node* pt, int x);
int color(node* pt);
node* rotate_left(node* pt);
node* rotate_right(node* pt);
node* recolor(node* pt);
void print_pre_order(node* pt_root);

int main(void)
{

    node* pt_root;
    pt_root = NULL;
    int counter = 0, limit = 10, value, i;
    int* nodes;
//    int* temp;
    nodes = (int*)malloc(sizeof(int)*limit);
    if(!nodes){
        puts("Erro de alocacao");
        exit(0);
    }

        while(scanf("%d", &value) != EOF){
            do{} while (getchar() != '\n');
            printf("%d value\n", value);
            nodes[counter] = value;
             printf("%d counter\n", counter);
              printf("%d node\n", nodes[counter]);
            counter++;


            /*
            if(counter >= limit){
                limit = 2*limit;
//                temp = (int*)malloc(sizeof(int)*limit);
//                if(!nodes){
//                    puts("Erro de alocacao");
//                    exit(0);
//                }

//                for(i = 0; i < counter; i++){
//                    temp[i] = nodes[i];
//                }
                nodes = (int*)realloc(nodes, limit);
            }*/
        }
printf("%d counter\n", counter);
                        for(i = 0; i < 10; i++){
                            printf("%d oi\n", nodes[i]);
                        }

//    pt_root = insert(pt_root, 50);
//    pt_root = insert(pt_root, 1);
//    pt_root = insert(pt_root, 2);
//    pt_root = insert(pt_root, 3);
//    pt_root = insert(pt_root, 20);
//    pt_root = insert(pt_root, 11);
//    pt_root = insert(pt_root, 9);
//    pt_root = insert(pt_root, 12);


//    print_pre_order(pt_root);
    free(pt_root);
    return 0;
}


node* insert(node* pt, int x){
    pt = insertLLRN(pt, x);
    pt->isRed = 0;
    return pt;
}

node* insertLLRN(node* pt, int x){
    node* temp;

    if(pt == NULL){
        temp = (node*)malloc(sizeof(node));
        if(!temp){
            puts("Erro de alocacao");
            exit(0);
        }
        temp->key = x;
        temp->left = NULL;
        temp->right = NULL;
        temp->isRed = 1;
        return temp;
    }

    if(x < pt->key)
        pt->left = insertLLRN(pt->left, x);
    else
        pt->right = insertLLRN(pt->right, x);


    if(color(pt->left) == 0 && color(pt->right) == 1)
        pt = rotate_left(pt);

    if(color(pt->left) == 1 && color(pt->left->left) == 1)
        pt = rotate_right(pt);

    if(color(pt->left) == 1 && color(pt->right) == 1){
        pt = recolor(pt);
    }

    return pt;
}

int color(node* pt){
    return (pt == NULL) ? 0 : pt->isRed;
}

node* rotate_left(node* pt){
    node* temp;
    temp = (node*)malloc(sizeof(node));
    if(!temp){
        puts("Erro de alocacao");
        exit(0);
    }

    temp = pt->right;
    pt->right = temp->left;
    temp->left = pt;
    temp->isRed = pt->isRed;
    pt->isRed = 1;
    return temp;
}

node* rotate_right(node* pt){
    node* temp;
    temp = (node*)malloc(sizeof(node));

    if(!temp){
        puts("Erro de alocacao");
        exit(0);
    }

    temp = pt->left;
    pt->left = temp->right;
    temp->right = pt;
    temp->isRed = pt->isRed;
    pt->isRed = 1;
    return temp;
}

node* recolor(node* pt){
    pt->isRed = 1;
    pt->left->isRed = 0;
    pt->right->isRed = 0;
    return pt;
}

void print_pre_order(node* pt){
    if(pt){
        printf("%d %c\n", pt->key, (pt->isRed == 1) ? 'R' : 'N');
        print_pre_order(pt->left);
        print_pre_order(pt->right);
    }
}
