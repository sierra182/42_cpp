#!/bin/bash

# test=6
# echo "testing value: " $test
# ./conversionOfScalarTypes $test gyWE78pxhzaph782qY

# test=42.0f
# echo "testing value: " $test
# ./conversionOfScalarTypes $test gyWE78pxhzaph782qY

# test=42.0
# echo "testing value: " $test
# ./conversionOfScalarTypes $test gyWE78pxhzaph782qY

values=(6 42.0f 42.0 "hjh")
index=0
while [ $index -lt ${#values[@]} ]
do
    echo -e "\n\033[1;31m testing value: " ${values[$index]} "\033[0m"
    ./conversionOfScalarTypes ${values[$index]} gyWE78pxhzaph782qY
    ((index++))
done