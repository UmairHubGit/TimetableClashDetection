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
struct node		//Doubly Linked List
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

struct slot		//For storing timetable
{
	char Timings[9][12];
	char Day[5][10];
	char Classroom[27][20];
	char CourseName[27][9][45];
	char Section[27][9][15];
	classlist* list;
};

struct Student	//For storing a student's registered courses
{
	int course_count;
	char name[15];
	char rollno[10];
	char course[10][45];
	char coursesection[10][15];
};


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
			while (curr->next != 0)
			{
				curr = curr->next;
			}
			curr->next = temp;
			temp->prev = curr;
		}

	}

	void Remove(char* ptr)		//Checks the entire registration data file, and removes any repeated roll numbers
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
		if (found == true && curr->next != 0)
		{
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			delete curr;
		}
	}

	node<Student>* Search(char* ptr)	//Searches for a specific roll number
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

	void SearchandPrint(char* ptr)	//Prints all the courses of one student
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
		else
			cout << "Student not found";
	}

	int GetCourseCount(char* ptr)		//Returns the total number of courses for a student
	{
		node<Student>* curr = Search(ptr);
		return curr->val.course_count;
	}

	void ReturnCourses(char arr[10][45], char* ptr, char sec[10][15])		//Returns the courses for a specific student
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

	void FindClashinTimetable(slot data[])		//Finds all the clashes in the timtable and stores them in file
	{
		ofstream fout("clash.txt");
		node<Student>* curr = first;
		int index = 0;
		bool found = false;
		int arr[3] = { 0 };
		char lab[] = "Lab";
		char eng[] = "English";
		int clashcount = 0;
		while (curr != 0)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 27; j++)
				{
					for (int k = 0; k < 9; k++)
					{
						if (index < curr->val.course_count)
						{
							//If the coursename and the section matches
							if (Helper::StringCompare(data[i].CourseName[j][k], curr->val.course[index]) == true && Helper::Substring(data[i].Section[j][k], curr->val.coursesection[index]) == true)
							{
								//This will store the index number of the slot
								found = true;
								arr[0] = i, arr[1] = j, arr[2] = k;
								int ind = index;
								if (found == true)
								{
									found = false;
									index = 0;
									j = 0;

									//This loop will go to the corresponding slot and start matching the student's courses one by one
									while (index < 10)	//10, the maximum number of courses a student can register into
									{
										//This will skip the curr->val.course[index], as we do not need to search it again
										if (index == ind)
											index++;
										while (j < 27)
										{
											
											if (Helper::StringCompare(data[i].CourseName[j][k], curr->val.course[index]) == true && Helper::Substring(data[i].Section[j][k], curr->val.coursesection[index]) == true)
											{
												if (Helper::Substring(curr->val.course[index], curr->val.course[ind]) == true && Helper::Substring(curr->val.coursesection[index], curr->val.coursesection[ind]) == true)
												{
													found = false;
													break;
												}
												found = true;
												clashcount++;
												fout << curr->val.rollno << " " << curr->val.name << " " << curr->val.course[ind] << " " << curr->val.coursesection[ind] << " " << curr->val.course[index] << " " << curr->val.coursesection[index] << " on " << data[i].Day[0] << " " << data[i].Timings[k] << endl;
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
								i = 0;
								break;
							}
						}
					}
					if (found == true)
						break;
				}
				if (i == 4 && index < curr->val.course_count)
				{
					index++;
					i = 0;
				}
				if (found == true)
					break;
			}

			found = false;
			curr = curr->next;
			index = 0;
		}
		fout << "Total Clashes: " << clashcount;
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

class LLADT		//contains the timetable
{
	node<slot>* first;
public:
	LLADT()
	{
		first = 0;
	}

	void Insert(slot value) //Inserts all the courses in a day from the timetable
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

	void Print(char* ptr,  char* ptr2)		//Prints the Timings of all the courses of a student
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
					if (Helper::Substring(curr->val.CourseName[i][j], ptr) == true && Helper::Substring(curr->val.Section[i][j], ptr2) == true)
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
					if (Helper::Substring(curr->val.Classroom[k], lab) == true && Helper::Substring(curr->val.CourseName[k][l], ptr) == true)
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
				cout << curr->val.Classroom[k] << " " << "|| ";
				found = false;

			}
			curr = curr->next;

		}
	}

	~LLADT()
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
	LLADT TTList;
	DLLADT StudentData;
	slot data[5];
	Student Studata;

