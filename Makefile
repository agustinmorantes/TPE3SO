include Makefile.inc

SERVER=server.out
CLIENT=client.out

SERVER_SRC=$(wildcard server/*.c)
CLIENT_SRC=$(wildcard client/*.c)

SERVER_ASM=$(wildcard server/*.asm)

SERVER_OBJ=$(SERVER_SRC:%.c=%.o) $(SERVER_ASM:%.asm=%.o)
CLIENT_OBJ=$(CLIENT_SRC:%.c=%.o)

SERVER_H=$(wildcard server/*.h)
CLIENT_H=$(wildcard client/*.h)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(SERVER_H)
	gcc -g -o $(SERVER) $(SERVER_OBJ) -lm $(GCC_FLAGS)
	objcopy --add-section .custom=custom_section --set-section-flags .custom=noload,readonly $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(CLIENT_H)
	gcc -g -o $(CLIENT) $(CLIENT_OBJ) $(GCC_FLAGS)

%.o: %.c
	gcc -g -c -o $@ $< $(GCC_FLAGS)
  
%.o: %.asm
	nasm -felf64 -o $@ $<

clean: 
	@rm -f $(SERVER) $(CLIENT) $(SERVER_OBJ) $(CLIENT_OBJ)

.PHONY: all clean