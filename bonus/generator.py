#!/usr/bin/env python3

import random
import sys

def random_gps() -> str:
    string = ""
    string += f"{random.randint(-89, 89):+03d}"
    for i in range(2):
        if random.choice([True, False]):
            string += f"{random.randint(0, 59):02d}"
    string += f"{random.randint(-179, 179):+04d}"
    for i in range(2):
        if random.choice([True, False]):
            string += f"{random.randint(0, 59):02d}"
    return string


if __name__ == "__main__":
    if (sys.argv[1] == "-h"):
        print("Usage: ./generator.py [number of planes] [speed of planes] [max spawn time] [number of atc] [min atc size] [max atc size]")
        exit(0)
    str = ""
    for i in range(int(sys.argv[1])):
        str += "P " + random_gps() + " " + random_gps() + " " + sys.argv[2] + " " + f"{random.randint(0, int(sys.argv[3]))}" + "\n"
    for i in range(int(sys.argv[4])):
        str += "T " + random_gps() + " " + f"{random.randint(int(sys.argv[5]), int(sys.argv[6]))}" + "\n"
    print(str)
