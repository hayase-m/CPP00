#include <iostream>
#include <string>

int main(void) {
  std::string input;

  // テスト1: cin >> でスペースを含む文字列を読む
  std::cout << "=== Test 1: cin >> ===" << std::endl;
  std::cout << "Enter a name (try 'John Smith'): ";
  std::cin >> input;
  std::cout << "cin >> got: [" << input << "]" << std::endl;

  // バッファに残った文字列を捨てる
  std::cin.ignore(1000, '\n');

  // テスト2: getline でスペースを含む文字列を読む
  std::cout << std::endl;
  std::cout << "=== Test 2: getline ===" << std::endl;
  std::cout << "Enter a name (try 'John Smith'): ";
  std::getline(std::cin, input);
  std::cout << "getline got: [" << input << "]" << std::endl;

  // テスト3: EOFの検出
  std::cout << std::endl;
  std::cout << "=== Test 3: EOF detection ===" << std::endl;
  std::cout << "Enter something (or press Ctrl+D): ";
  if (std::cin >> input) {
    std::cout << "Success: [" << input << "]" << std::endl;
  } else {
    std::cout << std::endl;
    std::cout << "cin failed! (EOF or error)" << std::endl;
  }

  return 0;
}