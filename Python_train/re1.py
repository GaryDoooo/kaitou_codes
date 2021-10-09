import re
input = """
All Students
Division of Specialized Instruction and Student Support: SpecialEducation@schools.nyc.gov
Special Education Hotline: 718-935-2007 or 311
Related Services: RelatedServices@schools.nyc.gov
Impartial Hearing Office: IHOInquiry@schools.nyc.gov
Preschool-Aged Students
Committee on Preschool Special Education (CPSE):
Pre-K For All and Elementary School Enrollment: ESEnrollment@schools.nyc.gov
Pre-K For All Programs: EarlyChildhood@schools.nyc.gov or 212-374-0351
Pre-K For All 504 Accommodations: EarlyChildhoodPolicy@schools.nyc.gov
Students Moving to Kindergarten
Turning5@schools.nyc.gov
Students in DOE District Schools Grades K-12
Your school: Use the Find a School tool to find contact information for your school
Community and High School Superintendents
Students in District 75 Programs
Your school: Use the Find a School tool to find contact information for your school
District 75 Superintendent's Office 212-802-1500 or D75info@schools.nyc.gov
Students Attending or Interested in Attending Specialized Programs
General: SpecializedPrograms@schools.nyc.gov
Academic, Career, and Essential Skills (ACES) Program: ACESprograms@schools.nyc.gov
Autism Spectrum Disorder (ASD) Programs (NEST and Horizon): ASDprograms@schools.nyc.gov
Bilingual Special Education (BSE) Program: BSEPrograms@schools.nyc.gov
Students Not Attending or in Non-Public, Private, Parochial or Charter School
Committee on Special Education (CSE)
"""
phone_num = re.compile(r'\d{3}-\d{3}-\d{4}')
results = re.findall(phone_num, input)
print(results)
# email = re.compile(r'\b[a-zA-Z]{1}[\w|\.]*@[\w|\.]+\.[a-zA-Z]{2,3}$')
results = re.findall(r'\b[a-zA-Z]{1}[a-zA-Z0-9]*@[\w|\.]+\.[a-zA-Z]{2,3}\b',
                     input)
print(results)