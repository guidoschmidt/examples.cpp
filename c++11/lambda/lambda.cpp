#include <iostream>
#include <vector>

using namespace std;

//--- Field class --------------------------------------------------------------
// \brief Field class for storing elements
// @class Field
class Field
{
	public:
		// \brief Returns an element based on a given function
		template<typename Function>
		vector<string> findElement(Function function)
		{
			vector<string> results;
			for(auto itr = m_elements.begin(), end = m_elements.end(); itr != end; ++itr)
			{
				if(function( *itr ))
				{
					results.push_back(*itr);
				}
			}
			if(results.empty())
				cout << "Nothing found!\n";
			else
				cout << results.size() << " items found!\n";

			return results;
		}

		// \brief Adds an element to the field
		void addElement(const string element) { m_elements.push_back(element); }

		// \brief
		void printElements(void)
		{
			cout << "Elements in Field: \n 	";
			for(auto e : m_elements){ cout << e << ", "; }
			cout << endl;
		}

	private:
		vector<string> m_elements;
};


void lamdaFunction(void)
{
	// This is the syntax of a lambda function/closure
	auto function = [] () {
		cout << "I am also known as closure!" << endl;
	};
	function();
	cout << "lambda" << endl;
}


vector<string> findElementsContaing(const string& searchString, Field & inField)
{
	cout << "Looking for: "<< searchString << endl << " 	";
	return inField.findElement(
			// Here comes the closure
			// [&] does a variable capture, while
			// [] does tell the compiler not to capture variables
			[&] (const string& value)
			{
				return value.find(searchString) != string::npos;
			}
		);
}

void lambda_as_argument(void (*fn)()) {
  fn();
}

//--- Main ---------------------------------------------------------------------
int main()
{
	cout << "C++ 11 lambda functions" << endl;
	cout << "---------------------------------------------------------" << endl;

	// Simple closure example
	lamdaFunction();

	cout << "---------------------------------------------------------" << endl;

	// Field example
	Field * myField = new Field();
	cout << "Field Example:" << endl;
	myField->addElement("Guido");
	myField->addElement("Verena");
	myField->addElement("Britta");
	myField->addElement("Sammy");
	myField->addElement("Leo");

	myField->printElements();
	string searchForString;

	cout << "Type a search string" << endl;
	cin >> searchForString;

	vector<string> results = findElementsContaing(searchForString, *myField);
	for(auto r : results)
	{
		cout << "	" << r << endl;
	}

  lambda_as_argument([] () {
    std::cout << "Hello from el closure..." << std::endl;
  });

	return 0;
}
