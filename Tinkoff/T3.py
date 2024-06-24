class Folder:
    def __init__(self, n, c):
        self.name = n
        self.children = c

    def AddFolder(self, f):
        for folder in self.children:
            if folder.name == f.name:
                return
        self.children.append(f)


n = int(input())

root = Folder('', [])

for i in range(n):
    path = input().split('/')
    prev = root

    for folder_name in path:
        folder = Folder(folder_name, [])
        prev.AddFolder(folder)
        prev = folder


def print_path(folder, depth):
    print(depth * '  ' + f'{folder.name}')
    for child in folder.children:
        print_path(child, depth + 1)


print_path(root, 0)
