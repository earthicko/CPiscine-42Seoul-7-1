import os
import subprocess
import random

TEST_CASE_DIR = "cases"

class RandomFileCreator:
    def __init__(self, size: int, dir: str):
        self.size = size
        self.dir = dir
        self.name = f"tc-{self.size}"
        self.path = os.path.join(self.dir, self.name)

    def create_binary(self):
        with open(self.path, 'wb') as fout:
            fout.write(os.urandom(self.size))

    def create_printable(self):
        with open(self.path, 'w') as fout:
            for _ in range(self.size):
                print(chr(random.randint(32, 127)), file=fout, end='')

    def create_nonprintable(self):
        with open(self.path, 'w') as fout:
            for _ in range(self.size):
                print(chr(random.randint(0, 127)), file=fout, end='')
                
    def delete(self):
        if os.path.isfile(self.path):
            os.remove(self.path)

if __name__ == "__main__":
    print("RandomFileCreator Running")

    size_files = int(input("Size of files to be created (in B): "))
    file_creator = RandomFileCreator(size_files, TEST_CASE_DIR)
    file_creator.create()
    print(os.listdir(TEST_CASE_DIR))
    file_creator.delete()
    print(os.listdir(TEST_CASE_DIR))
