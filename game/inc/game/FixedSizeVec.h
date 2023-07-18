#pragma once

#include <vector>

namespace space_invaders::game {

template <typename T>
struct FixedSizeVec : protected std::vector<T> {
 public:
  using value_type = typename std::vector<T>::value_type;
  using allocator_type = typename std::vector<T>::allocator_type;
  using size_type = typename std::vector<T>::size_type;
  using difference_type = typename std::vector<T>::difference_type;
  using reference = typename std::vector<T>::reference;
  using const_reference = typename std::vector<T>::const_reference;
  using pointer = typename std::vector<T>::pointer;
  using const_pointer = typename std::vector<T>::const_pointer;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;
  using reverse_iterator = typename std::vector<T>::reverse_iterator;
  using const_reverse_iterator =
      typename std::vector<T>::const_reverse_iterator;

  using std::vector<T>::vector;

  using std::vector<T>::at;
  using std::vector<T>::operator[];
  using std::vector<T>::front;
  using std::vector<T>::back;
  using std::vector<T>::data;

  using std::vector<T>::cend;
  using std::vector<T>::cbegin;
  using std::vector<T>::crend;
  using std::vector<T>::crbegin;

  using std::vector<T>::empty;
  using std::vector<T>::size;
};

}  // namespace space_invaders::game
