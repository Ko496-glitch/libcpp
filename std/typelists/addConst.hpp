#include "PushFront.hpp"


template<typename T>
class addConst{

  public:

    using type = T const;

};


template<typename T>
class addVolatile{

  public:

    using type = volatile T;

};

template<class T>
using AddConst = typename AddConst<T>::type;


template<typename List, template<typename T>class MetaFunc,bool empty = isEmpty<List>::value>
class transform;


template<typename List, template<typename T>class MetFunc> 
class Transform<List,MetaFunc,true>{
  
  public:
  using result = List;

};


//recursive case

//list = [int, char, unsigned] ->>>>>>> [const int, const char, const unsigned] 

template<typename List,template<typename T>class MetaFunc>

class Tranform<List,MetaFunc,false> : public PushFront<typename Transform<PopFront<List>>,MetaFunc<typename Front<List>>::type>{
  
  public:
    
    using type = PushFront<Transform<PopFront<List>>,MetaFunc<Front<List>>::type;
};

template<typename List, template<typename T>class MetaFunc>
using transform  = Transform<List,MetaFunc>::type;



