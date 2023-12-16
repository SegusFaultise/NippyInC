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
    NUM_KEYS
};

struct TokenMap {
    char token_value[MAX_SIZE];
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
void insert_token(struct TokenMap token_map[], const char *token, enum TokenType type);

/*
 * Prints out all the sets of token values and token types
 * */
void print_token_map(struct TokenMap token_map[]);
