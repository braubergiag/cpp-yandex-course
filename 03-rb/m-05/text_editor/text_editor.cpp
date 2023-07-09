#include <string>
#include <algorithm>
//#include "../test_runner.h"
using namespace std;

class Editor {
 public:
  Editor() : pos_(begin(text_)){}
  void Left(){
      if (pos_ > begin(text_) && ! text_.empty()){
          --pos_;
      }
  }
  void Right(){
      if (pos_ < end(text_) && ! text_.empty()){
          ++pos_;
      }
  }
  void Insert(char token){
      text_.insert(pos_++,1,token);
  }
  void Cut(size_t tokens = 1){
      buffer.clear();
      tokens = min(static_cast<size_t>(distance(pos_,end(text_))),
                    tokens);
      buffer.append(pos_, pos_ + tokens);
      text_.erase(pos_,pos_ + tokens);
  }
  void Copy(size_t tokens = 1){
      buffer.clear();
      tokens = min(static_cast<size_t>(distance(pos_,end(text_))),
                   tokens);
      buffer.append(pos_, pos_ + tokens);
  }
  void Paste(){
      text_.insert(pos_ - begin(text_), buffer);
      pos_ += buffer.size() ;
  }
  string GetText() const {
      return text_;
  }


private:
    string text_;
    string buffer;
    string::iterator pos_;
};

#if 1
void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestRightLeft(){
    Editor editor;
    TypeText(editor, "hello, world");
    for (int i = 0; i < 20; ++i) {
        editor.Right();
    }
    for (int i = 0; i < 20; ++i) {
        editor.Left();
    }
}

void TestCopy(){
    Editor editor;
    TypeText(editor,"world");
    for (int i = 0; i < 5; ++i) {
        editor.Left();
    }
    editor.Copy(20);
    for (int i = 0; i < 5; ++i) {
        editor.Right();
    }
    TypeText(editor,", ");
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(),"world, world");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "example");
}
void TestCopy2()
{
    Editor editor;
    TypeText(editor, "1234567");
    editor.Left();
    editor.Left();
    editor.Copy(2);
    editor.Right();
    editor.Right();
    editor.Right();
    editor.Right();
    editor.Right();
    editor.Paste();
    editor.Paste();
    ASSERT_EQUAL(editor.GetText(), "12345676767");
}
int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
    RUN_TEST(tr, TestRightLeft);
    RUN_TEST(tr, TestCopy);
    RUN_TEST(tr, TestCopy2);
  return 0;
}
#endif