public:
	void load(char filename[])
	{
		ifstream fin(filename);

		char arr[9][12] = { "8:00 a.m.", "9:30 a.m.", "11:00 a.m.", "12:30 p.m.", "2:00 p.m.", "3:30 p.m.", "5:00 p.m.", "6:30 p.m.", "8:00 p.m." };

		char days[5][10] = { "Monday","Tuesday","Wednesday","Thursday","Friday" };

		char room[27][20] = { "CS-1","CS-2","CS-3","CS-4","CS-5","CS-6","CS-7","CS-8","CS-9","CS-10","CS-11","CS-15","CS-16",
			"Seminar Hall","CE-2","CE-3","English Lab-I","English Lab-II","English Lab-III","Lab(CS-8)","Lab(CS-1)","Lab(CS-4)","Lab(CS-6)","Lab(CS-9)",
			"Lab(CS-10)","Physics Lab","Micro Lab" };

		char no[] = "No Class";
		char se[] = "NO";

		char buffer[500];
		int i = 0;
		int k = 0;
		int l = 0;
		int day_count = 0;
		int d = 0;
		int count2 = 0;
		int b = 0;
		int c = 0;
		int m = 0;
		int count1 = 0;
		int count3 = 0;
		int count4 = 0;
		int count5 = 0;
		char lab[] = "Lab";
		char eng[] = "English";
		int f = 0;
		if (fin.is_open())
		{
			while (i < 4)
			{
				fin.getline(buffer, 500);
				i++;
			}
			i = 0;
			while (!fin.eof())
			{
				if (buffer[i] == '\0')
				{
					i = 0;
					fin.getline(buffer, 500);
				}
				while (buffer[i] == ',')
					i++;
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
						for (int j = i; buffer[j] != ',' && buffer[j] != '\0'; j++)
						{
							data[d].Timings[f][l] = buffer[j];
							l++;
						}
						data[d].Timings[f][l] = '\0';
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
							for (int i = 0; days[day_count][i] != 0; i++)
							{
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
						for (int k = i; buffer[k] != '\0'; k++)
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
								if (Helper::Substring(data[d].CourseName[count4][count5], lab) == true && Helper::Substring(data[d].Classroom[count4], eng) == false)
								{
									count5++;
									count3++;
									m = 0;
									for (int b = 0; b < strlen(no); b++)
									{
										data[d].CourseName[count4][count5][m] = no[b];
										m++;
									}
									data[d].CourseName[count4][count5][m] = 0;
									c = 0;
									for (int b = 0; b < strlen(se); b++)
									{
										data[d].Section[count4][count3][c] = se[b];
										c++;
									}
									data[d].Section[count4][count3][c] = 0;
									c = 0;
									m = 0;
								}
								count3++;
								count5++;
							}
							else
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
									if (data[d].CourseName[count4][count5][0] == '\"')
									{
										for (int i = 0; data[d].CourseName[count4][count5][i] != 0; i++)
											data[d].CourseName[count4][count5][i] = data[d].CourseName[count4][count5][i + 1];
									}
									m = 0;
								}
								else
								{
									data[d].CourseName[count4][count5][m] = buffer[k];
									m++;
								}

							}
						}
						data[d].CourseName[count4][count5][m] = '\0';

						m = 0;
						data[d].Section[count4][count3][c] = '\0';
						c = 0;
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

				i++;

			}
		}
	}

	void loadStudentInfo(char filename[])
	{
		ifstream fin(filename);
		classlist* data1 = new classlist;
		char buffer[100];
		int n = 0;
		int z = 0;
		int count = 1;
		char a;
		int count2 = 0;
		bool search = true;
		if (fin.is_open())
		{
			fin.getline(buffer, 100);
			while (!fin.eof())
			{
				fin.getline(buffer, 100);
				count2++;
				int i = 0;
				int b = 0;
				int j = 0;
				int k = 0;
				int count1 = b;
				char temp_roll[10];

				while (buffer[i] != ',')
				{
					data1->rollNo[j][k] = buffer[i];
					temp_roll[k] = buffer[i];
					Studata.rollno[k] = buffer[i];
					k++;
					i++;
				}
				i++;
				data1->rollNo[j][k] = '\0';
				temp_roll[k] = '\0';
				Studata.rollno[k] = 0;
				k = 0;

				while (buffer[i] != ',')
				{
					data1->names[j][k] = buffer[i];
					Studata.name[k] = buffer[i];
					k++;
					i++;
				}
				i++;
				data1->names[j][k] = 0;
				Studata.name[k] = 0;
				k = 0;
				while (buffer[i] != ',')
				{
					Studata.course[j][k] = buffer[i];
					i++;
					k++;
				}
				i++;
				Studata.course[j][k] = 0;
				k = 0;
				while (buffer[i] != '\0')
				{
					Studata.coursesection[j][k] = buffer[i];
					i++;
					k++;

				}
				Studata.coursesection[j][k] = 0;
				Studata.course_count = 1;
				k = 0;
				j++;
				int h = 1;
				int l = 0;
				while (!fin.eof())
				{
					i = 0;
					fin.getline(buffer, 100);
					while (buffer[i] != ',')
					{
						data1->rollNo[j][k] = buffer[i];
						k++;
						i++;
					}
					i++;
					data1->rollNo[j][k] = '\0';

					k = 0;

					if (Helper::StringCompare(temp_roll, data1->rollNo[j]) == true)
					{
						while (buffer[i] != ',')
						{
							i++;
						}
						i++;
						while (buffer[i] != ',')
						{
							Studata.course[h][l] = buffer[i];
							i++;
							l++;
						}
						i++;
						Studata.course[h][l] = 0;
						l = 0;
						while (buffer[i] != '\0')
						{
							Studata.coursesection[h][l] = buffer[i];
							i++;
							l++;
						}
						Studata.coursesection[h][l] = 0;
						l = 0;
						data1->count++;
						Studata.course_count++;
						if (h >= 9)
							h = 1;
						else
							h++;
						i++;
					}
					else
					{
						while (buffer[i] != '\0')
						{
							i++;
						}
						i++;
					}

					if (j < 60)
						j++;
					else
						j = 0;
				}

				while (h < 10)
				{
					Studata.course[h][l] = '\0';
					Studata.coursesection[h][l] = '\0';
					h++;
				}
				StudentData.Insert(Studata);
				StudentData.Remove(Studata.rollno);
				Studata.course_count = 0;
				j = 0;
				fin.close();
				fin.open(filename);
				fin.getline(buffer, 100);
				int v = 0;
				while (v < count2)
				{
					fin.getline(buffer, 100);
					v++;
				}


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
		for (int i = 0; i < count; i++)
		{
			cout << temp[i] << " " << "(" << sec[i] << "):" << endl;
			TTList.Print(temp[i],  sec[i]);
			cout << endl << endl;

		}

	}

	void printStudentCourses(char rollno[])
	{
		StudentData.SearchandPrint(rollno);
		cout << endl << endl;
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
					cout << data[i].CourseName[j][l] << " " << data[i].Section[j][l] << endl << endl;


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
							cout << data[i].Timings[m];
							cout << endl << endl;
						}
						else
						{
							cout << data[i].Day[0] << " ";
							cout << data[i].Timings[k];
							cout << endl << endl;
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
	char time[] = "3:30 p.m.";
	char classroom[] = "Lab(CS-10)";
	char course[] = "Programming Fundamentals Lab";

	char section[] = "CS-G1";
	char roll[] = "13";

	TimeTable.load(file);

	TimeTable.loadStudentInfo(file2);

	TimeTable.printCourse(day, time, classroom);

	TimeTable.printCourseTimings(course, section);

	TimeTable.printStudentCourses(roll);

	TimeTable.printStudentTimeTable(roll);

	TimeTable.saveClashes();
}