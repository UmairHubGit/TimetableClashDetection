#include <iostream>
#include<fstream>
#include<conio.h>
using namespace std;

class Helper	//Contains all the relevant string functions
{
public:
	static int StringLength(char* str)
	{
		int count = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	static bool StringCompare(char* str, char* str1)
	{
		if (str1 != 0 && str != 0)
		{
			if (StringLength(str) == StringLength(str1))
			{
				int count = 0;

				for (int i = 0; str[i] != '\0'; i++)
				{
					if (str[i] == str1[i] || str[i] + 32 == str1[i] || str[i] - 32 == str1[i])// checking for both lower case and upper case characters
					{
						count++;
					}
				}
				if (count == StringLength(str1))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			return false;
		}
	}

	static void GetStringFromBuffer(char* source, char* str)
	{
		if (str != 0)
		{
			delete str;
		}
		int length = StringLength(source);

		str = new char[length + 1];
		str[length] = '\0';

		for (int i = 0; i < length; i++)
		{
			str[i] = source[i];
		}
	}

	static char* StringTokens(char* str)
	{
		int totalcount = 0;
		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == ',')
				totalcount++;
		//totalcount++;
		char* Tokens = new char[totalcount + 1];
		Tokens[totalcount] = '\0';
		int k = 0;
		int wordlength = 0;
		int i = 0, j = 0;
		for (int i = 0; i < totalcount; i++)
		{
			if (str[j] != ',')
				wordlength++;
			int l = 0;
			for (k, l; str[k] != ',' && str[k] != '\0'; l++, k++)
			{
				Tokens[i] = str[k];
				if (str[k + 1] == ',' || str[k + 1] == '\0')
					Tokens[i + 1] = '\0';
			}
			k++;
		}
		return Tokens;
	}

	static bool Substring(char* ptr, char* c)	//find a substring within a string
	{
		int count = 0;
		for (int j = 0; ptr[j] != 0; j++)
		{
			char* arr = ptr;
			for (int i = 0; i < strlen(arr); i++)
			{
				if (arr[i] == c[0] || arr[i] - 32 == c[0] || arr[i] + 32 == c[0])
				{
					int index = i + 1; bool found = true;
					for (int k = 1; k < strlen(c); k++)
					{
						if (arr[index] == c[k] || arr[index] - 32 == c[k] || arr[index] + 32 == c[k])
						{
							index++;
						}
						else
						{
							found = false;
							break;
						}
					}
					if (found)
					{
						return true;

					}

				}
			}

		}
		return false;
	}
};

template<class T>
struct node
{
	node<T>* next;
	node<T>* prev;
	T val;
};

struct classlist
{
	int count;
	char names[60][15]; //60 students in class, first name only.
	char rollNo[60][10];
};

struct slot
{
	char Timings[9][12];
	char Day[5][10];
	char Classroom[27][20];
	char CourseName[27][9][45];
	char Section[27][9][15];
	classlist* list;
};

//struct Course
//{
//	char Course_Name[10][45];
//	char Course_Sect[10][15];
//	classlist* list = new classlist;
//};

struct Student	//for storing a student's registered courses
{
	int course_count;
	char name[15];
	char rollno[10];
	char course[10][45];
	char coursesection[10][15];
};


//class LLADT1
//{
//	node<Course>* first;
//public:
//	LLADT1()
//	{
//		first = 0;
//	}
//
//	void Insert(Course value)
//	{
//		node<Course>* temp = new node<Course>;
//		temp->val = value;
//
//		temp->next = 0;
//
//		if (first == 0)
//		{
//			first = temp;
//		}
//		else
//		{
//			node<Course>* curr = first;
//			while (curr->next != 0)
//			{
//				curr = curr->next;
//			}
//			curr->next = temp;
//		}
//
//	}
//	
//	bool Search(char* ptr)
//	{
//		node<Course>* curr = first;
//		int i = 0;
//		bool found = false;
//		while (curr != 0)
//		{
//			if (Helper::StringCompare(ptr, curr->val.list->rollNo[i]) == true)
//			{
//				found = true;
//				break;
//			}
//			curr = curr->next;
//		}
//		return found;
//	}
//
//	void Print()
//	{
//		node<Course>* curr = first;
//		int k = 0;
//		while (curr != 0)
//		{
//			while (curr->val.list->rollNo[k] != 0)
//			{
//				cout << curr->val.list->rollNo[k];
//				k++;
//			}
//			for (int i = 0; i < 10; i++)
//			{
//				for (int j = 0; curr->val.Course_Name[i][j] != 0; j++)
//				{
//					cout << curr->val.Course_Name[i][j];
//				}
//				cout << endl;
//			}
//			curr = curr->next;
//		}
//	}
//	~LLADT1()
//	{
//		node<Course>* curr = first;
//		while (curr != 0)
//		{
//			delete curr;
//			curr = curr->next;
//		}
//		first = 0;
//	}
//
//};

class DLLADT		//contains a student's registered courses
{
	node<Student>* first;
public:
	DLLADT()
	{
		first = 0;
	}

