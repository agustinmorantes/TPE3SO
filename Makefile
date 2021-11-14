SERVER=server.out
CLIENT=client.out

SERVER_SRC=$(wildcard server/*.c)
CLIENT_SRC=$(wildcard client/*.c)

SERVER_OBJ=$(SERVER_SRC:%.c=%.o)
CLIENT_OBJ=$(CLIENT_SRC:%.c=%.o)

SERVER_H=$(wildcard server/*.h)
CLIENT_H=$(wildcard client/*.h)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(SERVER_H)
	gcc -g -o $(SERVER) $(SERVER_OBJ) -lm

$(CLIENT): $(CLIENT_OBJ) $(CLIENT_H)
	gcc -g -o $(CLIENT) $(CLIENT_OBJ)

%.o: %.c
	gcc -g -c -o $@ $<

clean: 
	@rm $(SERVER) $(CLIENT) $(SERVER_OBJ) $(CLIENT_OBJ)

.PHONY: all clean