''' (А. Кабанов) Два игрока, Петя и Ваня, играют в следующую игру. Перед игроками лежат две кучи камней. Игроки ходят по очереди, первый ход делает Петя. За один ход игрок может убрать из одной из куч один камень или уменьшить количество камней в куче в два раза (если количество камней в куче нечётно, остаётся на 1 камень больше, чем убирается). Например, пусть в одной куче 6, а в другой 9 камней; такую позицию мы будем обозначать (6, 9). За один ход из позиции (6, 9) можно получить любую из четырёх позиций: (5, 9), (3, 9), (6, 8), (6, 5). Игра завершается в тот момент, когда суммарное количество камней в кучах становится не более 30. Победителем считается игрок, сделавший последний ход, то есть первым получивший позицию, в которой в кучах будет 30 или меньше камней. В начальный момент в первой куче было 18 камней, во второй куче – S камней, S > 12.
Ответьте на следующие вопросы:
  Вопрос 1. Найдите значение S, при котором Ваня выигрывает своим первым ходом при любой игре Пети.
  Вопрос 2. Найдите минимальное и максимальное значение S, при котором у Пети есть выигрышная стратегия, причём одновременно выполняются два условия:
− Петя не может выиграть за один ход;
− Петя может выиграть своим вторым ходом независимо от того, как будет ходить Ваня.
Найденные значения запишите в ответе в порядке возрастания.
  Вопрос 3. Найдите значение S, при котором одновременно выполняются два условия:
– у Вани есть выигрышная стратегия, позволяющая ему выиграть первым или вторым ходом при любой игре Пети;
– у Вани нет стратегии, которая позволит ему гарантированно выиграть первым ходом. '''

from functools import lru_cache

def moves(h):
    a, b = h;
    result = []
    
    if (a > 0):
        result.append((a-1, b))
    if (b > 0):
        result.append((a, b-1))
    if (a > 1):
        result.append((a - a//2, b))
    if (b > 1):
        result.append((a, b - b//2))
    return result
    

@lru_cache(None)

def f(h):
    next = lambda *condition: (f(m) in condition for m in moves(h))
    
    if (sum(h) <= 30):
        return 'СР'
    
    elif any(next('СР')):
        return 'П1'
    elif all(next('П1')):
        return 'В1'
    elif any(next('В1')):
        return 'П2'
    elif all(next('П1', 'П2')):
        return 'В2'

for i in range(13, 95):
    print(i, '->', f((18, i)))