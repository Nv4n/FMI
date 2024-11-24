# Домашно за търговски пътник с генетичен алгоритъм
    Автор: Иван Петров
    ФН: 3MI0700035

## 1. Описание на метод на решение
    Първоначални данни:
    romania_map.locations = dict(
    Arad=(91, 492), Bucharest=(400, 327), Craiova=(253, 288),
    Drobeta=(165, 299), Eforie=(562, 293), Fagaras=(305, 449),
    Giurgiu=(375, 270), Hirsova=(534, 350), Iasi=(473, 506),
    Lugoj=(165, 379), Mehadia=(168, 339), Neamt=(406, 537),
    Oradea=(131, 571), Pitesti=(320, 368), Rimnicu=(233, 410),
    Sibiu=(207, 457), Timisoara=(94, 410), Urziceni=(456, 350),
    Vaslui=(509, 444), Zerind=(108, 531))

> Избрания алгоритъм на решение е генетичен алгоритъм написан в Python. 
> Използва се състезателния метод на решение, където случайно избрани групи
> от индивидуални извадки се съпоставят две по две. Използва се, за да предотврати
> получаване на шум в популацията от фитнес функцията в началните стадии.
> Сравнението между извадките е базирано на общата дължина на пътя.

## 2. Реализация чрез псевдо код
```sql
FUNCTION DISTANCE(begin, end) RETURNS a number
    RETURN distance BETWEEN coordinates of begin AND end

FUNCTION TOTAL-DISTANCE(points, path) RETURNS a number
    RETURN SUM OF distances FOR ALL consecutive pairs IN path

FUNCTION GENERATE-INITIAL-POPULATION(towns, start, population_size) RETURNS a population
    population ← EMPTY LIST
    REPEAT population_size TIMES
        random_population ← SHUFFLE(towns EXCLUDING start)
        PREPEND start TO rand_population
        ADD random_population TO population
    RETURN population

FUNCTION SELECT-POPULATION(points, old_generation) RETURNS a selected_population
    leftovers ← EMPTY LIST
    middle ← HALF LENGTH OF old_gen
    FOR i FROM 0 TO middle DO
        IF TOTAL-DISTANCE(points, old_generation[i]) < TOTAL-DISTANCE(points, old_generation[i + middle])
            APPEND old_generation[i] TO leftovers
        ELSE
            APPEND old_generation[i + middle] TO leftovers
    RETURN leftovers

FUNCTION GENERATE-OFFSPRING(firstParent, secondParent) RETURNS an offspring
    offspring ← EMPTY LIST
    start ← RANDOM NUMBER FROM 0 TO LENGTH(firstParent)-1
    end ← RANDOM NUMBER FROM start TO LENGTH(firstParent)
    initial_sub_path ← GET firstParent FROM start TO end
    remaining_sub_path ← GET TOWNS FROM secondParent IF NOT IN initial_sub_path
    FOR i FROM 0 TO LENGTH firstParent DO
        IF start <= i < end
            APPEND NEXT ELEMENT FROM initial_sub_path TO offspring
        ELSE
            APPEND NEXT ELEMENT FROM remaining_sub_path TO offspring
    RETURN offspring

FUNCTION APPLY-CROSSOVERS(leftovers) RETURNS a population
    crossovers ← EMPTY LIST
    RANDOM SHUFFLE leftovers 
    middle ← HALF LENGTH OF leftovers
    REPEAT middle TIMES
        firstParent ← leftover[i]
        secondParent ← leftover[i + middle]
        REPEAT 2 TIMES
            APPEND GENERATE-OFFSPRING(firstParent, secondParent) TO crossovers
            APPEND GENERATE-OFFSPRING(secondParent, firstParent) TO crossovers
    RETURN crossovers

FUNCTION APPLY-MUTATIONS(crossovers) RETURNS a mutated_population
    mutated_population ← EMPTY LIST
    FOR path IN crossovers DO
        IF RANDOM NUMBER FROM 0 TO 1000 < 9 THEN
            firstIndex ← RANDOM NUMBER FROM 1 TO LENGTH(path)-1
            secondIndex ← RANDOM NUMBER FROM 1 TO LENGTH(path)-1
            SWAP path[firstIndex] AND path[secondIndex]
        APPEND path TO mutated_population
    RETURN mutated_population

FUNCTION APPLY-POPULATION-LIFECYCLE(points, old_generation) RETURNS a population
    leftovers ← SELECT-POPULATION(points, old_generation)
    crossovers ← APPLY-CROSSOVERS(leftovers)
    new_population ← APPLY-MUTATIONS(crossovers)
    RETURN new_population

FUNCTION PLOT-PATH(towns, points, path)
    PLOT the path AND annotate points WITH their town names

SETUP PARAMETERS
    romania_map ← {locations: {TOWN_NAME: (COORDINATE_X, COORDINATE_Y), ...}}
    towns ← KEYS(romania_map["locations"])
    START_TOWN = "TOWN_NAME"
    INITIAL_POPULATION_SIZE = 1000
    GENERATION_COUNT = 250
    initial_population ← GENERATE-INITIAL-POPULATION(towns, START_TOWN, INITIAL_POPULATION_SIZE)
    latest_generation ← initial_population

REPEAT GENERATION_COUNT TIMES
    PRINT "Generation #" + i
    latest_generation ← APPLY-POPULATION-LIFECYCLE(romania_map["locations"], latest_generation)

SORT latest_generation BY TOTAL-DISTANCE(romania_map["locations"])
PRINT "Plotting!"
PRINT "Start town: " + START_TOWN
PRINT latest_generation[0]
PRINT "Best distance: " + TOTAL-DISTANCE OF latest_generation[0]

PLOT-PATH(towns, romania_map["locations"], latest_generation[0])
```

