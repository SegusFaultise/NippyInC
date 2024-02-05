#ifndef AST_H
#define AST_H

#define MAX_SIZE 255
#define MAP_SIZE 255

enum TokenType {
    MULTIPLY,
    DIVIDE,
    ADDITION,
    MINUS,
    INTEGER,
    ALPHA,
    AND,
    LEFT_ROUND_BRACKET,
    RIGHT_ROUND_BRACKET,
    LEFT_SQUARE_BRACKET,
    RIGHT_SQUARE_BRACKET,
    END_OF_LINE,
    ASSIGN,
    UNDERSCORE,
    NUM_KEYS,
    IF_STATEMENT,
    FOR_LOOP,
    WHILE_LOOP,
    GREATER_THAN,
    LESS_THAN,
    THAN_STATEMENT
};

struct AstNode {
    char token_alpha_value[MAP_SIZE];
    int token_number_value;
    int token_position;
    enum TokenType token_type;

    struct AstNode *left;
    struct AstNode *right;
};

struct AstNode* createNumberNode(int value);


struct AstNode* createBinaryNode(enum TokenType type, struct AstNode* left, struct AstNode* right);

/*
 * Inserts a token string value, enum TokenType value and token position into each AST node
 * */
void insert_token(struct AstNode **token_map, const char *token, enum TokenType type);

int get_token_position(struct AstNode *ast_node, const char *token);

int peek_next_token(struct AstNode *ast_root, int token_position);

int evaluate_ast(struct AstNode *ast_root);

void free_ast(struct AstNode *node);

void print_tree(struct AstNode *root, enum TokenType type);

void in_order_traversal(struct AstNode *ast_root);

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left);

#endif
