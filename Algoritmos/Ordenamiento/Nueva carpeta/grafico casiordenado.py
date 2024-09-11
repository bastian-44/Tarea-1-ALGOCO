import matplotlib.pyplot as plt

# Tamaños de los datasets
tamanios = [1000, 10000, 100000, 1000000, 10000000]

# Tiempos obtenidos
mergesort_tiempos = [0.717775, 0.0894176, 0.173, 1.000084, 10.0146]
quicksort_tiempos = [0.603999, 5.3037, 5.3037, 5.3037, 5.3037]
sort_tiempos = [0.0735287, 0.0696109, 1.138876, 0.356397, 4.40867]

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
plt.title('Comparación de tiempos de ejecución de algoritmos de ordenamiento con dataset casi ordenado')
plt.legend()
plt.grid(True, which="both", ls="--")

# Mostrar el gráfico
plt.show()

