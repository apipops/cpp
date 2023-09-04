#include "MutantStack.hpp"

int main()
{
  MutantStack<int> stack;

  for (int i = 0; i < 5; i++)
    stack.push(i);

  std::cout << "------ITERATORS-------" << std::endl;
  std::cout << "> from begin() to end()" << std::endl;
  for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
    std::cout << *it << std::endl;
  std::cout << std::endl << "> from rbegin() to rend()" << std::endl;
  for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); it++)
    std::cout << *it << std::endl;
  
  std::cout << std::endl << "------STACK METHODS-------" << std::endl;
  std::cout << "> top(): " << stack.top() << std::endl;
  std::cout << "> size(): " << stack.size() << std::endl;
  std::cout << "> pop()... New stack: ";
  stack.pop();
  for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}

// Main test fourni par le sujet
/* int main()
{
  {
    std::cout << "> RESULTS WITH MUTANT STACK" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
  }

  {
    std::cout << std::endl << "> RESULTS WITH LIST" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    //[...]
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::list<int> s(list);
  }

return 0;
} */