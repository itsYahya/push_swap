#!/bin/bash

args=$(./test.py $1)
echo "============="
echo "$args"
./push_swap $args | wc -l