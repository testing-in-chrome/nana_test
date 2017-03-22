#include <nana/gui.hpp>
#include <nana/gui/widgets/textbox.hpp>

int main() {
  using namespace nana;

  form fm;

  textbox tbox(fm);

  // Step 1: Set a highlight and name it "sql", specifies the foreground color
  // and background color
  tbox.set_highlight("sql", colors::blue, colors::yellow);
  //Step 2: Add words to the "sql".
  tbox.set_keywords("sql", false, true, {"select", "from", "where"});

  //Set another highlight
  tbox.set_highlight("country", colors::blue, colors::yellow);
  tbox.set_keywords("country", false, true, {"Germany", "Russia",
                        "United Kingdom", "United States"});
  tbox.set_keywords("country", false, true, {"China", "Japan", "Singapore"});

  fm.div("margin=10 text");
  fm["text"] << tbox;
  fm.collocate();

  fm.show();
  exec();
}
