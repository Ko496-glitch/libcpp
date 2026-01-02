include<new>
#include<type_trait>
#include<vector>
#include<utility>
#include<cassert>
#include "lib::type_trait.hpp"

namespace lib{

  template<typename T,std::size_t capacity_ = 1026, typename buffer_policy, template Container = std::array<T,capacity>>
  class ring_buffer{
    private:
      std::size_t head_; // pointer index to index that will be removed
      std::size_t tail_; // pointer index to free slot
      std::size_t size_; // current size of the array we will use
      Container storage_; // default is set to std::array
    
    T* ptr()noexcept{
      return reinterpret_cast<T>(storage_);
    }

    const T*()const noexcept{
      return reinterpret_cast<T>(storage_);
    }
    

    public:
      constexpr ring_buffer()noexcept : head_(0),tail_(0),size_(0){}
      
void clear(){
        if(this->size_ != 0){
          ptr().~T();
        }
      }

      ~ring_buffer(){
        this->clear();
      }

      constexpr std::size_t size()const noexcept{return this->size_;}
      constexpr std::size_t capacity() const noexcept{return this->capacity_;}
      constexpr bool empty() const noexcept{return this->size_ == 0;}
      constexpr bool full() const noexcept{return this->size_ == this->capacity_;}
      
      
      /* 0 <= size <= capacity
       * tail_ = (head_ + size_) % capacity-;  
       */
      
  };

}
