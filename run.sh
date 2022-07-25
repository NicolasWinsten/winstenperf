#!/usr/bin/bash


gcc -o seqSum seqSum.c

jsrun --erf_input core0erf perf stat -o perfout -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 1
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 1
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 1


jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 2
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 2
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 2


jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 3
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 3
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 3



jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 10
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 10
jsrun --erf_input core0erf perf stat -o perfout --append -e instructions:u,cycles:u,LLC-load-misses,L1-dcache-load-misses,pm_l2_ld_miss ./seqSum 1000000000 10
