/* BEGIN - LAB 2 ---------------------------------------------*/
#include "compiler.h"
#include <string.h>
#include "helpers/vector.h"
#include "helpers/buffer.h"

#define LEX_GETC_IF(buffer, c, exp) \
  for (c = peekc(); exp; c = peekc()) { \
    buffer_write(buffer, c); \
    nextc(); \
  } 

struct token* read_next_token();
static struct lex_process* lex_process;
static struct token tmp_token;

// Pegar um caractere do arquivo, sem mudar a posição de leitura
static char peekc() {
  return lex_process->function->peek_char(lex_process);
}

static char nextc() {
  char c = lex_process->function->next_char(lex_process);
  lex_process->pos.col += 1;

  if (c == '\n') {
    lex_process->pos.line += 1;
    lex_process->pos.col = 1;
  }
  return c;
}

// Adicionar novo caractere no arquivo
static void pushc(char c) {
  lex_process->function->push_char(lex_process, c);
}

static struct pos lex_file_position() {
  return lex_process->pos;
}

struct token* token_create(struct token* _token) {
  memcpy(&tmp_token, _token, sizeof(struct token));
  tmp_token.pos = lex_file_position();

  return &tmp_token;
}

static struct token* lexer_last_token() {
  return vector_back_or_null(lex_process->token_vec);
}

static struct token* handle_whitespace() {
  struct token* last_token = lexer_last_token();
  if (last_token) {
    last_token->whitespace = true;
  }

  nextc();
  return read_next_token();
}

// Funções para NUMERIC_CASE
const char* read_number_str() {
  const char* num = NULL;
  struct buffer* buffer = buffer_create();
  char c = peekc();
  LEX_GETC_IF(buffer, c, (c >= '0' && c <= '9'));

  // Finaliza a string
  buffer_write(buffer, 0x00);

  printf("Token: %s\n", buffer->data);
  // Retorna o ponteiro para o buffer
  return buffer_ptr(buffer);
}

unsigned long long read_number() {
  const char* s = read_number_str();
  return atoll(s);
}

struct token* token_make_number_for_value(unsigned long number){
  return token_create(&(struct token){.type=TOKEN_TYPE_NUMBER, .llnum=number});
}

struct token* token_make_number(){
  return token_make_number_for_value(read_number());
}

// Funções para STRING_CASE
const char* read_string() {
    struct buffer* buffer = buffer_create();
    char c = nextc(); // Consome a primeira aspas

    // Lê os caracteres até encontrar a aspas final ou EOF
    while ((c = peekc()) != '"' && c != EOF) {
        buffer_write(buffer, c);
        nextc();
    }

    if (c == '"') {
        nextc(); // Consome a última aspas
    } else {
        // Caso de erro: string não fechada
        printf("Erro: String não fechada!\n");
    }

     // Finaliza a string
    buffer_write(buffer, 0x00);

    printf("Token: %s\n", buffer->data);
    // Retorna o ponteiro para o buffer
    return buffer_ptr(buffer);
}

struct token* token_make_string_for_value(const char* str) {
  char* copied_str = strdup(str); // Copia a string para uma nova área de memória
  return token_create(&(struct token){.type=TOKEN_TYPE_STRING, .sval=copied_str});
}

struct token* token_make_string() {
  return token_make_string_for_value(read_string());
}



// Função responsável por ler o próximo token do arquivo
struct token* read_next_token() {
    struct token* token = NULL;
    char c = peekc();

    // Para depuração:
    printf("Caractere atual: %c\n", c);

    switch (c) {
    case EOF:
        // Fim do arquivo
        break;

    // TOKEN_TYPE_NUMERIC_CASE
    NUMERIC_CASE:
        token = token_make_number();
        break;

    // TOKEN_TYPE_STRING_CASE
    STRING_CASE:
        token = token_make_string();
        break;

    // TOKEN_TYPE_COMMENT_CASE
    case '/':
        nextc();
        if (peekc() == '/') {
            struct buffer* buffer = buffer_create();
            LEX_GETC_IF(buffer, c, (c != '\n' && c != EOF));
            buffer_write(buffer, 0x00);
            token = token_create(&(struct token){.type = TOKEN_TYPE_COMMENT, .sval = buffer_ptr(buffer)});
            nextc();
        } else {
            pushc('/');
        }
        break;

    // TOKEN_TYPE_NEWLINE_CASE
    case '\n':
        token = token_create(&(struct token){.type = TOKEN_TYPE_NEWLINE});
        nextc();
        break;

    case ' ':
    case '\t':
        token = handle_whitespace();
        break;

    default:
        printf("Caractere inválido ignorado: %c\n", c); // Depuração
        nextc();
        break;
    }

    return token;
}

int lex(struct lex_process* process) {
  process->current_expression_count = 0;
  process->parentheses_buffer = NULL;
  lex_process = process;
  process->pos.filename = process->compiler->cfile.abs_path;

  struct token* token = read_next_token();

  // Ler todos os tokens do arquivo de imput
  while (token) {
    vector_push(process->token_vec, token);
    token = read_next_token();
  }

  return LEXICAL_ANALYSIS_ALL_OK;

}

/* END - LAB 2 -----------------------------------------------*/
