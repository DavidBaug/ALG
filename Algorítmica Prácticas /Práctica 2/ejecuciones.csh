#!/bin/csh
@ inicio = 1
@ fin = 500001
@ incremento = 10000
set ejecutable = ./preferences
set salida = tiempos_prefences.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
