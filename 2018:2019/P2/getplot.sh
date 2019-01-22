#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Iteration"
set ylabel "Time"
plot 'built/times.txt' using 1:2 t "Datos columna tiempo real frente a iteraciones" w l, 'built/times.txt' using 1:3 t "Datos columna tiempo estimado frente a iteraciones" w l
_end_
