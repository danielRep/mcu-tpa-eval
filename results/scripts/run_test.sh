#/bin/bash

gnuplot -e "path='${1}'; title_arg='${2}'" "results/scripts/${3}"