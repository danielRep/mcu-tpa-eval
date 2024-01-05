#!/usr/bin/gnuplot --persist

set border 15

set grid ytics lc rgb "#555555" lw 1 lt 0
set term pdfcairo

set ylabel "Rel. Perf. Degradation"

set style data histogram
set style histogram cluster gap 1

set style fill solid
set xtics rotate by 30 right

set style fill solid


#set key auto columnheader
#set key at graph 1, 1.12
set key inside top right horizontal
#set title "NXP LPC55S69"

set output path.'/nxp.pdf'

#size of window
set terminal pdfcairo font "times new roman,10" size 5,1.8
#set format y "%g"
set logscale y 10
# Add more ticks to the y-axis
#set ytics add ("0" 0.5, 10, 25)
#set ytics

#set arrow from 0.,avg to 10., avg nohead front lc rgb "#555555" lw 2  dashtype "-"

# plot 'languages.data' using 2:xtic(1) ti col fc rgb C,
# 			'' u 3 ti col fc rgb Cpp, 
# 			'' u 4 ti col fc rgb Java, 
# 			'' u 5 ti col fc rgb Python

set linetype  1 lc rgb '#b2e061' lw 1
set linetype  2 lc rgb '#7eb0d5' lw 1
set linetype  3 lc rgb '#FE9D52' lw 1
set linetype  4 lc rgb '#C70039' lw 1
set linetype cycle  8

#size of coloumns
set boxwidth 0.7

#set grid ytics mytics  # draw lines for each ytics and mytics
#set mytics 2
#unset grid

graphable=path."/interf.dat"

plot \
	graphable using 2:xtic(1) title 'cmn1', \
	'' u 4 title 'cmn2', \
	'' u 6 title 'ctt1', \
	'' u 8 title 'ctt2', \
#	'' u ($0):2:3 with labels rotate by 90 left offset -2.4,0.5 font ",7" ,  \
#	'' u ($0):4:5 with labels rotate by 90 left offset -0.8,0.5 font ",7" ,  \
#	'' u ($0):6:7 with labels rotate by 90 left offset 0.6,0.5 font ",7" ,  \
