#!/bin/bash

folder="../demo/test/"

cd ../../src
./test -c ../use-cases/test.xml -g ../demo/test/test-graph.txt -w ../demo/test/test-workload.xml -r ../demo/test/

#cd querytranslate
#./test -w ../"$folder"test-workload.xml -o ../"$folder"test-translated

#cd ../queryinterface
#./test -w ../"$folder"test-workload.xml -t ../"$folder"test-translated -o ../"$folder"test-interface