	void Insert(Student value)
	{
		node<Student>* temp = new node<Student>;
		temp->val = value;

		temp->next = 0;
		temp->prev = 0;

		if (first == 0)
		{
			first = temp;
		}
		else
		{
			node<Student>* curr = first;
			while (curr ->next!= 0)
			{
				curr = curr->next;
			}
			curr->next = temp;
			temp->prev = curr;
		}

	}

	void Remove(char* ptr)
	{
		node<Student>* curr = first;
		bool found = false;
		while (curr != 0)
		{
			if (Helper::StringCompare(ptr, curr->val.rollno) == true)
			{
				break;
			}
			curr = curr->next;
		}
		if (curr != 0)
		{
			curr = curr->next;
		}
		while (curr != 0)
		{
			if (Helper::StringCompare(ptr, curr->val.rollno) == true)
			{
				found = true;
				break;
			}
			found = false;
			curr = curr->next;
		}
		if (found == false)
			return;
		if (found == true&&curr->next!=0)
		{
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			delete curr;
		}
	}

	node<Student>* Search(char* ptr)
	{
		node<Student>* prevcurr = 0;
		node<Student>* curr = first;
		bool found = false;
		while (curr != 0)
		{
			if (Helper::StringCompare(ptr, curr->val.rollno) == true)
			{
				found = true;
				break;
			}
			prevcurr = curr;
			curr = curr->next;
		}
		if (found == true)
			return curr;
	}

	void SearchandPrint(char* ptr)
	{
		node<Student>* prevcurr = 0;
		node<Student>* curr = first;
		int count = 0;
		bool found = false;
		while (curr != 0)
		{
			if (Helper::StringCompare(ptr, curr->val.rollno) == true)
			{
				found = true;
				break;
			}
			prevcurr = curr;
			curr = curr->next;
			count++;
		}
		if (found == true)
		{
			for (int j = 0; j <= curr->val.course_count; j++)
			{
				for (int k = 0; curr->val.course[j][k] != 0; k++)
				{
					cout << curr->val.course[j][k];
				}
				cout << " ";
				for (int k = 0; curr->val.coursesection[j][k] != 0; k++)
				{
					cout << curr->val.coursesection[j][k];
				}
				cout << endl;
			}
			curr = curr->next;
		}
		else
			cout << "Student not found";
	}

	void Print()
	{
		node<Student>* curr = first;
		while (curr != 0)
		{
			for (int i = 0; curr->val.rollno[i] != 0; i++)
				cout << curr->val.rollno[i];
			cout << " ";
			for (int i = 0; curr->val.name[i] != 0; i++)
				cout << curr->val.name[i];
			cout << " ";
			for (int j = 0; j < curr->val.course_count; j++)
			{
				for (int k = 0; curr->val.course[j][k] != 0; k++)
				{
					cout << curr->val.course[j][k];
				}
				cout << " ";
				for (int k = 0; curr->val.coursesection[j][k] != 0; k++)
				{
					cout << curr->val.coursesection[j][k];
				}
				cout << endl;
			}
			curr = curr->next;
		}
	}

	int GetCourseCount(char* ptr)
	{
		node<Student>* curr = Search(ptr);
		return curr->val.course_count;
	}

