#!/usr/local/bin/gnuplot -persist
# set terminal pngcairo  transparent enhanced fontscale 1.0 size 600, 400 
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
#     'histogram.dat' using 1:($2+0.25):2 with labels title ""


#set style fill   solid 0.40 noborder
#set format y "%.1f" 
#set key fixed center top vertical Left reverse enhanced autotitle nobox
#set samples 500, 500
#set style data lines
#set xtics  norangelimit 
#set xtics   ("-Ï€" -3.14159, "-Ï€/2" -1.57080, 0.00000, "Ï€/2" 1.57080, "Ï€" 3.14159)
#set title "Polynomial approximation of sin(x)" 
#set xrange [ -3.20000 : 3.20000 ] noreverse nowriteback
#set x2range [ * : * ] noreverse writeback
#set yrange [ * : * ] noreverse writeback
#set y2range [ * : * ] noreverse writeback
#set zrange [ * : * ] noreverse writeback
#set cbrange [ * : * ] noreverse writeback
#set rrange [ * : * ] noreverse writeback
#set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
#approx_1(x) = x - x**3/6
#approx_2(x) = x - x**3/6 + x**5/120
#approx_3(x) = x - x**3/6 + x**5/120 - x**7/5040
#NO_ANIMATION = 1
#label1 = "x - {x^3}/3!"
#label2 = "x - {x^3}/3! + {x^5}/5!"
#label3 = "x - {x^3}/3! + {x^5}/5! - {x^7}/7!"
#save_encoding = "utf8"
### Last datafile plotted: "+"
#plot '+' using 1:(sin($1)):(approx_1($1)) with filledcurve title label1 lt 3,      '+' using 1:(sin($1)):(approx_2($1)) with filledcurve title label2 lt 2,      '+' using 1:(sin($1)):(approx_3($1)) with filledcurve title label3 lt 1,      sin(x) with lines lw 1 lc rgb "black"
