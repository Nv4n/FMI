# Домашно за търговски пътник с генетичен алгоритъм

## 1. описание на предложения/използвания метод за решаване на задачата в свободен формат;

## 2. Реализация чрез псевдо код
```sql
DEFINE romania_map AS DICTIONARY
SET romania_map["locations"] TO:
    Arad -> (91, 492)
    Bucharest -> (400, 327)
    Craiova -> (253, 288)
    ...
    Zerind -> (108, 531)

FUNCTION distance(begin, end):
    RETURN Euclidean distance BETWEEN begin AND end

FUNCTION total_distance(points, path):
    INITIALIZE total_distance AS 0
    FOR i FROM 1 TO LENGTH(path):
        ADD distance(points[path[i-1]], points[path[i]]) TO total_distance
    RETURN total_distance

FUNCTION gen_population(destinations):
    INITIALIZE population AS EMPTY LIST
    FOR 100,000 ITERATIONS:
        CREATE rand_population AS A RANDOM SHUFFLE OF destinations.keys()
        PREPEND START LOCATION (0) TO rand_population
        APPEND rand_population TO population
    RETURN population

FUNCTION choose_best_pop(points, old_gen):
    INITIALIZE best_gen AS EMPTY LIST
    SHUFFLE old_gen RANDOMLY
    SET mid TO HALF OF LENGTH(old_gen)
    FOR i FROM 0 TO mid - 1:
        IF total_distance(points, old_gen[i][1:]) IS LESS THAN total_distance(points, old_gen[i + mid][1:]):
            APPEND old_gen[i] TO best_gen
        ELSE:
            APPEND old_gen[i + mid] TO best_gen
    RETURN best_gen
```

## 3. Реализация чрез Python код

```python
import math
import random
from pprint import pprint as pp

from utils import *

romania_map={}
romania_map["locations"] = dict(
Arad=(91, 492), Bucharest=(400, 327), Craiova=(253, 288),
Drobeta=(165, 299), Eforie=(562, 293), Fagaras=(305, 449),
Giurgiu=(375, 270), Hirsova=(534, 350), Iasi=(473, 506),
Lugoj=(165, 379), Mehadia=(168, 339), Neamt=(406, 537),
Oradea=(131, 571), Pitesti=(320, 368), Rimnicu=(233, 410),
Sibiu=(207, 457), Timisoara=(94, 410), Urziceni=(456, 350),
Vaslui=(509, 444), Zerind=(108, 531))

def distance(begin, end) :
    return math.dist(begin,end)
    
def total_distance(points,path):
    return sum(distance(points[path[i-1]],points[path[i]]) for i in range(len(path)))

def gen_population(destinations):
    population = []
    for _ in range(100000):
        rand_population = list (destinations.keys())
        random.shuffle(rand_population)
        rand_population=[0]+rand_population
        population.append(rand_population)
    return population

def choose_best_pop(points,old_gen):
    best_gen =[]
    random.shuffle(old_gen)
    mid = len(old_gen) // 2
    for i in range(mid):
        if total_distance(points,old_gen[i][1:])<total_distance(points,old_gen[i+mid][1:]) :
            best_gen.append(old_gen[i])
        else:
            best_gen.append(old_gen[i+mid])
    return best_gen

generated = gen_population(romania_map["locations"])
pp(len(choose_best_pop(romania_map["locations"],generated)))
```

## 4. Инструкции за компилиране

## 5. Примерни резултати