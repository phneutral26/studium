def checkIfPrimzahl(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True
    
        
print(checkIfPrimzahl(4))

# Laufzeit O(sqrt(n))
# -> Wir checken von 2 bis sqrt(n)+1 ob beim Dividieren durch i (2-sqrt(n)) ein Rest entsteht.
# Es reicht bis sqrt(n) zu schauen, da danach nurnoch "umgedrehte" Multiplikationen auftreten