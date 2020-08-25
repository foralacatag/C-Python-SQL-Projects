from cs50 import get_int

def main():
    while True:
        height=get_int("Enter height b/w 0-23 : ")
        if height>=0 and height<=23:
            if height==1:
                space=0
                pyramid=1
            else:
                space=height-1
                pyramid=1
            break
    for i in range(height):
        for j in range(space):
            print(" ",end = "")
        for k in range(pyramid):
            print("#",end = "")

        # space between walls
        print("  ",end = "")

        for k in range(pyramid):
            print("#",end = "")

        print()
        space-=1
        pyramid+=1

if __name__ == "__main__":
    main()