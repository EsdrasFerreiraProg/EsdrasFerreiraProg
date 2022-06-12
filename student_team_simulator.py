from time import sleep
import pickle
import os.path
import os

def return_what_user_wanna_do() -> int:
    print("TYPE WHAT YOU WANNA DO:"
          "\n1 - START A NEW GAME"
          "\n2 - LOAD PREVIOUS GAME"
          "\n3 - QUIT GAME\n")

    condition = int(input("TYPE>> "))

    while condition not in [1, 2, 3]:
        condition = int(input("TYPE AGAIN, YOU FAILED>> "))

    return condition

def save_data(student_state: dict):
    if not os.path.exists("file.dat"):
        print("here")
        pickle.dump({"Name": ""}, open("file.dat", "ab"))

    states = load_data()
    condition = True

    for i in states:
        if i["Name"] == student_state["Name"]:
            condition = False
            states.remove(i)
            states.append(student_state)

    if condition:
        states.append(student_state)

    os.remove("file.dat")

    for i in states:
        if i["Name"] != "":
            pickle.dump(i, open("file.dat", "ab"))

def who_wanna_load_user():
    names = set()

    for i in load_data():

        names.add(i["Name"])

    print("Choose which state you want to load!")

    counter = 0

    for i in names:
        print(counter, "-", i)
        counter += 1


    choice = int(input("TYPE>>> "))

    while choice > counter or choice < 0:
        choice = int(input("TYPE>>> "))

    names = list(names)

    for i in load_data():
        if i["Name"] == names[choice]:
            return i

def load_data():
    objects = []
    with (open("file.dat", "rb")) as openfile:
        while True:
            try:
                objects.append(pickle.load(openfile))
            except EOFError:
                break

    return objects

def print_menu():
    print("____WELCOME TO STUDENT TEAM SIMULATOR____VERSION 1.0 ALPHA")
    print("____THE REAL BRAZILIAN TEAMS GAME, A REAL INCEPTION________\n")

def print_teams():
    print("\n1 - Flamengo"
          "\n2 - Botafogo")

def tutorial():
    condicao = int(input("TYPE 1 IF YOU WANNA WATCH THE TUTORIAL: "))
    if condicao == 1:
        print("##################START OF TUTORIAL#########################")
        print("\nDERFEL: HI! MY GREETINGS! I'M DERFEL AND I'M GONNA SHOW YOU ALL THE GOALS OF OUR GAME!")
        print(
            "\nDERFEL: FIRST OF ALL, YOU WILL BE CONTROLLING A CHARACTER CALLED 'STUDENT', AND HE IS ALMOST REBORNING IN ANOTHER LIFE")
        sleep(4)
        print(
            "DERFEL: YOU MUST CHOOSE WHAT TEAM HE IS GONNA SUPPORT IN HIS NEXT LIFE AND IT IS GONNA GUIDE THROUGH ALL THE GAME")
        sleep(4)
        print("DERFEL: YOUR MAIN GOAL IS FINISH THE SEMESTER, IF YOU CAN'T, YOU LOSE!!!!!!")
        sleep(4)
        print("DERFEL: SOME ISSUES ARE GONNA HAPPEN DURING THE GAME SO HEADS UP!\n")
        sleep(4)
        print("PLEASE ENJOY!")
        print("##################FINISH OF TUTORIAL#########################")
    else:
        return

def choose_team():
    team = int(input(("1 - Flamengo\n2 - Botafogo\nTYPE>>>  ")))
    while team not in [1, 2]:
        print("DIGITE CORRETAMENTE!!!!!!")
        team = int(input(("1 - Flamengo\n2 - Botafogo\nTYPE>>> ")))
    if team == 1:
        return "Flamengo"
    else:
        return "Botafogo"

