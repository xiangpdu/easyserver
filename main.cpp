#include <stdio.h>
#include <iostream>
#include "HttpServer.h"

using namespace std;

int main(int argc, char const *argv[]) {
    HttpServer *server = new HttpServer();
    server->ListenAt(8080);
    return 0;
}
