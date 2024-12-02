import matplotlib.pyplot as plt
import csv

# Datei mit den Laufzeiten einlesen
csv_file = "hanoi_runtimes_avg.csv"

# Listen für die Daten
max_discs = []
avg_runtimes = []

# CSV-Datei lesen und Daten extrahieren
with open(csv_file, 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Überspringt die Kopfzeile
    for row in reader:
        max_discs.append(int(row[0]))
        avg_runtimes.append(float(row[1]))

# Diagramm erstellen
plt.figure(figsize=(10, 6))
plt.plot(max_discs, avg_runtimes, marker='o', linestyle='-', color='b', label='Durchschnittliche Laufzeit')
plt.xlabel('Anzahl der Scheiben (Max_Discs)', fontsize=12)
plt.ylabel('Durchschnittliche Laufzeit (Sekunden)', fontsize=12)
plt.title('Durchschnittliche Laufzeit der Türme von Hanoi', fontsize=14)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=12)

# Diagramm speichern
plt.savefig("hanoi_avg_runtime_plot.png")
print("Diagramm wurde als hanoi_avg_runtime_plot.png gespeichert.")

# Diagramm anzeigen
plt.show()
