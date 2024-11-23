import math
import random
from pprint import pprint as pp

INIT_POP_SIZE = 10000

def distance(begin, end) :
    return math.dist(begin,end)
    
def total_distance(points,path):
    return sum(distance(points[path[i-1]],points[path[i]]) for i in range(len(path)))

def gen_init_population(towns,start, pop_size=INIT_POP_SIZE):
    population = []
    for _ in range(pop_size):
        rand_population = [key for key in towns.keys() if key != start]
        random.shuffle(rand_population)
        rand_population=[start]+rand_population
        population.append(rand_population)
    return population

def choose_best_pop(towns,old_gen):
    best_gen =[]
    random.shuffle(old_gen)
    mid = len(old_gen) // 2
    for i in range(mid):
        if total_distance(towns,old_gen[i])<total_distance(towns,old_gen[i+mid]) :
            best_gen.append(old_gen[i])
        else:
            best_gen.append(old_gen[i+mid])
    return best_gen

romania_map={}
romania_map["locations"] = dict(
Arad=(91, 492), Bucharest=(400, 327), Craiova=(253, 288),
Drobeta=(165, 299), Eforie=(562, 293), Fagaras=(305, 449),
Giurgiu=(375, 270), Hirsova=(534, 350), Iasi=(473, 506),
Lugoj=(165, 379), Mehadia=(168, 339), Neamt=(406, 537),
Oradea=(131, 571), Pitesti=(320, 368), Rimnicu=(233, 410),
Sibiu=(207, 457), Timisoara=(94, 410), Urziceni=(456, 350),
Vaslui=(509, 444), Zerind=(108, 531))

START_TOWN = "Bucharest"

generated = gen_init_population(romania_map["locations"],START_TOWN)
pp(generated[50])
pp(len(choose_best_pop(romania_map["locations"],generated)))