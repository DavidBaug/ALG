#!/bin/csh
@ inicio = 100
@ fin = 4500
@ incremento = 50
set ejecutable = floyd
set salida = floyd_david.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
