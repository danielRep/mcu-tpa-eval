#!/usr/bin/gnuplot --persist

#unset key

unset grid
set border 1
set grid ytics mytics  # draw lines for each ytics and mytics
set mytics 2
unset my2tics
unset mytics
unset ytics
set ytics nomirror

set grid ytics lc rgb "#555555" lw 1 lt 0
set term pdfcairo

set auto x
set style data histogram
set style histogram cluster gap 1
set xtic scale 0


set style fill solid
set xtics rotate by 30 right

set logscale y 10
set yrange [0.5:26]
set tmargin at screen 0.90
set bmargin at screen 0.12
set lmargin at screen 0.04
set rmargin at screen 1


set key auto columnheader
set key at graph 1, 1.12
#set title title_arg

set output path.'/interf.pdf'
set terminal pdfcairo font "times new roman,9" size 6,2.7
set format y "%gx"

# Add more ticks to the y-axis
set ytics add ("0x" 0.5, 10, 25)
#set ytics

#set arrow from 0.,avg to 10., avg nohead front lc rgb "#555555" lw 2  dashtype "-"

# plot 'languages.data' using 2:xtic(1) ti col fc rgb C,
# 			'' u 3 ti col fc rgb Cpp, 
# 			'' u 4 ti col fc rgb Java, 
# 			'' u 5 ti col fc rgb Python

set linetype  1 lc rgb '#b2e061' lw 1 # blue
set linetype  2 lc rgb '#7eb0d5' lw 1 # orange
set linetype  3 lc rgb '#bd7ebe' lw 1 # yellowbd7ebe
set linetype  4 lc rgb '#fd7f6f' lw 1 # purple
set linetype  5 lc rgb '#ffb55a' lw 1 # green
set linetype  6 lc rgb '#ffee65' lw 1 # light-blue
set linetype  7 lc rgb '#beb9db' lw 1 # red
set linetype cycle  8
set boxwidth 0.7

set grid ytics mytics  # draw lines for each ytics and mytics
#set mytics 2
unset grid

graphable=path."/interf.dat"
plot \
	graphable using 2:xtic(1), \
	'' u 4, \
	'' u 6, \
	'' u 8, \
	'' u ($0):2:3 with labels rotate by 90 left offset -2.4,0.5 font ",7" ,  \
	'' u ($0):4:5 with labels rotate by 90 left offset -0.8,0.5 font ",7" ,  \
	'' u ($0):6:7 with labels rotate by 90 left offset 0.6,0.5 font ",7" ,  \
	'' u ($0):8:9 with labels rotate by 90 left offset 2.0,0.5 font ",7" ,  \