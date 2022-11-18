// Event handling
import java.awt.*;
import java.applet.*;
public class EventDemo extends Applet {
    static final int n = 4;
    Label label;
    public void init( ) {     // To initialize the applet for 16-cells grid
      setLayout (new GridLayout (n,n);           // To for 4x4 cells grid
      setFont (new Font ("Helvetica", Font.BOLD, 24 ));        // Font of Helvetica of size 24
      for (int i =0; i < n; i++ )   {
         for (int j = 0; j < n; j++ ) {
            int k = i * n + j;
            if (k > 0)
               add (new Button (" " + k);     // Place a button at (i,j)-th cell
         }
      }
      label = new Label (" * " , Label.CENTER );
      label.setFont (new FONT (" Times Roman", Font.ITALIC, 24 ));
      add (label );
    }
    public boolean action(Event e, Object obj) {                  // Overridden event handler
      if (e.target instanceof Button ) ) {                        // Wait for clicking a button object
         label.setText ((String ) obj );                    // Print the value of the Clicked butoon
      }
      return false ;
    }
}

