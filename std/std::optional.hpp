#pragma once
#include<iostream>
#include<utility>
#include<new>
#include<type_traits>

template<typename T, std::size_t N>
class optional{
  std::aligned_storage_t<sizeof(T), alignof(T)> storage;
    // storage here will be our array for current object slot space.
  bool engaged;// Flag for either we have a value or not;
  
  T *ptr()noexcept{
    return reinterpret_cast<T*>(storage);
  }

  const T* ptr()const noexcept{
    return reinterpret_cast<const T*>(storage);
  }
  
  public:
  

  void clear(){
    if(this->engaged){
      ptr()->~T();
      this->engaged = false;
    }
  }

  optional() noexcept : engaged(false){}//default constructor
  
  ~optional(){
    clear();   
  }


  // Copy Constructor --- ----------------------------------
  template<typename U = T, typename std::enable_if_t<std::is_copy_constructible_v<U>>>
  optional(const optional& other) noexcept : engaged(false){
    if(other.engaged){
      new (storage)T(*other.storage);
      this->engaged = true;
    }
  }

  //Move Constructor ----------------------------------------
  template<typename U = T, typename = std::enable_if_t<std::is_move_constructible_v<U>>>

  optional(optional&& other) noexcept : engaged(false){
    if(other.engaged){
      this->engaged = true;
      new(storage)T(std::move(*other.ptr()));
      other.engaged = false;
    }
  }

  optional operator=(optional&& other)noexcept{
    if(this == &other)return *this;
    // All 4 Conditions
    // 1) Both are engaged -> we wil
    // 2) !this    other -> contruct this and copy
    // 3) this    !other -> destroy
    // 4) !this   !other -> do nothing 
    if(this->engaged && other.engaged){
      *this->ptr() = *other.ptr();
    }else if(!this->engaged && !other.engaged){
      return *this;
    }else if(this->engaged && !other.engaged){
     ptr()->~T();
    }else{
      new(storage)T(*other.storage);
      this->engaged = true;
    }
  }
   
};




