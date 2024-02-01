#!/usr/local/bin/gnuplot -persist
reset 
set term pdf
set output 'Basic Blocks Histogram.pdf'

set boxwidth 0.5
set grid ytics linestyle 0
set style fill solid 0.20 border 
set title "Basic Block Sizes"
set xlabel "Number of Instructions"
set ylabel "Number of Blocks"
set yrange [0:] noreverse writeback

plot 'histogram.dat' using 0:2:xtic(1) with boxes lc rgb "#0045FF" title "Number of Blocks in llvm code"
