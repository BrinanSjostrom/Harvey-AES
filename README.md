# Harvey-AES
## How it works
Harvey-AES encrypts files using [base64](https://en.wikipedia.org/wiki/Base64) encoding 
and [AES](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard). It's also named after my dog Harvey.

![alt text](https://github.com/GRIM-OPS/Harvey-AES/blob/master/harvey.jpg)

## Compiling
You must have GCC installed! If you don't know how to install it, follow the guide [here](https://gcc.gnu.org/install/).

```
grim-ops@computer:~$ sudo make
```
This script will compile the code into an exexutable and move it into the `/usr/bin/` directory, allowing you to use harvey as a command. 

## Usage Examples
```
grim-ops@computer:~$ harvey --help
```
Brings up the tool's help menu.

```
grim-ops@computer:~$ harvey --file file.txt --mode e
[!] Password: Password123
[!] Confirm Password: Password123
[+] Generated key
[+] File Path: file.txt
[+] Mode: Encrypt
[+] Encrypting...
[+] Encrypted!
[+] Writing over file...
[+] File written!

```
Shows the flags you need to encrpyt a file named `test.txt`.
With the mode flag, `e` is for encrypt and `d` is for decrypt.
