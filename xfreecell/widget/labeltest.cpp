#include "widget.h"

class TestFrame : public NSFrame {
public:
  TestFrame() : l(""), con(100, 100) { con.add(&l); container(&con); selectInput(ButtonPressMask); }

  void dispatchEvent(const gi_msg_t&);

private:
  NSLabel l;
  NSHContainer con;
};
  
void TestFrame::dispatchEvent(const gi_msg_t& ev)
{
  static string str("");

  if (ev.type == ButtonPress) {
    str += 'a';
    l.label(str.c_str());
  }
}

int main()
{
  NSInitialize();

  TestFrame tf;

  tf.map();

  NSMainLoop();

  return 0;
}
