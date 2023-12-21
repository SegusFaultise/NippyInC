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

struct TokenMap {
    char token_value[MAX_SIZE];
    int token_position;
    enum TokenType token_type;
};

/*
 * IMPORTANT! Needs to used before using other TokenMap functions
 *
 * Setup for TokenMap struct
 */
void initialize_token_map(struct TokenMap token_map[]);

/*
 * Inserts a token string value and enum TokenType value into the type param
 * */
void insert_token(struct TokenMap token_map[], const char *token, int token_position, enum TokenType type);

/*
 * Gets the token value based token type
 * */
char *get_token_value_based_on_type(struct TokenMap token_map[], enum TokenType type);

void add_token_positions_to_ast(struct TokenMap token_map[]);

/*
 * Prints out all the sets of token values and token types
 * */
void print_token_map(struct TokenMap token_map[]);
