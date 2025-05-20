#include "compiler.h"
#include "helpers/vector.h"
#include <assert.h>

static struct compile_process* current_process;
static struct token* parser_last_token;

void parse_expressionable(struct history* history);
int parse_expressionable_single(struct history* history);
static bool parser_left_op_has_priority(const char* op_left, const char* op_right);
extern struct expressionable_op_precedence_group op_precedence[TOTAL_OPERADOR_GROUPS];

// ... existing code ...

void parse_exp_normal(struct history* history) {
    struct token* op_token = token_peek_next();
    char *op = op_token->sval;
    struct node* node_left = node_peek_expressionable_or_null();
    if (!node_left) return;

    token_next();
    node_pop();
    node_left->flags |= NODE_FLAG_INSIDE_EXPRESSION;

    parse_expressionable_for_op(history_down(history, history->flags), op);
    struct node* node_right = node_pop();
    node_right->flags |= NODE_FLAG_INSIDE_EXPRESSION;

    make_exp_node(node_left, node_right, op);
    struct node* exp_node = node_pop();
    parser_reorder_expression(&exp_node);
    node_push(exp_node);
}

void parser_reorder_expression(struct node** node_out) {
    struct node* node = *node_out;
    if (node->type != NODE_TYPE_EXPRESSION) return;
    if (node->exp.left != NODE_TYPE_EXPRESSION && node->exp.right && node->exp.right != NODE_TYPE_EXPRESSION) return;

    if (node->exp.left != NODE_TYPE_EXPRESSION && node->exp.right && node->exp.right == NODE_TYPE_EXPRESSION) {
        const char* op = node->exp.right->exp.op;
        const char* right_op = node->exp.right->exp.op;
        if (parser_left_op_has_priority(node->exp.op, right_op)) {
            parser_node_shift_children_left(node);
            parser_reorder_expression(&node->exp.left);
            parser_reorder_expression(&node->exp.right);
        }
    }
}

static bool parser_get_precedence_for_operator(const char* op, struct expressionable_op_precedence_group** group_out) {
    *group_out = NULL;
    for (int i = 0; i < TOTAL_OPERADOR_GROUPS; i++) {
        for (int j = 0; op_precedence[i].operators[j]; j++) {
            const char* _op = op_precedence[i].operators[j];
            if (S_EQ(op, _op)) {
                *group_out = &op_precedence[i];
                return i;
            }
        }
    }
    return -1;
}

static bool parser_left_op_has_priority(const char* op_left, const char* op_right) {
    struct expressionable_op_precedence_group* group_left = NULL;
    struct expressionable_op_precedence_group* group_right = NULL;

    if (S_EQ(op_left, op_right)) return false;

    int precedence_left = parser_get_precedence_for_operator(op_left, &group_left);
    int precedence_right = parser_get_precedence_for_operator(op_right, &group_right);

    if (group_left->associativity == ASSOCIATIVITY_RIGHT_TO_LEFT) return false;
    return precedence_left <= precedence_right;
}

void parser_node_shift_children_left(struct node* node) {
    assert(node->type == NODE_TYPE_EXPRESSION);
    assert(node->exp.right == NODE_TYPE_EXPRESSION);

    const char* right_op = node->exp.right->exp.op;
    struct node* new_exp_left_node = node->exp.left;
    struct node* new_exp_right_node = node->exp.right->exp.left;

    make_exp_node(new_exp_left_node, new_exp_right_node, node->exp.op);

    struct node* new_left_operand = node_pop();
    struct node* new_right_operand = node->exp.right->exp.right;

    node->exp.left = new_left_operand;
    node->exp.right = new_right_operand;
    node->exp.op = right_op;
}

// ... existing code ... 