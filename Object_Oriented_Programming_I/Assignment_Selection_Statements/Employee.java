class Employee{
   //@ Attributes
   private int empId;//{{{
   private String name;
   private String dept;
   private String designation;
   private String joinDate;
   private String dateOfBirth;
   private String contactNo;
   private String email;
   private double basicSalary;
   private double commission;
   private double totalSalary;
   private double totalSalesAmount;
   private double medicalAllowance;
   private double houseRent;
//}}}

   //@ constructors.
   public Employee(String name, int empId, String dept, String designation, double totalSalesAmount){//{{{
     this.name = name;
     this.empId = empId;
     this.dept = dept;
     this.designation = designation;
     this.totalSalesAmount = totalSalesAmount;

     if(this.dept=="Sales"){

     }

   }//}}}

   //@get methods
   void setname(String name){//{{{
      this.name = name;
   }
   void setdept(String dept){
      this.dept = dept;
   }
   void setdesignation(String designation){
      this.designation = designation;
   }
   void setjoinDate(String joinDate){
      this.joinDate = joinDate;
   }
   void setdateOfBirth(String dateOfBirth){
      this.dateOfBirth = dateOfBirth;
   }
   void setcontactNo(String contactNo){
      this.contactNo = contactNo;
   }
   void setemail(String email){
      this.email = email;
   }
   void setbasicSalary(double basicSalary){
      this.basicSalary = basicSalary;
   }
   void setcommission(double commission){this.commission = commission;
   }
   void settotalSalary(double totalSalary){
      this.totalSalary = totalSalary;
   }
   void settotalSalesAmount(double totalSalesAmount){
      this.totalSalesAmount = totalSalesAmount;
   }
   void setmedicalAllowance(double medicalAllowance){
      this.medicalAllowance = medicalAllowance;
   }
   void sethouseRent(double houseRent){
      this.houseRent = houseRent;
   }


   //}}}

   //@ Show methods
//{{{
   public void showEmpInfo(){
      System.out.println("------------------------------");
      System.out.println("Employee Id   : "+this.name);
      System.out.println("Employee Name : "+this.empId);
      System.out.println("Departments   : "+this.dept);
      System.out.println("Designation   : "+this.designation);
      System.out.println(" : "+this.joinDate);
      System.out.println(" : "+this.dateOfBirth);
      System.out.println(" : "+this.contactNo);
      System.out.println(" : "+this.email);
      System.out.println("Basic         : "+this.basicSalary);
      System.out.println("House Rent    : "+this.houseRent);
      System.out.println("Medical       : "+this.medicalAllowance);
      System.out.println("              : "+this.commission);
      System.out.println("Commission    : "+this.totalSalesAmount);
      System.out.println("------------------------------");
      System.out.println("Total Salary  : "+this.totalSalary);

   }//}}}

   public static void main(String args[]){
      Employee emp1 = new Employee("Ashik Ahmed", 1220, "Sales", "Manager", 1200);
      emp1.showEmpInfo();

   }
}
