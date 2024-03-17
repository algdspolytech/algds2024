#первый commit test.py , разберемся как решить задачу

def min_cost(X, Y, d, i, e):
    m = len(X)
    n = len(Y)
    
    # Создаем таблицу для сохранения результатов подзадач
    dp = [[0 for x in range(n+1)] for x in range(m+1)]
 
    # Заполняем dp[][] в порядке снизу вверх
    for x in range(m+1):
        for y in range(n+1):
 
            # Если X пуст, то стоимость равна количеству символов в Y
            if x == 0:
                dp[x][y] = y * i   # Min. operations = y
 
            # Если Y пуст, то стоимость равна количеству символов в X
            elif y == 0:
                dp[x][y] = x * d   # Min. operations = x
 
            # Если последние символы одинаковы, игнорируем последний символ
            # и рекурсивно вычисляем для оставшихся строк
            elif X[x-1] == Y[y-1]:
                dp[x][y] = dp[x-1][y-1]
 
            # Если последний символ отличается, рассмотрим все три случая
            else:
                dp[x][y] = min(dp[x][y-1] + i,        # Вставка
                               dp[x-1][y] + d,        # Удаление
                               dp[x-1][y-1] + e)    # Замена
 
    return dp[m][n]

X = "алгоритм"
Y = "аллигатор"
d = 2
i = 3
e = 1
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 8

X = "аллигатор"
Y = "коммутатор"
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 8

X = "коммутатор"
Y = "оператор"
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 7

X = "дом"
Y = "домик"
d = 3
i = 1
e = 2
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 2

X = "мама"
Y = "папа"
d = 2
i = 2
e = 1
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 2

X = "кот"
Y = "котенок"
d = 2
i = 1
e = 2
print(X, "->", Y, min_cost(X, Y, d, i, e))  # Вывод: 4

X = "kitten"
Y = "sitting"
d = 1
i = 3
e = 1
print(X, "->", Y, min_cost(X, Y, d, i, e))

X = "flaw"
Y = "lawn"
d = 1
i = 3
e = 1
print(X, "->", Y, min_cost(X, Y, d, i, e))

X = "kitten"
Y = ""
d = 1
i = 2
e = 1

print(X, "->", Y, min_cost(X, Y, d, i, e))
X = ""
Y = "sitting"
d = 1
i = 2
e = 1
print(X, "->", Y, min_cost(X, Y, d, i, e))
X = "cap"
Y = "dad"
d = 1
i = 2
e = 2
print(X, "->", Y, min_cost(X, Y, d, i, e))

   

