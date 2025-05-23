from skyfield.api import load
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.lines import Line2D

# Зареждане на ефемериди и време
planets = load('de421.bsp')
ts = load.timescale()
t = ts.utc(2002, 1, 21)

# Център: Слънцето
sun = planets['sun']

# Данни за планетите
planet_data = [
    ('Mercury', 'mercury', 'gray'),
    ('Venus', 'venus', 'orange'),
    ('Earth', 'earth', 'blue'),
    ('Mars', 'mars', 'red'),
    ('Jupiter', 'jupiter barycenter', 'brown'),
    ('Saturn', 'saturn barycenter', 'gold'),
    ('Uranus', 'uranus barycenter', 'lightblue'),
    ('Neptune', 'neptune barycenter', 'darkblue')
]

positions = []
orbital_radii = []
labels = []
colors = []

for label, name, color in planet_data:
    planet = planets[name]
    vector = planet.at(t).observe(sun).ecliptic_position().au
    positions.append(vector)
    orbital_radii.append(np.linalg.norm(vector))
    labels.append(label)
    colors.append(color)

positions = np.array(positions)
x, y = positions[:, 0], positions[:, 1]

# Настройка на графиката
fig, ax = plt.subplots(figsize=(12, 12))

# Орбити
for r in orbital_radii:
    orbit = plt.Circle((0, 0), r, color='lightgray', linestyle='--', fill=False, zorder=1)
    ax.add_artist(orbit)

# Слънце
ax.scatter(0, 0, color='yellow', s=400, edgecolors='black', zorder=5)

# Планети и текстове
label_offset = 1.25 # по-голямо отместване на имената
for i, label in enumerate(labels):
    ax.scatter(x[i], y[i], color=colors[i], s=120, edgecolors='black', zorder=6)
    ax.text(
        x[i] + label_offset, y[i] + label_offset,
        label,
        fontsize=10,
        weight='normal',
        color='blue',
        zorder=10
    )

# Легенда
legend_elements = [
    Line2D([0], [0], marker='o', color='w', label=label,
           markerfacecolor=color, markersize=10, markeredgecolor='black')
    for label, _, color in planet_data
]
legend = ax.legend(
    handles=legend_elements,
    loc='upper right',
    title='Планети',
    frameon=True,
    fontsize=10
)
ax.add_artist(legend)

# Оформление
ax.set_title('Положение и орбити на планетите на 21 януари 2002', fontsize=14)
ax.set_xlabel('Астрономически единици (AU)')
ax.set_ylabel('Астрономически единици (AU)')
ax.set_aspect('equal', 'box')
ax.grid(True, linestyle=':', alpha=0.6)

# Автоматично мащабиране
buffer = 5
max_range = max(orbital_radii) + buffer
ax.set_xlim(-max_range, max_range)
ax.set_ylim(-max_range, max_range)

plt.tight_layout()
plt.show()
