#include <stdio.h>
#include <stdlib.h>

#include "token_map.h"
#include "ast.h"

void ast_init(struct AstNode ast_node) {
    ast_node.token_position = 0;

    ast_node.right = NULL;
    ast_node.left = NULL;
}

void insert_ast_node(struct AstNode **ast_node, int token_position_value) {
    struct AstNode *temp_node = (struct AstNode*)malloc(sizeof(struct AstNode));

    temp_node->token_position = token_position_value;
    temp_node->left = NULL;
    temp_node->right = NULL;

    if(!(*ast_node)) {
        *ast_node = temp_node;
        return;
    } 
    struct AstNode *current_node = *ast_node;
    struct AstNode *parent_node = NULL;

    while(current_node != NULL) {
        parent_node = current_node;

        if(token_position_value < current_node->token_position) {
            current_node = current_node->left;
        }
        else if(token_position_value > current_node->token_position) {
            current_node = current_node->right;
        }
        else {
            free(temp_node);
            return;
        }
    }

    if(token_position_value < parent_node->token_position) {
        parent_node->left = temp_node;
    }
    else {
        parent_node->right = temp_node;
    }
}

void in_order_traversal(struct AstNode *ast_root) {
    if(ast_root != NULL) {
        in_order_traversal(ast_root->left);

        printf("[ %d ] -> ", ast_root->token_position);

        in_order_traversal(ast_root->right);
    }
}
