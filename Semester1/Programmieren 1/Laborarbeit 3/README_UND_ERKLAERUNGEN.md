# Laborarbeit No. 3

## Aufgabe 1

Ich habe für die erste Aufgabe (Türme von Hanoi) zwei Dateien: Einmal 'hanoi.c' und einmal 'hanoi_avg.c'.

Ich habe die zwei Dateien nur zu Übersichtlichkeits-Zwecken gesplitted.

### 'hanoi.c'

- Visuelle Darstellung der Lösung eines n-Scheiben hohen Türme-von-Hanoi-Problems

### 'hanoi_avg.c'

- Durchschnittsberechnung der Laufzeit für die Türme von Hanoi
- Nutzt exakt gleichen Algorithmus wie 'hanoi.c'
- Erstellt CSV-Datei mit Durchschnittszeiten

**Beispieldaten**
| MAX_DISCS | Durchschnittliche Laufzeit |
|-----------|----------------------------|
| 3-8       | 0.000000                   |
| 9         | 0.000200                   |
| 10        | 0.000000                   |
| 11        | 0.000000                   |
| 12        | 0.000200                   |
| 13        | 0.000400                   |
| 14        | 0.000600                   |
| 15        | 0.001000                   |
| 16        | 0.002200                   |
| 17        | 0.004200                   |
| 18        | 0.008000                   |
| 19        | 0.017000                   |
| 20        | 0.032600                   |
| 21        | 0.065200                   |
| 22        | 0.133400                   |
| 23        | 0.259600                   |
| 24        | 0.516200                   |
| 25        | 1.038000                   |
| 26        | 2.063000                   |
| 27        | 4.162400                   |
| 28        | 8.272600                   |

## Aufgabe 2

### Warum $𝑝^2>𝑛$ als Abbruchbedingung?

Alle Vielfachen einer Zahl $𝑞 > 𝑛 $ wurden bereits durch kleinere Primzahlen  $𝑝≤\sqrt𝑛$ markiert.

Beispiel: Wenn 𝑛=30, ist $30≈5,477$. Ab $𝑝=6$ gibt es keine neuen Zahlen, die durch $p$ markiert werden könnten.

## Was heißt das für Effizienz?
- Schleife läuft nur bis $\sqrt n$, was Laufzeit von $O(n^2)$ zu $O(n \log \log n)$

## Bsp.: $n=30$
- Schleife markiert Vielfachen von $2$ $(4, 6, 8, ...)$ und $5$ $(25)$
- Danach wird $p=6$ übersprungen, da $6^2 > 30$


# Mathematischer Beweis der Abbruchbedingung $p^2 > n$ im Sieb des Eratosthenes

## Behauptung
Die Abbruchbedingung $p^2 > n$ ist hinreichend, um sicherzustellen, dass alle Nicht-Primzahlen bis $n$ korrekt markiert werden.

## Beweis
### 1. Definition der Vielfachen
Sei $n \in \mathbb{N}$, und wir suchen alle Primzahlen $p \leq n$.  
Eine Zahl $k \leq n$ ist keine Primzahl, wenn sie mindestens einen echten Teiler $t$, mit $1 < t < k$, besitzt. Wir schreiben:
$$
k = p \cdot q
$$
Dabei sind $p$ und $q$ echte Teiler von $k$.

### 2. Einschränkung auf $p \leq q$
Ohne Beschränkung der Allgemeinheit können wir annehmen, dass $p \leq q$. Daraus folgt:
$$
p \cdot p \leq p \cdot q = k
$$
Daher muss gelten:
$$
p^2 \leq k
$$
Falls $p^2 > n$, können wir daraus schließen, dass keine weiteren $k$ durch $p$ teilbar sind, da alle Vielfachen von $p$ bereits durch kleinere Primzahlen $p' \leq \sqrt{n}$ markiert wurden.

### 3. Konsequenzen der Bedingung $p^2 > n$
- Für $p^2 > n$ gilt: $k > n$, wenn $k$ ein Vielfaches von $p$ ist.
- Das bedeutet, dass wir bei $p > \sqrt{n}$ keine neuen Zahlen $k$ finden können, die markiert werden müssen.
- Die Schleife kann daher abgebrochen werden, sobald $p > \sqrt{n}$.

### 4. Beispiel zur Veranschaulichung
Betrachten wir $n = 30$:
- $\sqrt{30} \approx 5,477$
- Wir markieren die Vielfachen von:
  - $2$: $4, 6, 8, \dots, 30$
  - $3$: $9, 12, 15, \dots, 30$
  - $5$: $25$
- Für $p = 6$ gilt $6^2 = 36 > 30$, und es gibt keine neuen Vielfachen $k \leq 30$.

### 5. Fazit
Die Abbruchbedingung $p^2 > n$ ist hinreichend, da:
1. Alle Vielfachen von Primzahlen $p \leq \sqrt{n}$ korrekt markiert werden.
2. Für $p > \sqrt{n}$ keine neuen Nicht-Primzahlen markiert werden können.


$$
\boxed{\text{Die Abbruchbedingung \( p^2 > n \) ist korrekt und effizient.}}
$$