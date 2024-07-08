#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum TokenType {
    ADDITION
};

struct AstNode {   
    int ast_node_value;

    struct AstNode* node_left;
    struct AstNode* node_right;
};

void inorder_traaversal(struct AstNode* ast_root) {
    if(ast_root == NULL) return;

    inorder_traaversal(ast_root->node_left);
    
    printf("[AST NODE VALUE]: (%d)\n", ast_root->ast_node_value);

    inorder_traaversal(ast_root->node_right);
}

struct AstNode* create_ast_node(int token_value) {
    struct AstNode* new_ast_node = malloc(sizeof(struct AstNode));

    new_ast_node->ast_node_value = token_value;

    new_ast_node->node_left = NULL;
    new_ast_node->node_right = NULL;

    return new_ast_node;
} 

struct AstNode* insert_left_node(struct AstNode* ast_root, int token_value) {
    if(ast_root == NULL) exit(-1);
    
    if(ast_root->node_left == NULL) {
        ast_root->node_left = create_ast_node(token_value); 
    }
    else {
        insert_left_node(ast_root->node_left, token_value);
    }

    return ast_root->node_left;
}

struct AstNode* insert_right_node(struct AstNode* ast_root, int token_value) {
    if(ast_root == NULL) exit(-1);
    
    if(ast_root->node_right == NULL) {
        ast_root->node_right = create_ast_node(token_value); 
    }
    else {
        insert_right_node(ast_root->node_right, token_value);
    }

    return ast_root->node_right;
}

void build_ast(struct AstNode* ast_root, int token_stream[], size_t token_stream_length) {
    
    for(int i = 0; i < token_stream_length; i++) {
        if(token_stream[i] == ADDITION) {
            printf("- %d \n", token_stream[i]);

            insert_left_node(ast_root, token_stream[i]);
        }
        else if(isdigit(token_stream[i] + '0')){
            printf("- %d \n", token_stream[i]);

            insert_left_node(ast_root->node_left, token_stream[i]);
        }
    }
}

void evalualte_ast(struct AstNode* ast_root, int level) {
    if (ast_root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("[AST NODE VALUE]: (%d)\n", ast_root->ast_node_value);

    if (ast_root->node_left != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("  Left -> ");
        evalualte_ast(ast_root->node_left, level + 1);
    }
    if (ast_root->node_right != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("  Right -> ");
        evalualte_ast(ast_root->node_right, level + 1);
    }
}

void print_tree(struct AstNode* root, int level) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("[AST NODE VALUE]: (%d)\n", root->ast_node_value);

    if (root->node_left != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("  Left -> ");
        print_tree(root->node_left, level + 1);
    }
    if (root->node_right != NULL) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("  Right -> ");
        print_tree(root->node_right, level + 1);
    }
}

int main(int argc, char *argv[]) {
    struct AstNode* ast_root = create_ast_node(1); 
    
    int token_array[] = {ADDITION, 6, 4};
    size_t token_array_length = *(&token_array + 1) - token_array;

    build_ast(ast_root, token_array, token_array_length);
    
    inorder_traaversal(ast_root);

    printf("\n");

    print_tree(ast_root, 0);

    return 0;
}
