#!/usr/bin/gnuplot --persist

set border 15

set grid ytics lc rgb "#555555" lw 1 lt 0
set term pdfcairo

set auto x
set style data histogram
set style histogram cluster gap 1
set xtic scale 0

set ylabel "Rel. Perf. Degradation"

set style fill solid
set xtics rotate by 30 right

#set key auto columnheader
set key inside top right horizontal

set output path.'/stm.pdf'

#size of window
set terminal pdfcairo font "times new roman,10" size 5,1.8

set linetype  1 lc rgb '#FE9D52' lw 1
set linetype cycle  8
set ytics add ("0" 0.1)
set logscale y 10


#size of coloumns
set boxwidth 0.4

#set grid ytics mytics  # draw lines for each ytics and mytics
#set mytics 2
#unset grid

graphable=path."/interf.dat"
plot \
	graphable using 2:xtic(1) title 'ctt5'#, \
	#'' u 4, \