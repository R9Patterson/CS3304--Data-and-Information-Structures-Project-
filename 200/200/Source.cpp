
#include <iostream> 
#include <string>
#include <cstring>
#include <cstdlib>
#include <array>
#include <list>

using namespace std;

//class declaration
class courses
{
private:
	int courseNum;  //Stores the number of courses the user has
	double tests;
	double quizzes;
	double hw;
	string description;
	double classAve;

	//node structure   RE-NAME LATER!!
	struct ListNode
	{
		double value;			// stores the course's average
		string courseName;     // stores the course name
		struct ListNode *next; // points to the next node
	};
	ListNode *head;       // List head pointer
public:
	courses() //constructor
	{
		head = nullptr;
		tests = 0;
		quizzes = 0;
		hw = 0;
		classAve = 0;
	}

	void setCourseNum(int);
	void setTests(double);
	void setQuizzes(double);
	void setHw(double);
	void setDescription(string);
	void setClassAve(double);

	double getTests() const;
	double getQuizzes() const;
	double getHw() const;
	string getDescription() const;
	double getClassAve() const;
	int getCourseNum() const;
	//linkedlists
	void insertNode(double, string);   // insert node for linked list
	void displayList()const;   // display the nodes in the linked list
							   //promt for information gathering
	void displayPrompt();
	void displayPromptHW();
	void displayPromptQZ();


};

//methods to enter data into object
void courses::setCourseNum(int number)
{
	courseNum = number;
}
void courses::setQuizzes(double number)
{
	quizzes = number;
}
void courses::setHw(double number)
{
	hw = number;
}

