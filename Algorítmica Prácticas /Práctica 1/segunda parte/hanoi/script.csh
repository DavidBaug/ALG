#!/bin/csh
@ inicio = 1
@ fin = 35
@ incremento = 1
set ejecutable = hanoi
set salida = hanoi_david.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
