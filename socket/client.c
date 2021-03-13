/*
 * Client
 */
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS  "192.168.1.199"
#define PORT            8080

/* Test sequence */
char buf_tx[] = "Hello server, I am a client.";
char buf_rx[100];

int main(void){

    int sockfd;
    struct sockaddr_in servaddr;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        printf("CLIENT: socket creation failed...\n");
        return -1;
    }
    else{
        printf("CLIENT: Socket successfully created.\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));

    /* Assign IP, PORT */
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    servaddr.sin_port = htons(PORT);

    /* Try to connect the client socket to server socket */
    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
        printf("Connection with the server failed...\n");
        return -1;
    }
    else{
        printf("Connected to the server.\n");
    }

    /* Send test sequence */
    write(sockfd, buf_tx, sizeof(buf_tx));
    read(sockfd, buf_rx, sizeof(buf_rx));
    printf("CLIENT: Received: %s \n", buf_rx);

    /* Close the socket */
    close(sockfd);

    return 0;
}
