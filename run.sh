#!/usr/bin/bash


gcc -o seqSum seqSum.c

perf stat -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000

