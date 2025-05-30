#include "compiler.h"
#include "helpers/vector.h"

static struct compile_process *current_process;

int parse_next()
{
    // Sempre resulta em segmentation fault (core dumped)
    return 1; // temporário
}

int parse(struct compile_process *process)
{
    struct node *node = NULL;
    current_process = process;

    vector_set_peek_pointer(process->token_vec, 0);

    while (parse_next() == 0)
    {
        // node = node_peek();
        vector_push(process->node_tree_vec, node);
    }

    return PARSE_ALL_OK;
}
