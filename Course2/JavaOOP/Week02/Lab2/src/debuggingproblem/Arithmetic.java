package debuggingproblem;//   Debugging Problem /

public class Arithmetic {

    
   public void static main( String args[] )
   {
      String firstNumber, secondNumber, thirdNumber;  
      int num2, num3, sum, product, average;

      firstNumber =  JoptionPane.showInputDialog( "Enter first integer:" )

      secondNumber =  JoptionPane.showInputDialog( "Enter second integer:" )
      
      thirdNumber = JoptionPane.showInputDialog( "Enter third integer: )
  
      num1 == Integer.parseInt( firstNumber );
      num2 == Integer.parseInt( secondNumber );
      num3 == Integer.parseInt( thirdNumber );
      
      sum = firstNumber + secondNumber + thirdNumber ;
      product = num1 * num2 * num3;
      average = ( num1 + num2 + num3 ) / 3;
      
      JOptionPane.showMessage( nul, "The sum is " + sum + 
         "\nThe product is " + product +  "\nThe average is " + average, 
         "Results", JOptionPane.PLAIN_MESSAGE );
   }

} // end class Arithmetic

