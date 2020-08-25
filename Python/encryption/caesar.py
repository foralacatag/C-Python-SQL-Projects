# caesar.py

# Written by Fatma Orsun

# Encrypts text using a Caesar cipher key.
import sys
from cs50 import get_string

def main():

    shift=0

    if len(sys.argv) != 2:
        print("Usage: ./caesar key");
        sys.exit(1)

    # ensure key is non-negative
    shift = int(sys.argv[1]);
    if (shift < 0):
        print("Key must be a non-negative integer")
        exit(1)

    # prompt user for text to encrypt

    text = get_string("plaintext: ")
    cipher=""
    # encrypt text by using shifting key

    for sample in text:
        if sample.isalpha():
            if sample.isupper():
                cipher= cipher+chr(((ord(sample) - 65 )+ shift) % 26 + 65)
            elif sample.islower():
                cipher= cipher+chr(((ord(sample) - 97 )+ shift) % 26 + 97)
        else:
            cipher= cipher+sample
    print(f"ciphertext: {cipher}")

if __name__ == "__main__":
    main()

