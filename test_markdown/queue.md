
Queue is First in First out. Queue elements are pushed in the back of the queue
and come out from front of the queue. Removal of elements is from the Front 
Adding of elements is from the back of the Queue. cpp we can access elements
from the back of the Queue or front of the Queue.




```cpp
#include "vector"
#in
int main() {
       std::map<int, std::string> m;
        m[1] = "ee"; // first way
        m.insert(std::make_pair(23, "ee"));// second way
        m.insert(std::pair(34, "333")); // third way
        m.insert({2, "err"});  //fourth way

    return 0;
}
```

How to insert into a unordered map im c++

```cpp
#include <unordered_map>


int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    return 0;
}
```

How to iterate all the elements of a map c++

```cpp
#include <unordered_map>


int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    return 0;
}

// working types
// how to iterate over a map  using for loop and auto keyword.

int main() {
    std::unordered_map<int, std::string> m;
    m[1] = "ee";
    m.insert(std::make_pair(23, "ee"));
    m.insert(std::pair(34, "333"));
    m.insert({2, "err"});
    for (auto i: m) {
        std::cout << i.first << std::endl;
        assert((is_same<decltype(i), pair<const int, string>>::value));
        assert((is_same<decltype(i.first), const int>::value));
        assert((is_same<remove_const<remove_reference<decltype(i.first)>::type>::type, int>::value));
        assert((is_same<decltype(i.second), string>::value));
    }
    return 0;
}
```

Find element in a map by key


```cpp

#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }

  return 0;
}




```