#!/bin/bash
gcc ./srcs/*.c -o run.out
./run.out $1 $2
/bin/rm run.out

