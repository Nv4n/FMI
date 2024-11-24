import math
import random
from pprint import pprint as pp
import matplotlib.pyplot as plt

INIT_POP_SIZE = 5000

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

def apply_crossovers(leftover):
    crossovers = []
    random.shuffle(leftover)
    mid = len(leftover) // 2
    for i in range(mid):
        fstParent, sndParent = leftover[i],leftover[i+mid]
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
        plt.text(points[towns[i]][0] + 2, points[towns[i]][1] + 0.25, towns[i], fontsize=9)
    
    x_coords=[]
    y_coords=[]
    for i in range(len(path)):
        x_coords.append(points[path[i]][0])
        y_coords.append(points[path[i]][1])

    for i in range(len(x_coords)):
        x_start,x_end = x_coords[i-1],x_coords[i]
        y_start,y_end = y_coords[i-1],y_coords[i]
        plt.arrow(x_start, y_start, (x_end - x_start)*.95, (y_end - y_start)*.95, head_width=10, head_length=7, fc='orange', ec='orange')
    
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

START_TOWN = "Hirsova"

towns = list(romania_map['locations'].keys())
init_population = gen_init_population(towns,START_TOWN)

latest_gen = init_population

for i in range(100):
    print(f"Generation #{i}")
    latest_gen = apply_population_lifecycle(romania_map["locations"],latest_gen)

print("Plotting!")
sorted(latest_gen,key=lambda x: total_distance(romania_map["locations"],x))
pp(len(latest_gen[0]))
pp(latest_gen[0])

pp("Best distance {0}".format(total_distance(romania_map["locations"],latest_gen[0])))

plotPath(towns,romania_map["locations"],latest_gen[0])