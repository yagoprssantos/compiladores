OBJECTS=./build/compiler.o ./build/cprocess.o ./build/helpers/buffer.o ./build/helpers/vector.o ./build/lex_process.o ./build/lexer.o ./build/parser.o
INCLUDES= -I./

all: ${OBJECTS} 
	gcc main.c ${INCLUDES} ${OBJECTS} -g -o ./main 

./build/compiler.o: ./compiler.c 
	gcc ./compiler.c ${INCLUDES} -o ./build/compiler.o -g -c 

./build/cprocess.o: ./cprocess.c
	gcc ./cprocess.c ${INCLUDES} -o ./build/cprocess.o -g -c

./build/helpers/buffer.o: ./helpers/buffer.c 
	mkdir -p ./build/helpers
	gcc ./helpers/buffer.c ${INCLUDES} -o ./build/helpers/buffer.o -g -c

./build/helpers/vector.o: ./helpers/vector.c
	gcc ./helpers/vector.c ${INCLUDES} -o ./build/helpers/vector.o -g -c

./build/lex_process.o: ./lex_process.c
	gcc ./lex_process.c ${INCLUDES} -o ./build/lex_process.o -g -c

./build/lexer.o: ./lexer.c
	gcc ./lexer.c ${INCLUDES} -o ./build/lexer.o -g -c

./build/parser.o: ./parser.c
	gcc ./parser.c ${INCLUDES} -o ./build/parser.o -g -c

clean: 
	rm -f ./main 
	rm -rf ./build/*