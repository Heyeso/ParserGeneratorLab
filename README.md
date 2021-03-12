# ParserGeneratorLab
 takes a grammar as input and automatically generates source code that can parse streams of characters using the grammar
 
 Compile
 
 compile on linux
 
flex tokenizer.l
bison -d -v -o y.tab.c parser.y
cc -o audio y.tab.c lex.yy.c audio_controller.c

run audio
