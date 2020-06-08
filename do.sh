#!/bin/sh
make re >/dev/null
clang main.c -I . -L ./ -lftprintf >/dev/null
make fclean >/dev/null
./a.out
