#!/usr/bin/bash


gcc -o seqSumRand seqSumRand.c

perf stat -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSumRand 10000000

