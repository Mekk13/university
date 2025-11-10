#Functions

def create_coffee(name,price,country_of_origin):
    return [name,price,country_of_origin]

def get_coffee_name(coffee):
    return coffee[0]

def get_coffee_price(coffee):
    return coffee[1]

def get_coffee_country(coffee):
    return coffee[2]

def add_coffee(name,price,country_of_origin,coffees):
    coffee=create_coffee(name,price,country_of_origin)
    coffees.append(coffee)

def hard_coded_5_coffees(coffees):
    names=["Latte","Americano","Espresso","Pumpkin spice latte","Cappuccino"]
    prices=[18,11,5,20,11]
    country_of_origin=["Rwanda","Peru","Vietnam","Peru","Nicaragua"]
    for i in range(5):
        add_coffee(names[i],prices[i],country_of_origin[i],coffees)

def sort_coffees(coffees):
    for i in range(len(coffees)):
        for j in range(len(coffees)-i-1):
            if coffees[j+1][2]<coffees[j][2]:
                coffees[j],coffees[j+1]=coffees[j+1],coffees[j]
            elif coffees[j+1][2]==coffees[j][2]:
                if coffees[j+1][1]<coffees[j][1]:
                    coffees[j],coffees[j+1]=coffees[j+1],coffees[j]

def filter_by_country_and_price(country,price,coffees):
    filtered_coffees=[]
    for coffee in coffees:
        if coffee[2]==country and coffee[1]<=price:
            filtered_coffees.append(coffee)
#UI
def print_sorted_coffees(coffees):
    sort_coffees(coffees)
    print_all_coffees(coffees)

def get_coffee_input():
    name=input("Name: ")
    if name == "":
        raise ValueError("Name cannot be an empty string")
    price=input("Price: ")
    try:
        price = float(price)
        if price <= 0:
            raise ValueError("Price must be greater than zero")
    except ValueError:
        raise ValueError("Price must be a valid number")
    country_of_origin=input("Country of origin: ")
    if country_of_origin == "":
        raise ValueError("Country of origin cannot be an empty string")
    return name, price, country_of_origin


def handle_add_coffee(coffees):
    try:
        name, price, country_of_origin = get_coffee_input()
        add_coffee(name,price,country_of_origin,coffees)
        print("Coffee added successfully!")
    except ValueError as ve:
        print(ve)

def print_all_coffees(coffees):
    if len(coffees)==0:
        print("No coffees added yet.")
    for coffee in coffees:
        print("Name: ", coffee[0], " Price: ", coffee[1], " Country of origin: ", coffee[2])

def menu():
    print("What would you like to do?")
    print("1. Add coffee")
    print("2. See all coffees")
    print("3. Display all coffees sorted by country and price" )

def main():
    commands={
        "1": handle_add_coffee,
        "2": print_all_coffees,
        "3": print_sorted_coffees,
    }
    coffees=[]
    hard_coded_5_coffees(coffees)
    menu()
    while True:
        command_text=input("Pick an action: ")
        if command_text in commands:
            commands[command_text](coffees)

main()