#!/bin/sh
make -C ../ re >/dev/null
clang main.c -I . -L ../ -lftprintf >/dev/null
make -C ../ fclean >/dev/null
./a.out