void courses::setDescription(string x)   //may not need
{
	description = x;
}
void courses::setTests(double number)
{
	tests = number;
}
void courses::setClassAve(double num)
{
	classAve = num;
}
//methods to get all data from object
string courses::getDescription() const    // may not need
{
	return description;
}
double courses::getTests() const
{
	return tests;
}
double courses::getQuizzes() const
{
	return quizzes;
}
double courses::getHw() const
{
	return hw;
}
int courses::getCourseNum() const
{
	return courseNum;
}
double courses::getClassAve() const
{
	return classAve;
}
void courses::displayPromptQZ()
{
	int quizNum = 0;            // Stores the number of tests the student has
	float quizPercent = 0;     // Stores the percentage weight of users's tests
	double percentQuiz;      // calculated %
	int *quizArray = NULL; //Pointer for test array
	int quizScores = 0;     // stores the test scores

	cout << "How many quizzes do you have for course " << getDescription() << endl;
	cin >> quizNum;

	quizArray = new int[quizNum];  //dynamic space allocation for number of quizzes

	cout << "Enter the weighted percentage of your quizzes for course " << getDescription() << endl;  //storing quiz percentage
	cin >> quizPercent;

	//turns the entered percent value into an actuall percentage
	percentQuiz = (quizPercent / 100);

	//populates the scores from the user into a quiz array
	cout << "Enter in your quiz scores for course " << getDescription() << endl;
	for (int i = 0; i< quizNum; i++)
	{
		cout << "Enter score " << i + 1 << endl;
		cin >> quizScores;
		quizArray[i] = quizScores;
	}
	//displays the scores the user entered to the screen
	double temp = 0;
	for (int i = 0; i< quizNum; i++)
	{
		temp += quizArray[i];
		cout << "Score # " << i + 1 << " is " << quizArray[i] << endl;
	}
	temp = temp / quizNum;  //Calculates average
	temp = (temp * percentQuiz);   //converts average into percentage
	setQuizzes(temp);             // stores percentage in private quizzes variable

								  //deallocates memory space from dynamic array
	delete[]quizArray;
}
void courses::displayPromptHW()
{
	//string courseName= " ";    // string variable for course name
	int hwNum = 0;            // Stores the number of homework grades the student has
	float hwPercent = 0;     // Stores the percentage weight of users's homework
	double percentHW;      // calculated %
	int *homeworkArray = NULL; //Pointer for homework array
	int homeworkScores = 0;     // stores the homework scores

	cout << "How many home work grades do you have for course " << getDescription() << endl;
	cin >> hwNum;
	homeworkArray = new int[hwNum];													 //dynamic space allocation for number of homework grades

	cout << "Enter the weighted percentage of your homework grades for course " << getDescription() << endl;  //storing homework percentage
	cin >> hwPercent;

	//turns the entered percent value into an actuall percentage
	percentHW = (hwPercent / 100);

	//populates the scores from the user into a homework array
	cout << "Enter in your homework scores for course " << getDescription() << endl;
	for (int i = 0; i< hwNum; i++)
	{
		cout << "Enter score " << i + 1 << endl;
		cin >> homeworkScores;
		homeworkArray[i] = homeworkScores;
	}
	//displays the scores the user entered to the screen
	double temp = 0;
	for (int i = 0; i< hwNum; i++)
	{
		temp += homeworkArray[i];
		cout << "Score # " << i + 1 << " is " << homeworkArray[i] << endl;
	}
	temp = temp / hwNum;				 //Calculates average
	temp = (temp * percentHW);		 //converts average into percentage
	setHw(temp);					// stores percentage in private homework variable

									//deallocates memory space from dynamic array
	delete[]homeworkArray;
}
void courses::displayPrompt()
{
	//string courseName= " ";    // string variable for course name
	int testNum = 0;            // Stores the number of tests the student has
	float testPercent = 0;     // Stores the percentage weight of users's tests
	double percentTest;      // calculated %
	int *testArray = NULL; //Pointer for test array
	int testScores = 0;     // stores the test scores

	cout << "How many tests do you have for course " << getDescription() << endl;
	cin >> testNum;
	testArray = new int[testNum];												  //dynamic space allocation for number of tests

	cout << "Enter the weighted percentage of your tests for course " << getDescription() << endl;  //storing test percentage
	cin >> testPercent;

	//turns the entered percent value into an actuall percentage
	percentTest = (testPercent / 100);

	//populates the scores from the user into a test array
	cout << "Enter in your test scores for course " << getDescription() << endl;
	for (int i = 0; i< testNum; i++)
	{
		cout << "Enter score " << i + 1 << endl;
		cin >> testScores;
		testArray[i] = testScores;
	}
	//displays the scores the user entered to the screen
	double temp = 0;
	for (int i = 0; i< testNum; i++)
	{
		temp += testArray[i];
		cout << "Score # " << i + 1 << " is " << testArray[i] << endl;
	}
	temp = temp / testNum;				  //Calculates average
	temp = (temp * percentTest);		//converts average into percentage
	setTests(temp);					   // stores percentage in private tests variable

									   //deallocates memory space from dynamic array
	delete[]testArray;
}
/*=====================================================================================================================================
|||||||||||||||||||||||||||						START OF MAIN FUNCTION        |||||||||||||this comment section can be deleted later
======================================================================================================================================*/
int main()
{

	try
	{

		courses rep;   //courses object

		int num; // variable to hold input for number of courses

		cout << "How many courses are you taking?" << endl; //user input of course numbers
		cin >> num;
		cin.ignore(); //allows for the getline to work!
		rep.setCourseNum(num);  //set the number of courses taken by user
								// creates a dynamic array to hold course names
		string* cn = NULL;
		cn = new string[num];

		// loop to enter course names dynamically based off user input
		for (int i = 0; i < num; i++)
		{
			cout << "What is the name of course number  " << (i + 1) << endl;
			getline(cin, cn[i]);

		}

		//this loop will run the program for however many courses the user supplies! 
		for (int index = 0; index < rep.getCourseNum(); index++)
		{
			double tempNum = 0;		//stores class percentage average
			char answer = ' ';    // for yes or no input
			rep.setDescription(cn[index]);
			rep.displayPrompt();
			cout << "Do you have any homework grades to enter? [Y/N/]" << endl;
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				rep.displayPromptHW();
			}
			else if (answer == 'N' || answer == 'n')
			{
				cout << "Okay, skipping past homework grades..." << endl;
			}
			cout << "Do you have any quiz grades to enter? [Y/N/]" << endl;
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				rep.displayPromptQZ();
			}
			else if (answer == 'N' || answer == 'n')
			{
				cout << "Okay, skipping past quiz grades..." << endl;
			}
			tempNum = (rep.getTests() + rep.getQuizzes() + rep.getHw());
			rep.setClassAve(tempNum);

			rep.insertNode(rep.getClassAve(), cn[index]);  //creates a node for each course, with the total data stored within[per course]
		}
		rep.displayList();

		delete[] cn;  //deallocates memory
		cin.get(); cin.get();
		return 0;

	}
	catch (...)
	{
		cout << "Hello, you've entered incorrectly" << endl;
		cout << "please try again." << endl;
		system("PAUSE");

	}





}
/*=====================================================================================================================================
||||||||||||||||||||||||||||||||||						END OF MAIN FUNCTION         |||||||||||||||||||||||||||||||||||||||||
======================================================================================================================================*/
void courses::insertNode(double num, string name)
{
	ListNode *newNode;
	ListNode *nodeptr;
	ListNode *previousNode = nullptr;

	//allocate new node to store num and name there
	newNode = new ListNode;
	newNode->value = num;
	newNode->courseName = name;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodeptr = head;
		previousNode = nullptr;

		while (nodeptr != nullptr && nodeptr->value <num)
		{
			previousNode = nodeptr;
			nodeptr = nodeptr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodeptr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodeptr;
		}
	}
}

void courses::displayList() const
{
	ListNode *nodeptr;

	nodeptr = head;
	cout << endl << "According to your submitted data, you should focus on ......" << endl;
	while (nodeptr)
	{
		if (nodeptr->value <70)
		{
			cout << nodeptr->courseName << ": " << nodeptr->value << endl;
			nodeptr = nodeptr->next;
		}
		else
		{
			cout << "....nothing more.";
			nodeptr = NULL;
		}
	}

}
