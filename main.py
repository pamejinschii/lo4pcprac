import numpy as np

def gauss(A, b):
    n = len(b)
    for i in range(n):
        # Поиск ведущего элемента
        max_row = i + np.argmax(np.abs(A[i:, i]))
        A[[i, max_row]] = A[[max_row, i]]
        b[[i, max_row]] = b[[max_row, i]]
        
        # Приведение к ступенчатому виду
        for j in range(i + 1, n):
            factor = A[j, i] / A[i, i]
            A[j, i:] -= factor * A[i, i:]
            b[j] -= factor * b[i]
    
    # Обратный ход
    x = np.zeros_like(b)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(A[i, i + 1:], x[i + 1:])) / A[i, i]
    return x

# Коэффициенты системы уравнений
A = np.array([[1, 4, -9, 7],
              [2, -2, 2, 3],
              [-1, 3, 9, -2],
              [5, 2, 2, -2]], dtype=float)

# Правая часть
b = np.array([-67, -57, -26, 52], dtype=float)

# Решение системы уравнений
x = gauss(A, b)

print("Решение системы методом Гаусса:", x)
