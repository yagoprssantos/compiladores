#ifndef COMPILER_H
#define COMPILER_H

#include <stdio.h> 
#include <stdlib.h>

/* BEGIN - LAB 2 ---------------------------------*/
#include <stdbool.h>

struct pos {
    int line;
    int col;
    const char* filename;
};

#define NUMERIC_CASE \
    case '0':   \
    case '1':   \
    case '2':   \
    case '3':   \
    case '4':   \
    case '5':   \
    case '6':   \
    case '7':   \
    case '8':   \
    case '9'

#define STRING_CASE \
    case '"'

    enum {
    LEXICAL_ANALYSIS_ALL_OK ,
    LEXICAL_ANALYSIS_IMPUT_ERROR
};

enum {
    TOKEN_TYPE_KEYWORD ,
    TOKEN_TYPE_IDENTIFIER ,
    TOKEN_TYPE_OPERATOR ,
    TOKEN_TYPE_SYMBOL ,
    TOKEN_TYPE_NUMBER ,
    TOKEN_TYPE_STRING ,
    TOKEN_TYPE_COMMENT ,
    TOKEN_TYPE_NEWLINE
};

struct token{ 
    int type;
    int flags;

    struct pos pos; //Identificar onde o token esta no arquivo.

    union {
        char cval;
        const char *sval;
        unsigned int inum;
        unsigned long lnum;
        unsigned long long llnum;
        void* any;

    };
    // Sera 'true' se tiver um espaço entre um token e o próximo token.
    bool whitespace;

    // Retira a string que estiver dentro de parênteses. Ex: (1+2+3) resulta em 1+2+3.
    const char* between_brackets;
};

struct lex_process;

// Definicao de ponteiros para funcoes.
typedef char (*LEX_PROCESS_NEXT_CHAR) (struct lex_process* process);            
typedef char (*LEX_PROCESS_PEEK_CHAR) (struct lex_process* process);            
typedef void (*LEX_PROCESS_PUSH_CHAR) (struct lex_process* process, char c);

struct lex_process_functions {
    LEX_PROCESS_NEXT_CHAR next_char;
    LEX_PROCESS_PEEK_CHAR peek_char;
    LEX_PROCESS_PUSH_CHAR push_char;
};

struct lex_process {
    struct pos pos;
    struct vector* token_vec;
    struct compile_process* compiler;

    
    int current_expression_count; //Qts parenteses existem no momento.

    struct buffer* parentheses_buffer;
    struct lex_process_functions* function;

    void* private; //Dados privados que o lexer nao entende mas o programador entende.
};

// Funcoes do arquivo cprocess.c
char compile_process_next_char(struct lex_process* lex_process);
char compile_process_peek_char(struct lex_process* lex_process);
void compile_process_push_char(struct lex_process* lex_process, char c);

// Funcoes do arquivo lex_process.c
struct lex_process* lex_process_create(struct compile_process* compiler, struct lex_process_functions* functions, void *private);
void lex_process_free(struct lex_process* process);
void* lex_process_private(struct lex_process* process);
struct vector* lex_process_tokens(struct lex_process* process);

// Funcoes do arquivo lexer.c
int lex(struct lex_process* process);

// Funcoes do arquivo compiler.c
void compiler_error(struct compile_process* compiler, const char* msg, ...);
void compiler_warning(struct compile_process* compiler, const char* msg, ...);


/* END - LAB 2 ---------------------------------*/

enum{
    COMPILER_FILE_COMPILED_OK,
    COMPILER_FAILED_WITH_ERRORS
};

struct compile_process {
    // Como o arquivo deve ser compilado
    int flags;

    /* LAB2*/
    struct pos pos;

    struct compile_process_imput_file{
        FILE* fp;
        const char* abs_path;
    } cfile;

    FILE* ofile;
};


int compile_file(const char* filename, const char* out_finename, int flags);
struct compile_process* compile_process_create(const char* filename, const char* filename_out, int flags);




#endif



