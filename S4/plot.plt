set terminal png size 500 500 enhanced font "Helveica,20"
set output 'plot.png'
set title "A simple plot of x^2 vs x"
set xlabel "x"
set ylabel "y"
plot "./data.dat" using 1:2 title "Bla"