	void ReturnCourses(char arr[10][45], char* ptr, char sec[10][15])
	{
		node<Student>* curr = Search(ptr);
			int k = 0;
			for (int j = 0; j <= curr->val.course_count; j++)
			{
				for (k = 0; curr->val.course[j][k] != 0; k++)
				{
					arr[j][k] = curr->val.course[j][k];
				}
				arr[j][k] = 0;
				for (k = 0; curr->val.coursesection[j][k] != 0; k++)
				{
					sec[j][k] = curr->val.coursesection[j][k];
				}
				sec[j][k] = 0;
				k = 0;
			}
	}

	void FindClashinTimetable(slot data[])
	{
		ofstream fout("clash.txt");
		node<Student>* curr = first;
		int index = 0;
		bool found = false;
		int arr[3] = {0};
		char lab[] = "Lab";
		char eng[] = "English";
		while (curr != 0)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 27; j++)
				{
					for (int k = 0; k < 9; k++)
					{
						if (Helper::StringCompare(data[i].CourseName[j][k], curr->val.course[index]) == true&&Helper::Substring(data[i].Section[j][k],curr->val.coursesection[index])==true)
						{
							found = true;
							arr[0] = i, arr[1] = j, arr[2] = k;
							int ind = index;
							if (found == true)
							{
								found = false;
								index = 0;
								j = 0;
								while (index < 10)
								{
									if (index == ind)
										index++;
									while (j < 27)
									{
										if (Helper::StringCompare(data[i].CourseName[j][k], curr->val.course[index]) == true&&Helper::Substring(data[i].Section[j][k],curr->val.coursesection[index])==true)
										{
											found = true;
											fout << curr->val.rollno << " " << curr->val.name << " " << curr->val.course[ind] <<" "<< curr->val.coursesection[ind] <<" "<< curr->val.course[index] <<" "<< curr->val.coursesection[index] << " on " << data[i].Day[0] << " " << data[i].Timings[k] << endl;

											break;
										}
										else
											j++;
									}
									if (found == true)
										break;
									index++;
									j = 0;
								}
							}
							index = ind + 1;
							break;
						}
					}
					if (found == true)
						break;
				}
				if (found == true)
					break;
			}

			found = false;
			curr = curr->next;
		}
	}
	~DLLADT()
	{
		while (first)
		{
			node<Student>* curr = first;
			first = first->next;
			delete curr;
		}
	}

};

class LLADT3		//contains the timetable
{
	node<slot>* first;
public:
	LLADT3()
	{
		first = 0;
	}

	void Insert(slot value)
	{
		node<slot>* temp = new node<slot>;
		temp->val = value;

		temp->next = 0;

		if (first == 0)
		{
			first = temp;
		}
		else
		{
			node<slot>* curr = first;
			while (curr->next != 0)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}

	}

	void Print(char* ptr, slot value,char* ptr2)
	{
		node<slot>* curr = first;
		bool found = false;
		int count = 0;
		char lab[] = "Lab";
		char eng[] = "English";
		int k = 0, l = 0;
		int c = 0;
		while (curr != 0)
		{
			for (int i = 0; i < 27; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (Helper::Substring(curr->val.CourseName[i][j],ptr) == true && Helper::Substring(curr->val.Section[i][j], ptr2) == true)
					{
						k = i, l = j;
						found = true;
						if (Helper::Substring(curr->val.CourseName[k][l], lab) == true && Helper::Substring(ptr, lab) == false)
						{
							found = false;
						}
						break;
					}
					
				}
				if (found == true)
					break;

			}
			
			if (found == true)
			{		
				if (Helper::Substring(curr->val.CourseName[k][l], lab) == true && Helper::Substring(curr->val.Classroom[k], eng) == false)
				{
					if (Helper::Substring(curr->val.Classroom[k], lab) == true&&Helper::Substring(curr->val.CourseName[k][l],ptr)==true)
					{
						for (int g = 0; g < l; g++)
							count++;
						cout << curr->val.Day[0] << " - ";
						cout << curr->val.Timings[count * 2];
						cout << " : ";
						cout << curr->val.Timings[count * 2 + 2];
					}
					else
					{
						cout << curr->val.Day[0] << " - ";
						cout << curr->val.Timings[l];
						cout << " : ";
						cout << curr->val.Timings[l + 2];
					}
				}
				else
				{
					cout << curr->val.Day[0] << " - ";
					cout << curr->val.Timings[l];
					cout << " : ";
					cout << curr->val.Timings[l + 1];
				}
				cout << " , ";
				cout << curr->val.Classroom[k] << " ";
				found = false;
				
			}
			curr = curr->next;

		}
	}
	~LLADT3()
	{
		while (first)
		{
			node<slot>* curr = first;
			first = first->next;
			delete curr;
		}
	}

};

