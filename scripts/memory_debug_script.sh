#!/bin/bash

cd build/

valgrind ./nippy &>> ../logs/memory_log.txt
