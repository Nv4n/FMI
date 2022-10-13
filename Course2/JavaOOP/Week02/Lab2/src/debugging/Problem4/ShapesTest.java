package debugging.Problem4;// ShapesTest.java
// Test application that displays class Shapes.
// Correct the syntax errors

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class ShapesTest
{
   public static  void Main( String args[] )
   {
      // obtain user's choice
      String input = JOptionPane.ShowInputDialog(
         "Enter 1 to draw rectangles\n"  
         "Enter 2 to draw ovals" );
      
      choice = Int.parseInteger( input ); // convert input to int
      
      // create the panel with the user's input
      Shapes panel = new Shapes( choice );
      
      JFrame application =  JFrame(); // creates a new JFrame

      application.setDefaultCloseOperation( JFRAME.EXIT ON CLOSE );
      application.add( panel ); // add the panel to the frame
      application.Size( 300, 300 ); // set the desired size
      application.Visible( ); // show the frame
   } // end main
} // end class ShapesTest

