import java.lang.*;
import java.util.*;
abstract class Human{
private String name;
private String DOB;
private String fatherName;

Human(String name,String DOB,String fatherName){
this.name=name;
this.DOB=DOB;
this.fatherName=fatherName;
}
float ageOnDate(){
         Date d1 = new Date(DOB);
         Date d2 = new Date();
         long diff = d2.getTime() - d1.getTime();
return ((float)diff/(1000*60*60*24))/365;
}
String getName(){
return name;
}
}

class Student extends Human{
private String rollNo;
private String department;
private String dateOfGraduation;
private int rank;
Student(String name,String DOB,String fatherName,String rollNo,String department,String dateOfGraduation,int rank){
super(name,DOB,fatherName);
this.rollNo=rollNo;
this.department=department;
this.dateOfGraduation=dateOfGraduation;
this.rank=rank;
}
float ageOfScholar(){
return ageOnDate();
}
}

class Stuff extends Human{
private String dateOfJoin;
private String designation;
private int salary;
Stuff(String name,String DOB,String fatherName,String dateOfJoin,String designation,int salary){
super(name,DOB,fatherName);
this.dateOfJoin=dateOfJoin;
this.designation=designation;
this.salary=salary;
}
float ageOfSuperanuation(){
return ageOnDate();
}
}

class Faculty extends Human{
private String dateOfJoin;
private String designation;
private int salary;
private String qualification;
private String researchGuide;
private String dateOfPromotion;
Faculty(String name,String DOB,String fatherName,String dateOfJoin,String designation,int salary,String qualification,String researchGuide,String dateOfPromotion){
super(name,DOB,fatherName);
this.dateOfJoin=dateOfJoin;
this.designation=designation;
this.salary=salary;
this.qualification=qualification;
this.researchGuide=researchGuide;
this.dateOfPromotion=dateOfPromotion;
}
float ageOfScholar(){
return ageOnDate();
}
}

class Assn2_6{
String name;
float age;
public String toString(){
return "name:: "+name+"  age:: "+age+"\n";
}
Assn2_6(Human h){
this.name = h.getName();
this.age = h.ageOnDate();
}
	public static void main(String arg[]){
		Student s1 =new Student("Amal","22 jan 1988","Aloi","10dA26","dept1","15 sep 2009",333);
		Student s2 =new Student("Ajoy","2 sep 1984","Bijon","10dB71","dept2","2 sep 2005",423);
		Stuff st1 =new Stuff("Chokse","14 jul 1968","Abasti","clerk","12 sep 1990",15000);
		Stuff st2 =new Stuff("Jyo","20 jan 1975","Askhim","accountant","4 mar 1999",23000);
		Faculty f1 =new Faculty("Raj","20 jan 1978","Rabi","15 dec 2000","asst. prof",60000,"Phd. mathematics","Soumadip Biswas","11 nov 2009");
		Faculty f2 =new Faculty("Vodafone","17 aug 1969","Airtel","11 feb 2003","asst. prof",50000,"Phd. physics","Soumadip Biswas","12 jan 2009");

	Vector v = new Vector(7);
v.add(new Assn2_6(s1));
v.add(new Assn2_6(s2));
v.add(new Assn2_6(st1));
v.add(new Assn2_6(st2));
v.add(new Assn2_6(f1));
v.add(new Assn2_6(f2));
for(int i=0;i<6;i++){
System.out.println(v.elementAt(i));
}
}
}
