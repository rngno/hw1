#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

std::string const &ULListStr::front() const{
  // catch if list is empty
  if(head_ == nullptr){
    return NULL;
  }
  return head_->val[head_->first];
}

std::string const &ULListStr::back() const{
  // catch if list is empty
  if(tail_ == nullptr){
    return NULL;
  }
  return tail_->val[tail_->last-1];
}

std::string *ULListStr::getValAtLoc(size_t loc) const{
  // handle if loc is invalid (probably don't need head_ as a condition but im scared to take it out)
  if(head_ == nullptr || loc >= size_){
    return nullptr;
  }
  Item* tmp = head_;
  while(tmp != nullptr){
    size_t idx = tmp->last-tmp->first;
    // determine if loc is within tmp, if not then we move to the next node
    if(loc < idx){
      return tmp->val + tmp->first + loc;
    }
    // loc isn't in tmp, so move onto next node
    else{
      loc = loc - idx;
      tmp = tmp->next;
    }
  }
  return nullptr; // this shouldn't be reachable but it needs to be here for compiler
}

void ULListStr::push_back(const std::string& val)
{
  // handle if list is empty
  if (tail_ == nullptr) {
    Item* tmp = new Item();
    // since only 1 item now, head and tail are listed as tmp
    head_ = tmp;
    tail_ = tmp;
  }
  // make a new tail node if one already exists and tail is full
  if (tail_->last == ARRSIZE) {
    Item* tmp = new Item();
    tmp->prev = tail_;
    tail_->next = tmp;
    tail_ = tmp;
  }
  // handle inserting val after the position of tmp in the LL
  tail_->val[tail_->last] = val;
  tail_->last++; // last index is exclusive per requirements
  size_ ++;
}

void ULListStr::pop_back(){
  // handle empty list
  if(tail_ == nullptr){
    return; // nothing to do here
  }
  // get rid of dead space if array isn't empty
  else if(tail_->last - tail_->first > 1){
    tail_->last--;
  }
  else{
    Item* tmp = tail_;
    // check if list is only 1 item
    if(size_ == 1){
      // if list is only 1 item, head_ and tail_ will be empty after popping
      head_ = nullptr;
      tail_ = nullptr;
    }
    // >1 item list
    else{
      tail_ = tail_->prev; // second to last node takes over now empty tail_
      tail_->next = nullptr; // the new tail_ shouldn't have a next node
    }
    delete tmp; // free the old tail_ node
  }
  size_--;
}

void ULListStr::push_front(const std::string& val){
  // empty list handling
  if(head_ == nullptr){
    Item* tmp = new Item();
    head_ = tmp;
    tail_ = tmp; // same handling as push_back()
    head_->first = ARRSIZE-1; // insert on right side so other elements can be insert to the left later
    head_->val[head_->first] = val;
    head_->last = ARRSIZE;
  }
  // handle if there is some room left in head_ before first
  else if (head_->first > 0){
    // insert into slot before head_->first
    head_->first--;
    head_->val[head_->first] = val;
  }
  // handle if there is no room in head_
  else{
    // replace head_ with tmp
    Item* tmp = new Item();
    tmp->next = head_;
    head_->prev = tmp;
    head_ = tmp;
    head_->first = ARRSIZE-1; // insert on right side so other elements can be insert to the left later
    head_->val[head_->first] = val;
    head_->last = ARRSIZE;
  }
  size_++;
}

void ULListStr::pop_front(){
  if(head_ == nullptr){
    return; // list is empty anyway
  }
  // get rid of dead space if array isn't empty
  else if(head_->last - head_->first > 1){
    head_->first++; // just get rid of first element
  }
  else{
    Item* tmp = head_;
    // if list is only 1 item, head_ and tail_ will be empty after popping
    if(size_ == 1){
      head_ = nullptr;
      tail_ = nullptr;
    }
    // >1 item list
    else{
      head_ = head_->next; // node after head takes over now empty head_
      head_->prev = nullptr; // new head_ shouldn't have a prev node
    }
    delete tmp; // free old head_ node
  }
  size_--;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
