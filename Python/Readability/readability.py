# Credit Card Checksum Program written by Fatma Orsun
from cs50 import get_float


def main():



    #Get the Message
    punctuations = '''()-[]{};:'"\,<>/@#$%^&*_~'''
    texts = input('Text: ')
    sc=texts.count("!") + texts.count("?")+texts.count(".")

    wc=0
    lc=0

    for text in texts:
        for letter in text:
            if letter.isalpha():
                lc=lc+1

    wc=len(texts.split(" "))
    print (texts.split(" "))
    #lc=lc-wc+1
    print(wc, lc, sc)


    index = round(0.0588 * 100*(lc/wc) - 0.296 * 100*(sc/wc) - 15.8);
    print(wc, lc, index)

    if index <= 1:
        print("Before Grade 1");
    elif index  < 16:
        print("Grade "+str(index));
    else:
        print("Grade 16+");

if __name__ == "__main__":
    main()