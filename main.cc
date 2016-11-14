//Include nana/gui.hpp header file to enable Nana C++ Library
//for the program.
#include "nana/gui.hpp"
//Include a label widget, we will use it in this example.
#include "nana/gui/widgets/label.hpp"

int main() {
  //All names of Nana is in the namespace nana;
  using namespace nana;
  //Define a form object, class form will create a window
  //when a form instance is created.
  //The new window default visibility is false.
  form fm;

  /*
  drawing{fm}.draw([](paint::graphics &graph) {
      std::string hw = "Hello, world!";
      auto hw_size = graph.text_extent_size(hw);
      graph.string(
          point{static_cast<int>(graph.width() - hw_size.width) / 2,
                  static_cast<int>(graph.height() - hw_size.height) / 2},
          hw);
  });
  */

  //It's unnecessary to specify a rectangle if useing
  //layout management.
  label lb{fm};
  lb.caption("Hello, world!");
  //Set a background color, just for observation.
  lb.bgcolor(colors::azure);
  //Define a layout object for the form.
  place layout(fm);
  //The div-text
  layout.div("vert<><<><here weight=80><>><>");
  layout["here"] << lb;
  layout.collocate();

  fm.show();
  //Pass the control of the application to Nana's event
  //service. It blocks the execution for dispatching user
  //input until the form is closed.
  exec();
}