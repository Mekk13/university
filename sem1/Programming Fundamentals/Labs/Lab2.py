


def f_add_number(list_of_numbers):
    """
    function that adds a number to a list
    :return:
    """
    nr= input("Enter a number: ")
    list_of_numbers.append(int(nr))
def f_print_numbers(list_of_numbers):
    if len(list_of_numbers) == 0:
        print("the list is empty")
        return
    print("the list of numbers is: ")
    for number in list_of_numbers:
        print(number)
def run():
    """
    function running the main loop for the console based appplication
    :return:
    """
    lista_de_numere = []
    commands= {"add number":f_add_number,"print all numbers": f_print_numbers}
    while True:
        cmd = input(">>>")
        cmd =cmd.lower()
        cmd=cmd.strip()
        if cmd == "exit":
            break
        if cmd in commands:
            commands[cmd](lista_de_numere) #transmisa prin referinta

run()