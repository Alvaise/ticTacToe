#!/bin/bash
rm -rf ./target
mkdir ./target
gcc -Wall -O3  -s -o ./target/ticTacToe ./main.c
./target/ticTacToe
done
