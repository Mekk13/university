from Assignments.Assignment_6.Functions import add_participant, insert_participant
from Functions import *
from texttable import Texttable

def display_top_by_avg(participants,number):
    if number>len(participants):
        raise IndexError("Index is out of range")
    sort_by_avg_desc(participants)
    t=Texttable()
    t.add_row(['Place','P1','P2','P3','Average'])
    for i in range(number):
        participant=participants[i]
        t.add_row([i+1, participant["P1"], participant["P2"], participant["P3"], get_avg(participant)])
    print(t.draw())

def display_top_by_problem(participants,number,problem):
    if problem!='P1' and problem!='P2' and problem!='P3':
        raise ValueError("Invalid problem type. It must be 'P1', 'P2' or 'P3'")
    sort_desc_by_problem(participants,problem)
    t=Texttable()
    t.add_row(['Place','P1','P2','P3','Average'])
    for i in range(number):
        participant=participants[i]
        t.add_row([i+1, participant["P1"], participant["P2"], participant["P3"], get_avg(participant)])
    print(t.draw())

def print_sorted_participants(participants):
    t=Texttable()
    t.add_row(['P1','P2','P3','Average'])
    sort_by_avg_desc(participants)
    for participant in participants:
        t.add_row([participant["P1"],participant["P2"],participant["P3"],get_avg(participant)])
    print(t.draw())

def list_participants_by_condition(participants,condition,score):
    t=Texttable()
    t.add_row(['P1','P2','P3','Average'])
    if condition!='=' and condition!='<' and condition!='>':
        raise ValueError("Invalid condition type. It must be '=' or '<' or '>' ")
    for participant in participants:
        avg_score=get_avg(participant)
        if condition=='=' and avg_score==float(score):
            t.add_row([participant["P1"],participant["P2"],participant["P3"],avg_score])
        if condition=='<' and avg_score<float(score):
            t.add_row([participant["P1"],participant["P2"],participant["P3"],avg_score])
        if condition=='>' and avg_score>float(score):
            t.add_row([participant["P1"],participant["P2"],participant["P3"],avg_score])
    print(t.draw())

def print_participants(participants):
    t=Texttable()
    t.add_row(['Participant','P1','P2','P3','Average'])
    i=0
    for participant in participants:
        t.add_row([i, participant["P1"], participant["P2"], participant["P3"], get_avg(participant)])
        i+=1
    print(t.draw())

def handle_add(context):
    participants = context["participants"]
    command = context["parameters"]
    try:
        parts=command.split()
        if len(parts)==4:
            p1,p2,p3=map(int,parts[1:])
            add_participant(p1,p2,p3,participants)
            print("Participant added!")
        else:
            print("Invalid command. Example: add 3 8 10")
    except ValueError:
        print("Invalid score values. Please enter valid integers for the scores.")

def handle_insert(context):
    participants = context["participants"]
    command = context["parameters"]
    try:
        parts= command.split()
        if len(parts)==6:
            p1,p2,p3=map(int,parts[1:4])
            position=int(parts[5])
            insert_participant(p1,p2,p3,participants,position)
            print(f"Participant inserted at position {position}.")
        else:
            print("Invalid insert command format. Example: insert 10 10 9 at 5")
    except ValueError:
        print("Invalid score or position. Please enter valid integers.")

def handle_remove(context):
    participants = context["participants"]
    command = context["parameters"]
    try:
        parts = command.split()
        if len(parts) == 2:
            position = int(parts[1])
            remove_score(participants,position)  # Call the appropriate function
            print(f"Participant scores at position {position} removed.")
        elif len(parts) == 4 and parts[2] == "to":
            start = int(parts[1])
            end = int(parts[3])
            remove_multiple_scores(participants,start,end)  # Call the appropriate function
            print(f"Participants from position {start} to {end} removed.")
        elif len(parts)==3:
            operator=parts[1]
            score=int(parts[2]) # list [ < | = | > ] <score>
            remove_type_score(participants,operator,score)
        else:
            print("Invalid remove command format. Example: remove 1 or remove 1 to 3")
    except ValueError:
        print("Invalid position values. Please enter valid integers.")
        return
    print("Removal successful!")

def handle_replace(context):
    participants = context["participants"]
    command = context["parameters"]

    try:
        parts = command.split()
        if len(parts) == 5:
            position = int(parts[1])
            problem = parts[2]
            new_score = int(parts[4])
            replace_old_score(participants,position,problem,new_score)  # Call the appropriate function
            print(f"Replaced the score at position {position} with {new_score} for problem {problem}.")
        else:
            print("Invalid replace command format. Example: replace 4 P2 with 5")
    except ValueError:
        print("Invalid score values. Please enter valid integers.")

def handle_list(context):
    participants = context["participants"]
    command = context["parameters"]

    try:
        parts = command.split()
        if parts[0]=='list' and len(parts)==1:
            print_participants(participants)
        elif parts[0]=='list' and parts[1]=='sorted' and len(parts)==2:
            print("The list of participants sorted by average score, descending order: ")
            print_sorted_participants(participants)
        elif len(parts)==3:
            condition=parts[1]
            score=parts[2]
            print(f"Printing all participants that have the avg score {condition} {score}")
            list_participants_by_condition(participants,condition,score)
        else:
            raise ValueError("Invalid list command format.")
    except ValueError:
        print("Invalid command format")

def handle_top(context):
    participants = context["participants"]
    command = context["parameters"]
    try:
        parts = command.split()
        if len(parts)==2:
            number=int(parts[1])
            display_top_by_avg(participants,number)
        elif len(parts)==3:
            number=int(parts[1])
            problem=parts[2]
            display_top_by_problem(participants,number,problem)
        else:
            print("Invalid top command format. Example: top 3 P1 P2 P3")
    except ValueError:
        print("Invalid command format")

def handle_undo(context):
    history_stack=context["history_stack"]
    participants=context["participants"]
    try:
        if len(history_stack) == 0:
            raise ValueError("History stack is empty")
        undo(history_stack,participants)
    except ValueError as ve:
        print(ve)

def handle_help(context):
    print("Available commands:")
    print("  add <P1 score> <P2 score> <P3 score>")
    print("  insert <P1 score> <P2 score> <P3 score> at <position>")
    print("  remove <position>")
    print("  remove <start position> to <end position>")
    print("  remove [ < | = | > ] <score>")
    print("  replace <old score> <P1 | P2 | P3> with <new score>")
    print("  list")
    print("  list sorted")
    print("  list [ < | = | > ] <score>")
    print("  top <number>")
    print("  top <number> <P1 | P2 | P3>")
    print("  undo")
    print("  exit")

def main_menu():
    print("Type 'help' to see the list of available commands. ")
    participants = []
    history_stack = []
    generate_10_random_participants(participants)
    context ={
        "participants": participants,
        "history_stack": history_stack,
        "parameters":None
    }
    # Command handlers dictionary
    command_handlers = {
        'add': handle_add,
        'insert': handle_insert,
        'remove': handle_remove,
        'replace': handle_replace,
        'list': handle_list,
        'top': handle_top,
        'undo': handle_undo,
        'help': handle_help
    }

    while True:
        try:
            command = input("Enter command: ").strip()
            if command == 'exit':
                print("Exiting...")
                break

            # Search for the command handler based on the start of the input string
            for cmd in command_handlers:
                if command.startswith(cmd):
                    context["parameters"] = command
                    # Execute the corresponding function
                    if cmd != 'list' and cmd != 'top' and cmd != 'undo':
                        save_state(history_stack,participants)
                    command_handlers[cmd](context)

        except Exception as e:
            print(f"Error: {e}")