def first_test(student_state: dict) -> bool:
    print("#################################################################################")
    if student_state["team"] == "Flamengo":
        print(
            "WHO IS THE PLAYER THAT SCORED MORE GOALS IN LIBERTADORES FOR FLAMENGO??\na-Gabigol\nb-Pelé\nc-Nunes Camisa 9")
        answer = input("TYPE>>>> ")
        if answer == "a":
            print("CORRECT ANSWER!!!!!! CONGRATULATIONS!!!!")
            print("YOU ARE NOW HAVING A LEVEL UP AND MORE 100 REAIS")
            return True
        else:
            print("INCORRECT!!!!! YOU ARE STARTING THE TEST AGAIN!!")
            return False
    else:
        print("WHO IS THE MORE IMPORTANT PLAYER BOTAFOGO EVER REVEALED??\na-Adílio\nb-Andrade\nc-Garrincha")
        answer = input("TYPE>>>> ")
        if answer == "c":
            print("CORRECT ANSWER!!!!!! CONGRATULATIONS!!!!")
            print("YOU ARE NOW HAVING A LEVEL UP AND MORE 100 REAIS")
            return True
        else:
            print("INCORRECT!!!!! YOU ARE STARTING THE TEST AGAIN!!")
            return False

    print("##################################################################################")


def choose_apostila(student_state: dict):
    print("MANAWYDAN: HI FOREIGNER! I'M THE APOSTILA SELLER, WHAT ONE WOULD YOU LIKE TO BUY TO STUDY?")
    print("1 - Letras - Costs: 10 reais\n2 - Matemática - Costs: 15 reais\n3 - Ciências Sociais - Costs: 100 reais")
    sleep(1)
    choice = int(input("MANAWYDAN: WHICH ONE YOU CHOOSE?\nTYPE>>>  "))

    if choice == 1:
        student_state["money"] -= 10
        student_state["course"] = "Letras"
        student_state["possessions"] = "APOSTILA DE LETRAS"
    elif choice == 2:
        student_state["money"] -= 15
        student_state["course"] = "Matematica"
        student_state["possessions"] = "APOSTILA DE MATEMATICA"
    else:
        student_state["money"] -= 100
        student_state["course"] = "Ciências Sociais"
        student_state["possessions"] = "APOSTILA DE CIENCIAS SOCIAIS"


def second_test(student_state: dict):
    print("MAWAYDAN: HEY! MANAWYDAN HERE, IF YOU NEED SOME WATER SERVICES CALL ME, ARGH, THIS AWFUL WATER RATS!")
    sleep(2)
    print("MANAWYDAN: OK, LET'S GO, I'LL ALLOW YOU TO SEE YOUR APOSTILA ONE TIME...HERE IT IS>>")
    sleep(2)
    choice = ""

    if student_state["course"] == "Letras":
        print("APOSTILA: Na minha terra tem Palmeiras onde canta o sabiá")
        sleep(2)
        print("MANAWYDAN: OK...ARE YOU READY FOR THE TEST? HERE IT GOES")
        sleep(3)
        print("Qual o time do poeta? ")
        choice = input("TYPE >>> ")
        if choice not in ["Palmeiras", "palmeiras"]:
            print("GOD: I CANT BELIEVE YOU FAILED! YOU ARE DEAD RIGHT NOW!!!! REBORN AGAIN...LITLLE CHILDREN!")
            return False
        else:
            print("GOD: CONGRATULATIONS! YOU PASSED MY SON! I'M SO PROUD OF YOU!")
            sleep(1)
            print("GOD: YOU NOW GONNA ADD IN YOUR POSSESSIONS PAPERS AND BOOKS")
            student_state["possessions"] += ";PAPERS;BOOKS"

    elif student_state["course"] == "Matematica":
        print("APOSTILA: A soma do quadrado dos catetos é igual à Arena Condá")
        sleep(2)
        print("MANAWYDAN: OK...ARE YOU READY FOR THE TEST? HERE IT GOES")
        sleep(2)
        print("Qual o time do coração de Pitágoras? ")
        choice = input("TYPE >>> ")
        if choice not in ["Chapecoense", "Chape", "chapecoense"]:
            print("GOD: I CANT BELIEVE YOU FAILED! YOU ARE DEAD RIGHT NOW!!!! REBORN AGAIN...LITLLE CHILDREN!")
            return False
        else:
            print("GOD: CONGRATULATIONS! YOU PASSED MY SON! I'M SO PROUD OF YOU!")
            sleep(2)
            print("GOD: YOU NOW GONNA ADD IN YOUR POSSESSIONS ONE ABACUS, ONE RIVOTRIL AND ONE LICENSE TO MATLAB")

            student_state["possessions"] += ";ABACUS;RIVOTRIL;LICENSE TO MATLAB"
    else:
        print("APOSTILA: Botafogo, Botafogo, campeão desde 1910")
        sleep(2)
        print("MANAWYDAN: OK...ARE YOU READY FOR THE TEST? HERE IT GOES")
        sleep(2)
        print("Qual o time preferido de Marx? ")
        choice = input("TYPE >>> ")
        if choice not in ["Botafogo", "botafogo"]:
            print("GOD: I CANT BELIEVE YOU FAILED! YOU ARE DEAD RIGHT NOW!!!! REBORN AGAIN...LITLLE CHILDREN!")
            return False
        else:
            print("GOD: CONGRATULATIONS! YOU PASSED MY SON! I'M SO PROUD OF YOU!")
            sleep(2)
            print("GOD: YOU NOW GONNA ADD IN YOUR POSSESSIONS ORGANIC TOBACCO, BOOKS AND HAVAIANA SANDALS")
            student_state["possessions"] += ";ORGANIC TOBACCO;BOOKS;HAVAIANA SANDALS"
    return True


