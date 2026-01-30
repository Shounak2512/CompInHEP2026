#!/bin/bash
make 

for i in {1..10}
do
    ./opt $i > ./opts/$i.txt &
done

echo "Job Successfully Completed"