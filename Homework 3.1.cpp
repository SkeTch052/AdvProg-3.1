#include <iostream>

class smart_array {
private:
    int* array;
    int count, size;
public:
    smart_array(int user_size) {
      size = user_size;
      count = 0;
      array = new int[size];
    }
    void add_element(int elem) {
        if (count >= size) {
          throw std::exception("ERROR 1: The number of elements is greater than the number of elements for which memory is allocated");
        }
        else {
          array[count] = elem;
          count++;
        }
    }
    int get_element(unsigned int index) {
        if (index > size) {
          throw std::exception("ERROR 2: Bad index");
        }
        else {
          return array[index];
        }
    }
    ~smart_array() {
        delete[] array;
        count = 0;
    }
};

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}