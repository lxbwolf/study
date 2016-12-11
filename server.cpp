#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    // Create socket
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    // bind socket with ip and port
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // IPV4 address
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr);

    // Switch into monitor status, waiting for request from user
    listen(serv_sock, 20);

    // Receive request sent from client
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    // Sent data to client 
    char str[] = "Hello";
    write(clnt_sock, str, sizeof(str));

    // Close socket
    close(clnt_sock);
    close(serv_sock);

    return 0;
}
