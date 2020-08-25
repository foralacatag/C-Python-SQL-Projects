from cs50 import get_int, get_float

def main():

    change=[25,10,5,1]
    coins=0
    while True:
        money=get_float("Enter Money higher than 0 : ")
        if money>=0:
            break

    cents=int(money*100)
    for i in range(4):
        coins=coins+cents//change[i]
        cents=cents%change[i]

    print("Total Change ")
    print(coins)

if __name__ == "__main__":
    main()