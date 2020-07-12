#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};
int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (unsigned int long position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, position));
        }

        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty() && opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            }
            else {
                std::cout << (position + 1) << std::endl;
                return 0;
            }
        }
    }
    if (opening_brackets_stack.empty()) {
        std::cout << "Success" << std::endl;
    }
    else {
        std::cout << (opening_brackets_stack.top().position + 1) << std::endl;
    }
    return 0;
}
