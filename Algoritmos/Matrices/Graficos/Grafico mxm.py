import matplotlib.pyplot as plt

# Tamaños de los datasets
tamanios = [10, 100, 500, 1000]

# Tiempos obtenidos

Cubico = [0.0186513,	 0.0163802,	2.3764,	24.51010]
Cubico_Transpuesto = [0.0161686,	0.018233,	2.16234,24.77120]
Strassen = [0.892124,	0.919176,	41.1719,286.508]
# Crear el gráfico
plt.figure(figsize=(10,6))
plt.plot(tamanios, Cubico, label='Cubico', marker='o')
plt.plot(tamanios, Cubico_Transpuesto, label='Cubico_Transpuesto', marker='s')
plt.plot(tamanios, Strassen, label='Strassen', marker='^')

# Configuraciones del gráfico
plt.xscale('log')  # Escala logarítmica para el eje x
plt.yscale('log')  # Escala logarítmica para el eje y
plt.xlabel('Tamaño del dataset')
plt.ylabel('Tiempo de ejecución (segundos)')
plt.title('Comparación de tiempos de ejecución de algoritmos multiplicación de matrices')
plt.legend()
plt.grid(True, which="both", ls="--")

# Mostrar el gráfico
plt.show()

