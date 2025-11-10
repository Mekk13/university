#Functions:

def create_festival(month, ticket_cost, list_of_artists):
    return {
        "month":month,
        "ticket_cost":ticket_cost,
        "list_of_artists":list_of_artists,
    }

def get_festival_name(festival_name,festivals):
    if festival_name in festivals:
        return festival_name
    raise ValueError("festival does not exist")

def get_festival_month(festival_name,festivals):
    if festival_name in festivals:
        return festivals[festival_name]["month"]
    else:
        raise ValueError("festival does not exist")

def get_festival_ticket_cost(festival_name,festivals):
    if festival_name in festivals:
        return festivals[festival_name]["ticket_cost"]
    else:
        raise ValueError("festival does not exist")

def get_festival_artists(festival_name,festivals):
    if festival_name in festivals:
        return festivals[festival_name]["list_of_artists"]
    else:
        raise ValueError("festival does not exist")

def get_summer_festivals(festivals):
    summer_festivals = {}
    for i in festivals:
        if festivals[i]["month"] in [6,7,8]:
            summer_festivals[i]=festivals[i]
    return summer_festivals

def get_winter_festivals(festivals):
    winter_festivals = {}
    for i in festivals:
        if festivals[i]["month"] in [1,2,12]:
            winter_festivals[i]=festivals[i]
    return winter_festivals

def get_autumn_festivals(festivals):
    autumn_festivals = {}
    for i in festivals:
        if festivals[i]["month"] in [9,10,11]:
            autumn_festivals[i]=festivals[i]
    return autumn_festivals

def get_spring_festivals(festivals):
    spring_festivals = {}
    for i in festivals:
        if festivals[i]["month"] in [3,4,5]:
            spring_festivals[i]=festivals[i]
    return spring_festivals

def sort_festivals_asc_month_name(festivals):
    sorted_dict=dict(sorted(festivals.items(), key=lambda item: (item[1]["month"],item[0])))
    return sorted_dict

#UI:
def print_festivals_from_season(season,festivals):
    if season not in ["summer","winter","autumn","spring"]:
        raise ValueError("season does not exist")
    if season=="summer":
        season_festivals=get_summer_festivals(festivals)
        sorted_festivals=sort_festivals_asc_month_name(season_festivals)
        print(sorted_festivals)
    if season=="winter":
        season_festivals=get_winter_festivals(festivals)
        sorted_festivals=sort_festivals_asc_month_name(season_festivals)
        print(sorted_festivals)
    if season=="autumn":
        season_festivals=get_autumn_festivals(festivals)
        sorted_festivals=sort_festivals_asc_month_name(season_festivals)
        print(sorted_festivals)
    if season=="spring":
        season_festivals=get_spring_festivals(festivals)
        sorted_festivals=sort_festivals_asc_month_name(season_festivals)
        print(sorted_festivals)

def handle_festivals_by_season(festivals):
    season=input("Enter the season: ")
    try:
        print_festivals_from_season(season,festivals)
    except ValueError as ve:
        print(ve)

def get_input(message):
    i= input(message)
    return i

def get_festival_details_from_user(festivals):
    name=get_input("Enter Festival name: ")
    if name in festivals:
        raise ValueError("festival already exists")
    month=int(get_input("Enter Festival month: "))
    if month < 1 or month > 12:
        raise ValueError("month must be between 1 and 12")
    ticket_cost=float(get_input("Enter Festival ticket cost: "))
    list_of_artists=[]
    print("Enter list of artists separated by enter")
    while True:
        artist=get_input("")
        if artist=="":
            break
        list_of_artists.append(artist)
    if len(list_of_artists)==0:
        raise ValueError("No artists entered")
    return name,month,ticket_cost,list_of_artists


def handle_add(festivals):
    try:
        name, month, ticket_cost, list_of_artists = get_festival_details_from_user(festivals)
        festivals[name]=create_festival(month, ticket_cost, list_of_artists)
        print("Festival added successfully")
    except ValueError as ve:
        print(ve)

def print_festival_details(festival_name,festivals):
    if festival_name not in festivals:
        raise ValueError("festival does not exist")
    print(festivals[festival_name])

def handle_print(festivals):
    try:
        festival_name=get_input("Enter Festival name: ")
        print_festival_details(festival_name,festivals)
    except ValueError as ve:
        print(ve)
def show_all(festivals):
    for i in festivals:
        print(i)
        print_festival_details(i,festivals)
        print()

def Exit(festivals):
    exit()

def menu():
    print("What do you wish to do?")
    print("1. Add Festival")
    print("2. Show Festival Details")
    print("3. Show festivals during a given season") #sorted
    print("4. Show festivals with a given artist") #sorted
    print("5. Show all festivals")
    print("6. Exit")

def main():
    festivals={
        "Untold": {
            "month": 8,
            "ticket_cost": 700,
            "list_of_artists": ["Tzanca Uraganu", "Simion AUR", "Emil Boc", "Billie Eilish"]
        },
        "Neversea": {
            "month": 9,
            "ticket_cost": 500,
            "list_of_artists": ["Mihai Eminescu", "Smiley", "Inna"]
        },
        "Enigma":{
            "month": 10,
            "ticket_cost": 250,
            "list_of_artists": ["Otilia", "Felix Sima", "Carlas Dreams"]
        },
        "Festival1":{
            "month": 5,
            "ticket_cost": 1000,
            "list_of_artists": ["Tame Impala", "Arctic Monkeys","Amanda Palmer"]
        },
        "Festival2":{
            "month": 2,
            "ticket_cost": 340,
            "list_of_artists": ["Delia","Puya","Antonia"]
        },
        "Festival3":{
            "month": 12,
            "ticket_cost": 600,
            "list_of_artists": ["Dorian Popa","Dan Simian", "Impodobeste mama bradul"]
        },
        "ana":{
            "month": 9,
            "ticket_cost": 600,
            "list_of_artists": ["Dorian Popa", "Dan Simian", "Impodobeste mama bradul"]
        }
    }

    menu()
    commands={
        "1":handle_add,
        "2":handle_print,
        "3":handle_festivals_by_season,
        "5":show_all,
        "6":Exit,
    }
    """
    while True:
        command_text=input("Pick an option: ")
        if command_text in commands:
            commands[command_text](festivals)
    """
    fest1=get_autumn_festivals(festivals)
    diction=sort_festivals_asc_month_name(fest1)
    print(diction)
#i gave up bro
main()