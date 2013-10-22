Class Student{
	//all the numbers
	Float cgpa;
	int currentSemester;
	
	//all the strings 
	String name;
	String id;
	String address;
	String dateOfBirth;
	String admissionDate;
	String bloodGroup;
	
	//All the set methods.
	void setPersonalInfo(String name,  String id,  String add,  String dateOfBirth,  String bloodGroup){
		this.name = name;
		this.id = id;
		this.address = add;
		this.dateOfBirth = dateOfBirth;
		this.bloodGroup = bloodGroup;
	}
	
	void setAcademicInfo(String admDate,  float cgpa,  int currSem){
		this.admissionDate = admDate;
		this.cgpa = cgpa;
		this.currentSemester = currSem;
	}
	
	//All the show methods.
	void showPersonalInfo(){
		System.out.println("Name             : "+this.name);
		System.out.println("ID               : "+this.id);
		System.out.println("Address          : "+this.address);
		System.out.println("Date of Birth    : "+this.dateOfBirth);
		System.out.println("Blood Group      : "+this.bloodGroup);
		
	}
	
	vodi showAcademicInfo(){
		System.out.println("Admission Date   : "+this.admissionDate);
		System.out.println("CGPA             : "+this.cgpa);
		System.out.println("Current Semester : "+this.currentSemester);
	}
	
	vodi showStudentInfo(){
		this.showPersonalInfo();
		this.showAcademicInfo
	}

	
	public static void main(String args[]){
		//create an objet and object referene for the class Student
		Student std1 = new Student();
		
		//set the information of the student object using the set methods
		std1.setAcademicInfo("Ahmed Ashik",  "12-20978-1",  "Uttara,  Dhaka",  "3-03-1994",  "O+ve");
		
		//Print the information of the student object using show methods
		std1.showPersonalInfo();
	}
}