## 3. Реализация чрез Python код

```python
import math
import random
from pprint import pprint as pp
import matplotlib.pyplot as plt

INIT_POP_SIZE = 1000
START_TOWN = "Hirsova"
GENERATION_COUNT = 250

def distance(begin, end) :
    return math.dist(begin,end)

def total_distance(points,path):
    return sum(distance(points[path[i-1]],points[path[i]]) for i in range(len(path)))

def gen_init_population(towns, start, pop_size=INIT_POP_SIZE):
    population = []
    for _ in range(pop_size):
        rand_population = [town for town in towns if town != start]
        random.shuffle(rand_population)
        rand_population=[start]+rand_population
        population.append(rand_population)
    return population

def select_population(points,old_gen):
    leftovers = []
    mid = len(old_gen) // 2
    for i in range(mid):
        if total_distance(points,old_gen[i])<total_distance(points,old_gen[i+mid]):
            leftovers.append(old_gen[i])
        else:
            leftovers.append(old_gen[i+mid])
    return leftovers

def gen_offspring(fstParent,sndParent):
    offspring = []
    start = random.randint(0,len(fstParent)-1)
    end = random.randint(start,len(fstParent))
    init_sub_path = fstParent[start:end]
    remaining_sub_path = [town for town in sndParent if town not in init_sub_path]
    for i in range(0,len(fstParent)):
        if(start <= i < end):
            offspring.append(init_sub_path.pop(0))
        else:
            offspring.append(remaining_sub_path.pop(0))
    return offspring

def apply_crossovers(leftovers):
    crossovers = []
    random.shuffle(leftovers)
    mid = len(leftovers) // 2
    for i in range(mid):
        fstParent, sndParent = leftovers[i],leftovers[i+mid]
        for _ in range(2):
            crossovers.append(gen_offspring(fstParent,sndParent))
            crossovers.append(gen_offspring(fstParent,sndParent))
    return crossovers

def apply_mutations (crossovers):
    mutated_pop = []
    for path in crossovers:
        if random.randint(0,1000)<9 :
            fstInd = random.randint(1,len(path)-1)
            sndInd = random.randint(1,len(path)-1)
            path[fstInd],path[sndInd] = path[sndInd],path[fstInd]
        mutated_pop.append(path)
    return mutated_pop

def apply_population_lifecycle(points, old_gen):
    leftovers = select_population(points,old_gen)
    crossovers = apply_crossovers(leftovers)
    new_population = apply_mutations(crossovers)
    return new_population

def plotPath(towns,points,path):
    for i in range(len(towns)):
        if towns[i] != START_TOWN:
            plt.text(points[towns[i]][0] + 2, points[towns[i]][1] + 0.25, towns[i], fontsize=9)
        else:
            plt.text(points[towns[i]][0] + 2, points[towns[i]][1] + 0.25, towns[i], fontsize=9,color="blue")
    
    x_coords=[]
    y_coords=[]
    for i in range(len(path)):
        x_coords.append(points[path[i]][0])
        y_coords.append(points[path[i]][1])

    x_directions=[]
    y_directions=[]
    for i in range(len(x_coords)):
        x_direct = x_coords[i-1]-x_coords[i]
        y_direct = y_coords[i-1]-y_coords[i]
        x_directions.append(x_direct)
        y_directions.append(y_direct)
    
    plt.quiver(x_coords,y_coords,x_directions,y_directions,angles='xy', scale_units='xy', scale=1,color="orange")
    x_coords.append(x_coords[0])
    y_coords.append(y_coords[0])

    
    plt.scatter(x_coords,y_coords,color="red")
    plt.title("Traveling Salesman Problem")
    plt.xlabel("X Coordinate")
    plt.ylabel("Y Coordinate")
    plt.show()

romania_map={}
romania_map["locations"] = dict(
Arad=(91, 492), Bucharest=(400, 327), Craiova=(253, 288),
Drobeta=(165, 299), Eforie=(562, 293), Fagaras=(305, 449),
Giurgiu=(375, 270), Hirsova=(534, 350), Iasi=(473, 506),
Lugoj=(165, 379), Mehadia=(168, 339), Neamt=(406, 537),
Oradea=(131, 571), Pitesti=(320, 368), Rimnicu=(233, 410),
Sibiu=(207, 457), Timisoara=(94, 410), Urziceni=(456, 350),
Vaslui=(509, 444), Zerind=(108, 531))


towns = list(romania_map['locations'].keys())
init_population = gen_init_population(towns,START_TOWN)

latest_gen = init_population

for i in range(GENERATION_COUNT):
    print(f"Generation #{i}")
    latest_gen = apply_population_lifecycle(romania_map["locations"],latest_gen)

sorted(latest_gen,key=lambda x: total_distance(romania_map["locations"],x))

pp("Plotting!")
pp(f"Start town: {START_TOWN}")
pp(latest_gen[0])
pp("Best distance {0:.2f}".format(total_distance(romania_map["locations"],latest_gen[0])))

plotPath(towns,romania_map["locations"],latest_gen[0])
```

