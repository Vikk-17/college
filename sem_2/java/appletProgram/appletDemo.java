import javax.swing.*;
import java.awt.*;

/* <applet code="appletDemo" width='300' height='300'>
</applet>
*/



class appletDemo extends JApplet{
  JLabel l;
  JTextField t;
  JCheckBox r, g, b, y;

  public void init(){
    l = new JLabel("Select colors: ");
    t = new JTextField(20);
    r = new JCheckBox("Red");
    g = new JCheckBox("Green");
    b = new JCheckBox("Blue");
    y = new JCheckBox("Yellow");
  }
}
