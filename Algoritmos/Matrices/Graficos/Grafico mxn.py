import matplotlib.pyplot as plt

# Tamaños de los datasets
tamanios = [10, 100, 500, 1000]

# Tiempos obtenidos

Cubico = [0.000042,0.0364916,5.03684,59.436]
Cubico_Transpuesto = [0.0000384,0.0364257,5.07338,59.2352]
Strassen = [0.0030384, 1.00889, 51.0370, 374.345]
0.0000384,0.0364257,5.07338

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

