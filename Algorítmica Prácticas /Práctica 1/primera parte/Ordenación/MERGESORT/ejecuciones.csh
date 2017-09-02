#!/bin/csh
@ inicio = 1
@ fin = 30000000
@ incremento = 1200000
set ejecutable = mergesort
set salida = tiempos_busqueda_mergesort.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