class TTADT
{
	LLADT3 TTList;
	/*LLADT1 Courselist;*/
	DLLADT StudentData;
	slot data[5];
	//Course courses;
	Student Studata;

public:
	void load(char filename[])
	{
		ifstream fin(filename);

		char a;
		int count = 1;
		char arr[9][12] = { "8:00 a.m.", "9:30 a.m.", "11:00 a.m.", "12:30 p.m.", "2:00 p.m.", "3:30 p.m.", "5:00 p.m.", "6:30 p.m.", "8:00 p.m." };

		char days[5][10] = { "Monday","Tuesday","Wednesday","Thursday","Friday" };

		char room[27][20] = { "CS-1","CS-2","CS-3","CS-4","CS-5","CS-6","CS-7","CS-8","CS-9","CS-10","CS-11","CS-15","CS-16",
			"Seminar Hall","CE-2","CE-3","English Lab-I","English Lab-II","English Lab-III","Lab(CS-8)","Lab(CS-1)","Lab(CS-4)","Lab(CS-6)","Lab(CS-9)",
			"Lab(CS-10)","Physics Lab","Micro Lab" };

		char no[] = "No Class";
		char se[] = "NO";

		char buffer[15100];
		int i = 0;
		int z = 0;
		if (fin.is_open())
			while (!fin.eof())
			{
				a = fin.get();
				if (a == ',' && count == 0)
				{
					;

				}
				else
				{
					buffer[i] = a;
					i++;
					z = i;
					if (a == ',')
					{
						count = 0;
					}
					else
					{
						count = 1;
					}
				}
			}
		int k = 0;
		int l = 0;
		int day_count = 0;
		int d = 0;
		int g = 0;
		int count1 = 0;
		int count2 = 0;
		int count0 = 0;
		int b = 0;
		int c = 0;
		int m = 0;
		int count3 = 0;
		int count4 = 0;
		int count5 = 0;
		int f = 0;
		for (int i = 0; buffer[i] != 0; i++)
		{

			if (buffer[i] == arr[k][l] && buffer[i + 1] == arr[k][l + 1])
			{
				int l = 0;
				int v = 0;
				int h = i;
				for (int s = 0; s < strlen(arr[k]); s++)
				{
					if (buffer[h] == arr[k][s])
						v++;
					h++;
				}
				if (v == strlen(arr[k]))
				{
					int c1 = 0, c2 = 0;
					for (int j = i; buffer[j] != ','; j++)
					{
						data[d].Timings[f][l] = buffer[j];
						l++;
					}
					data[d].Timings[f][l] = '\0';
					for (int r = 0; r < 5; r++)
					{
						for (c1 = 0; c1 < 9; c1++)
						{
							for (c2 = 0; data[r].Timings[c1][c2] != 0; c2++)
								data[r].Timings[c1][c2] = data[d].Timings[c1][c2];
						}
					}
					k++;
					f++;

				}

			}
			if (k == 9)
			{
				if (d > 0)
				{
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; data[d - 1].Timings[i][j] != 0; j++)
							data[d].Timings[i][j] = data[d - 1].Timings[i][j];
					}
				}
				int l = 0;

				int h = 0;
				int v = 0;

				d = d % 5;
				if (buffer[i] == days[day_count][l] && buffer[i + 1] == days[day_count][l + 1])
				{
					h = i;
					for (int k = 0; k < strlen(days[day_count]); k++)
					{
						if (buffer[h] == days[day_count][k])
							v++;

						h++;
					}

					if (v == strlen(days[day_count]))
					{
						//h = 0;
						for (int i = 0; days[day_count][i] != 0; i++)
						{
							//data[d].Day[day_count][i] = days[day_count][i];
							data[d].Day[0][i] = days[day_count][i];
							l++;
						}
						data[d].Day[0][l] = '\0';
						day_count++;

					}

				}
			}
			if (buffer[i] == room[count1][b] && buffer[i + 1] == room[count1][b + 1])
			{
				int h = i;
				int v = 0;
				for (int j = 0; j < strlen(room[count1]); j++)
				{
					if (buffer[h] == room[count1][j])
						v++;
					h++;
				}
				int a = 0;
				h = i;
				if (v == strlen(room[count1]))
				{
					for (int j = 0; room[count1][j] != 0; j++)
					{
						data[d].Classroom[count2][j] = buffer[h];
						h++;
						a++;
					}
					data[d].Classroom[count2][a] = '\0';

					for (c = 0; c < strlen(room[count1]); c++)
					{
						i++;
					}
					i++;
					for (int k = i; buffer[k] != '\n' && (k + 1) < z; k++)
					{
						if (buffer[k] == ',')
						{
							m = 0;
						}
						else if (buffer[k] == '(')
						{
							k++;
							c = 0;
							while (buffer[k] != ')')
							{
								if (buffer[k] >= 97 && buffer[k] <= 122 || buffer[k + 1] >= 97 && buffer[k + 1] <= 122)
								{
									break;
								}
								else
								{
									data[d].Section[count4][count3][c] = buffer[k];
									k++;
									c++;
								}
							}
							data[d].Section[count4][count3][c] = '\0';
							count3++;
							count5++;
						}
						else
						{
							if ((k + 1) < z)
							{
								if (buffer[k + 1] == '(')
								{
									if (buffer[k + 2] >= 97 && buffer[k + 2] <= 122 || buffer[k + 3] >= 97 && buffer[k + 3] <= 122)
									{
										while (buffer[k - 1] != ')')
										{
											data[d].CourseName[count4][count5][m] = buffer[k];
											k++;
											m++;
										}
									}
									data[d].CourseName[count4][count5][m] = '\0';
									m = 0;
								}
								else
								{
									data[d].CourseName[count4][count5][m] = buffer[k];
									m++;
								}
							}
						}
					}
					data[d].CourseName[count4][count5][m] = '\0';
					m = 0;
					data[d].Section[count4][count3][c] = '\0';
					int count7 = count4, count8 = count5;
					while (count8 < 9)
					{
						data[d].CourseName[count7][count8][m] = no[m];
						data[d].Section[count7][count8][m] = se[m];
						if (m == strlen(no))
						{
							count8++;
							m = 0;
						}
						else
							m++;
					}
					count5 = 0;
					count3 = 0;

					count4++;
					count2++;
					//m = 0;
					count1++;
				}


			}
			if (count2 == 27)
			{
				TTList.Insert(data[d]);
				d++;
				m = 0;
				count2 = 0;
				count1 = 0;
				count3 = 0;
				count4 = 0;
				count5 = 0;
			}

		}
	}

	void loadStudentInfo(char filename[])
	{
		ifstream fin(filename);
		classlist* data1 = new classlist;
		char buffer[297000];
		int n = 0;
		int z = 0;
		int count = 1;
		char a;
		bool search = true;
		if (fin.is_open())
			while (!fin.eof())
			{
				a = fin.get();
				if (a == ',' && count == 0)
				{
					;
				}
				else
				{
					buffer[n] = a;
					n++;
					z = n;
					if (a == ',')
					{
						count = 0;
					}
					else
					{
						count = 1;
					}
				}
			}
		int b = 0;
		for (int i = 0; i < 4; i++)
		{
			while (buffer[b] != ',')
			{
				if (buffer[b] == '\n')
					break;
				b++;
			}
			b++;
		}
		int j = 0;
		int k = 0;
		int count1 = b;
		char temp_roll[10];
		int count2 = 0;
		int i = 0;
		for (int x = b; x < z; x++)
		{
			for (i = b; buffer[i] != '\n'; i++)
			{
				while (buffer[i] != ',')
				{
					data1->rollNo[j][k] = buffer[i];
					temp_roll[k] = buffer[i];
					//courses.list->rollNo[j][k] = buffer[i];
					Studata.rollno[k] = buffer[i];
					k++;
					i++;
				}
				i++;
				data1->rollNo[j][k] = '\0';
				temp_roll[k] = '\0';
				Studata.rollno[k] = 0;
				//courses.list->rollNo[j][k] = 0;
				k = 0;

				while (buffer[i] != ',')
				{
					data1->names[j][k] = buffer[i];
					//courses.list->names[j][k] = buffer[i];
					Studata.name[k] = buffer[i];
					k++;
					i++;
				}
				i++;
				data1->names[j][k] = 0;
				//courses.list->names[j][k] = 0;
				Studata.name[k] = 0;
				k = 0;
				while (buffer[i] != ',')
				{
					//courses.Course_Name[j][k] = buffer[i];
					Studata.course[j][k] = buffer[i];
					i++;
					k++;
				}
				i++;
				//courses.Course_Name[j][k] = 0;
				Studata.course[j][k] = 0;
				k = 0;

				while (buffer[i] != '\n' && (i + 1) < z)
				{
					//courses.Course_Sect[j][k] = buffer[i];
					Studata.coursesection[j][k] = buffer[i];
					i++;
					k++;

				}
				//courses.Course_Sect[j][k] = 0;
				Studata.coursesection[j][k] = 0;
				k = 0;
				b = i;
				count2 = i;
				j++;
				break;
			}
			int l = 0;
			int h = 1;
			for (i = b; i < z; i++)
			{

				while (buffer[i] != '\n' && (i + 1) < z)
				{
					i++;
				}
				i++;

				while (buffer[i] != ',' && (i + 1) < z)
				{
					data1->rollNo[j][l] = buffer[i];

					i++;
					l++;
				}
				data1->rollNo[j][l] = 0;
				//courses.list->rollNo[j][l] = 0;
				l = 0;
				if (temp_roll[k] == data1->rollNo[j][l] && temp_roll[k + 1] == data1->rollNo[j][k + 1])
				{
					if (Helper::StringCompare(temp_roll, data1->rollNo[j]) == true)
					{
						i++;
						while (buffer[i] != ',')
						{
							i++;
						}
						i++;
						while (buffer[i] != ',')
						{
							//courses.Course_Name[h][l] = buffer[i];
							Studata.course[h][l] = buffer[i];
							i++;
							l++;
						}
						i++;
						//courses.Course_Name[h][l] = 0;
						Studata.course[h][l] = 0;
						l = 0;
						while (buffer[i] != '\n' && (i + 1) < z)
						{
							//courses.Course_Sect[h][l] = buffer[i];
							Studata.coursesection[h][l] = buffer[i];
							i++;
							l++;
						}
						//courses.Course_Sect[h][l] = 0;
						Studata.coursesection[h][l] = 0;
						l = 0;
						data1->count++;
						Studata.course_count++;
						if (h >= 9)
							h = 1;
						else
							h++;
					}
					i++;

				}
				if (i == z)
				{
					while (h < 10)
					{
						//courses.Course_Name[h][l] = 0;
						//courses.Course_Sect[h][l] = 0;
						Studata.course[h][l] = 0;
						Studata.coursesection[h][l] = 0;
						h++;
					}
					break;
				}
				if (j < 60)
					j++;
				else
					j = 0;
			}
			if (i == z)
			{
				StudentData.Insert(Studata);
				Studata.course_count = 0;
				i = b + 1;
				b = i;
				j = 0;
			}
			x = b;
		}

		int f = 0;
		int e = 0;
		for (int i = count1; i < z; i++)
		{
			while (buffer[i] != ',')
			{
				Studata.rollno[f] = buffer[i];
				i++;
				f++;
			}
			i++;
			Studata.rollno[f] = 0;
			f = 0;
			while (e < 10)
			{
				StudentData.Remove(Studata.rollno);
				e++;
			}
			e = 0;

			while (buffer[i] != '\n' && (i + 1) < z)
			{
				i++;
			}
		}
	}

	void saveClashes()
	{
		int i = 0;
		StudentData.FindClashinTimetable(data);

	}

	void printStudentTimeTable(char rollno[])
	{
		int count = StudentData.GetCourseCount(rollno);
		char temp[10][45];
		char sec[10][15];
		StudentData.ReturnCourses(temp, rollno, sec);

		int k = 0;
		int j = 0;
		for (int i = 0; i <= count; i++)
		{
			cout << temp[i] << " " << "(" << sec[i] << "):" << endl;
			TTList.Print(temp[i], data[j], sec[i]);
			cout << endl << endl;

		}

	}

	void printStudentCourses(char rollno[])
	{
		StudentData.SearchandPrint(rollno);
	}

	void printCourse(char day[], char time[], char classroom[])
	{
		int count = 0;
		int i = 0;
		bool found = false;
		for (i = 0; i < 5; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				for (int k = 0; data[i].Day[j][k] != 0; k++)
				{
					if (data[i].Day[j][k] == day[k])
					{
						count++;
					}
					if (count == strlen(day))
					{
						found = true;
						break;
					}
				}
				if (found == true)
				{
					count = 0;
					break;
				}
			}
			if (found == true)
			{
				count = 0;
				break;
			}

		}
		if (found == true)
		{
			int j = 0;

			for (j = 0; data[i].Classroom[j] != 0; j++)
			{
				for (int l = 0; data[i].Classroom[j][l] != 0; l++)
				{
					if (data[i].Classroom[j][l] == classroom[l])
						count++;
					if (count == strlen(classroom))
					{
						found = true;
						break;
					}
					found = false;
				}
				count = 0;
				if (found == true)
				{
					break;
				}
			}


			if (found == true)
			{
				int l = 0;
				for (l = 0; data[i].Timings[l] != 0; l++)
				{
					for (int m = 0; data[i].Timings[l][m] != 0; m++)
					{
						if (data[i].Timings[l][m] == time[m])
						{
							count++;
						}
						if (count == strlen(time))
						{
							found = true;
							break;
						}
						found = false;
					}
					count = 0;
					if (found == true)
					{
						count = 0;
						break;
					}
				}
				if (found == true)
					cout << data[i].CourseName[j][l] << " " << data[i].Section[j][l] << endl;


			}
		}



	}

	void printCourseTimings(char coursename[], char section[])
	{
		int i = 0;
		int m = 0;
		int count = 0;
		bool found = false;
		char la[] = "Lab";
		char en[] = "English";
		for (i = 0; i < 5; i++)
		{
			for (int j = 0; j < 27; j++)
			{
				for (int k = 0; k < 9; k++)
				{
					if (Helper::Substring(data[i].CourseName[j][k], coursename) == true && Helper::Substring(data[i].Section[j][k], section) == true)
					{
						if (Helper::Substring(coursename, la) == true && Helper::Substring(data[i].Classroom[j], en) == false)
						{
							for (int l = 0; l < k; l++)
							{
								if (Helper::Substring(data[i].CourseName[j][l], la) == true)
									count++;
							}
							m = k;
							cout << data[i].Day[0] << " ";
							cout << data[i].Timings[m*2];
							cout << endl;
						}
						else
						{
							cout << data[i].Day[0] << " ";
							cout << data[i].Timings[k];
							cout << endl;
						}

						m = 0;
						count = 0;
					}

				}
				count = 0;
			}

		}
	}

	~TTADT()
	{

	}
};

int main()
{
	TTADT TimeTable;
	char file[] = "CS Time Table  List of Courses (Spring 2019) v 1.9 - CS Time Table Spring 2019.csv";
	char file2[] = "Registration data.csv";
	char day[] = "Monday";
	char time[] = "8:00 a.m.";
	char classroom[] = "CS-1";
	char course[] = "Comm & Presentation Skills Lab";

	char section[] = "CS-A1";
	char roll[] = "1";

	TimeTable.load(file);
	TimeTable.loadStudentInfo(file2);
	TimeTable.printCourse(day, time, classroom);
	TimeTable.printCourseTimings(course, section);
	TimeTable.printStudentCourses(roll);
	TimeTable.printStudentTimeTable(roll);
	TimeTable.saveClashes();
}

