import matplotlib.pyplot as plt
import numpy as np

planets = {
    "Меркурий": {"a": 0.387, "e": 0.206, "I": 7.00, "theta": 48.33, "g": 29.12, "L0": 252.25, "T": 0.241},
    "Венера":   {"a": 0.723, "e": 0.007, "I": 3.39, "theta": 76.68, "g": 54.85, "L0": 181.98, "T": 0.615},
    "Земя":   {"a": 1.000, "e": 0.017, "I": 0.00, "theta": 0.00,  "g": 114.20, "L0": 100.46, "T": 1.000},
    "Луната": {"a": 0.00257,"e": 0.0549,"I": 5.145,"theta": 125.08,"g": 318.15,"L0": 115.3654,"T": 27.321661},
    "Марс":    {"a": 1.524, "e": 0.093, "I": 1.85, "theta": 49.56, "g": 286.50, "L0": 355.45, "T": 1.881},
    "Юпитер": {"a": 5.203, "e": 0.049, "I": 1.30, "theta": 100.46, "g": 273.87, "L0": 34.40, "T": 11.862},
    "Сатурн":  {"a": 9.537, "e": 0.056, "I": 2.49, "theta": 113.72, "g": 339.39, "L0": 50.08, "T": 29.457},
    "Уран":  {"a": 19.191, "e": 0.047, "I": 0.77, "theta": 74.00, "g": 96.73, "L0": 314.05, "T": 84.020},
    "Нептун": {"a": 30.068, "e": 0.009, "I": 1.77, "theta": 131.79, "g": 273.18, "L0": 304.22, "T": 164.8},
    "Плутон": {"a": 39.48, "e": 0.2488, "I": 17.16, "theta": 110.30, "g": 113.8, "L0": 238.95, "T": 90560},
}

# Константи
days_since_j2000 = (2002 - 2000) * 365.25 + 20  # Януари 21, 2002 - Януари 1, 2000
# 2D Top-down view (X-Y plane) with orbits

fig, ax = plt.subplots(figsize=(10, 10))

for name, p in planets.items():
    a = p["a"]
    e = p["e"]
    I = np.radians(p["I"])
    theta = np.radians(p["theta"])
    g = np.radians(p["g"])
    L0 = np.radians(p["L0"])
    T = p["T"]
    
    # Mean motion and anomaly
    n = 360 / (T * 365.25)  # deg/day
    M = L0 + np.radians(n * days_since_j2000) - g

    # Solve Kepler's Equation
    E = M
    for _ in range(5):
        E = E - (E - e * np.sin(E) - M) / (1 - e * np.cos(E))
    
    v = 2 * np.arctan2(np.sqrt(1+e)*np.sin(E/2), np.sqrt(1-e)*np.cos(E/2))
    r = a * (1 - e * np.cos(E))

    # Position in orbital plane
    x_orb = r * np.cos(v)
    y_orb = r * np.sin(v)

    # Rotate to ecliptic coordinates (2D projection)
    cos_O = np.cos(theta)
    sin_O = np.sin(theta)
    cos_i = np.cos(I)
    sin_i = np.sin(I)
    cos_wv = np.cos(g + v)
    sin_wv = np.sin(g + v)

    x = r * (cos_O * cos_wv - sin_O * sin_wv * cos_i)
    y = r * (sin_O * cos_wv + cos_O * sin_wv * cos_i)

    ax.plot(x, y, 'o', label=name)
    ax.text(x, y, name, fontsize=9)

    # Draw orbit
    orbit_points = []
    for angle in np.linspace(0, 2*np.pi, 500):
        E_orb = angle
        r_orb = a * (1 - e * np.cos(E_orb))
        v_orb = 2 * np.arctan2(np.sqrt(1+e)*np.sin(E_orb/2), np.sqrt(1-e)*np.cos(E_orb/2))
        cos_wv = np.cos(g + v_orb)
        sin_wv = np.sin(g + v_orb)
        x_orb = r_orb * (cos_O * cos_wv - sin_O * sin_wv * cos_i)
        y_orb = r_orb * (sin_O * cos_wv + cos_O * sin_wv * cos_i)
        orbit_points.append((x_orb, y_orb))
    
    orbit_points = np.array(orbit_points)
    ax.plot(orbit_points[:, 0], orbit_points[:, 1], linestyle='--', alpha=0.5)

ax.set_xlabel("X (AU)")
ax.set_ylabel("Y (AU)")
ax.set_title("2D Изглед отгоре 2002-01-21")
ax.set_aspect('equal')
ax.grid(True)
ax.legend()
plt.show()
