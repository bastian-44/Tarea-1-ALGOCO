import matplotlib.pyplot as plt

# Tamaños de los datasets
tamanios = [1000, 10000, 100000, 1000000, 10000000]

# Tiempos obtenidos
mergesort_tiempos = [0.07773, 0.0943855, 0.20003, 1.08303, 11.1108]
quicksort_tiempos = [0.461522, 3.906,3.906,3.906,3.906]
sort_tiempos = [0.124949, 0.0678193, 0.10468, 0.418436, 5.04735]

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
plt.title('Comparación de tiempos de ejecución de algoritmos de ordenamiento con data set parcialmente ordenado')
plt.legend()
plt.grid(True, which="both", ls="--")

# Mostrar el gráfico
plt.show()

