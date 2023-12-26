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
    NUM_KEYS
};

struct AstNode {
    char token_value[MAP_SIZE];
    int token_position;
    enum TokenType token_type;

    struct AstNode *left;
    struct AstNode *right;
};

/*
 * Inserts a token string value, enum TokenType value and token position into each AST node
 * */
void insert_token(struct AstNode **token_map, const char *token, int token_position, enum TokenType type);

int get_token_position(struct AstNode *ast_node, const char *token);

void in_order_traversal(struct AstNode *ast_root);

void print_tree_structure(struct AstNode *ast_root, const char *prefix, int is_left);
