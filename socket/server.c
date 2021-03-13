/*
 * Server
 */
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#define SERV_PORT       8080
#define SERV_HOST_ADDR  "192.168.1.33"
#define BUF_SIZE        100
#define BACKLOG         5 /* Max. clients pending connection */

int main(void){

    int sockfd, connfd;
    unsigned int len;
    struct sockaddr_in servaddr, client;
    int len_rx, len_tx = 0;
    char buff_tx[BUF_SIZE] = "Hello client, I am the server.";
    char buff_rx[BUF_SIZE];

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        fprintf(stderr, "[SERVER-error]: socket creation failed. %d: %s\n", errno, strerror(errno));
        return -1;
    }
    else{
        printf("[SERVER]: Socket successfully created.\n");
    }

    /* Clear structure */
    memset(&servaddr, 0, sizeof(servaddr));

    /* Assign IP, SERV_PORT, IPV4 */
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERV_HOST_ADDR);
    servaddr.sin_port = htons(SERV_PORT);

    /* Bind socket */
    if((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0){
        fprintf(stderr ,"[SERVER-error]: Socket bind failed. %d: %s \n", errno, strerror(errno));
        return -1;
    }
    else{
        printf("[SERVER]: Socket successfully binded.\n");
    }

    /* Listen */
    if((listen(sockfd, BACKLOG)) != 0){
        fprintf(stderr, "[SERVER-error]: Socket listen failed. %d: %s \n", errno, strerror(errno));
        return -1;
    }
    else{
        printf("[SERVER]: Listening on SERV_PORT %d \n\n", ntohs(servaddr.sin_port));
    }

    len = sizeof(client);

    /* Accept the data from incoming sockets in an interactive way */
    while(1){
        if((connfd = accept(sockfd, (struct sockaddr *)&client, &len)) < 0){
            fprintf(stderr, "[SERVER-error]: Connection not accepted. %d: %s \n", errno, strerror(errno));
            return -1;
        }
        else{
            while(1){ /* Read data from a client socket till it is closed */
                /* Read client message, copy it into buffer */
                if((len_rx = read(connfd, buff_rx, sizeof(buff_rx))) == -1){
                    fprintf(stderr, "[SERVER-error]: connfd cannot be read. %d: %s \n", errno, strerror(errno));
                }
                else if(len_rx == 0){ /* If length is 0 client socket closed */
                    printf("[SERVER]: Client socket closed \n\n");
                    close(connfd);
                    break;
                }
                else{
                    write(connfd, buff_tx, strlen(buff_tx));
                    printf("[SERVER]: %s \n", buff_rx);
                }
            }
        }
    } 

    return 0;
}
