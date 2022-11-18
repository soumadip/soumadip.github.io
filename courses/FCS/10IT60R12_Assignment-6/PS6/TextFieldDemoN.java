import java.awt.*;
import java.applet.*;
import java.lang.Math;
//import Mypackage.*;
public class TextFieldDemo extends Applet{
      TextField prin,inter,year,stotal,ctotal;
      Label Prin,Inter,Year,Stotal,Ctotal;
      float p,i,y,tcI,tsI;
      Button sI,cI;
      public void init(){
            prin=new TextField("0.0",10);
            inter=new TextField("0.0",10);
            year=new TextField("1.0",10);
            stotal=new TextField("0.0",10);
            ctotal=new TextField("0.0",10);
            stotal.setEditable(false); // Make output field not editable.
            ctotal.setEditable(false);
             Prin=new Label("Principal");
             Inter=new Label("Interest");
             Year=new Label("Year");
           Stotal=new Label("SI Total",Label.CENTER);
           Ctotal=new Label("CI Total",Label.CENTER);
            sI=new Button("Simple Interest");
            cI=new Button("Compound Interest");
            //TextField year=new TextField("1.0",10);
            add(Prin);        add(prin);
            add(Year);        add(year);
            add(Inter);       add(inter);
            add(Stotal);      add(stotal);
            add(Ctotal);      add(ctotal);
            add(sI);
            add(cI);
      }
      public void calculate(){
            String temp;
            //Graphics g;
      //    Myclass myclass=new Myclass();
            temp=prin.getText();
            p=Float.valueOf(temp).floatValue();
            temp=year.getText();
            y=Float.valueOf(temp).floatValue();
            temp=inter.getText();
            i=Float.valueOf(temp).floatValue();
            //tsI=myclass.getsI(p,i,y);
           tsI=p+p*i*y/100;
           //tcI=myclass.getcI(p,i,y);
           tcI=p*(float) (Math.pow( (1+i/100),y) );
     }
     public void paint(Graphics g){
           int i[]=new int[2];
           int j=1;
           Graphics g2;
           i[0]=(int)(360*p/tsI);
           i[1]=(int)(360*p/tcI);
           System.out.println("i =\t"+i);
           //catch(NumberFormatException nfe)
           g.setColor(Color.blue);
           g.fillArc(100,100,100,100,180,i[0]);
           g.setColor(Color.red);
           g.fillArc(100,100,100,100,180,-360+i[0]);
           g.setColor(Color.blue);
           g.fillArc(200,100,100,100,180,i[1]);
           g.setColor(Color.red);
           g.fillArc(200,100,100,100,180,-360+i[1]);
     }
public boolean action (Event evt, Object arg) {
    String temp;
              // Button hit
     if (evt.target instanceof Button) {
               if (evt.target == sI) {
                 calculate();
                 temp=String.valueOf(tsI);
                    stotal.setText(temp);
               }
               else if (evt.target == cI) {
                 calculate();
                 temp=String.valueOf(tcI);
                    ctotal.setText(temp);
               }
             }
             return(true);
           }
   }

