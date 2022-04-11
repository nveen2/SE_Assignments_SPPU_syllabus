#Game of Luck
import random

def get_number_set(size):
    numbers_set = []
    i = 0
    while i < size:
        temp = random.randint(1,10)
        if temp not in numbers_set:
            numbers_set.append(temp)
            i+=1

    win_number = random.choice(numbers_set)
    return numbers_set, win_number

def game_of_luck():
    player = input('Enter Name: ')
    print(player, 'Welcome to the Game of Luck!!!')
    print('Lets fill up the wallet')
    print('Enter Amount')
    wallet = int(input())
    if wallet <=0:
        print('Invalid Amount')
        print('Game Ends')
        return

    while wallet > 0:
        print(player, ', your wallet has Rs.', wallet )
        bet_amount = int(input('Enter Bet Amount '))
        if bet_amount < 1 or bet_amount > wallet:
            print('Invalid Bet Amount')
            print('Enter a value in range 1-', wallet)
            continue

        size = 3
        num_set, win_num = get_number_set(size) 

        print('Guess a value from ', num_set)
        print('On a correct guess, you would win Rs. ', 10*bet_amount)
        print('On a wrong guess, you would lose Rs. ',  bet_amount)
        guess = int(input())

        if guess == win_num:
            print('Hurray, you won Rs. ', bet_amount*10)
            wallet += (10*bet_amount)
        else:
            print('Oh!!! the winning number was:', win_num)
            print('You lost Rs.', bet_amount)
            wallet -= bet_amount

        print('Keep playing as there are 33% chances of winning!!!')
        print('play again? (y/n) ')
        if input().lower() != 'y':
            break

    print(player,'Thank You for playing the Game of Luck')

def main():
    game_of_luck()


main()