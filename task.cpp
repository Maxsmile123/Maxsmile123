#include <iostream>
#include <string>

void FindExpression(int32_t num, int32_t current_var, int32_t target, std::string&& expression) {
    if (num == -1) {
        if (target == 200) {
            if (expression[0] == '+') {
                for (size_t i = 1; i < expression.length(); ++i) {
                    std::cout << expression[i];
                }
                std::cout << " = 200" << std::endl;
            } else{
                std::cout << expression << " = 200" << std::endl;
            }
        }
        return;
    }
    // put +
    FindExpression(num - 1, num - 1, target + current_var, expression + "+" + std::to_string(current_var));
    // put -
    FindExpression(num - 1, num - 1, target - current_var, expression + "-" + std::to_string(current_var));
    // merge numbers
    FindExpression(num - 1, current_var*10 + (num - 1), target, std::move(expression));
}

int main() {
    FindExpression(9, 9, 0, "");
    return 0;
}
/* output:
9-8+7-6-5-4-3+210 = 200
9-8-7-6-5+4+3+210 = 200
-9+8-7-6+5-4+3+210 = 200
-9-8+7+6-5-4+3+210 = 200
-9-8+7-6+5+4-3+210 = 200
98-7+65+43+2-1+0 = 200
98-7+65+43+2-1-0 = 200
98-7+65+43+2-1 = 200
98+76-5+43-2-10 = 200
-98+76+5+4+3+210 = 200

*/
