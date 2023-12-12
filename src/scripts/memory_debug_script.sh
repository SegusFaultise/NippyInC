#!/bin/bash

cd build/

valgrind ./nippy >> ../memory_log.txt
