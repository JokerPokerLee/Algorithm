#!/bin/bash
while true; do
    ./gen            
    ./B > B.out
    ./B_baoli > baoli.out
    if diff baoli.out B.out; then 
    	printf "AC\n" 
    else 
    	printf "WA\n" 
        exit 0 
    fi 
done