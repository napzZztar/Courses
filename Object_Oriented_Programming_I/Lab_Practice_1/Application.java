class Application{
	Student std = new Student();
	
	void setStudentInfo(String name,  String id,  String add,  String dateOfBirth,  String bloodGroup,  String admDate,  float cgpa,  int currSem){
		std.setPersonalInfo(name,  id,  add,  dateOfBirth,  bloodGroup);
		std.setAcademicInfo(admDate,  cgpa,  currSem);
	}
	
	void showStudentInfo(){
		std.showStudentInfo();
	}
}