## 4. Инструкции за компилиране

> ### Използвана среда на разработка:
>
> - Python 3.12.x
> - IDE: VSCode
> - Кода се възпроизвежда чрез команди в терминала

> ### Преди компилация:
>
> - Избирането на начален град се получава чрез смяна на променливата **START_TOWN** (в диаграмата се представя със син цвят градът начало)
> - Смяната на размера на популацията става чрез смяна на променливата **INIT_POP_SIZE** (за оптималност на бързина на алгоритъма и намляване на стагнацията му е сложено като **1000**)
> - Смяната на максималния брой поколения става чрез смяна на променливата **GENERATION_COUNT** (оптимални резултати при популация **1000** се забелязва при **поколения >=№200** )

> ### Стъпки за компилация:
>
> 1. cd directory_of_homework
> 2. python -m pip install -U pip
> 3. python -m pip install -U matplotlib
> 4. python fn3mi0700035.py

## 5. Примерни резултати

> ### Start town: Hirsova
> - Best distance: ~1589.84 (при различни опити може да варира до ~1860)
> - Път: Hirsova-> Vaslui-> Iasi-> Neamt-> Fagaras-> Rimnicu-> Sibiu-> Oradea-> Zerind-> Arad-> Timisoara-> Lugoj-> Mehadia-> Drobeta-> Craiova-> Pitesti-> Giurgiu-> Bucharest-> Urziceni-> Eforie


![alt text]({A605B7F8-A559-44B9-9249-B4940A7B6308}.png)