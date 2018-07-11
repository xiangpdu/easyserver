#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <map>
#include <netdb.h>

using namespace std;

enum HttpServerErrors {
    LISTEN,
    GETADDRINFO,
    BIND,
    PORT_ERROR
};

class HttpServer {
    private:
        struct addrinfo * GetAddrInfo(unsigned int port);
    public:
        HttpServer(/* args */);
        ~HttpServer();

        void ListenAt(unsigned int port);
        void HandleError(HttpServerErrors error);
};


