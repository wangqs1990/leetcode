/**
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

 Valid operators are +, -, *, /. Each operand may be an integer or another expression.

 Some examples:
   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    if (tokens.size() == 0) {
      return 0;
    }

    string s = tokens.back();
    tokens.pop_back();
    int tmp1, tmp2;
    if (s.length() == 1 && s[0] < 48){
      switch (s[0]) {
      case '+':
        tmp1 = evalRPN(tokens);
        tmp2 = evalRPN(tokens);
        return tmp2 + tmp1;
      case '-':
        tmp1 = evalRPN(tokens);
        tmp2 = evalRPN(tokens);
        return tmp2 - tmp1;
      case '*':
        tmp1 = evalRPN(tokens);
        tmp2 = evalRPN(tokens);
        return tmp2 * tmp1;
      case '/':
        tmp1 = evalRPN(tokens);
        tmp2 = evalRPN(tokens);
        return tmp2 / tmp1;
      default:
        return atoi(s.c_str());
      }
    } else {
      return atoi(s.c_str());
    }
  }
};