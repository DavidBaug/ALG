#!/bin/csh
#################################################################
# Script para lanzar un conjunto de algoritmos, 
# con un número creciente de entradas y capturar 
# sus salidas en ficheros.
#
# USO: ./script_name <algoritmo1> <algoritmo2> ... <algoritmoN>
# 
# PRECONDICIONES: los parámetros que se le pasan, deben de ser
# programas ejecutables, que acepten un parámetro (la entradas 
# que van a procesar).
#################################################################

#VARIABLES:
@ inicio = 5000 #tamaño de la entrada inicial
@ fin = 200000 #tamaño hasta el que se pretende llegar
@ incremento = 500 #incremento entre entrada y entrada
@ i = $inicio
@ u = 1
set nombre_fichero = "tiempos_"


#PROGRAMA:
while ($u <= $#argv)
	@ i = $inicio 
	while ($i <= $fin)
		echo "Ejecutando : $argv[$u] con tamanio de entrada $i"
		echo "`./$argv[$u] $i` ">> $nombre_fichero$argv[$u].dat
		@ i += $incremento
	end
	@ u++
end

#fin