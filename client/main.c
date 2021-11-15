#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");

    if (connect(socketfd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        perror("connect");
        close(socketfd);
        return -1;
    };

    char bufInput[4096];
    int len = 0;
    while((len = read(STDIN_FILENO, bufInput, 4096)) > 0)
        write(socketfd, bufInput, len); 

    close(socketfd);

    return 0;
}
