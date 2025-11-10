from random import randint

def save_state(history_stack,participants):
     history_stack.append(participants.copy())

def undo(history_stack:list,participants):
    if len(history_stack)==0:
        raise ValueError("History stack is empty")
    participants[:] = history_stack[-1]
    history_stack.pop()

def create_participant(p1,p2,p3):
    return  {"P1":p1,"P2":p2,"P3":p3}

def get_p1(participant:dict):
    return participant["P1"]

def get_p2(participant:dict):
    return participant["P2"]

def get_p3(participant:dict):
    return participant["P3"]

def get_scores(participant:dict):
    return participant["P1"],participant["P2"],participant["P3"]

def set_scores(participant:dict,p1,p2,p3):
    participant["P1"]=p1
    participant["P2"]=p2
    participant["P3"]=p3

def get_avg(participant:dict):
    return (participant["P1"]+participant["P2"]+participant["P3"])/3

def participant_to_string(participant:dict):
    return f"P1:{participant["P1"]} , P2:{participant["P2"]} ,P3:{participant["P3"]}"

def add_participant(p1,p2,p3,participants):
    if (p1<0 or p1>10) or (p2<0 or p2>10) or (p3<0 or p3>10):
        raise ValueError("The scores must be between 0 and 10")
    new_participant = create_participant(p1,p2,p3)  #We create a new object
    participants.append(new_participant) # we add it to out list of participants

def insert_participant(p1,p2,p3,participants,position):
    if position <0 or position>(len(participants)):
        raise IndexError("Index is out of range")
    new_participant=create_participant(p1,p2,p3)
    participants.insert(position,new_participant)

def remove_score(participants,position):
    if position <0 or position>len(participants)-1:
        raise IndexError("Index is out of range")
    set_scores(participants[position],0,0,0)


def remove_multiple_scores(participants,position1,position2):
    if position1 <0 or position1>len(participants)-1 or position1>position2:
        raise IndexError("Index is out of range")
    if position2 <0 or position2>len(participants)-1:
        raise IndexError("Index is out of range")
    for i in range(position1,position2+1):
        set_scores(participants[i],0,0,0)

def replace_old_score(participants,position,problem,new_score):
        if problem!='P1' and problem!='P2' and problem!='P3':
            raise ValueError("Invalid problem type. It must be 'P1', 'P2' or 'P3'")
        old_scores=participants[position].get_scores()
        if problem == 'P1':
            participants[position].set_scores(new_score,old_scores[1],old_scores[2])
        if problem == 'P2':
            participants[position].set_scores(old_scores[0],new_score,old_scores[2])
        if problem == 'P3':
            participants[position].set_scores(old_scores[0],old_scores[1],new_score)

def sort_by_avg_desc(participants):
    for i in range(0,len(participants)):
        ok=True
        for j in range(0,len(participants)-i-1):
            if get_avg(participants[j])<get_avg(participants[j+1]):
                participants[j],participants[j+1]=participants[j+1],participants[j]
                ok=False
        if ok:
            return


def sort_desc_by_problem(participants,problem):
    if problem!='P1' and problem!='P2' and problem!='P3':
        raise ValueError("Invalid problem type. It must be 'P1', 'P2' or 'P3'")
    if problem=='P1':
        participants.sort(key=lambda x: x.get_scores()[0],reverse=True)
    elif problem=='P2':
        participants.sort(key=lambda x: x.get_scores()[1],reverse=True)
    elif problem=='P3':
        participants.sort(key=lambda x: x.get_scores()[2], reverse=True)


def remove_type_score(participants,operator,score):
    if operator!='=' and operator!='<' and operator!='>':
        raise ValueError("Invalid operator. It must be '=' or '<' or '>' ")
    for i in range(len(participants)):
        participant=participants[i]
        if operator=='=' and get_avg(participant)==score:
            remove_score(participants,i)
        elif operator=='<' and get_avg(participant)<score:
            remove_score(participants,i)
        elif operator=='>' and get_avg(participant)>score:
            remove_score(participants,i)

def generate_10_random_participants(participants):
    for i in range(10):
        p1=randint(0,10)
        p2=randint(0,10)
        p3=randint(0,10)
        add_participant(p1,p2,p3,participants)


def test_undo():
    participants1=[]
    history_stack=[]
    add_participant(1,2,3,participants1)
    copy_for_test=participants1.copy()
    save_state(history_stack,participants1)
    add_participant(3,4,5,participants1)
    undo(history_stack,participants1)
    assert participants1==copy_for_test

def tests():
    test_undo()

