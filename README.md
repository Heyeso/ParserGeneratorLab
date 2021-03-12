## Parser Generator
takes a grammar as input and automatically generates source code that can parse streams of characters using the grammar.  
this is a sample program. 
 
 ### Compile on linux
 ```
flex tokenizer.l
bison -d -v -o y.tab.c parser.y
cc -o audio y.tab.c lex.yy.c audio_controller.c
```
##### To run
```
audio
```

### Commands
```
add <name> //adds an object with properties: name(set to name), status(set to off as defualt), volume(set to 10 as default)
status <name> //displays object properties
turn <name> (on|off) //changes status property to on or off
increase <name> //increase the volume property by 1
decrease <name> //decrease the volume property by 1
set <name> <number> //set the value of the volume property
```
