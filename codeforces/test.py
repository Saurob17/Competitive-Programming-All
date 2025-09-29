from hashlib import sha256
import os
from Crypto.Cipher import AES

def m(y,w):
    """ Given year and word strings, produce AES-256 key: key = SHA256(f"{year}:{word}") 
    you must find the correct year and word from challenge hints. """
    return sha256((y+":"+w).encode()).digest()

def decrypt_flag(key, iv, ciphertext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    decrypted_data = cipher.decrypt(ciphertext)
    return decrypted_data.decode('utf-8').rstrip('\0')

def run():
    y = "1861"
    w = "hridoy" # or try "dhon"
    k = m(y, w)
    
    # In a real scenario, you'd load IV and ciphertext from the provided file.
    # The first 16 bytes of the file are usually the IV
    # and the rest is the ciphertext.
    
    with open("ciphertext.bin", "rb") as f:
        data = f.read()

    iv = data[:16]
    ciphertext = data[16:]
    
    decrypted_flag = decrypt_flag(k, iv, ciphertext)
    print("Decrypted Flag:", decrypted_flag)

if __name__=="__main__":
    run()