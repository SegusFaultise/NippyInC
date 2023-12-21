struct AstNode {
    int token_position;

    struct AstNode *left;
    struct AstNode *right;
};

void ast_init(struct AstNode ast_node);

void insert_ast_node(struct AstNode **ast_node, int token_position_value);

void in_order_traversal(struct AstNode *ast_root);
