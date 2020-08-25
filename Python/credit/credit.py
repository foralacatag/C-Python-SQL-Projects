# Credit Card Checksum Program written by Fatma Orsun
from cs50 import get_float


def main():

    while True:
        cnumber = get_float("Number: ")
        if cnumber >= 0:
            break
    digits=cnumber
    snumber=0

    while True:
         digits=int(digits/10)
         snumber+=1
         if digits==0:
             break

    if ( (snumber !=13) and (snumber != 15) and (snumber != 16)) :
        print("INVALID")
        return 0


    list=[]

    for i in range(snumber):
        list.append(int(cnumber % 10))
        cnumber=cnumber / 10



    # initialize variables for checksum
    total=0
    x=1
    multiple=[]



    while True:
        if (snumber % 2)==0:
            for i in range(1,snumber,2):
                multiple.append(int(list[i] * 2))

            for k in range(0,snumber,2):
                total=total+int(list[k])

        if len(multiple)==8:
            break

        else:
             for k in range(0,15,2):
                total=total+int(list[k])
             for i in range(1,15,2):
                multiple.append(int(list[i] * 2))

        if len(multiple)==7:
                break
    mul_total=0


    for i in range(0,len(multiple),1):
        mul_total=(multiple[i]%10)+(multiple[i]//10)
        total=total+mul_total


    if (total % 10) ==0 :
        if (snumber ==16):

            if (list[15]==4):
                print("VISA")
            elif (list[15]==5):
                if ( (list[14]==1 ) or (list[14]==2) or (list[14]==3 ) or (list[14]==4 ) or (list[14]==5) ):
                    print("MASTERCARD")
                else:
                    print("INVALID")
        elif (snumber==15):
            if (list[14]==3):
                if ((list[13]==4) or (list[13]==7)):
                    print("AMEX")
                else:
                    print("INVALID")
        else:
            print("INVALID")


if __name__ == "__main__":
    main()

