#include "HttpServer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LOCAL_HOST "127.0.0.1"
#define LISTEN_BACKLOG 100

HttpServer::HttpServer(/* args */) {
}

HttpServer::~HttpServer() {
}

void HttpServer::ListenAt(unsigned int port) {
    
    if (port > 65535) {
        HandleError(PORT_ERROR);
    }
    
    int sock = 0;
    struct addrinfo * result = GetAddrInfo(port);
    for(struct addrinfo * p = result; p != NULL; p = p->ai_next) {
        sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (bind(sock, result->ai_addr, result->ai_addrlen) == 0) {
            printf("socket bind at port: %u \n", port);
            break;
        }
        close(sock);
    }

    freeaddrinfo(result);

    int listenFd = listen(sock, LISTEN_BACKLOG);
    
    struct sockaddr peeraddr;
    socklen_t peeraddrsize;
    while(true){
        int res = accept(sock, &peeraddr, &peeraddrsize);
    }
    
}

struct addrinfo * HttpServer::GetAddrInfo(unsigned int port) {
    struct sockaddr addr;
    struct addrinfo hints;
    struct addrinfo *result;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char portBuffer[6];
    sprintf(portBuffer, "%u", port);

    int s = getaddrinfo(LOCAL_HOST, portBuffer, &hints, &result); // 主机名转换成ip地址

    
    if (s != 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }
    return result;
}

void HttpServer::HandleError(HttpServerErrors error) {
    
    switch (error) {
        case LISTEN:
            break;
        case GETADDRINFO:
            break;
        case BIND:
            break;
        case PORT_ERROR:
            break;
        default:
            break;
    }
}