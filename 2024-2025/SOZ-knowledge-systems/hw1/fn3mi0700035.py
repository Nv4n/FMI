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

generated = gen_population(romania_map["locations"])