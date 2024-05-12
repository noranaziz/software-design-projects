#include "Array.h"
#include <iostream> // to output to console

int main (int argc, char * argv [])
{
  // TODO Add code here to test your Array class.
  
  // === TESTING DEFAULT CTOR ===
  Array * defaultArr = new Array();
  std::cout << "current size of default array: " << defaultArr->size() << "\n";
  std::cout << "max size of default array: " << defaultArr->max_size() << "\n";
  for(size_t i = 0; i < defaultArr->size(); i++) {
    std::cout << defaultArr->get(i) << " ";
  } // nothing will be outputted
  std::cout << "\n"; std::cout << "\n";
  
  // === TESTING CTOR W/ LENGTH PARAM (+) ===
  Array * lengthArr1 = new Array(5);
  std::cout << "current size of array w/ length 5: " << lengthArr1->size() << "\n";
  std::cout << "max size of array w/ length 5: " << lengthArr1->max_size() << "\n";
  for(size_t i = 0; i < lengthArr1->size(); i++) {
    std::cout << lengthArr1->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  // === TESTING CTOR W/ LENGTH PARAM (0) ===
  try {
    Array * lengthArr2 = new Array(0);
    std::cout << "current size of array w/ length 0: " << lengthArr2->size() << "\n";
    std::cout << "max size of array w/ length 0: " << lengthArr2->max_size() << "\n";
    for(size_t i = 0; i < lengthArr2->size(); i++) {
      std::cout << lengthArr2->get(i) << " ";
    }
    std::cout << "\n"; std::cout << "\n";
    
      // delete 
    delete lengthArr2;
  } catch(const std::exception & e) {
    std::cerr << "caught exception: " << e.what() << "\n\n";
  }
  
  // TESTING CTOR W/ LENGTH PARAM (-) ===
  try {
    Array * lengthArr3 = new Array(-5);
    std::cout << "current size of array w/ length -5: " << lengthArr3->size() << "\n";
    std::cout << "max size of array w/ length -5: " << lengthArr3->max_size() << "\n";
    for(size_t i = 0; i < lengthArr3->size(); i++) {
      std::cout << lengthArr3->get(i) << " ";
    }
    std::cout << "\n"; std::cout << "\n";
    
      // delete
    delete lengthArr3;
  } catch(const std::exception & e) {
    std::cerr << "caught exception: " << e.what() << "\n\n";
  }

  
  // === TESTING CTOR W/ LENGTH PARAM (+), FILL PARAM ('A') ===
  Array * lengthCharArr1 = new Array(5, 'L');
  std::cout << "current size of array w/ length 5, char 'L': " << lengthCharArr1->size() << "\n";
  std::cout << "max size of array w/ length 5, char 'L': " << lengthCharArr1->max_size() << "\n";
  for(size_t i = 0; i < lengthCharArr1->size(); i++) {
    std::cout << lengthCharArr1->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // === TESTING CTOR W/ LENGTH PARAM (0), FILL PARAM ('A') ===
  try {
    Array * lengthCharArr2 = new Array(0, 'A');
    std::cout << "current size of array w/ length 0, char 'A': " << lengthCharArr2->size() << "\n";
    std::cout << "max size of array w/ length -5, char 'A': " << lengthCharArr2->max_size() << "\n";
    for(size_t i = 0; i < lengthCharArr2->size(); i++) {
      std::cout << lengthCharArr2->get(i) << " ";
    }
    std::cout << "\n"; std::cout << "\n";
    
    // delete
    delete lengthCharArr2;
  } catch(const std::exception & e) {
    std::cerr << "caught exception: " << e.what() << "\n\n";
  }

  // === TESTING CTOR W/ LENGTH PARAM (-), FILL PARAM ('F') ===
  try {
    Array * lengthCharArr3 = new Array(-5, 'F');
    std::cout << "current size of array w/ length -5, char 'F': " << lengthCharArr3->size() << "\n";
    std::cout << "max size of array w/ length -5: char 'F': " << lengthCharArr3->max_size() << "\n";
    for(size_t i = 0; i < lengthCharArr3->size(); i++) {
      std::cout << lengthCharArr3->get(i) << " ";
    }
    std::cout << "\n"; std::cout << "\n";
    
    // delete 
    delete lengthCharArr3;
  } catch(const std::exception & e) {
    std::cerr << "caught exception: " << e.what() << "\n\n";
  }

  
  // === TESTING COPY CTOR W/ EMPTY ARRAY (defaultArr) ===
  Array * copyArr1 = new Array(*defaultArr);
  std::cout << "current size of copied default array: " << copyArr1->size() << "\n";
  std::cout << "max size of copied default array: " << copyArr1->max_size() << "\n";
  for(size_t i = 0; i < copyArr1->size(); i++) {
    std::cout << copyArr1->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete defaultArr;
  delete copyArr1;
  
  // === TESTING COPY CTOR W/ ARRAY W/ LENGTH PARAM (+) (lengthArr1) ===
  Array * copyArr2 = new Array(*lengthArr1);
  std::cout << "current size of copied lengthArr1 array: " << copyArr2->size() << "\n";
  std::cout << "max size of copied lengthArr1 array: " << copyArr2->max_size() << "\n";
  for(size_t i = 0; i < copyArr2->size(); i++) {
    std::cout << copyArr2->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete lengthArr1;
  delete copyArr2;

  
  // === TESTING COPY CTOR W/ ARRAY W/ LENGTH PARAM (+), FILL PARAM ('A') (lengthCharArr1) ===
  Array * copyArr5 = new Array(*lengthCharArr1);
  std::cout << "current size of copied lengthCharArr1 array: " << copyArr5->size() << "\n";
  std::cout << "max size of copied lengthCharArr1 array: " << copyArr5->max_size() << "\n";
  for(size_t i = 0; i < copyArr5->size(); i++) {
    std::cout << copyArr5->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete lengthCharArr1;
  delete copyArr5;
  
  // === TESTING COPY CTOR W/ LARGE ARRAY, FILL PARAM ('Z') (largeArray) ===
  Array * largeArr = new Array(100, 'Z');
  Array * copyArr8 = new Array(*largeArr);
  std::cout << "current size of copied large array: " << copyArr8->size() << "\n";
  std::cout << "max size of copied large array: " << copyArr8->max_size() << "\n";
  for(size_t i = 0; i < copyArr8->size(); i++) {
    std::cout << copyArr8->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete largeArr;
  delete copyArr8;

  // === TESTING OPERATOR = - DIFFERENT ARRAYS ===
  Array * setArray1 = new Array(10, 'Y');
  Array * setArray2 = new Array(13, 'X');
  std::cout << "Before = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n";
  std::cout << "setArray2: ";
  for(size_t i = 0; i < setArray2->size(); i++) {
    std::cout << setArray2->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  std::cout << "setting setArray1 to setArray2" << "\n\n";
  *setArray1 = *setArray2;
  
  std::cout << "After = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n";
  std::cout << "setArray2: ";
  for(size_t i = 0; i < setArray2->size(); i++) {
    std::cout << setArray2->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete setArray2;
  
  // === TESTING OPERATOR = - SAME ARRAYS ===
  std::cout << "Before = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "setting setArray1 to setArray1" << "\n\n";
  *setArray1 = *setArray1;

  std::cout << "After = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  // === TESTING OPERATOR = - EMPTY ARRAY ===
  Array * emptyArr = new Array();
  std::cout << "Before = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n";
  std::cout << "emptyArr: ";
  for(size_t i = 0; i < emptyArr->size(); i++) {
    std::cout << emptyArr->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "setting setArray1 to emptyArr" << "\n\n";
  *setArray1 = *emptyArr;

  std::cout << "After = operator: " << "\n";
  std::cout << "setArray1: ";
  for(size_t i = 0; i < setArray1->size(); i++) {
    std::cout << setArray1->get(i) << " ";
  }
  std::cout << "\n";
  std::cout << "emptyArr: ";
  for(size_t i = 0; i < emptyArr->size(); i++) {
    std::cout << emptyArr->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete emptyArr;
  delete setArray1;

  // === TESTING OPERATOR [] ===
  Array * bracketArray = new Array(10, 'C');
  for(size_t i = 0; i < bracketArray->size(); i++) {
    std::cout << bracketArray->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // set 
  (*bracketArray)[0] = 'B';
  for(size_t i = 0; i < bracketArray->size(); i++) {
    std::cout << bracketArray->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // get
  char value = (*bracketArray)[0];
  std::cout << "Index 0 of bracketArray: " << value << "\n\n";

  // === TESTING OPERATOR [] CONST ===
  Array * constArray = new Array(7, 'M');
  for(size_t i = 0; i < constArray->size(); i++) {
    std::cout << constArray->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // since constArray is const, can only "get"
  value = (*constArray)[3];
  std::cout << "Index 3 of constArray: " << value << "\n\n";

  delete constArray;

  // === TESTING .GET() ===
  std::cout << "char at index 6 of bracketArray: " << bracketArray->get(6) << "\n\n";
  try {
    std::cout << "char at index -1 of bracketArray: " << bracketArray->get(-1) << "\n"; // throws std::out_of_range
  } catch(const std::exception & e) {
    std::cerr << "caught exception: " << e.what() << "\n\n";
  }

  // === TESTING .SET() ===
  bracketArray->set(7, 'S');
  std::cout << "setting char at index 7 of bracketArray to S: " << bracketArray->get(7) << "\n";
  for(size_t i = 0; i < bracketArray->size(); i++) {
    std::cout << bracketArray->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  delete bracketArray;
  

  // === TESTING .RESIZE() ===
  Array * abc = new Array(26, 'A');
  for(size_t i = 0; i < abc->size(); i++) {
    abc->set(i, static_cast<char>('A' + i));
  }
  std::cout << "alphabet (abc) array of length 26: \n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  abc->resize(10);
  std::cout << "resizing abc to 10: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  abc->resize(26);
  std::cout << "resizing abc to 26: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  abc->resize(5);
  std::cout << "resizing abc to 5: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  abc->resize(26);
  std::cout << "resizing abc to 26: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  abc->resize(30);
  std::cout << "resizing abc to 30: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  abc->resize(20);
  std::cout << "resizing abc to 20: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  abc->resize(26);
  std::cout << "resizing abc to 26: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // == TESTING .FIND(ch) ===
  int index = abc->find('B');
  std::cout << "finding B in abc: index " << index << "\n\n";
  index = abc->find('C');
  std::cout << "finding C in abc: index " << index << "\n\n";
  index = abc->find('A');
  std::cout << "finding A in abc: index " << index << "\n\n";

  // === TESTING .FIND(ch, start) ===
  index = abc->find('B', 0);
  std::cout << "finding B starting from 0 in abc: index " << index << "\n\n";
  index = abc->find('B', 1);
  std::cout << "finding B starting from 1 in abc: index " << index << "\n\n";
  index = abc->find('C', 0);
  std::cout << "finding C starting from 0 in abc: index " << index << "\n\n";
  index = abc->find('C', 5);
  std::cout << "finding C starting from 5 in abc: index " << index << "\n\n";

  // === TESTING OPERATOR == ===
  Array * lArray = new Array(3, 'L');
  Array * lArray2 = new Array(3, 'L');
  Array * lArray3 = new Array(5, 'L');
  Array * nArray = new Array(5, 'N');

  std::cout << "lArray == lArray?" << "\n";
  for(size_t i = 0; i < lArray->size(); i++) {
    std::cout << lArray->get(i) << " ";
  }
  std::cout << "\n";
  bool equality = *lArray == *lArray;
  if(equality) {
    std::cout << "lArray and lArray are equal.";
  } else {
    std::cout << "lArray and lArray are not equal.";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "lArray == lArray2?" << "\n";
  for(size_t i = 0; i < lArray->size(); i++) {
    std::cout << lArray->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < lArray2->size(); i++) {
    std::cout << lArray2->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray == *lArray2;
  if(equality) {
    std::cout << "lArray and lArray2 are equal.";
  } else {
    std::cout << "lArray and lArray2 are not equal.";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "lArray == lArray3?" << "\n";
  for(size_t i = 0; i < lArray->size(); i++) {
    std::cout << lArray->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < lArray3->size(); i++) {
    std::cout << lArray3->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray == *lArray3;
  if(equality) {
    std::cout << "lArray and lArray3 are equal.";
  } else {
    std::cout << "lArray and lArray3 are not equal.";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "lArray3 == nArray?" << "\n";
  for(size_t i = 0; i < lArray3->size(); i++) {
    std::cout << lArray3->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < nArray->size(); i++) {
    std::cout << nArray->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray3 == *nArray;
  if(equality) {
    std::cout << "lArray3 and nArray are equal.";
  } else {
    std::cout << "lArray3 and nArray are not equal.";
  }
  std::cout << "\n"; std::cout << "\n"; 
  
  // === TESTING OPERATOR != ===
  std::cout << "lArray != lArray2?" << "\n";
  for(size_t i = 0; i < lArray->size(); i++) {
    std::cout << lArray->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < lArray2->size(); i++) {
    std::cout << lArray2->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray != *lArray2;
  if(equality) {
    std::cout << "lArray and lArray2 are not equal.";
  } else {
    std::cout << "lArray and lArray2 are equal.";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "lArray != lArray3?" << "\n";
  for(size_t i = 0; i < lArray->size(); i++) {
    std::cout << lArray->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < lArray3->size(); i++) {
    std::cout << lArray3->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray != *lArray3;
  if(equality) {
    std::cout << "lArray and lArray3 are not equal.";
  } else {
    std::cout << "lArray and lArray3 are equal.";
  }
  std::cout << "\n"; std::cout << "\n";

  std::cout << "lArray3 != nArray?" << "\n";
  for(size_t i = 0; i < lArray3->size(); i++) {
    std::cout << lArray3->get(i) << " ";
  }
  std::cout << "\n";
  for(size_t i = 0; i < nArray->size(); i++) {
    std::cout << nArray->get(i) << " ";
  }
  std::cout << "\n";
  equality = *lArray3 != *nArray;
  if(equality) {
    std::cout << "lArray3 and nArray are not equal.";
  } else {
    std::cout << "lArray3 and nArray are equal.";
  }
  std::cout << "\n"; std::cout << "\n";
  
  // === TESTING FILL ===
  std::cout << "Filling lArray3 with N: \n";
  lArray3->fill('N');
  for(size_t i = 0; i < lArray3->size(); i++) {
    std::cout << lArray3->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  delete lArray;
  delete lArray2;
  delete lArray3;
  delete nArray;

  // === TESTING .SHRINK() ===
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  abc->shrink();
  std::cout << "shrinking abc: \n";
  std::cout << "cur_size_ of abc: " << abc->size() << "\n";
  std::cout << "max_size_ of abc: " << abc->max_size() << "\n";
  for(size_t i = 0; i < abc->max_size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // === TESTING .REVERSE() ===
  std::cout << "abc: \n";
  for(size_t i = 0; i < abc->max_size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n";
  std::cout << "reverse abc: \n";
  abc->reverse();
  for(size_t i = 0; i < abc->max_size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  std::cout << "reverse again: \n";
  abc->reverse();
  for(size_t i = 0; i < abc->max_size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  
  // === TESTING .SLICE(begin) ===
  std::cout << "sliced abc array from index 10: \n";
  Array * slice = new Array(abc->slice(10));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "sliced abc array from index 5: \n";
  slice = new Array(abc->slice(5));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "sliced abc array from index 15: \n";
  slice = new Array(abc->slice(15));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "abc: \n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";

  // === TESTING .SLICE(begin, end) ===
  std::cout << "sliced abc array from index 0 to index 10: \n";
  slice = new Array(abc->slice(0, 10));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "sliced abc array from index 5 to index 2: \n";
  slice = new Array(abc->slice(5, 2));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "sliced abc array from index 15 to index 22: \n";
  slice = new Array(abc->slice(15, 22));
  for(size_t i = 0; i < slice->size(); i++) {
    std::cout << slice->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete slice;
  std::cout << "abc: \n";
  for(size_t i = 0; i < abc->size(); i++) {
    std::cout << abc->get(i) << " ";
  }
  std::cout << "\n"; std::cout << "\n";
  delete abc;
  
  return 0;
}