def print_student_possessions(student_state: dict) -> str:
    string_out = ""
    for i in student_state["possessions"]:
        if i != ";":
            string_out += i
        else:
            string_out += ", "
    return string_out


def print_actions_student_can_do_phase_4(student_state: dict):
    if student_state["course"] == "Letras" and student_state["team"] == "Flamengo":
        print("MITRA: NOW YOU HAVE TO CREATE THE FLAMENGUISTA BIBLE AND UNFOLD THE WORD!")
        sleep(2)
        writing = str(input("WRITE YOUR BIBLE: "))
        print("ZICO: I CAN'T BELIEVE YOU DIT IT!!!!!!!!!!!!!!!!!!!!!!! YOU'RE DEAD...")
        exit(0)

    elif student_state["course"] == "Letras" and student_state["team"] == "Botafogo":
        print("MITRA: NOW YOU HAVE TO CREATE THE FOGAO BIBLE AND UNFOLD THE WORD!")
        sleep(2)
        writing = str(input("WRITE YOUR BIBLE: "))
        print("GARRINCHA: I CAN'T BELIEVE YOU COULD NOT MAKE IT!!!!!!!!!!!!!!!!!!!!!!! YOU'RE DEAD...")
        exit(0)

    elif student_state["course"] == "Matematica":
        print(
            "MITRA: NOW YOU HAVE TO PROVE FOR A+B THAT YOUR TEAM IS THE GREATEST, OR YOU CANT TAKE THE RIVOTRIL AND FINISH THE GAME NOW!")
        sleep(4)
        wish = input("DO YOU WANT TO HAVE THE PILL AND FINISH THE GAME? Y/N\nTYPE>>>>")

        while wish not in ["Y", "y"] and wish not in ["N", "n"]:
            wish = input("DO YOU WANT TO HAVE THE PILL AND FINISH THE GAME? Y/N\nTYPE>>>>")
        if wish == "Y":
            fase5(student_state)
        else:
            print(
                "MITRA: I CAN'T ADMIT YOU FAILED GETTING OUT HERE! I GAVE YOU THE OPPORTUNITY AND YOU WASTED IT HAHAHAHA, NOW YOU ARE BACK TO THE FIRST PHASE! FOOL!!!!")
            sleep(4)
            fase1()

    elif student_state["course"] == "Ciências Sociais":
        print(
            "MITRA: NOW YOU HAVE TO FOUND YOUR HEART TEAM CHURCH OR SMOKE THE ORGANIC TOBACCO AND FINISH THE GAME IMMEDIATELY!")
        wish = input("DO YOU WANT TO HAVE TOBACCO AND FINISH THE GAME? Y/N\nTYPE>>>> ")
        while wish not in ["Y", "y"] and wish not in ["N", "n"]:
            wish = input("DO YOU WANT TO HAVE TOBACCO AND FINISH THE GAME? Y/N\nTYPE>>>>")
        if wish == "Y":
            fase5(student_state)
        else:
            print(
                "MITRA: I CAN'T ADMIT YOU FAILED GETTING OUT HERE! I GAVE YOU THE OPPORTUNITY AND YOU WASTED IT HAHAHAHA, NOW YOU ARE BACK TO THE FIRST PHASE! FOOL!!!!")
            fase1()

