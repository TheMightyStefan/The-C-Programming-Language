#!/bin/bash

gcc -Wall -std=c99 4-1.c
 
input=(
    "string\ntri"
)
expected=(
    "2"
)
 
for i in "${!input[@]}"; do
    if [ ${expected[$i]} == $(echo ${input[$i]} | ./a.out) ]
    then
        echo "Pass"
    else
        echo "Fail"
        echo
    fi
done
