#define TOTAL_OPERADOR_GROUPS 14
#define MAX_OPERATORS_IN_GROUP 12

enum {
    ASSOCIATIVITY_LEFT_TO_RIGTH,
    ASSOCIATIVITY_RIGHT_TO_LEFT
};

struct expressionable_op_precedence_group {
    char* operators[MAX_OPERATORS_IN_GROUP];
    int associativity;
}; 