#!/bin/csh
@ inicio = 5000
@ fin = 200000
@ incremento = 8000
set ejecutable = burbuja
set salida = tiempos_busqueda_burbuja.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
