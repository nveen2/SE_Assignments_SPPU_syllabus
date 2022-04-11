#Game of Luck
import random

def get_number_set(size):
    #generate a set of random, unique numbers in range 1-10
    numbers_set = []
    i = 0
    while i < size:
        temp = random.randint(1,10)
        if temp not in numbers_set: #to ensure temp is a unique value
            numbers_set.append(temp) #append temp to the number set
            i+=1

    #decide the winning number
    win_number = random.choice(numbers_set) #return any random value from the list
    return numbers_set, win_number #multiple returned values are packed (as a tuple) and returned

def game_of_luck():
    player = input('Enter Name: ')
    print(player, 'Welcome to the Game of Luck!!!')
    print('Lets fill up the wallet')
    print('Enter Amount')
    wallet = int(input())
    if wallet <=0:
        print('Invalid Amount')
        print('Game Ends')
        return #No value returned, just to cause termination of the function

    while wallet > 0:
        print(player, ', your wallet has Rs.', wallet )
        bet_amount = int(input('Enter Bet Amount '))
        if bet_amount < 1 or bet_amount > wallet:
            print('Invalid Bet Amount')
            print('Enter a value in range 1-', wallet)
            continue # skip execution of remaining code in the loop body. Resume with the next iteration.

        size = 3
        num_set, win_num = get_number_set(size) #The returned tuple is unpacked implicitly.

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