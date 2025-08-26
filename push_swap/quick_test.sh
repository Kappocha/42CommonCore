#!/bin/bash

# Test simplificado que solo cuenta operaciones
numbers="$@"
operations=$(./push_swap $numbers | wc -l)

# Verificar si es un número razonable de operaciones para el tamaño
size=$#
if [ $size -le 3 ]; then
    max_ops=3
elif [ $size -le 5 ]; then
    max_ops=12
elif [ $size -le 100 ]; then
    max_ops=700
elif [ $size -le 500 ]; then
    max_ops=5500
else
    max_ops=11500
fi

echo "🔢 Números: $size"
echo "� Operaciones: $operations"
echo "📊 Máximo recomendado: $max_ops"

if [ $operations -le $max_ops ]; then
    echo "✅ DENTRO DEL LÍMITE"
else
    echo "❌ EXCEDE EL LÍMITE"
fi
