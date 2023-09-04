#include "MutanStack.hpp"

int main()
{
  MutanStack<int> stack;

  for (int i = 0; i < 5; i++)
    stack.push(i);

  std::cout << "------ITERATORS-------" << std::endl;
  std::cout << "> from begin() to end()" << std::endl;
  for (MutanStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
    std::cout << *it << std::endl;
  std::cout << std::endl << "> from rbegin() to rend()" << std::endl;
  for (MutanStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); it++)
    std::cout << *it << std::endl;
  
  std::cout << std::endl << "------STACK METHODS-------" << std::endl;
  std::cout << "> top(): " << stack.top() << std::endl;
  std::cout << "> size(): " << stack.size() << std::endl;
  std::cout << "> pop()... New stack: ";
  stack.pop();
  for (MutanStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}