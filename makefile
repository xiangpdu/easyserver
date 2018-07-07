httpserver: HttpServer.cpp HttpServer.h
	g++ -c HttpServer.cpp -o httpserver

main: main.cpp  httpserver
	g++ main.cpp -o main

clean: main
	if [ -f "main" ]; then rm main;fi
	if [ -f "httpserver" ]; then  rm httpserver;fi