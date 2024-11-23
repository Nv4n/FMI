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
        rand_population = [town for town in towns if town != start]
        random.shuffle(rand_population)
        rand_population=[start]+rand_population
        population.append(rand_population)
    return population

def select_population(points,old_gen):
    leftovers =[]
    random.shuffle(old_gen)
    mid = len(old_gen) // 2
    for i in range(mid):
        if total_distance(points,old_gen[i])<total_distance(points,old_gen[i+mid]) :
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
        if(i < end):
            offspring.append(init_sub_path.pop(0))
        else:
            offspring.append(remaining_sub_path.pop(0))
    return offspring

def apply_crossovers(leftover):
    crossovers = []
    random.shuffle(leftover)
    mid = len(leftover)//2
    for i in range(0,len(leftover)):
        fstParent, sndParent = leftover[i],leftover[i+mid]
        for _ in range(2):
            crossovers.append(gen_offspring(fstParent,sndParent))
            crossovers.append(gen_offspring(fstParent,sndParent))
    return crossovers


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