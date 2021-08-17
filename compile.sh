#!/usr/bin/env bash
gcc -lchibi-scheme -pthread -Wall -Wextra -O2 -I /usr/local/include -I ./include/ -std=c99 -pedantic -fPIC     -shared chibized-socket.c wslib.a -o websocket.so