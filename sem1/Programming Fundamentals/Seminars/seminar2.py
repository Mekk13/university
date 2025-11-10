import random
# A city: [name, population]
# A city: [name, population]


def generateNRandomCities(n, listOfCities):
    cityNames = ["Cluj-Napoca", "Oradea", "Sibiu", "Alba-Iulia", "Suceava", "Valencia", "Zalau", "Constanta", "Iasi",
                 "Timisoara", "Bistrita"]
    for i in range(n):
        population = random.randint(0, 5000000)
        nameIndex = random.randint(0, len(cityNames) - 1)
        listOfCities.append(createCity(cityNames[nameIndex], population))

#GETTERS

def createCity(name, population):
    return [name, population]
    #return {"name": name, "population": population}


def printCities(listOfCities):
    for i in range(len(listOfCities)):
        print("City's name = ", listOfCities[i][0], " | Population = ", listOfCities[i][1])


def printMenu():
    print("1. see all cities")
    print("2. add a city")
    print("3. generate random cities")
    print("4. sort the list of cities")
    print("5. exit")


def sortCities(listOfCities):
    ok = 0
    while (ok == 0):
        ok=1
        for i in range(0, len(listOfCities) - 1):
            if (listOfCities[i][1] > listOfCities[i + 1][1]):
                helper = listOfCities[i][1]
                listOfCities[i][1] = listOfCities[i + 1][1]
                listOfCities[i + 1][1] = helper
                ok=0

def increment(val):
    val+=1

def main():
    listOfCities = []
    while True:
        printMenu()
        option = input("Choose an option: ")
        if option == "0":
            break
        elif option == "1":
            printCities(listOfCities)
        elif option == "2":
            name = input("Enter a name: ")
            population = int(input("Enter a population: "))
            listOfCities.append(createCity(name, population))
        elif option == "3":
            n = int(input("Enter the number of cities: "))
            generateNRandomCities(n, listOfCities)
        elif option == "4":
            sortCities(listOfCities)
"""
val=2
increment(val)
print(val)

import copy

listOfNames=["Cluj-Napoca", "Oradea", "Sibiu", "Alba-Iulia", "Suceava", "Valencia", "Zalau", "Constanta", "Iasi",
                 "Timisoara", "Bistrita"]
newList= listOfNames.copy()
deepCopyList= copy.deepcopy(listOfNames)
deepCopyList[2]="Botosani"

print(listOfNames)
print(deepCopyList)


print(id(listOfNames))
print(id(newList))
print(id(deepCopyList))

print(type(listOfNames))
print(type(newList))
print(type(deepCopyList))
"""
main()