def fase1():
    student_state = {"Name": "", "life": 0, "money": 0, "possessions": "", "team": "", "course": "", "level": 0}
    student_state["Name"] = input("PLEASE TYPE YOUR NAME HERE TO SAVE THE STATE!\nTYPE>>>>>  ")

    print("###########FIRST PHASE##############")
    print("MITRA: WELCOME TO STUDENT TEAM SIMULATOR! I'M MITRA AND I'M GONNA GUIDE YOU THROUGH THIS AMAZING JOURNEY!\n")
    sleep(2)
    tutorial()
    print("MITRA: YOU ARE NOW GETTING 100 OF LIFE, LEVEL 1, NO POSSESSIONS AND NO MONEY\n")
    sleep(2)

    if student_state["life"] == 0:
        student_state["life"] = 100

    student_state["level"] = 1
    print("MITRA: TO KEEP PLAYING PLEASE CHOOSE THE TEAM OF YOUR HEART : ")
    sleep(2)
    student_state["team"] = choose_team()
    print("GOD: YOUR FAMILY IS JUVENTINO, YOUR DAD, JOSEFINA, YOUR MOTHER AND MARQUITO, YOUR BROTHER")
    sleep(2)
    print("GOD: I DECLARE YOU NOW ALIVE!!!!!!!!!!\n")
    sleep(4)
    os.system('cls')
    fase2(student_state)

def fase2(student_state: dict):
    student_state["level"] = 2
    print("#########################SECOND_PHASE##############################")
    print("MITRA: CONGRATULATIONS YOU PASSED THE PHASE! BUT IT IS NOT SO EASY! HUMPF...\n")
    sleep(2)
    print("MITRA: TO PASS TO PHASE 3 YOU NEED JUST TO ANSWER A TEST, YOUR FIRST! NOT HARD FOR YOU I KNOW...\n")
    sleep(2)
    print("OK...YOU HAVE THE TIME YOU WANT TO RESPOND THIS SIMPLE QUESTION:\n")
    while not first_test(student_state):
        first_test(student_state)

    student_state["level"] = 3
    student_state["money"] += 100

    save_data(student_state)
    sleep(4)
    os.system('cls')
    fase3(student_state)

def fase3(student_state: dict):
    print("##########################THIRD_PHASE#############################")
    student_state["level"] = 3
    print("MITRA: OK THEN!!!! YOU ARE TOO SMART, ALL RIGHT ALL RIGHT...")
    sleep(2)
    print(
        "MITRA: NOW YOU CAN CHOOSE YOUR HEART COURSE CHOOSING A APOSTILA, YOU'LL HAVE TO PASS THROUGH A TEST TO MAKE PART OF IT")
    sleep(3)
    choose_apostila(student_state)
    print("MITRA: CONGRATULATIONS, YOU JUST BOUGHT YOUR TICKET TO THE FUTURE! ")
    sleep(2)
    print("MITRA: UNFORTUNATELY YOU HAVE ANOTHER TEST TO DO, THIS TIME YOU'RE GONNA BE TESTED FOR REAL!!!!!!!!!!!!")
    sleep(2)
    if second_test(student_state) == False:
        fase1()
    else:
        student_state["money"] += 100
        student_state["life"] += 100

    print("MITRA: CONGRATULATIONS MY FRIEND! NOW YOU CAN PASS THE PHASE!")
    sleep(2)
    print("MITRA: YOU GOT 100 OF MONEY AND 100 OF LIFE, YOU'LL NEED IT")
    sleep(2)
    print("MITRA: HERE YOU CAN SEE ALL YOUR ATTRIBUTES:\n", "LIFE: " + str(student_state["life"]),
          "| TEAM: " + str(student_state["team"]), "| MONEY: " + str(student_state["money"]),
          "| COURSE: " + str(student_state["course"]), " | LEVEL: " + str(student_state["level"]),
          " | POSSESSIONS: " + str(print_student_possessions(student_state)))
    save_data(student_state)
    sleep(8)
    os.system('cls')
    fase4(student_state)

