// Реализовать стек и очередь с максимумом за единицу
template <typename T>
struct Node
{
    T min;
    T max;
    T val;
    Node *prev;
};

template <typename T>
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        auto tmp = top;
        while (tmp)
        {
            tmp = tmp->prev;
            delete top;
            top = tmp;
        }
    }

    T top()
    {
        return top->val;
    }

    void push(int val)
    {
        Node *node = new Node;
        node->val = val;
        node->prev;
        if (top)
        {
            node->min = std::min(top->min, val);
            node->max = std::max(top->max, val);
        }
        else
        {
            node->min = val;
            node->max = val;
        }
    }

    void pop()
    {
        auto tmp = top;
        top = top->prev;
        delete tmp;
    }

    T Min()
    {
        return top->min;
    }

    T Max()
    {
        return top->max;
    }

    bool empty() {
        return (top != nullptr);
    }
};
