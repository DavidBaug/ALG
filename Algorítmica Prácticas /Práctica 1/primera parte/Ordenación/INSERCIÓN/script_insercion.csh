#!/bin/csh
@ inicio = 5000
@ fin = 200000
@ incremento = 8000
@ i = $inicio
echo > tiempos.dat
while ( $i <= $fin )
    echo Ejecución tam = $i
    echo $i `./insercion  $i` >> tiempos.dat
    @ i += $incremento
end
