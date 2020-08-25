# Vigenere.py

# Written by Fatma Orsun

# Encrypts text using a Vigenere cipher key.
import cs50
import sys
from cs50 import get_string

def main():
    # Check/iterate for vigenere key
    if len(sys.argv)!=2:
        print("Usage: ./Vigenere key");
        exit(1)

    # Check/iterate for vigenere key for alphabetical characters */
    chunk = len(sys.argv[1])
    shift=[]
    for s in sys.argv[1]:
        if s.isalpha()==False:
            print("Usage: ./vigenere key")
            exit(1)
        else:
            if s.isupper():
                shift.append(ord(s)-65)
            if s.islower():
                shift.append(ord(s)-97)


     # prompt user for text to encrypt
    cipher=""
    text = get_string("plaintext: ")
    index=0
    for t in range(len(text)):
        index= t % len(shift)
        cipher=cipher+encrypt(text[t], shift[index])
    print(f"ciphertext: {cipher}")




def encrypt(char, key):
    if char.isupper():
                return chr(((ord(char) - 65 )+ key) % 26 + 65)
    elif char.islower():
                 return chr(((ord(char) - 97 )+ key) % 26 + 97)
    else:
        return char

if __name__ == "__main__":
    main()

