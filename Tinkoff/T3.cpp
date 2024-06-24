#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <set>

class Folder
{
public:
    std::string name_;
    std::list<Folder *> children_;

    Folder(std::string name, std::list<Folder *> children = {})
    {
        name_ = name;
        children_ = children;
    }

    void add_folder(Folder *other)
    {
        for (Folder *child : children_)
        {
            if (child->name_ == other->name_)
            {
                return;
            }
        }

        children_.push_back(other);
    }
};

void print_path(const Folder &folder, const int &depth = 0)
{
    for (int i = 0; i < 2 * depth; i++)
    {
        std::cout << ' ';
    }
    std::cout << folder.name_ << '\n';

    for (const Folder *child : folder.children_)
    {
        print_path(*child, depth + 1);
    }
}

std::vector<std::string> splitString(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;
    while ((end = s.find(delimiter, start)) != std::string::npos)
    {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

// int main() {
//     string myString = "foo\\bar\\baz\\qux";
//     vector<string> parts = splitString(myString, '\\');

//     cout << "Parts of the string after splitting:" << endl;
//     for (const auto& part : parts) {
//         cout << part << endl;
//     }

//     return 0;
// }

int main()
{
    int n;
    std::cin >> n;

    Folder root = Folder("", {});

    for (int i = 0; i < n; i++)
    {
        Folder *prev = &root;

        std::string str;
        std::cin >> str;
        std::vector<std::string> parts = splitString(str, '\\');

        for (const auto &part : parts)
        {
            Folder *cur = new Folder(part);
            prev->add_folder(cur);
            prev = cur;
        }
    }

    // Folder root = Folder("root");
    // Folder a = Folder("a");
    // Folder b = Folder("b");
    // Folder c = Folder("c");
    // b.add_folder(c);
    // a.add_folder(b);
    // root.add_folder(a);

    print_path(root);
}