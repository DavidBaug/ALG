#!/bin/csh
@ inicio = 2000
@ fin = 500000
@ incremento = 500
set ejecutable = insercion
set salida = tiempos_insercion.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
