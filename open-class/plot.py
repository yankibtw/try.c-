import numpy as np
import matplotlib.pyplot as plt

# Функция
def f(x):
    return np.exp(2 * x) * np.sin(2 * x + 3)

# Границы
# Примерные значения
a, b = 1.9, 3.1
x = np.linspace(a, b, 500)
y = f(x)

# Построение графика
plt.figure(figsize=(10, 6))
plt.plot(x, y, label=r"$f(x) = e^{2x} \sin(2x + 3)$", color="blue")
plt.fill_between(x, y, alpha=0.3, label="Область под графиком", color="cyan")
plt.title("График функции и область интегрирования")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.legend()
plt.grid()
plt.savefig("graph.png")
