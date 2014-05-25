/**
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 */

class Solution {
public:
  void reverseWords(string &s) {
    string::size_type size = s.size();
    stack<string> words;
    int lastSpace = 0, current = 0;
    bool spaceFlag = true;
    for (int i = 0; i < size; i++) {
      if(s[i] == ' ') {
        if (spaceFlag == false) {
          spaceFlag = true;
          words.push(s.substr(lastSpace, i - lastSpace));
        }
      } else {
        if (spaceFlag == true) {
          spaceFlag = false;
          lastSpace = i;
        }
      }
    }
    if (spaceFlag == false) {
      words.push(s.substr(lastSpace, size - lastSpace));
    }
    s = "";
    if (words.empty()) {
      return;
    }
    while (true) {
      s.append(words.top());
      words.pop();
      if (words.empty()) {
        break;
      }
      s.append(" ");
    }
  }
};