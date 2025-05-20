#include "src/compiler.h"
#include "src/helpers/vector.h"
#include "src/helpers/buffer.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>

extern struct lex_process_functions compiler_lex_functions;

void test_precedence_1() {
    // Teste 1: Verifica precedência entre operadores aritméticos
    // 2 + 3 * 4 deve ser interpretado como 2 + (3 * 4)
    const char* input = "2 + 3 * 4";
    char temp_filename[] = "/tmp/test_precedence_XXXXXX";
    int fd = mkstemp(temp_filename);
    assert(fd != -1);
    FILE* fp = fdopen(fd, "w");
    assert(fp != NULL);
    fprintf(fp, "%s", input);
    fclose(fp);
    
    struct compile_process* process = compile_process_create(temp_filename, NULL, 0);
    assert(process != NULL);
    
    // Adicionar análise léxica
    struct lex_process* lex_process = lex_process_create(process, &compiler_lex_functions, NULL);
    assert(lex_process != NULL);
    assert(lex(lex_process) == LEXICAL_ANALYSIS_ALL_OK);
    process->token_vec = lex_process->token_vec;
    
    struct node* root = parse(process);
    assert(root != NULL);
    assert(root->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.op, "+"));
    assert(root->exp.right->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.right->exp.op, "*"));
    unlink(temp_filename);
    printf("Teste 1 passou: Precedência entre operadores aritméticos\n");
}

void test_precedence_2() {
    // Teste 2: Verifica precedência entre operadores de comparação e lógicos
    // a < b && c > d deve ser interpretado como (a < b) && (c > d)
    const char* input = "a < b && c > d";
    char temp_filename[] = "/tmp/test_precedence_XXXXXX";
    int fd = mkstemp(temp_filename);
    assert(fd != -1);
    FILE* fp = fdopen(fd, "w");
    assert(fp != NULL);
    fprintf(fp, "%s", input);
    fclose(fp);
    
    struct compile_process* process = compile_process_create(temp_filename, NULL, 0);
    assert(process != NULL);
    
    // Adicionar análise léxica
    struct lex_process* lex_process = lex_process_create(process, &compiler_lex_functions, NULL);
    assert(lex_process != NULL);
    assert(lex(lex_process) == LEXICAL_ANALYSIS_ALL_OK);
    process->token_vec = lex_process->token_vec;
    
    struct node* root = parse(process);
    assert(root != NULL);
    assert(root->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.op, "&&"));
    assert(root->exp.left->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.left->exp.op, "<"));
    assert(root->exp.right->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.right->exp.op, ">"));
    unlink(temp_filename);
    printf("Teste 2 passou: Precedência entre operadores de comparação e lógicos\n");
}

void test_precedence_3() {
    // Teste 3: Verifica precedência entre operadores de atribuição e aritméticos
    // a = b + c * d deve ser interpretado como a = (b + (c * d))
    const char* input = "a = b + c * d";
    char temp_filename[] = "/tmp/test_precedence_XXXXXX";
    int fd = mkstemp(temp_filename);
    assert(fd != -1);
    FILE* fp = fdopen(fd, "w");
    assert(fp != NULL);
    fprintf(fp, "%s", input);
    fclose(fp);
    
    struct compile_process* process = compile_process_create(temp_filename, NULL, 0);
    assert(process != NULL);
    
    // Adicionar análise léxica
    struct lex_process* lex_process = lex_process_create(process, &compiler_lex_functions, NULL);
    assert(lex_process != NULL);
    assert(lex(lex_process) == LEXICAL_ANALYSIS_ALL_OK);
    process->token_vec = lex_process->token_vec;
    
    struct node* root = parse(process);
    assert(root != NULL);
    assert(root->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.op, "="));
    assert(root->exp.right->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.right->exp.op, "+"));
    assert(root->exp.right->exp.right->type == NODE_TYPE_EXPRESSION);
    assert(S_EQ(root->exp.right->exp.right->exp.op, "*"));
    unlink(temp_filename);
    printf("Teste 3 passou: Precedência entre operadores de atribuição e aritméticos\n");
}

int main() {
    test_precedence_1();
    test_precedence_2();
    test_precedence_3();
    printf("Todos os testes passaram com sucesso!\n");
    return 0;
} 