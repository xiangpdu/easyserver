main: main.cpp  httpserver.o
	g++ main.cpp -o main httpserver.o

httpserver.o: HttpServer.cpp HttpServer.h
	g++ -c HttpServer.cpp

clean: main
	if [ -f "main" ]; then rm main;fi
	if [ -f "httpserver" ]; then  rm httpserver;fi
	if [ -f "HttpServer.o" ]; then  rm HttpServer.o;fi