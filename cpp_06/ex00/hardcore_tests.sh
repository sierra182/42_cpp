#!/bin/bash

values=(6 42.0f 42.0 "hjh")
index=0
while [ $index -lt ${#values[@]} ]
do
    echo -e "\n\033[1;31m testing value: " ${values[$index]} "\033[0m"
    ./conversionOfScalarTypes ${values[$index]} gyWE78pxhzaph782qY
    ((index++))
    sleep 1
done