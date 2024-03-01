from src.board import Board
import random


def star_can_be_placed(game_board, star_row, star_col):
    """

    :param game_board: the board where we check if we can place a star
    :param star_row: the row of the star we want to place
    :param star_col: the column of the star we want to place
    :return:
    """
    list = [-1, 0, 1]
    for i in list:
        for j in list:
            if -1 < star_row + i < 8 and -1 < star_col + j < 8:
                if game_board.getcoord(star_row + i, star_col + j) == "*":
                    return False
    return True


def test_for_stars(player_board, game_board):
    """

    :param player_board: the empty board SEEN by the player where we place a random star
    :param game_board: the empty board UNSEEN by the player where we place a random star
    :return: It tests the function to see if it works
    """
    star_row = random.randint(0, 7)
    star_col = random.randint(1, 8)
    assert star_can_be_placed(game_board, star_row, star_col)
    assert star_can_be_placed(player_board, star_row, star_col)


def place_ten_stars(player_board, game_board):
    """

    :param player_board: the empty board SEEN by the player that we have to place stars on
    :param game_board: the empty board unseen by the player that we have to place stars on
    :return: the board completed with stars
    """
    for i in range(10):
        not_ok = True
        while not_ok:
            star_row = random.randint(0, 7)
            star_col = random.randint(1, 8)
            if star_can_be_placed(game_board, star_row, star_col):
                player_board.setcoord(star_row, star_col, '*')
                game_board.setcoord(star_row, star_col, '*')
                not_ok = False


def place_USS_Endeavour(player_board, game_board):
    USS_row = random.randint(0, 7)
    USS_col = random.randint(1, 8)
    if game_board.getcoord(USS_row, USS_col) == " ":
        player_board.setcoord(USS_row, USS_col, 'E')
        game_board.setcoord(USS_row, USS_col, 'E')


def place_Blingon(game_board, nr_of_them):
    for i in range(0, nr_of_them):
        not_ok = True
        while not_ok:
            Blingon_row = random.randint(0, 7)
            Blingon_col = random.randint(1, 8)
            if game_board.getcoord(Blingon_row, Blingon_col) == " ":
                game_board.setcoord(Blingon_row, Blingon_col, 'B')
                not_ok = False


def clear_Blingon_ships(player_board, game_board):
    for i in range(0, 7):
        for j in range(1, 8):
            if game_board.getcoord(i, j) == 'B':
                game_board.setcoord(i, j, " ")
                player_board.setcoord(i, j, " ")


def check_for_Blingon(player_board, game_board):
    try:
        E_row, E_col = player_board.coords_of_Endeavour()
        list = [-1, 0, 1]
        for i in list:
            for j in list:
                if -1 < E_row + i < 8 and -1 < E_col + j < 8:
                    if game_board.getcoord(E_row + i, E_col + j) == "B":
                        player_board.setcoord(E_row + i, E_col + j, 'B')
    except TypeError:
        pass


def print_options():
    print("What's your next move?")
    print("1. Warp")
    print("2. Fire")
    print("x. Exit")


def real_row(x):
    if x == 'A':
        return 0
    elif x == 'B':
        return 1
    elif x == 'C':
        return 2
    elif x == 'D':
        return 3
    elif x == 'E':
        return 4
    elif x == 'F':
        return 5
    elif x == 'G':
        return 6
    elif x == 'H':
        return 7


def warp_to_coordinates(player_board, game_board, x_row, y_col):
    E_row, E_col = player_board.coords_of_Endeavour()

    if E_row == x_row:
        ok = 1
        for i in range(E_col, y_col):
            if game_board.getcoord(x_row, i) == '*':
                ok = 0

    elif E_col == y_col:
        ok = 1
        for i in range(E_row, x_row):
            if game_board.getcoord(i, y_col) == '*':
                ok = 0

    elif E_col - y_col == E_row - x_row or y_col - E_col == E_row - x_row:
        ok = 1
        for i in range(E_row, x_row):
            if game_board.getcoord(i, y_col) == '*':
                ok = 0

    else:
        print("! Incorrect coordinates !")
        print("! You need to warp on the same row, column or diagonal !")
        return

    if ok == 1:
        if game_board.getcoord(x_row, y_col) == 'B':
            return "DEAD"
        player_board.warp_Endeavour(E_row, E_col, x_row, y_col)
        game_board.warp_Endeavour(E_row, E_col, x_row, y_col)
    else:
        print("! Incorrect coordinates !")
        print("! There's a star in the way !")


def cheatcode(player_board, game_board):
    for i in range(0, 7):
        for j in range(1, 8):
            if game_board.getcoord(i, j) == 'B':
                player_board.setcoord(i, j, 'B')


def fire_at_coordinates(player_board, game_board, x_row, y_col):
    E_row, E_col = player_board.coords_of_Endeavour()
    ok = 0

    list = [-1, 0, 1]
    for i in list:
        for j in list:
            if -1 < E_row + i < 8 and -1 < E_col + j < 8:
                if x_row == E_row + i and y_col == E_col + j:
                    ok = 1

    if ok == 1:
        if game_board.getcoord(x_row, y_col) == 'B':
            print("Congrats, you destroyed a Blingon!")
            return "DESTROYED"
        else:
            print("Miss...")

    else:
        print("You can't shoot that far")


def menu():
    player_board = Board()
    game_board = Board()
    nr_of_Blingon = 3

    place_ten_stars(player_board, game_board)
    place_USS_Endeavour(player_board, game_board)
    place_Blingon(game_board, nr_of_Blingon)

    while True:
        try:
            check_for_Blingon(player_board, game_board)
            print(player_board)

            print_options()
            option = input(">")

            if option == 'x':
                break

            elif option == "cheat":
                cheatcode(player_board, game_board)

            elif int(option) == 1:
                coords = input("Coordinates: ")

                x_row = (coords[0])
                x_row = int(real_row(x_row))
                y_col = int(coords[1])
                DEAD = warp_to_coordinates(player_board, game_board, x_row, y_col)
                if DEAD == "DEAD":
                    print("GAME OVER")
                    print("YOU DIED")
                    break

            elif int(option) == 2:
                coords = input("Coordinates: ")

                x_row = (coords[0])
                x_row = int(real_row(x_row))
                y_col = int(coords[1])
                destroyed = fire_at_coordinates(player_board, game_board, x_row, y_col)

                if destroyed == "DESTROYED":
                    clear_Blingon_ships(player_board, game_board)

                    nr_of_Blingon = nr_of_Blingon - 1
                    if nr_of_Blingon == 0:
                        print("YOU WON")
                        print("ALL BLINGON SHIPS ARE DESTROYED")
                        break
                    else:
                        place_Blingon(game_board, nr_of_Blingon)

        except ValueError and TypeError and ValueError:
            print("Invalid input.")
