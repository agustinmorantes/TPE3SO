#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "desafios.h"

#define clear() printf("\033[H\033[J")
#define PORT 8181

int main(int argc, char const *argv[])
{
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("socket");
        return -1;
    }
    
    int option = 1;
    setsockopt(serverfd, SOL_SOCKET, SO_REUSEPORT, &option, sizeof(option));

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(serverfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(serverfd);
        return -1;
    }

    struct sockaddr_in clientaddr;
    int clientLen = sizeof(clientaddr);
    
    if (listen(serverfd, 1) < 0) {
        perror("listen");
        close(serverfd);
        return -1;
    }
    
    int clientfd = accept(serverfd, (struct sockaddr*)&clientaddr, &clientLen);
    if(clientfd < 0) {
        perror("accept");
        close(serverfd);
        return -1;
    }

    
    for(int i = 0; i < DESAFIO_COUNT; i++) {
        char buf[4096];
        int len = 0;
        int wrong = 0;
        do {
            if(wrong) {
                printf("Respuesta incorrecta: %s\n", buf);
                sleep(2);
            }

            clear();

            desafios[i].setup();
            if((len = read(clientfd, buf, 4095)) <= 0) {
                close(clientfd);
                close(serverfd);
                return 0;
            }
            buf[len] = 0;
        } while ((wrong = strncmp(buf, desafios[i].pass, strlen(desafios[i].pass))) != 0);
    }

    clear();
    printf("Felicidades!\n");

    close(clientfd);
    close(serverfd);

    return 0;
}