def fase4(student_state: dict):
    student_state["level"] = 4
    print("##########################FOURTH_PHASE#############################")
    print(
        "MITRA: OH....... OK... I NEVER THOUGHT YOU COULD GO SO FAR!!! BUT NOW.................SOME..ONE....IS...COMING!!!!")
    sleep(2)
    if student_state["team"] == "Botafogo":
        print(
            "GARRINCHA'S SPIRIT: YOUR GOAL IS NOT FINISH THE COURSE ANYMORE!!!! NOW YOU HAVE TO TRANSFORM YOUR CAMPUS IN A BOTAFOGO HEADQUARTERS!!")
        sleep(2)
        print(
            "GARRINCHA'S SPIRIT: I CAN ENSURE YOU ARE NOT GETTING CRAZY! DO IT FOR ME AND YOU CAN WIN THE GAME AUTOMATICALLY!!!")

    elif student_state["team"] == "Flamengo":
        print("DERFEL: I'M SURE YOUR GOAL IS NOT FINISHING THIS GAME HAHAHAHAHAHA!!!!!!!!!!!")
        sleep(2)
        print("DERFEL: YOU CAN ONLY WIN IF YOU TRANSFORM YOUR CAMPUS IN A FLAMENGO HEADQUARTERS!! DO IT NOW!")
        sleep(2)

    save_data(student_state)
    print_actions_student_can_do_phase_4(student_state)

def fase5(student_state: dict):
    os.system('cls')
    print("##########################FIFTH_PHASE#############################")
    student_state["level"] = 5
    save_data(student_state)
    print("GOD: NOW YOU ARE FREE FROM THESE GUYS...HUMPF....I DID NOT WANT DO CREATE THEM, I WAS OBBLIGED...")
    print("GOD: NOW IT'S THE FINAL QUESTION AND YOU CAN FINISH THE COURSE, THAT TIME YOU WON'T HAVE OPTIONS...")
    option = input("GOD: WHAT IS THE BEST COURSE OF ALL?\nTYPE>>>>>  ")
    if option in ["Computing", "Computacao", "Computação", "Comp", "CC"]:
        print("GOD: CONGRATS! YOU FINISHED THE GAME VERY WELL!\n****************************************")

def start_game():
    student_state = {}
    what_user_wanna_do = return_what_user_wanna_do()

    if what_user_wanna_do == 1:
        fase1()

    elif what_user_wanna_do == 2 and os.path.exists("file.dat"):
        student_state = who_wanna_load_user()

        level = student_state["level"]

        if level == 2:
            print("MITRA: OK! YOU ARE STARTING FROM PHASE 2! GOOD LUCK...YOU'LL NEED IT")
            sleep(2), os.system('cls')
            fase2(student_state)
        if level == 3:
            print("MITRA: OK! YOU ARE STARTING FROM PHASE 3! GOOD LUCK...YOU'LL NEED IT")
            sleep(2), os.system('cls')
            fase3(student_state)
        if level == 4:
            print("MITRA: OK! YOU ARE STARTING FROM PHASE 4! GOOD LUCK...YOU'LL NEED IT")
            sleep(2), os.system('cls')
            fase4(student_state)
        if level == 5:
            print("MITRA: OK! YOU ARE STARTING FROM PHASE 5! GOOD LUCK...YOU'LL NEED IT")
            sleep(2), os.system('cls')
            fase5(student_state)

    elif what_user_wanna_do == 2 and not(os.path.exists("file.dat")):
        print("####THERE IS NO SAVE, PLEASE START A NEW GAME#####")
        sleep(3)
        os.system('cls')
        print_menu()
        start_game()
    else:
        exit(0)

def student_team_simulator():
    print_menu()

    start_game()

student_team_simulator()
