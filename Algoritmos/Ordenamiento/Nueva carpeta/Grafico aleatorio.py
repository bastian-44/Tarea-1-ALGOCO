import matplotlib.pyplot as plt

# Tamaños de los datasets
tamanios = [1000, 10000, 100000, 1000000, 10000000]

# Tiempos obtenidos
mergesort_tiempos = [0.0856064, 0.104651, 0.211708, 1.28852, 12.9047]
quicksort_tiempos = [0.0347743, 0.0379118, 0.0641591, 0.439666, 5.090149]
sort_tiempos = [0.0406647, 0.043769, 0.104954, 0.556559, 5.96162]

# Crear el gráfico
plt.figure(figsize=(10,6))
plt.plot(tamanios, mergesort_tiempos, label='MergeSort', marker='o')
plt.plot(tamanios, quicksort_tiempos, label='QuickSort', marker='s')
plt.plot(tamanios, sort_tiempos, label='Sort (Función estándar)', marker='^')

# Configuraciones del gráfico
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.xlabel('Tamaño del dataset')
plt.ylabel('Tiempo de ejecución (segundos)')
plt.title('Comparación de tiempos de ejecución de algoritmos de ordenamiento con dataset aleatorio')
plt.legend()
plt.grid(True, which="both", ls="--")

# Mostrar el gráfico
plt.show()

